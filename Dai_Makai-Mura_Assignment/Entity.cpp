#include "Entity.h"

void Entity::initialise(string inputTextureFileName, float inputSpeedMax, float inputInitialJumpSpeed, float inputMass, unsigned char inputHealthMax, Vector2f inputPosition)
{
	// Local variables
	Vector2f originAssign;
	// Main "initialise()"
	traversibleTiles.push_back(255);
	entityAnimationStates.frame = 0;
	entityAnimationStates.state = 0;
	entityAnimationStates.interval = 0.5;
	speedMax = inputSpeedMax;
	initialJumpSpeed = inputInitialJumpSpeed;
	healthMax = inputHealthMax;
	position = inputPosition;
	if (!textures.loadFromFile(inputTextureFileName)) //The "Background" Image...
	{
		cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	else
	{
		cout << "Successfully loaded: " << inputTextureFileName << endl;
	}
	Sprite::setTexture(textures);
	Sprite::setTextureRect(sf::IntRect(Vector2i(0, 0), Vector2i(192, 192)));
	//Sprite::setScale(Vector2f(0.5, 0.5));
	size.x = 64;
	size.y = 128;
	originAssign.x = 96;
	originAssign.y = 128;
	Sprite::setOrigin(originAssign);
}

void Entity::update(float inputProcessSpeed)
{
	// Local variables

	// Main "update()"
	position.y -= velocity.y * inputProcessSpeed;
	position.x += velocity.x * inputProcessSpeed;
	animator();
	collisionDetection();
	Sprite::setPosition(position);
}

void Entity::horizontalMove(bool direction, bool moving)
{
	// Local variables

	// Main "horizontalMove()" 
	if (moving)
	{
		if (direction && velocity.x < speedMax)
		{
			velocity.x = speedMax;
		}
		else if (direction == false)
		{
			velocity.x = -speedMax;
		}
	}
	else
	{
		velocity.x = 0;
	}
}

void Entity::animator()
{
	// Local variables
	Time elapsedTime;
	// Main "travel()"
	if (velocity.x == 0)
	{
		if (entityAnimationStates.state != 0)
		{
			entityAnimationStates.frame = 0;
			intervalTimer.restart();
		}
		entityAnimationStates.state = 0;
	}
	else if (velocity.x > 0)
	{
		Sprite::setScale(Vector2f(1.0f, 1.0f));
		if (entityAnimationStates.state != 1)
		{
			entityAnimationStates.frame = 0;
			intervalTimer.restart();
		}
		entityAnimationStates.state = 1;
	}
	else if (velocity.x < 0)
	{
		Sprite::setScale(Vector2f(-1.0f, 1.0f));
		if (entityAnimationStates.state != 1)
		{
			entityAnimationStates.frame = 0;
			intervalTimer.restart();
		}
		entityAnimationStates.state = 1;
	}
	elapsedTime = intervalTimer.getElapsedTime();
	if (elapsedTime.asSeconds() > entityAnimationStates.interval)
	{
		entityAnimationStates.frame++;
		if (entityAnimationStates.frame > 5)
		{
			entityAnimationStates.frame = 0;
		}
		intervalTimer.restart();
	}
	//cout << +entityAnimationStates.state << " " << +entityAnimationStates.frame << endl;
	Sprite::setTextureRect(sf::IntRect(Vector2i(entityAnimationStates.frame * 192, entityAnimationStates.state * 192), Vector2i(192, 192)));
}

contact Entity::collisionDetection()
{
	// Local variables
	contact outPutContact;
	array<Vector2u, 6> tileMapCoordinates;
	int count = 0;
	// main "collisionDetection()"
	outPutContact.top = false;
	outPutContact.bottom = false;
	outPutContact.left = false;
	outPutContact.right = false;
	hitBox[0] = Vector2f(position.x - size.x / 2, position.y - size.y / 2);
	hitBox[1] = Vector2f(position.x + size.x / 2, position.y - size.y / 2);
	hitBox[2] = Vector2f(position.x - size.x / 2, position.y);
	hitBox[3] = Vector2f(position.x + size.x / 2, position.y);
	hitBox[4] = Vector2f(position.x - size.x / 2, position.y + size.y / 2 - 48);
	hitBox[5] = Vector2f(position.x + size.x / 2, position.y + size.y / 2 - 48);
	for (auto item : hitBox)
	{
		count++;
		cout << count << " " << item.x << " " << item.y << endl;
	}
	for (unsigned char i = 0; i < tileMapCoordinates.size(); i++)
	{
		tileMapCoordinates[i].x = hitBox[i].x / 64;
		tileMapCoordinates[i].y = hitBox[i].y / 64;
	}
	count = 0;
	//for (auto item : tileMapCoordinates)
	//{
	//	count++;
	//	cout << count << " " << item.x << " " << item.y << endl;
	//}
	for (int i = 0; i < traversibleTiles.size(); i++)
	{
		//cout << +localGameVariablesPointer->gameMap[tileMapCoordinates[2].y][tileMapCoordinates[2].x];
		if ((*localGameVariablesPointer->gameMap)[tileMapCoordinates[0].y][tileMapCoordinates[0].x] != traversibleTiles[i] || (*localGameVariablesPointer->gameMap)[tileMapCoordinates[2].y][tileMapCoordinates[2].x] != traversibleTiles[i])
		{
			position.x = (64 * tileMapCoordinates[1].x) + (size.x / 2);
			velocity.x = 0;
			outPutContact.left = true;
		}
		if ((*localGameVariablesPointer->gameMap)[tileMapCoordinates[1].y][tileMapCoordinates[1].x] != traversibleTiles[i] || (*localGameVariablesPointer->gameMap)[tileMapCoordinates[3].y][tileMapCoordinates[3].x] != traversibleTiles[i])
		{
			position.x = (64 * tileMapCoordinates[0].x) + (size.x / 2);
			velocity.x = 0;
			outPutContact.right = true;
		}
		if (((*localGameVariablesPointer->gameMap)[tileMapCoordinates[4].y][tileMapCoordinates[4].x] != traversibleTiles[i] || (*localGameVariablesPointer->gameMap)[tileMapCoordinates[5].y][tileMapCoordinates[5].x] != traversibleTiles[i]))
		{
			position.y = (64 * tileMapCoordinates[4].y) - (size.y / 2) + 48;
			velocity.y = 0;
			outPutContact.bottom = true;
		}
	}
	//cout << outPutContact.top << outPutContact.bottom << outPutContact.left << outPutContact.right << endl;
	return outPutContact;
}
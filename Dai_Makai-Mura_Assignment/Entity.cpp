#include "Entity.h"

void Entity::initialise(string inputTextureFileName, float inputSpeedMax, float inputInitialJumpSpeed, float inputMass, unsigned char inputHealthMax, Vector2f inputPosition)
{
	//Local Variables
	Vector2f originAssign;
	//Main Initialise()
	speedMax = inputSpeedMax;
	initialJumpSpeed = inputInitialJumpSpeed;
	healthMax = inputHealthMax;
	position = inputPosition;
	if (!textures[0].loadFromFile(inputTextureFileName)) //The "Background" Image...
	{
		cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	else
	{
		cout << "Successfully loaded: " << inputTextureFileName << endl;
	}
	sprite.setTexture(textures[0]);
	sprite.setScale(Vector2f(0.5, 0.5));
	size.x = textures->getSize().x / 2;
	size.y = textures->getSize().y / 2;
	originAssign.x = size.x / 2;
	originAssign.y = size.y / 2;
	sprite.setOrigin(originAssign);
}

void Entity::update(float inputProcessSpeed)
{
	//Local Variables

	//Main Update()
	position.y -= velocity.y * inputProcessSpeed;
	position.x += velocity.x * inputProcessSpeed;
	sprite.setPosition(position);
	if (position.y > 600 - size.x)
	{
		position.y = 600 - size.x;
		velocity.y = 0;
	}
}

void Entity::horizontalMove(bool direction, bool moving)
{
	//Local Variables

	//Main HorizontalMove() 
	if (moving)
	{
		if (direction && velocity.x < speedMax)
		{
			//*velocityXPointer = 500;
			velocity.x += acceleration;
		}
		else if (direction == false && velocity.x > -speedMax)
		{
			//*velocityXPointer = -500;
			velocity.x -= acceleration;
		}
	}
	else
	{
		velocity.x = 0;
	}
}

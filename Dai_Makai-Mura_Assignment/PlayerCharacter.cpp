#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	if (!backgroundTexture.loadFromFile("Assets/Backgrounds/Day Background Texture.png")) //The "Background" Image...
	{
		cout << "Error 2: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	else
	{
		cout << "Successfully loaded: Assets/Backgrounds/Day Background Texture.png" << endl;
	}
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setOrigin(Vector2f(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2 ));
	backgroundSprite.setPosition(position);
}

void PlayerCharacter::update(float inputProcessSpeed)
{
	GroundEntity::update(inputProcessSpeed);
	backgroundSprite.setPosition(position);
}
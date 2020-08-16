// Dai_Makai-Mura_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "PlayerCharacter.h"

using namespace std;
using namespace sf;

//Global Variables
	//Game Window Variables
sf::Vector2f theGameWindow_CurrentDimensions(960, 640);
sf::Vector2f theGameWindow_PerspectiveDimensions(960, 640);
sf::RenderWindow theGameWindow(sf::VideoMode(theGameWindow_CurrentDimensions.x, theGameWindow_CurrentDimensions.y), "Dai Makai-Mura", sf::Style::Titlebar);
PlayerCharacter MainPlayer;
void InputListener();

int main()
{
	//Local Variables
		//Clock Variables
	Clock clockSpeed;
	Time delta;
	float deltaAsSeconds;
	Texture grass;
	if (!grass.loadFromFile("Assets/Grass_Tile_1.png")) //The "Background" Image...
	{
		cout << "Error 2: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	else
	{
		cout << "Successfully loaded: Assets/Grass_Tile_1.png" << endl;
	}
	Sprite grassSprite;
	grassSprite.setTexture(grass);
	grassSprite.setScale({ 0.5, 0.5 });
	Vector2f grassSpawn(0.f, 600);
	//Main main()
	Vector2f position(100.f, 100.f);
	MainPlayer.initialise("Assets/Main_Character.png", 500, 400, 500, 1, position);
	MainPlayer.mainView = theGameWindow.getDefaultView();
	theGameWindow.setFramerateLimit(60);
	while (theGameWindow.isOpen())
	{
		delta = clockSpeed.restart();
		InputListener();
		theGameWindow.clear();
		MainPlayer.update(delta.asSeconds());
		MainPlayer.mainView.setCenter(MainPlayer.position);
		theGameWindow.setView(MainPlayer.mainView);
		grassSprite.setPosition(grassSpawn);
		for (int i = 0; i < 30; i++)
		{
			theGameWindow.draw(grassSprite);
			grassSprite.move({ 50, 0 });
		}
		theGameWindow.draw(MainPlayer.sprite);
		theGameWindow.display();
	}
}

void InputListener()
{
	//Local Variables
	sf::Event event;

	//Main "InputListener()"
	while (theGameWindow.pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		{
			theGameWindow.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				MainPlayer.jump();
			}
			if (event.key.code == sf::Keyboard::D)
			{
				MainPlayer.horizontalMove(true, true);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				MainPlayer.horizontalMove(false, true);
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::D)
			{
				MainPlayer.horizontalMove(true, false);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				MainPlayer.horizontalMove(false, false);
			}
		}
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

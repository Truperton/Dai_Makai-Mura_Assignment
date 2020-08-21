// Dai_Makai-Mura_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "sharedVariables.h"
#include "TileMap.h"
#include "Entity.h"
#include "PlayerCharacter.h"

using namespace std;
using namespace sf;

//Global Variables
	//Game Window Variables
sf::Vector2f theGameWindow_CurrentDimensions(960, 640);
sf::Vector2f theGameWindow_PerspectiveDimensions(960, 640);
//sf::RenderWindow theGameWindow(sf::VideoMode(theGameWindow_CurrentDimensions.x, theGameWindow_CurrentDimensions.y), "Dai Makai-Mura", sf::Style::Titlebar);
PlayerCharacter *MainPlayer;
TileMap *mainTileMap;
sharedVariables gameVariables;

void InputListener();

int main()
{
	//Local Variables
		//Clock Variables
	//Clock clockSpeed;
	//Time delta;
	//float deltaAsSeconds;
	gameVariables.gameMap = new array<array<unsigned char, 128>, 64>;
	mainTileMap = new TileMap(&gameVariables);
	MainPlayer = new PlayerCharacter();
	mainTileMap->load("Assets/Tile Sets/Main Tile Set.png", "Map 1.csv", Vector2u(64, 64), gameVariables.gameMap);
	//Main main()
	gameVariables.theGameWindow = new RenderWindow(sf::VideoMode(theGameWindow_CurrentDimensions.x, theGameWindow_CurrentDimensions.y), "Dai Makai-Mura", sf::Style::Default);
	Vector2f position(200.0f, 200.f);
	MainPlayer->initialise("Assets/Sprite Sheets/Main Character.png", 500.0f, 400.0f, 500.0f, 1, position);
	MainPlayer->mainView = gameVariables.theGameWindow->getDefaultView();
	MainPlayer->localGameVariablesPointer = &gameVariables;
	gameVariables.theGameWindow->setFramerateLimit(60);
	while (gameVariables.theGameWindow->isOpen())
	{
		gameVariables.delta = gameVariables.clockSpeed.restart();
		InputListener();
		gameVariables.theGameWindow->clear();
		gameVariables.theGameWindow->draw(MainPlayer->backgroundSprite);
		gameVariables.theGameWindow->draw(*mainTileMap);
		MainPlayer->update(gameVariables.delta.asSeconds());
		MainPlayer->mainView.setCenter(MainPlayer->position);
		gameVariables.theGameWindow->setView(MainPlayer->mainView);
		gameVariables.theGameWindow->draw(*MainPlayer);
		gameVariables.theGameWindow->display();
	}
}

void InputListener()
{
	//Local Variables
	sf::Event event;

	//Main "InputListener()"
	while (gameVariables.theGameWindow->pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		{
			gameVariables.theGameWindow->close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				MainPlayer->jump();
			}
			if (event.key.code == sf::Keyboard::D)
			{
				MainPlayer->horizontalMove(true, true);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				MainPlayer->horizontalMove(false, true);
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::D)
			{
				MainPlayer->horizontalMove(true, false);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				MainPlayer->horizontalMove(false, false);
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

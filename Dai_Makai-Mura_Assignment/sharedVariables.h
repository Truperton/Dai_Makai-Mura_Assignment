#pragma once

#include <iostream>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct sharedVariables
{
	Clock clockSpeed;
	Time delta;
	mt19937 numberGenerator;
	sf::RenderWindow *theGameWindow;
	array<array<unsigned char, 128>, 64> *gameMap;
};

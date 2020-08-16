#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct sharedVariables
{
	Clock clockSpeed;
	Time delta;
	array<array<unsigned char, 128>, 64> gameMap;
};

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity : public Sprite
{
public:
	Entity()
	{
		cout << "Entities object created\n";
	}
	~Entity()
	{
		cout << "Entities object destroyed\n";
	}
	Vector2f velocity = { 0, 0 };
	float speedMax = 50;
	float acceleration = 100;
	float initialJumpSpeed = 70;
	unsigned char healthMax = 1;
	unsigned char health = 1;
	Vector2u size;
	Vector2f position;
	Sprite sprite;
	Texture textures[1];
	void initialise(string inputTextureFileName, float inputSpeedMax, float inputInitialJumpSpeed, float inputMass, unsigned char inputHealthMax, Vector2f inputPosition);
	virtual void update(float inputProcessSpeed);
	void horizontalMove(bool direction, bool moving);
private:

};


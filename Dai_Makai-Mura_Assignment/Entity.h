#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "sharedVariables.h"

using namespace std;
using namespace sf;

struct contact
{
	bool top;
	bool bottom;
	bool left;
	bool right;
};

struct animationStates
{
	unsigned char state;
	unsigned char frame;
	float interval;
};

class Entity : public Sprite
{
public:
	// Public variables
	sharedVariables *localGameVariablesPointer;
	Vector2f velocity = { 0, 0 };
	float speedMax = 50;
	float initialJumpSpeed = 70;
	unsigned char healthMax = 1;
	unsigned char health = 1;
	Vector2u size;
	Vector2f position;
	Texture textures;
	vector<unsigned char> traversibleTiles;
	array<Vector2f, 6> hitBox;
	contact contacts;
	animationStates entityAnimationStates;
	Clock intervalTimer;

	// Constructors
	Entity()
	{
		
	}

	Entity(sharedVariables *inputSharedVariablesPointer)
	{
		cout << "Entities object created\n";
	}

	// Destructor
	~Entity()
	{
		cout << "Entities object destroyed\n";
	}

	//Public methods
	void initialise(string inputTextureFileName, float inputSpeedMax, float inputInitialJumpSpeed, float inputMass, unsigned char inputHealthMax, Vector2f inputPosition);
	virtual void update(float inputProcessSpeed);
	void horizontalMove(bool direction, bool moving);
protected:
	// Protected variables

	// Protected methods
	void animator();
	contact collisionDetection();
private:
	// Private variables

	// Private methods

};
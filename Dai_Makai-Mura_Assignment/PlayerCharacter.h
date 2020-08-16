#pragma once

#include "GroundEntity.h"

class PlayerCharacter : public GroundEntity
{
public:
	// Public variables
	View mainView;

	// Constructor
	PlayerCharacter()
	{
		cout << "PlayerCharacter object created\n";
	}

	// Destructor
	~PlayerCharacter()
	{
		cout << "PlayerCharacter object destroyed\n";
	}

	// Public methods
	void update(float inputProcessSpeed);
protected:
	// Protected variables

	// Protected methods

private:
	// Private variables

	// Private methods

};
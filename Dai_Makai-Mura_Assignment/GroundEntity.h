#pragma once

#include "Entity.h"

class GroundEntity : public Entity
{
public:
	// Public variables
	float mass = 100;
	// Public methods
	virtual void update(float inputProcessSpeed);
	void jump();
protected:
	// Protected variables

	// Protected methods
private:
	// Private variables

	// Private methods

};


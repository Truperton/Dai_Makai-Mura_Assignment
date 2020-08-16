#include "GroundEntity.h"

void GroundEntity::update(float inputProcessSpeed)
{
	velocity.y -= mass * 8 * inputProcessSpeed;
	Entity::update(inputProcessSpeed);
}

void GroundEntity::jump()
{
	velocity.y = initialJumpSpeed;
}
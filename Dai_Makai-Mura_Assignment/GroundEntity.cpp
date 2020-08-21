#include "GroundEntity.h"

void GroundEntity::update(float inputProcessSpeed)
{
	Entity::update(inputProcessSpeed);
	velocity.y -= mass * 8 * inputProcessSpeed;

	//if (position.y > 992 - size.y / 2.33)
	//{
	//	position.y = 992 - size.y / 2.33;
	//	velocity.y = 0;
	//}
}

void GroundEntity::jump()
{
	velocity.y = initialJumpSpeed;
}
#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "BoundingShape.h"
#include "Asteroids.h"
#include "ChildAsteroid.h"

ChildAsteroid:: ChildAsteroid(parent_position_x, parent_position_y) : Asteroid()
{
	mAngle = rand() % 360;
	mRotation = 0; // rand() % 90;
	mPosition.x = parent_position;
	mPosition.y = parent_position;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
	
}
 


ChildAsteroid::~Asteroid(void)
{

}

bool ChildAsteroid::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void ChildAsteroid::OnCollision(const GameObjectList& objects) {
	mWorld->FlagForRemoval(GetThisPtr());
}



#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "BoundingShape.h"
#include "Asteroids.h"
#include "ChildAsteroid.h"

ChildAsteroid:: ChildAsteroid() : Asteroid ()
{
	mAngle = rand() % 360;
	mRotation = 0; // rand() % 90;
	mVelocity.x = ( rand() % 6) * cos(DEG2RAD * mAngle);
	mVelocity.y = (rand() % 6) * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
	
}
 


ChildAsteroid::~ChildAsteroid(void)
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



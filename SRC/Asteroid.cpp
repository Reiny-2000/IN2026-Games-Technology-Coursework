#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "GameWorld.h"
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "Asteroids.h"
Asteroid::Asteroid(void) : GameObject("Asteroid")
{
	mAngle = rand() % 360;
	mRotation = 0; // rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
}



Asteroid::~Asteroid(void)
{

}

bool Asteroid::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return mBoundingShape->CollisionTest(o->GetBoundingShape());
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Asteroid::OnCollision(const GameObjectList& objects) {
	for (auto& obj : objects)
	{
		if (obj == GetThisPtr()) continue;

		if (obj->GetType() == GameObjectType("Asteroid"))
		{
			// Get other asteroid velocity

			auto other = dynamic_pointer_cast<Asteroid>(obj);
			if (!other) continue;
				
			// Simple velocity swap (arcade bounce)
			GLVector3f temp = mVelocity;
			mVelocity = other->GetVelocity();
			other->SetVelocity(temp);
			
		}
		else {
			mWorld->FlagForRemoval(GetThisPtr());
		}
	}


}


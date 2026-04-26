#include "ExtraLife.h"
#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "GameWorld.h"
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "Asteroids.h"
#include "Player.h"
 ExtraLife::ExtraLife(void) : GameObject("ExtraLife")
{
	mAngle = rand() % 360;
	mRotation = rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 0.0;
	mVelocity.y = 0.0;
	mVelocity.z = 0.0;
}

 ExtraLife::~ExtraLife(void)
{

}

bool ExtraLife::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return mBoundingShape->CollisionTest(o->GetBoundingShape());
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void ExtraLife::OnCollision(const GameObjectList& objects) {
	for (auto& obj : objects)
	{
		if (obj == GetThisPtr()) continue;

		if (obj->GetType() == GameObjectType("Spaceship") || obj->GetType() == GameObjectType("Bullet"))
		{
			mWorld->FlagForRemoval(GetThisPtr());

		}
		else {

			auto other = dynamic_pointer_cast<Asteroid>(obj);
			if (!other) continue;

			// Simple velocity swap (arcade bounce)
			GLVector3f temp = mVelocity;
			mVelocity = other->GetVelocity();
			other->SetVelocity(temp);
		}
	}


}


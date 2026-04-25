#ifndef __CHILDASTEROID_H__
#define __CHILDASTEROID_H__
#include "GameObject.h"
#include "Asteroid.h"

class ChildAsteroid : public Asteroid {
public:
	ChildAsteroid(void);
	~ChildAsteroid(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
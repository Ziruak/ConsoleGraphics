#include <Scene.h>

Scene::~Scene()
{
	if (destroyObjectsOnDeletion) {
		for (auto i : objects) {
			delete i;
		}
	}
}

vec3 Scene::getClosestCollision(vec3 pos, vec3 rayd)
{
	vec3 n(0);
	vec2 tmin(0), tcur(0);
	for (auto i : objects) {
		vec2 tcur = i->collisionsWithRay(pos, rayd);
		if (tcur.x > 0 && (tcur.x < tmin.x || tmin.x == 0)) {
			tmin = tcur;
			n = i->getNorm(pos + rayd * tmin.x);
		}
	}
    return n;
}

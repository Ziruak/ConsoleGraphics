#pragma once
#include "RenderedObject.h"
#include "Vec2.h"
#include "Vec3.h"
#include <vector>
class Scene
{
	std::vector<IRenderedObject*> objects;
public:
	bool destroyObjectsOnDeletion = true;
	Scene(std::vector<IRenderedObject*> objs) :objects(objs) {};
	Scene(std::initializer_list<IRenderedObject*> list) :objects(list.begin(), list.end()) {};
	~Scene();
	vec3 getClosestCollision(vec3 pos, vec3 rayd);
};


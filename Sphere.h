#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include <math.h>
#include "Vec3.h"
#include "RenderedObject.h"

class Sphere:RenderedObject {
public:
	vec3 _pos;
	float _r;

	Sphere(vec3& pos, float r) : _pos(pos), _r(r) {};
	Sphere(float x, float y, float z, float r) : _pos(vec3(x, y, z)), _r(r) {};

	vec2 collisionsWithRay(vec3 pos, vec3 ray);
};

#endif // !SPHERE_H

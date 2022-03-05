#pragma once
#ifndef SPHERE_H
#include "Vec3.h"
#include <math.h>
#include "RenderedObject.h"

class Sphere:RenderedObject {
public:
	vec3 _pos;
	float _r;

	Sphere(vec3& pos, float r) : _pos(pos), _r(r) {};
	Sphere(float x, float y, float z, float r) : _pos(vec3(x, y, z)), _r(r) {};

	vec2 collisionsWithRay(vec3 pos, vec3 ray) {
		vec3 ro_sub_so = pos - _pos;
		float a = ray.dot(ray);
		float b = 2 * ray.dot(ro_sub_so);
		float c = ro_sub_so.dot(ro_sub_so) - _r * _r;
		if (b * b - 4 * a * c < 0) return vec2(-1.0);
		else return vec2((-b - sqrt(b * b - 4 * a * c)) / (2 * a), (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
	}
};

#endif // !SPHERE_H

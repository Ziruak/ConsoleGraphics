#pragma once
#ifndef PLANE_H
#include "RenderedObject.h";
#include "Vec3.h"

class Plane : public IRenderedObject
{
	vec3 _norm;
	vec3 _point;

	public:

	Plane(vec3 point, vec3 norm) :_point(point), _norm(norm) {};
	Plane(vec3 pa, vec3 pb, vec3 pc);

	vec3 getNorm(vec3 point);
	virtual vec2 collisionsWithRay(vec3 pos, vec3 ray);
	bool pointOnPlane(vec3 point);
};

#endif // !PLANE_H
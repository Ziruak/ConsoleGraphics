#pragma once
#ifndef RENDERED_OBJECT_H
#define RENDERED_OBJECT_H
#include "Vec3.h"
#include "VecFunctions.h"

class IRenderedObject
{
public:
	virtual vec2 collisionsWithRay(vec3 pos, vec3 ray)=0;
	virtual vec3 getNorm(vec3 point) = 0;
};

#endif // !RENDERED_OBJECT_CLASS


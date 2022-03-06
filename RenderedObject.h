#pragma once
#ifndef RENDERED_OBJECT_H
#define RENDERED_OBJECT_H
#include "Vec3.h"
#include "VecFunctions.h"

class RenderedObject
{
	virtual vec2 collisionsWithRay(vec3 pos, vec3 ray)=0;
};

#endif // !RENDERED_OBJECT_CLASS


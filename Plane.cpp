#include "Plane.h"

vec3 Plane::getNorm(vec3 point)
{
    vec3 norm(0);
    if (pointOnPlane(point))
        norm = _norm;
    return norm;
}

bool Plane::pointOnPlane(vec3 point)
{
    return fabsf(_norm.dot(point-_point))<=1e-4f;
}

#pragma once
#ifndef VEC_FUNCTIONS_H
#define VEC_FUNCTIONS_H
#include <math.h>
#include "Vec2.h"
#include "Vec3.h"

float clamp(float value, float min, float max);
double sign(double a);
double step(double edge, double x);

float length(vec2 const& v);

float length(vec3 const& v);

vec3 norm(vec3 v);

float dot(vec3 const& a, vec3 const& b);

vec3 abs(vec3 const& v);

vec3 sign(vec3 const& v);

vec3 step(vec3 const& edge, vec3 v);

vec3 reflect(vec3 rd, vec3 n);

vec3 rotateX(vec3 a, double angle);

vec3 rotateY(vec3 a, double angle);

vec3 rotateZ(vec3 a, double angle);

// line: ro + rd*t <-> o+dt
// sphere: (x-x0)^2+(y-y0)^2+(z-z0)^2=r^2
// sphere in vec form: (m-so)^2=r^2
// m = o+dt
// (dt + (o-c))^2-r^2=0
// ...
// a = d^2; b = 2d(o-so); c = ((o-so)^2 - r^2);
// t = (-b +/- sqrt(b^2 - 4ac))/2a
// can be optimised
vec2 sphere(vec3 ro_sub_so, vec3 rd, float r);

vec2 box(vec3 ro, vec3 rd, vec3 boxSize, vec3& outNormal);

float plane(vec3 ro, vec3 rd, vec3 p, float w);

#endif // !VEC_FUNCTIONS_H
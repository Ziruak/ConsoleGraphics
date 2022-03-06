#pragma once
#ifndef VEC_2_H
#define VEC_2_H
#include <math.h>



class vec2
{
public:
	float x, y;

	vec2(float value) : x(value), y(value) {}
	vec2(float _x, float _y) : x(_x), y(_y) {}

	vec2 operator+(vec2 const& other);
	vec2 operator-(vec2 const& other);
	vec2 operator*(vec2 const& other);
	vec2 operator*(const float other);
	vec2 operator/(vec2 const& other);

	float length();
	vec2 norm();
	float dot(vec2 const& b);
	vec2 abs();
};

#endif // !VEC_2_H
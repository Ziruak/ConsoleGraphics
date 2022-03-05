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

	vec2 operator+(vec2 const& other) { return vec2(x + other.x, y + other.y); }
	vec2 operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }
	vec2 operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
	vec2 operator*(const float other) { return vec2(x * other, y * other); }
	vec2 operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }

	float length() { return sqrt(x * x + y * y); }
	vec2 norm() { return *this / this->length(); }
	float dot(vec2 const& b) { return x * b.x + y * b.y; }
	vec2 abs() { return vec2(fabs(x), fabs(y)); }
};

#endif // !VEC_2_H
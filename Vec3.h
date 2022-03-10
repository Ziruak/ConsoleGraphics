#pragma once
#ifndef VEC_3_H
#define VEC_3_H
#include "Vec2.h"
#include <vector>

class vec3
{
public:
	float x, y, z;

	vec3(float _value) : x(_value), y(_value), z(_value) {};
	vec3(float _x, const vec2 v) : x(_x), y(v.x), z(v.y) {};
	vec3(const vec2 v, float _z) : x(v.x), y(v.y), z(_z) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {};
	vec3(const std::vector<float> v) : x(v[0]), y(v[1]), z(v[2]) {};

	vec3 operator+(const vec3 other);
	vec3 operator-(const vec3 other);
	vec3 operator*(const vec3 other);
	vec3 operator*(const float other);
	vec3 operator/(const vec3 other);
	vec3 operator-();
	vec3 operator=(const vec3 other);
	vec3 operator+=(const vec3 other);
	float operator[](const int i);

	float length();
	vec3 norm();
	float dot(vec3 const& b);
	vec3 abs();
	vec3 sign();
	vec3 reflect(vec3 n);
	// axb =
	// | i  j  k  |
	// | ax ay az |
	// | bx by bz |
	vec3 cross(vec3 b);

	vec3 rotateX(double angle);

	vec3 rotateY(double angle);

	vec3 rotateZ(vec3 a, double angle);
};

vec3 operator*(const float f, vec3& vec);

#endif // !VEC_3_H
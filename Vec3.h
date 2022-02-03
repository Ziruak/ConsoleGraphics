#pragma once
#ifndef VEC_3_H
#define VEC_3_H
#include "Vec2.h"

class vec3
{
public:
	float x, y, z;

	vec3(float _value) : x(_value), y(_value), z(_value) {};
	vec3(float _x, vec2 const& v) : x(_x), y(v.x), z(v.y) {};
	vec3(vec2 const& v, float _z) : x(v.x), y(v.y), z(_z) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	vec3 operator+(vec3 const& other) { return vec3(x + other.x, y + other.y, z + other.z); }
	vec3 operator-(vec3 const& other) { return vec3(x - other.x, y - other.y, z - other.z); }
	vec3 operator*(vec3 const& other) { return vec3(x * other.x, y * other.y, z * other.z); }
	vec3 operator*(const float other) { return vec3(x * other, y * other, z * other); }
	vec3 operator/(vec3 const& other) { return vec3(x / other.x, y / other.y, z / other.z); }
	vec3 operator-() { return vec3(-x, -y, -z); }

	float length() { return sqrt(x * x + y * y + z * z); }
	vec3 norm() { return *this / this->length(); }
	float dot(vec3 const& b) { return x * b.x + y * b.y + z * b.z; }
	vec3 abs() { return vec3(fabs(x), fabs(y), fabs(z)); }
	vec3 sign() {
		auto dsign = [](double a) {return (0 < a) - (a < 0); };
		return vec3(dsign(x), dsign(y), dsign(z)); }
	vec3 reflect(vec3 n) { return *this - n * (2 * this->dot(n)); }
	// axb =
	// | i  j  k  |
	// | ax ay az |
	// | bx by bz |
	vec3 cross(vec3 b) { return vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x); }

	vec3 rotateX(double angle)
	{
		vec3 b(x,y,z);
		b.z = z * cos(angle) - y * sin(angle);
		b.y = z * sin(angle) + y * cos(angle);
		return b;
	}

	vec3 rotateY(double angle)
	{
		vec3 b(x,y,z);
		b.x = x * cos(angle) - z * sin(angle);
		b.z = x * sin(angle) + z * cos(angle);
		return b;
	}

	vec3 rotateZ(vec3 a, double angle)
	{
		vec3 b(x,y,z);
		b.x = x * cos(angle) - y * sin(angle);
		b.y = x * sin(angle) + y * cos(angle);
		return b;
	}
};

#endif // !VEC_3_H
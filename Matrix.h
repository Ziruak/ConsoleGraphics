#pragma once
#ifndef MATRIX_H
#include"Vec3.h"

class mat3 {
	float _arr[9];
public:
	mat3() :mat3(0.0f) {};
	mat3(float elem);
	mat3(const mat3& m);
	mat3(vec3& a, vec3& b, vec3& c);

	static mat3 one();

	vec3 operator*(const vec3& v);
	vec3 operator[](const int i);
	mat3 operator+(const mat3& m);
	mat3 operator-(const mat3& m);
	mat3 operator*(const float f);
	mat3 operator*(const mat3& m);
	friend mat3 operator* (const float f, const mat3& m);

	bool operator==(const mat3& m);
	
};

mat3 operator* (const float f, const mat3& m);

#endif // !MATRIX_H
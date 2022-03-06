#include "Vec2.h"

vec2 vec2::operator+(vec2 const& other)
{
	return vec2(x + other.x, y + other.y);
}

vec2 vec2::operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }

vec2 vec2::operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
vec2 vec2::operator*(const float other) { return vec2(x * other, y * other); }
vec2 vec2::operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }

float vec2::length() { return sqrt(x * x + y * y); }
vec2 vec2::norm() { return *this / this->length(); }
float vec2::dot(vec2 const& b) { return x * b.x + y * b.y; }
vec2 vec2::abs() { return vec2(fabs(x), fabs(y)); }
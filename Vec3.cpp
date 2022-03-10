#include "Vec3.h"

vec3 operator*(const float f, vec3& vec) { return vec * f; }

vec3 vec3::operator+(const vec3 other) { return vec3(x + other.x, y + other.y, z + other.z); }
vec3 vec3::operator-(const vec3 other) { return vec3(x - other.x, y - other.y, z - other.z); }
vec3 vec3::operator*(const vec3 other) { return vec3(x * other.x, y * other.y, z * other.z); }
vec3 vec3::operator*(const float other) { return vec3(x * other, y * other, z * other); }
vec3 vec3::operator/(const vec3 other) { return vec3(x / other.x, y / other.y, z / other.z); }
vec3 vec3::operator-() { return vec3(-x, -y, -z); }
vec3 vec3::operator=(const vec3 other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}
vec3 vec3::operator+=(const vec3 other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

float vec3::operator[](const int i)
{
	switch (i)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	default:
		throw std::exception("Array out of bounds");
		break;
	}
}

float vec3::length() { return sqrt(x * x + y * y + z * z); }
vec3 vec3::norm() { return *this / this->length(); }
float vec3::dot(vec3 const& b) { return x * b.x + y * b.y + z * b.z; }
vec3 vec3::abs() { return vec3(fabs(x), fabs(y), fabs(z)); }
vec3 vec3::sign() {
	auto dsign = [](double a) {return (0 < a) - (a < 0); };
	return vec3(dsign(x), dsign(y), dsign(z));
}
vec3 vec3::reflect(vec3 n) { return *this - n * (2 * this->dot(n)); }
// axb =
// | i  j  k  |
// | ax ay az |
// | bx by bz |
vec3 vec3::cross(vec3 b) { return vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }

vec3 vec3::rotateX(double angle)
{
	vec3 b(x, y, z);
	b.z = z * cos(angle) - y * sin(angle);
	b.y = z * sin(angle) + y * cos(angle);
	return b;
}

vec3 vec3::rotateY(double angle)
{
	vec3 b(x, y, z);
	b.x = x * cos(angle) - z * sin(angle);
	b.z = x * sin(angle) + z * cos(angle);
	return b;
}

vec3 vec3::rotateZ(vec3 a, double angle)
{
	vec3 b(x, y, z);
	b.x = x * cos(angle) - y * sin(angle);
	b.y = x * sin(angle) + y * cos(angle);
	return b;
}
#include "Sphere.h"

vec2 Sphere::collisionsWithRay(vec3 pos, vec3 ray)
{
	vec3 ro_sub_so = pos - _pos;
	float a = ray.dot(ray);
	float b = 2 * ray.dot(ro_sub_so);
	float c = ro_sub_so.dot(ro_sub_so) - _r * _r;
	if (b * b - 4 * a * c < 0) return vec2(-1.0);
	else return vec2((-b - sqrt(b * b - 4 * a * c)) / (2 * a), (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
}

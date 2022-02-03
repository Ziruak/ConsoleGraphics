#pragma once
#ifndef CAM_H
#define CAM_H
#include "Vec3.h"

class Cam {
public:
	vec3 pos;
	vec3 look_f;
	vec3 look_up;
	vec3 look_r;
	float r;
	vec2 screenSize;

	Cam(vec3& _pos, vec3 _look_f, vec3 _look_up, float _r, vec2 _screenSize) : 
		pos(_pos), 
		look_f(_look_f), 
		look_up(_look_up), 
		look_r(_look_f.cross(_look_up)), 
		r(_r), 
		screenSize(_screenSize) {}
	Cam(vec3& _pos, vec3 _look_f, vec3 _look_up, float _r, int width, int height) : 
		Cam(_pos, _look_f, _look_up, _r, vec2(width, height)) {}
};

#endif // !CAM_H
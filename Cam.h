#pragma once
#ifndef CAM_H
#define CAM_H
#include<math.h>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include "Vec3.h"

class Cam {
public:
	vec3 pos; // camera position
	vec3 look_f; // look forward vector
	vec3 look_u; // look up vector
	vec3 look_r; // look right vector
	float r; // distance from camera to screen
	vec2 screenSize; // size of screen in pixels

	Cam(vec3 _pos, vec3 _look_f, vec3 _look_up, float _r, vec2 _screenSize) : 
		pos(_pos), 
		look_f(_look_f.norm()), 
		look_u(_look_up.norm()), 
		look_r(_look_f.cross(_look_up)), 
		r(_r), 
		screenSize(_screenSize) {}
	Cam(vec3 _pos, vec3 _look_f, vec3 _look_up, float _r, int width, int height) : 
		Cam(_pos, _look_f, _look_up, _r, vec2(width, height)) {}

	void move(vec3 v) {
		pos += v;
	}

	void moveFoward(float r) {
		pos += r * look_f;
	}

	void moveUp(float r) {
		pos += r * look_u;
	}

	void moveRight(float r) {
		pos += r * look_r;
	}

	void setPos(vec3 pos) {
		this->pos = pos;
	}

	vec3 getPixelVec(float x, float y) {
		return (r * look_f + (x - screenSize.x / 2) * look_r + (screenSize.y / 2 - y) * look_u).norm();
	}

	vec3 getPixelVec(vec2 pixelPos) {
		return getPixelVec(pixelPos.x, pixelPos.y);
	}

	void pitchCam(float a) {
		a *= M_PI / 180.0f;
		look_f = vec3(look_f.x * cos(a) + look_f.z * sin(a), look_f.y, -sin(a) * look_f.x + cos(a) * look_f.z);
		look_u = vec3(look_u.x * cos(a) + look_u.z * sin(a), look_u.y, -sin(a) * look_u.x + cos(a) * look_u.z);
	}

	void yawCam(float a) {
		a *= M_PI / 180.0f;
		look_f = vec3(look_f.x * cos(a) - look_f.y * sin(a), sin(a)*look_f.x + cos(a)*look_f.y, look_f.z);
		look_r = vec3(look_r.x * cos(a) - look_r.y * sin(a), sin(a) * look_r.x + cos(a) * look_r.y, look_r.z);
	}

	void rollCam(float a) {
		a *= M_PI / 180.0f;
		look_u = vec3(look_u.x, look_u.y * cos(a) - sin(a) * look_u.z, look_u.y * sin(a) + look_u.z * cos(a));
		look_r = vec3(look_r.x, look_r.y * cos(a) - sin(a) * look_r.z, look_r.y * sin(a) + look_r.z * cos(a));
	}

	// pitch: right - static
	// yaw: up - static
	// roll: foward - static
	void rotateCamera(float pitch, float yaw, float roll) {
		this->pitchCam(pitch);
		this->yawCam(yaw);
		this->rollCam(roll);
	}
};

#endif // !CAM_H
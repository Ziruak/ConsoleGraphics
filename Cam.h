#pragma once
#ifndef CAM_H
#define CAM_H
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

	void move(vec3 v);
	void moveFoward(float r);
	void moveUp(float r);
	void moveRight(float r);
	void setPos(vec3 pos);
	vec3 getPixelVec(float x, float y);
	vec3 getPixelVec(vec2 pixelPos);
	void pitchCam(float a);
	void yawCam(float a);
	void rollCam(float a);
	// pitch: right - static
	// yaw: up - static
	// roll: foward - static
	void rotateCamera(float pitch, float yaw, float roll);
};

#endif // !CAM_H
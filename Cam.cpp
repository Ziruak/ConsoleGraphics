#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include "Cam.h"
#include<cmath>


void Cam::move(vec3 v)
{
	pos += v;
}

void Cam::moveFoward(float r)
{
	pos += r * look_f;
}

void Cam::moveUp(float r)
{
	pos += r * look_u;
}

void Cam::moveRight(float r)
{
	pos += r * look_r;
}

void Cam::setPos(vec3 pos)
{
	this->pos = pos;
}

vec3 Cam::getPixelVec(float x, float y)
{
	return (r * look_f + (x - screenSize.x / 2) * look_r + (screenSize.y / 2 - y) * look_u).norm();
}

vec3 Cam::getPixelVec(vec2 pixelPos)
{
	return getPixelVec(pixelPos.x, pixelPos.y);
}

void Cam::pitchCam(float a)
{
	a *= M_PI / 180.0f;
	look_f = vec3(look_f.x * cos(a) + look_f.z * sin(a), look_f.y, -sin(a) * look_f.x + cos(a) * look_f.z);
	look_u = vec3(look_u.x * cos(a) + look_u.z * sin(a), look_u.y, -sin(a) * look_u.x + cos(a) * look_u.z);
}

void Cam::yawCam(float a)
{
	a *= M_PI / 180.0f;
	look_f = vec3(look_f.x * cos(a) - look_f.y * sin(a), sin(a) * look_f.x + cos(a) * look_f.y, look_f.z);
	look_r = vec3(look_r.x * cos(a) - look_r.y * sin(a), sin(a) * look_r.x + cos(a) * look_r.y, look_r.z);
}

void Cam::rollCam(float a)
{
	a *= M_PI / 180.0f;
	look_u = vec3(look_u.x, look_u.y * cos(a) - sin(a) * look_u.z, look_u.y * sin(a) + look_u.z * cos(a));
	look_r = vec3(look_r.x, look_r.y * cos(a) - sin(a) * look_r.z, look_r.y * sin(a) + look_r.z * cos(a));
}

void Cam::rotateCamera(float pitch, float yaw, float roll)
{
	this->pitchCam(pitch);
	this->yawCam(yaw);
	this->rollCam(roll);
}

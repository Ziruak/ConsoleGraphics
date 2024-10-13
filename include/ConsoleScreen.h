#pragma once
#ifndef ICONSOLE_H
#define ICONSOLE_H
#include<string>
#include"Vec2.h"

class IConsole {
	int _width, _height;

public:

	virtual int getWidth() { return _width; };
	virtual int getHeight() { return _height; };
	virtual void setScreen(std::string& buffer) = 0;
	virtual vec2 getScreenSize() { return vec2(_width, _height); };
	virtual float getAspect() { return _width / (float)_height; };
};

#endif // !ICONSOLE_H

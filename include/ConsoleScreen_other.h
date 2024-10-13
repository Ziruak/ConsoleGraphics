#pragma once
#ifndef CONSOLE_SCREEN_OTHER
#define CONSOLE_SCREEN_OTHER
#include "ConsoleScreen.h"
#include "Vec2.h"
#include <string>

class ConsoleScreen_other : IConsole
{
	int _width, _height;

public:
	ConsoleScreen_other(int width, int height);
    ~ConsoleScreen_other();
    int getWidth() { return _width; };
	int getHeight() { return _height; };
	vec2 getScreenSize() { return vec2(_width, _height); };
	void setScreen(std::string& buffer);
	float getAspect() { return _width / (float)_height; };
};

#endif // !CONSOLE_SCREEN_WIN32


#pragma once
#ifndef CONSOLE_SCREEN_CLASS
#include <Windows.h>
#include "Vec2.h";
#include <string>

class ConsoleScreen
{
	int _width, _height;
	HANDLE _handleConsole;
	void SetWindow(int width, int height);

public:
	ConsoleScreen(int width, int height) : _width(width), _height(height) { SetWindow(width, height);
	_handleConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(_handleConsole);
	};
	int getWidth() { return _width; };
	int getHeight() { return _height; };
	vec2 getScreenSize() { return vec2(_width, _height); };
	void setPixel(short x, short y, char sym);
	void setScreen(std::string& buffer);
	float getAspect() { return _width / (float)_height; };
};

#endif // !CONSOLE_SCREEN_CLASS


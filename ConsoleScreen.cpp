
#include "ConsoleScreen.h"

void ConsoleScreen::SetWindow(int Width, int Height)
{
	
		_COORD coord;
		coord.X = Width;
		coord.Y = Height;
		_SMALL_RECT Rect;
		Rect.Top = 0;
		Rect.Left = 0;
		Rect.Bottom = Height;
		Rect.Right = Width;
		HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferSize(Handle, coord);

		SetConsoleWindowInfo(Handle, TRUE, &Rect);
	
}

void ConsoleScreen::setPixel(short x, short y, char sym)
{
	wchar_t symbol[1] = { sym };
	DWORD dwBytesWritten;
	WriteConsoleOutputCharacter(_handleConsole, symbol, 1, { x, y }, &dwBytesWritten);
}

void ConsoleScreen::setScreen(std::string& buffer)
{
	if (buffer.size() == _width * _height) {
		size_t sizeofscreen = (_width * _height + 1);
		wchar_t* screen = new wchar_t[sizeofscreen];
		size_t charsConverted;
		mbstowcs_s(&charsConverted,screen, sizeofscreen, buffer.c_str(), _width* _height);
		DWORD dwBytesWritten;
		WriteConsoleOutputCharacter(_handleConsole, screen, _width*_height, {0, 0}, &dwBytesWritten);
	}
}

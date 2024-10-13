#include "ConsoleScreen_other.h"
#include <iostream>
#include <ncurses.h>

void ConsoleScreen_other::setScreen(std::string& buffer) {
	/*for (int i = 0; i < _height; ++i) {
		std::cout<<std::string(buffer.c_str() + i * _width).substr(_width)<<std::endl;
	}*/
    mvprintw(0,0,"%s",buffer.c_str());

    refresh();
}

ConsoleScreen_other::ConsoleScreen_other( int w, int h)  : _width(w), _height(h) {
    int y,x;
    initscr();
    cbreak();
    noecho();
    getmaxyx(stdscr, y, x);
    _height = y;
    _width = x;
}

ConsoleScreen_other::~ConsoleScreen_other()
{
    endwin();
}


/*vec2 ConsoleScreen_other::getScreenSize()
{
    int y,x;
    getmaxyx(stdscr,y,x);
    return vec2(x, y);
}*/

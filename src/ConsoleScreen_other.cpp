#include "ConsoleScreen_other.h"
#include <iostream>

void ConsoleScreen_other::setScreen(std::string& buffer) {
	for (int i = 0; i < _height; ++i) {
		std::cout<<std::string(buffer.c_str() + i * _width).substr(_width)<<std::endl;
	}
}
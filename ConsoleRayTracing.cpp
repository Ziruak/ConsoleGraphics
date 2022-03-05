#include <iostream>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "Cam.h"
#include "Sphere.h"
#include "VecFunctions.h"
#include "ConsoleScreen.h"
#include <conio.h>
#include <thread>

constexpr float p_aspect = 9.0f/15.0f;
const float camSpeed = 0.2f;

void inputProcess(Cam& cam, bool& running) {
	while (running) {
		char sym = _getch();
		if (sym == 'w') {
			cam.move(vec3(0,0,camSpeed));
		}
		else if (sym == 's') {
			cam.move(vec3(0, 0, -camSpeed));
		}
		else if (sym == 'd') {
			cam.move(vec3(0,camSpeed,0));
		}
		else if (sym == 'a') {
			cam.move(vec3(0,-camSpeed,0));
		}
		else if (sym == 'z') {
			cam.move(vec3(-camSpeed, 0, 0));
		}
		else if (sym == 'c') {
			cam.move(vec3(camSpeed, 0, 0));
		}
		else if (sym == 'i') {
			cam.pitchCam(90);
		}
		else if (sym == 'k') {
			cam.pitchCam(-90);
		}
		else if (sym == 'j') {
			cam.yawCam(-90);
		}
		else if (sym == 'l') {
			cam.yawCam(90);
		}
		else if (sym == 'q') {
			running = false;
		}
	}
}

int main() {
	ConsoleScreen screen(160, 40);
	float aspect = screen.getAspect(); // aspect for x value
	float pixelAspect = 9.0f / 15.0f;
	std::string gradient(" .:!/r(l1Z4H9W8$@");
	std::string screenBuff(screen.getHeight() * screen.getWidth(),gradient[0]);

	vec3 light = vec3(-1, 1, -1).norm();
	Cam camera(vec3(5, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 1), 0.9, screen.getScreenSize());
	Sphere sphere(0, 0, 0, 4);

	bool running = true;

	std::thread input_thread(inputProcess, std::ref(camera), std::ref(running));

	while (running) {
		for (int i = 0; i < screen.getWidth(); ++i) {
			for (int j = 0; j < screen.getHeight(); ++j) {
				if (i == screen.getWidth() / 2 && j == screen.getHeight() / 2) {
					int flag = 1;
				}
				vec3 rayd = camera.getPixelVec(i, j);
				vec3 campos = (camera.pos + (i - camera.screenSize.x / 2) * camera.look_r + (camera.screenSize.y / 2 - j) * camera.look_u);
				rayd.x *= pixelAspect * aspect;
				//rayd = rayd.norm();
				rayd = camera.look_f;
				vec3 n(0);
				vec2 t(0);
				if ((t = sphere.collisionsWithRay(campos, rayd)).x>0) {
					n = (campos + rayd * t.x - sphere._pos).norm();
				}
				float diff = (dot(n, light) * 0.5 + 0.5);

				int color = (int)(diff * 20)*(t.x>0);
				color = clamp(color, 0, gradient.size()-1);
				char pixel = gradient[color];
				screenBuff[i + j * screen.getWidth()] = pixel;
			}
		}
		screen.setScreen(screenBuff);
	}

	input_thread.join();
	return 0;
}
#include <iostream>
#include <math.h>
#include <string.h>
#include "Cam.h"
#include "Sphere.h"
#include "VecFunctions.h"
#ifdef _WIN32
#include "ConsoleScreen_win.h"
#define ConsoleScreen ConsoleScreen_win
#else
#include "ConsoleScreen_other.h"
#define ConsoleScreen ConsoleScreen_other
#endif // _WIN32



#include <conio.h> // WIN ONLY((
#include <thread>

constexpr float p_aspect = 9.0f/15.0f;
const float camSpeed = 0.2f;

void inputProcess(Cam& cam, bool& running) {
	while (running) {
		char sym = _getch();
		if (sym == 'w') {
			cam.moveUp(camSpeed);
		}
		else if (sym == 's') {
			cam.moveUp(-camSpeed);
		}
		else if (sym == 'd') {
			cam.moveRight(camSpeed);
		}
		else if (sym == 'a') {
			cam.moveRight(-camSpeed);
		}
		else if (sym == 'z') {
			cam.moveFoward(camSpeed);
		}
		else if (sym == 'c') {
			cam.moveFoward(-camSpeed);
		}
		else if (sym == 'i') {
			cam.pitchCam(10);
		}
		else if (sym == 'k') {
			cam.pitchCam(-10);
		}
		else if (sym == 'j') {
			cam.yawCam(10);
		}
		else if (sym == 'l') {
			cam.yawCam(-10);
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
	Cam camera(vec3(5, 0, 0), vec3(-1, 0, 0), vec3(0, 0, 1), 90.0f, screen.getScreenSize());
	Sphere sphere(0, 0, 0, 2);
	Sphere sphere2(0, 3, 1, 1.5f);

	bool running = true;

	std::thread input_thread(inputProcess, std::ref(camera), std::ref(running));

	while (running) {
		for (int i = 0; i < screen.getWidth(); ++i) {
			for (int j = 0; j < screen.getHeight(); ++j) {
				if (i == screen.getWidth() / 2 && j == screen.getHeight() / 2) {
					int flag = 1;
				}
				vec3 rayd = camera.getPixelVec(i, j);
				rayd.x *= aspect*pixelAspect;
				rayd = rayd.norm();
				vec3 n(0);
				vec2 tmin(0), tcur(0);
				if ((tmin = sphere.collisionsWithRay(camera.pos, rayd)).x>0) {
					n = (camera.pos + rayd * tmin.x - sphere._pos).norm();
				}
				if ((tcur = sphere2.collisionsWithRay(camera.pos, rayd)).x > 0 && (tcur.x < tmin.x || tmin.x <= 0)) {
					tmin = tcur;
					n = (camera.pos + rayd * tmin.x - sphere._pos).norm();
				}
				float diff = (dot(n, light) * 0.5 + 0.5);

				int color = (int)(diff * 20)*(tmin.x>0);
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
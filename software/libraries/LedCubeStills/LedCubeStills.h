#include "Arduino.h"

#ifndef LEDCUBESTILLS

#define LEDCUBESTILLS

class LedCubeStills {
	public:
		static void xyPlane(byte leds[8][8], int planeIndex);
		static void xzPlane(byte leds[8][8], int planeIndex);
		static void yzPlane(byte leds[8][8], int planeIndex);
		static void flood(byte leds[8][8]);
		static void randomLeds(byte leds[8][8], int n);
		static void wireFrame(byte leds[8][8]);
		static void clearAll(byte leds[8][8]);
		static void letter(byte leds[8][8], char letter, int planeIndex);
};

#endif
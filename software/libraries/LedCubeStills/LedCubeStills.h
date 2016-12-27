#include "Arduino.h"

#ifndef LEDCUBESTILLS

#define LEDCUBESTILLS

struct StaticLED {
  byte x;
  byte y;
  byte z;
};

class LedCubeStills {
	public:
    static void happyFace(byte leds[8][8], int planeIndex);
		static void xyPlane(byte leds[8][8], int planeIndex);
    static void xyPlaneOff(byte leds[8][8], int planeIndex);
		static void xzPlane(byte leds[8][8], int planeIndex);
    static void xzPlaneOff(byte leds[8][8], int planeIndex);
		static void yzPlane(byte leds[8][8], int planeIndex);
  	static void yzPlaneOff(byte leds[8][8], int planeIndex);
		static void flood(byte leds[8][8]);
		static void randomLeds(byte leds[8][8], int n);
		static void wireFrame(byte leds[8][8]);
		static void clearAll(byte leds[8][8]);
		static void letter(byte leds[8][8], char letter, int planeIndex);
		static void tanslateDown(byte leds[8][8]);
		static void on(byte leds[8][8], int x, int y, int z);
		static void off(byte leds[8][8], int x, int y, int z);
  private:
    static bool inBounds(int x, int y, int z);
};

#endif

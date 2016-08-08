#include "Arduino.h"
#include "LedCubeStills.h"

#ifndef LEDCUBESEQUENCES

#define LEDCUBESEQUENCES

struct FireworkStreamer {
	signed int xvel;
	signed int yvel;
	signed int zvel;
	int x;
	int y;
	int z;
};

struct LED { 
	float x;
	float y;
	float z;
	byte state;
};

class LedCubeSequences {
	public:
		static void sinWave(byte leds[8][8], int numCycles);
		static void randomUntilAllOn(byte leds[8][8], int numLedsPerRound);
		static void randomBursts(byte leds[8][8], int numLedsPerRound, int numRounds);
		static void launchFirework(byte leds[8][8]);
		static void lettersAcrossPlanes(byte leds[8][8], char* letters, int length);
		static void flash(byte leds[8][8], int delayLength, int numFlashes);
		static void rotate360(byte leds[8][8], LED ledList[100], int n);
	private:
		static bool inBounds(int x, int y, int z);
		static bool ledOn(byte leds[8][8], int x, int y, int z);
};

#endif
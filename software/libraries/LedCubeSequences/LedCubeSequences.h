#include "Arduino.h"
#include "LedCubeStills.h"

#ifndef LEDCUBESEQUENCES

#define LEDCUBESEQUENCES

struct MobileLED {
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
};

class LedCubeSequences {
	public:
		static void sinWave(byte leds[8][8], int numCycles);
    static void planarSinWave(byte leds[8][8]);
		static void randomUntilAllOn(byte leds[8][8]);
    static void randomUntilAllOff(byte leds[8][8]);
		static void randomBursts(byte leds[8][8], int numLedsPerRound, int numRounds);
		static void launchFirework(byte leds[8][8]);
		static void launchNFireworks(byte leds[8][8], int n);
		static void lettersAcrossPlanes(byte leds[8][8], char* letters, int length);
		static void flash(byte leds[8][8], int delayLength, int numFlashes);
		static void rotateCenterZ(byte leds[8][8], float radStep, int numSteps, int delayLength);
		static void rotateCenterZ(byte leds[8][8]);
		static void xy0Toxz0(byte leds[8][8]);
		static void crossingxzPlanes(byte leds[8][8]);
		static void rain(byte leds[8][8]);
		static void shiftAcrossFreezeContinue(byte leds[8][8], int xvel, int yvel, int zvel);
    static void miniCubeDance(byte leds[8][8]);
    static void rotatingSymbol(byte leds[8][8]);
    static void moveLeds(byte leds[8][8], int x, int y, int z);
	private:
		static bool inBounds(int x, int y, int z);
		static bool isLedOn(byte leds[8][8], int x, int y, int z);
		static int fillLedList(byte ledArray[8][8], LED ledList[128]);
		static int getNumLedsOn(byte leds[8][8]);
		static void initStreamers(MobileLED streams[24], int x, int y, int z);
};

#endif

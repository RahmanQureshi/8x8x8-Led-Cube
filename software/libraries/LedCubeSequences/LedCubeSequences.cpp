#include "LedCubeSequences.h"

// =====================================================================================================
// wave() 
// Description: Runs a wave in the y-axis for 5 wavelengths.
// Parameters:
//  wavelength - in inches (or the distance between LEDs)
// =====================================================================================================
void LedCubeSequences::sinWave(byte leds[8][8], int numCycles)
{
  int wavelength = 100;
  for(int t=0; t<wavelength*numCycles; t++)
  {
    for(int i=0; i<8; i++) 
    {
      int y = i;
      int z = 3.5*sin(2*3.14*t/wavelength + i)+3.5 + 0.5; // +0.5 for rounding
      leds[z][y] = 255;
    }
    delay(5);
    LedCubeStills::clearAll(leds);
  }
}

// =====================================================================================================
// launchFirework() 
// Description: Randomly chosen LED on the xy plane moves up z-axis and 'explodes' at top
// =====================================================================================================
void LedCubeSequences::launchFirework(byte leds[8][8])
{
  int x = random(3, 6);
  int y = random(3, 6);
  int z = 0;
  int radius = 1;
  int height = random(3, 8);
  // launch
  for(int i=0; i<height; i++)
  {
    z = i;
    leds[z][y] = 1 << x; 
    delay(80);
    leds[z][y] = 0;
  }
  // explode
  int numStreams = 24;
  FireworkStreamer streams[numStreams];
  for(int i=0; i<numStreams; i++)
  {
    streams[i].x = x;
    streams[i].y = y;
    streams[i].z = z;
  }
  streams[0].xvel = 1;
  streams[0].yvel = 1;
  streams[0].zvel = 1;

  streams[1].xvel = 1;
  streams[1].yvel = 1;
  streams[1].zvel = 0;

  streams[2].xvel = 1;
  streams[2].yvel = 1;
  streams[2].zvel = -1;

  streams[3].xvel = 1;
  streams[3].yvel = 0;
  streams[3].zvel = 1;

  streams[4].xvel = 1;
  streams[4].yvel = 0;
  streams[4].zvel = 0;

  streams[5].xvel = 1;
  streams[5].yvel = 0;
  streams[5].zvel = -1;

  streams[6].xvel = 0;
  streams[6].yvel = 1;
  streams[6].zvel = 1;

  streams[7].xvel = 0;
  streams[7].yvel = 1;
  streams[7].zvel = 0;

  streams[8].xvel = 0;
  streams[8].yvel = 1;
  streams[8].zvel = -1;

  streams[9].xvel = 0;
  streams[9].yvel = 0;
  streams[9].zvel = 1;

  streams[10].xvel = 0;
  streams[10].yvel = 0;
  streams[10].zvel = 0;

  streams[11].xvel = 0;
  streams[11].yvel = 0;
  streams[11].zvel = -1;

  streams[12].xvel = -1;
  streams[12].yvel = 1;
  streams[12].zvel = 1;

  streams[13].xvel = -1;
  streams[13].yvel = 1;
  streams[13].zvel = 0;

  streams[14].xvel = -1;
  streams[14].yvel = 1;
  streams[14].zvel = -1;

  streams[15].xvel = 1;
  streams[15].yvel = -1;
  streams[15].zvel = 1;

  streams[16].xvel = 1;
  streams[16].yvel = -1;
  streams[16].zvel = 0;

  streams[17].xvel = 1;
  streams[17].yvel = -1;
  streams[17].zvel = -1;

  streams[18].xvel = 0;
  streams[18].yvel = -1;
  streams[18].zvel = 1;

  streams[19].xvel = 0;
  streams[19].yvel = -1;
  streams[19].zvel = 0;

  streams[20].xvel = 0;
  streams[20].yvel = -1;
  streams[20].zvel = -1;

  streams[18].xvel = -1;
  streams[18].yvel = -1;
  streams[18].zvel = 1;

  streams[19].xvel = -1;
  streams[19].yvel = -1;
  streams[19].zvel = 0;

  streams[20].xvel = -1;
  streams[20].yvel = -1;
  streams[20].zvel = -1;

  streams[21].xvel = -1;
  streams[21].yvel = 0;
  streams[21].zvel = 1;

  streams[22].xvel = -1;
  streams[22].yvel = 0;
  streams[22].zvel = 0;

  streams[23].xvel = -1;
  streams[23].yvel = 0;
  streams[23].zvel = -1;

  for(int t=0; t<5; t++) { // 4 steps
    for(int i=0; i<numStreams; i++)
    {
      if(inBounds(streams[i].x, streams[i].y, streams[i].z))
      {
        leds[streams[i].z][streams[i].y] |= 1<<streams[i].x;
      }
      streams[i].x = streams[i].x + streams[i].xvel;
      streams[i].y = streams[i].y + streams[i].yvel;
      streams[i].z = streams[i].z + streams[i].zvel;
      streams[i].zvel = streams[i].zvel - 1;
    }
    delay(90);
  }
}

// =====================================================================================================
// randomUntilAllOn() 
// Description: Turns on numLedsPerRound each cycle until all LEDs are on
// =====================================================================================================
void LedCubeSequences::randomUntilAllOn(byte leds[8][8], int numLedsPerRound)
{
  for(int i=0; i < 3*512/numLedsPerRound; i++)
  {
    LedCubeStills::randomLeds(leds, numLedsPerRound);
    delay(100);
  }
  LedCubeStills::flood(leds);
}

// =====================================================================================================
// randomBurst() 
// Description: Turns on numLedsPerRound each cycle until all LEDs are on
// =====================================================================================================
void LedCubeSequences::randomBursts(byte leds[8][8], int numLedsPerRound, int numRounds)
{
  for(int i=0; i < numRounds; i++)
  {
    LedCubeStills::randomLeds(leds, numLedsPerRound);
    delay(200);
    LedCubeStills::clearAll(leds);
  }
}

// =====================================================================================================
// lettersAcrossPlanes
// Description:
// =====================================================================================================
void LedCubeSequences::lettersAcrossPlanes(byte leds[8][8], char* letters, int length)
{
  for(int i=0; i<length; i++)
  {
    for(int j=0; j<8; j++)
    {
      LedCubeStills::letter(leds, letters[i], 7-j);
      delay(100);
      LedCubeStills::clearAll(leds);
    }
  }
}

// =====================================================================================================
// flash()
// Description:
// =====================================================================================================
void LedCubeSequences::flash(byte leds[8][8], int delayLength, int numFlashes)
{
  for(int i=0; i<numFlashes; i++)
  {
    LedCubeStills::flood(leds);
    delay(delayLength);
    LedCubeStills::clearAll(leds);
    delay(delayLength);
  }
}

// =====================================================================================================
// rotate
// Description: rotates the current LED display about the center z-axis
// =====================================================================================================
void LedCubeSequences::rotate360(byte leds[8][8])
{
  LED ledList[512];
  // populate list of LEDs
  for(int z=0; z<8; z++)
  {
    for(int y=0; y<8; y++)
    {
      for(int x=0; x<8; x++)
      {
        ledList[z*64+y*8+x].x = x;
        ledList[z*64+y*8+x].y = y;
        ledList[z*64+y*8+x].z = z;
        if( (leds[z][y] & 1<<x) > 0)
        {
          ledList[z*64+y*8+x].state = 1;
        } else
        {
          ledList[z*64+y*8+x].state = 0;
        }
      }
    }
  }

  int degreesPerStep = 1;
  float cosDegrees = cos(degreesPerStep*2*3.14/360.0); // 1 degree increments
  float sinDegrees = sin(degreesPerStep*2*3.14/360.0);

  for(int i=0; i<360/degreesPerStep; i++)
  {
    // rotate LEDs
    for(int j=0; j<512; j++)
    {
      if(ledList[i].state == 1)
      {
        float x = ledList[i].x - 3.5;
        float y = ledList[i].y - 3.5;
        float z = ledList[i].z;

        ledList[i].x = cosDegrees*x - sinDegrees*y + 3.5;
        ledList[i].y = sinDegrees*x + cosDegrees*y + 3.5;
        ledList[i].z = z;
      }
    }

    LedCubeStills::clearAll(leds); // clear here so that some of the computation can be finished before turning LEDs off

    // display LEDs
    for(int j=0; j<512; j++)
    {
      int x = ledList[i].x + 0.5;
      int y = ledList[i].y + 0.5;
      int z = ledList[i].z + 0.5;
      if(ledList[i].state == 1 && inBounds(x, y, z))
      {
        leds[z][y] |= 1 << x;
      }
    }
    delay(100);
  }
}

bool LedCubeSequences::inBounds(int x, int y, int z)
{
  return (x >= 0 && x <= 7 
    && y >= 0 && y <= 7
    && z >= 0 && z <= 8);
}
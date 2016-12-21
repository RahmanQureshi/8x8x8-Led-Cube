#include "LedCubeSequences.h"

/* Private */

bool LedCubeSequences::isLedOn(byte leds[8][8], int x, int y, int z)
{
  return ( leds[z][y] & (1<<x) ) > 0;
}

int LedCubeSequences::getNumLedsOn(byte leds[8][8])
{
  int numLedsOn = 0;
  for(int z=0; z<8; z++)
  {
    for(int y=0; y<8; y++)
    {
      for(int x=0; x<8; x++)
      {
        if(isLedOn(leds, x, y, z)) numLedsOn++;
      }
    }
  }
  return numLedsOn;
}

bool LedCubeSequences::inBounds(int x, int y, int z)
{
  return (x >= 0 && x <= 7 
    && y >= 0 && y <= 7
    && z >= 0 && z <= 7);
}

int LedCubeSequences::fillLedList(byte ledArray[8][8], LED ledList[128])
{
  int i = 0;
  for(int z=0; z<8; z++)
  {
    for(int y=0; y<8; y++)
    {
      for(int x=0; x<8; x++) {
        if(isLedOn(ledArray, x, y, z))
        {
          ledList[i].x = x;
          ledList[i].y = y;
          ledList[i].z = z;
          i = i+1;
          if(i==128) return i;
        }
      }
    }
  }
  return i;
}

/* Public */

// =====================================================================================================
// moveLeds
// Description: moves all active LEDs in the cube by x, y and z 
// =====================================================================================================
void LedCubeSequences::moveLeds(byte leds[8][8], int x, int y, int z)
{
  int numLedsOn = getNumLedsOn(leds);
  LED ledList[numLedsOn];
  fillLedList(leds, ledList);
  LedCubeStills::clearAll(leds);
  for(int i=0; i<numLedsOn; i++)
  {
    ledList[i].x += x;
    ledList[i].y += y;
    ledList[i].z += z;
    LedCubeStills::on(leds, ledList[i].x, ledList[i].y, ledList[i].z);
  }
}

// =====================================================================================================
// miniCubeDance
// Description: Initializes a miniture 5x5x5 cube and moves it around
// =====================================================================================================
void LedCubeSequences::miniCubeDance(byte leds[8][8])
{
  LedCubeStills::clearAll(leds);
  //side
  LedCubeStills::on(leds, 0, 0, 0);
  LedCubeStills::on(leds, 1, 0, 0);
  LedCubeStills::on(leds, 2, 0, 0);
  LedCubeStills::on(leds, 3, 0, 0);
  LedCubeStills::on(leds, 4, 0, 0);
  //side
  LedCubeStills::on(leds, 4, 1, 0);
  LedCubeStills::on(leds, 4, 2, 0);
  LedCubeStills::on(leds, 4, 3, 0);
  LedCubeStills::on(leds, 4, 4, 0);
  //side
  LedCubeStills::on(leds, 3, 4, 0);
  LedCubeStills::on(leds, 2, 4, 0);
  LedCubeStills::on(leds, 1, 4, 0);
  LedCubeStills::on(leds, 0, 4, 0);
  //side
  LedCubeStills::on(leds, 0, 3, 0);
  LedCubeStills::on(leds, 0, 2, 0);
  LedCubeStills::on(leds, 0, 1, 0);

  //side
  LedCubeStills::on(leds, 0, 0, 4);
  LedCubeStills::on(leds, 1, 0, 4);
  LedCubeStills::on(leds, 2, 0, 4);
  LedCubeStills::on(leds, 3, 0, 4);
  LedCubeStills::on(leds, 4, 0, 4);
  //side
  LedCubeStills::on(leds, 4, 1, 4);
  LedCubeStills::on(leds, 4, 2, 4);
  LedCubeStills::on(leds, 4, 3, 4);
  LedCubeStills::on(leds, 4, 4, 4);
  //side
  LedCubeStills::on(leds, 3, 4, 4);
  LedCubeStills::on(leds, 2, 4, 4);
  LedCubeStills::on(leds, 1, 4, 4);
  LedCubeStills::on(leds, 0, 4, 4);
  //side
  LedCubeStills::on(leds, 0, 3, 4);
  LedCubeStills::on(leds, 0, 2, 4);
  LedCubeStills::on(leds, 0, 1, 4);

  //side
  LedCubeStills::on(leds, 0, 0, 1);
  LedCubeStills::on(leds, 0, 0, 2);
  LedCubeStills::on(leds, 0, 0, 3);
  //side
  LedCubeStills::on(leds, 4, 4, 1);
  LedCubeStills::on(leds, 4, 4, 2);
  LedCubeStills::on(leds, 4, 4, 3); 
  //side
  LedCubeStills::on(leds, 0, 4, 1);
  LedCubeStills::on(leds, 0, 4, 2);
  LedCubeStills::on(leds, 0, 4, 3);
  //side
  LedCubeStills::on(leds, 4, 0, 1);
  LedCubeStills::on(leds, 4, 0, 2);
  LedCubeStills::on(leds, 4, 0, 3);


  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }


  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 0, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, -1, 0); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, 0, 0); delay(50); }


  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 1, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, -1, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 1, 1, 0); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, 1); delay(50); }
  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, 0, 0, -1); delay(50); }

  for(int i=0; i<3; i++) { LedCubeSequences::moveLeds(leds, -1, -1, 0); delay(50); }


}
 
// =====================================================================================================
// shiftAcrossFreeze
// Description: Maximum of 64 LEDs should be on. Shifts LEDs by their velocity 8 times and gives 1/8 chance that the LED's
// velocities will be set to 0. Once all LEDs are stopped, will resume and all LEDs will continue to edge. 
// Note that this is meant to be used with a boundary plane and only one of the velocities 1 and the rest 0.
// =====================================================================================================
void LedCubeSequences::shiftAcrossFreezeContinue(byte leds[8][8], int xvel, int yvel, int zvel)
{
  int numLedsOn = getNumLedsOn(leds);
  MobileLED LEDs[numLedsOn];
  int i = 0;
  for(int z=0; z<8; z++)
  {
    for(int y=0; y<8; y++)
    {
      for(int x=0; x<8; x++)
      {
        if(isLedOn(leds, x, y, z))
        {
          LEDs[i].x = x;
          LEDs[i].y = y;
          LEDs[i].z = z;
          LEDs[i].xvel = xvel;
          LEDs[i].yvel = yvel;
          LEDs[i].zvel = zvel;
          i = i+1;
        }
      }
    }
  }
  // shift the LEDs according to their velocities 8 times. 1/8 chance that LED's velocities will be set to 0.
  for (int j=0; j<8; j++) 
  {
    for(i=0; i<numLedsOn; i++)
    {
      LedCubeStills::off(leds, LEDs[i].x, LEDs[i].y, LEDs[i].z);
      if(random(8) == 2 || random(8)==2 || !(inBounds(LEDs[i].x + xvel, LEDs[i].y + yvel, LEDs[i].z + zvel))) 
      {
        LEDs[i].xvel = 0;
        LEDs[i].yvel = 0;
        LEDs[i].zvel = 0;
      }
      LEDs[i].x = LEDs[i].x + LEDs[i].xvel;
      LEDs[i].y = LEDs[i].y + LEDs[i].yvel;
      LEDs[i].z = LEDs[i].z + LEDs[i].zvel; 
      LedCubeStills::on(leds, LEDs[i].x, LEDs[i].y, LEDs[i].z);
    }
    delay(25);
  }
  delay(500); // Pause for 2 seconds
  // shift LEDs all the way over. Maximum moves required is 8.
  for (int j=0; j<8; j++) 
  {
    for(i=0; i<numLedsOn; i++)
    {
      if (inBounds(LEDs[i].x + xvel, LEDs[i].y + yvel, LEDs[i].z + zvel))
      {
        LedCubeStills::off(leds, LEDs[i].x, LEDs[i].y, LEDs[i].z);
        LEDs[i].x = LEDs[i].x + xvel;
        LEDs[i].y = LEDs[i].y + yvel;
        LEDs[i].z = LEDs[i].z + zvel;
        LedCubeStills::on(leds, LEDs[i].x, LEDs[i].y, LEDs[i].z);
      }
    }
    delay(25);
  }
}

// =====================================================================================================
// rain()
// Description: Randomly tuns on LEDs and moves them downward
// =====================================================================================================
void LedCubeSequences::rain(byte leds[8][8])
{
  // randomly turn on one LED per column
  for(int x=0; x<8; x++) {
    for (int y=0; y<8; y++) {
      leds[random(0, 8)][y] |= 1 << x;
    }
  }

  int numLedsOn = getNumLedsOn(leds);
  LED ledList[numLedsOn];
  fillLedList(leds, ledList);
  
  for(int i=0; i<100; i++)
  {
    for(int j=0; j<numLedsOn; j++)
    {
      LedCubeStills::off(leds, ledList[j].x, ledList[j].y, ledList[j].z);
      if(ledList[j].z == 0) ledList[j].z = 7;
      else ledList[j].z = ledList[j].z-1;
      LedCubeStills::on(leds, ledList[j].x, ledList[j].y, ledList[j].z);
    }
    delay(75);
  }
}

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
// initStreamers() 
// Description: Initializes the velocities of the streams
// Parameters:
//  wavelength - in inches (or the distance between LEDs)
// =====================================================================================================
void LedCubeSequences::initStreamers(MobileLED streams[24], int x, int y, int z)
{
  for(int i=0; i<24; i++)
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
  MobileLED streams[numStreams];
  initStreamers(streams, x, y, z);

  for(int t=0; t<5; t++) { // 5 steps
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
// launchFirework() 
// Description: Randomly choses n LED on the xy plane moves up z-axis and 'explodes' at top
// Keep n below 5 to avoid using too much memory
// =====================================================================================================
void LedCubeSequences::launchNFireworks(byte leds[8][8], int n)
{
  int xvec[n];
  int yvec[n];
  int zvec[n];
  int rising[n]; // Is firework still rising?
  int heightvec[n];
  byte done = 0;
  MobileLED streams[n][24];

  for(int f=0; f<n; f++)
  {
    xvec[f] = random(1, 7);
    yvec[f] = random(1, 7);
    zvec[f] = 0;
    heightvec[f] = random(3, 8);
    rising[f] = 1;
    initStreamers(streams[f], xvec[f], yvec[f], heightvec[f]);
  }

  int count = 0;
  while(count<(7+5)) // upperbound with LED going to top of cube
  {
    count++;
    for(int f=0; f<n; f++)
    {
      if(rising[f]==1) // fireworks rising
      {
        leds[zvec[f]][yvec[f]] |= 1<<xvec[f];
        zvec[f]++;
        if(zvec[f]==heightvec[f]) rising[f] = 0;
      } else // exploding
      {
        for(int i=0; i<24; i++)
        {
          if(inBounds(streams[f][i].x, streams[f][i].y, streams[f][i].z))
          {
            leds[streams[f][i].z][streams[f][i].y] |= 1<<streams[f][i].x;
          }
          streams[f][i].x = streams[f][i].x + streams[f][i].xvel;
          streams[f][i].y = streams[f][i].y + streams[f][i].yvel;
          streams[f][i].z = streams[f][i].z + streams[f][i].zvel;
          streams[f][i].zvel = streams[f][i].zvel - 1;
        }
      }
    }
    delay(100);
  }
}

// =====================================================================================================
// randomUntilAllOn() 
// Description: Turns on numLedsPerRound each cycle until all LEDs are on
// =====================================================================================================
void LedCubeSequences::randomUntilAllOn(byte leds[8][8], int numLedsPerRound)
{
  byte randomizedLeds[512][3]; // Why the fuck is too much memory used if I do StaticlED[512]??? Each StaticLED is also 3 bytes ffs.
  // init and shuffle
  for(int x=0; x<8; x++)
  {
    for(int y=0; y<8; y++)
    {
      for(int z=0; z<8; z++)
      {
        randomizedLeds[64*x+8*y+z][0] = x;
        randomizedLeds[64*x+8*y+z][1] = y;
        randomizedLeds[64*x+8*y+z][2] = z; 
      }
    }
  }
  for(int i=0; i<512; i++)
  {
    int randomIndex = random(0, 512);
    byte xTemp = randomizedLeds[i][0];
    byte yTemp = randomizedLeds[i][1];
    byte zTemp = randomizedLeds[i][2];
    randomizedLeds[i][0] = randomizedLeds[randomIndex][0];
    randomizedLeds[i][1] = randomizedLeds[randomIndex][1];
    randomizedLeds[i][2] = randomizedLeds[randomIndex][2];
    randomizedLeds[randomIndex][0] = xTemp;
    randomizedLeds[randomIndex][1] = yTemp;
    randomizedLeds[randomIndex][2] = zTemp;
  }
  for(int i=0; i<512/numLedsPerRound; i++)
  {
    for(int j=0; j<numLedsPerRound; j++)
    {
      int ind = i*numLedsPerRound + j;
      LedCubeStills::on(leds, randomizedLeds[ind][0], randomizedLeds[ind][1], randomizedLeds[ind][2]);
    }
    delay(200);
  }
  LedCubeStills::flood(leds); // get last remaining LEDs
}

// =====================================================================================================
// randomBurst() 
// Description: Turns on numLedsPerRound each round 
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
      LedCubeStills::clearAll(leds);
      LedCubeStills::letter(leds, letters[i], 7-j);
      delay(100);
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
    delay(delayLength);
    LedCubeStills::clearAll(leds);
    delay(delayLength);
    LedCubeStills::flood(leds);
  }
}

// =====================================================================================================
// rotateCenterZ
// Description: This function rotates all LEDs one step counter-clockwise around z.
// =====================================================================================================
void LedCubeSequences::rotateCenterZ(byte leds[8][8])
{
  byte temp[8][8];
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      temp[i][j] = 0;
    }
  }

  for(int z=0; z<8; z++) 
  {
    for(int y=0; y<8; y++) 
    {
      for(int x=0; x<8; x++)
      {
        if(isLedOn(leds, x, y, z))
        {
          // Outer most Square
          if(x==0 && y<7)
          {
            temp[z][y+1] |= 1<<x;
          }
          if(y==7 && x<7)
          {
            temp[z][y] |= 1<<(x+1);
          }
          if(x==7 && y>0)
          {
            temp[z][y-1] |= 1<<x;
          }
          if(y==0 && x>0) 
          {
            temp[z][y] |= 1<<(x-1);
          }
          // Next layer
          if(x==1 && y>=1 && y<6)
          {
            temp[z][y+1] |= 1<<x;
          }
          if(y==6 && x>=1 && x<6)
          {
            temp[z][y] |= 1<<(x+1);
          }
          if(x==6 && y<=6 && y>1)
          {
            temp[z][y-1] |= 1<<x;
          }
          if(y==1 && x<=6 && x>1) 
          {
            temp[z][y] |= 1<<(x-1);
          }
          // Next layer
          if(x==2 && y>=2 && y<5)
          {
            temp[z][y+1] |= 1<<x;
          }
          if(y==5 && x>=2 && x<5)
          {
            temp[z][y] |= 1<<(x+1);
          }
          if(x==5 && y<=5 && y>2)
          {
            temp[z][y-1] |= 1<<x;
          }
          if(y==2 && x<=5 && x>2) 
          {
            temp[z][y] |= 1<<(x-1);
          }
          // Next layer
          if(x==3 && y>=3 && y<4)
          {
            temp[z][y+1] |= 1<<x;
          }
          if(y==4 && x>=3 && x<4)
          {
            temp[z][y] |= 1<<(x+1);
          }
          if(x==4 && y<=4 && y>3)
          {
            temp[z][y-1] |= 1<<x;
          }
          if(y==3 && x<=4 && x>3) 
          {
            temp[z][y] |= 1<<(x-1);
          }
        }
      }
    }
  }
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      leds[i][j] = temp[i][j];
    }
  }
}

// =====================================================================================================
// rotateCenterZ
// Description: rotates a maximum of 128 LEDs that are on in the current display.
// Be very careful. Requires a lot of memory for 128 LEDs!
// =====================================================================================================
void LedCubeSequences::rotateCenterZ(byte leds[8][8], float radStep, int numSteps, int delayLength)
{
  float pi = 3.141593;
  float cosVal = cos(radStep); // 1 degree increments
  float sinVal = sin(radStep);

  int numLedsOn = getNumLedsOn(leds);
  LED ledList[numLedsOn];
  fillLedList(leds, ledList);

  for(int d=0; d<numSteps; d++)
  {
    // rotate LEDs in LED list
    for(int i=0; i<numLedsOn; i++)
    {
      float xnew;
      float ynew;
      xnew = cosVal*(ledList[i].x - 3.5) - sinVal*(ledList[i].y - 3.5) + 3.5;
      ynew = sinVal*(ledList[i].x - 3.5) + cosVal*(ledList[i].y - 3.5) + 3.5;
      ledList[i].x = xnew;
      ledList[i].y = ynew;
    }
    LedCubeStills::clearAll(leds); // clear here so that some of the computation can be finished before turning LEDs off
    // display LEDs
    for(int i=0; i<numLedsOn; i++)
    {
      int x = ledList[i].x + 0.5;
      int y = ledList[i].y + 0.5;
      int z = ledList[i].z + 0.5;
      if(inBounds(x, y, z))
      {
        leds[z][y] |= 1 << x;
      }
    }
    delay(delayLength);
  }
}

void LedCubeSequences::crossingxzPlanes(byte leds[8][8])
{
  for(int i=0; i<4; i++)
  {
    delay(100);
    LedCubeStills::clearAll(leds);
    LedCubeStills::xzPlane(leds, i);
    LedCubeStills::xzPlane(leds, 7-i);
  }
  for(int i=0; i<3; i++)
  {
    delay(100);
    LedCubeStills::clearAll(leds);
    LedCubeStills::xzPlane(leds, 2-i);
    LedCubeStills::xzPlane(leds, 5+i);
  }
  delay(500);
}

void LedCubeSequences::xy0Toxz0(byte leds[8][8])
{
  for(int stop=8; stop>=0; stop--)
  {
    for(int y=0; y<8; y++)
    {
      int z = y;
      if (y<stop)
      {
        leds[z][0] = 0b00000000;
        leds[0][y] = 0b11111111;
      } else
      {
        leds[7-z][0] = 0b11111111;
        leds[0][y] = 0b00000000;
      }
    }
    delay(25);
  }
}

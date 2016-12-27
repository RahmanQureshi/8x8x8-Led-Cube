#include "LedCubeStills.h"

// private

bool LedCubeStills::inBounds(int x, int y, int z)
{
  return (x >= 0 && x <= 7 
    && y >= 0 && y <= 7
    && z >= 0 && z <= 7);
}

//public
// =====================================================================================================
// happyFace()
// Description: Draws on x plane
// =====================================================================================================

void LedCubeStills::happyFace(byte leds[8][8], int planeIndex)
{
  LedCubeStills::on(leds, planeIndex, 1, 6); // eyes
  LedCubeStills::on(leds, planeIndex, 1, 5);
  LedCubeStills::on(leds, planeIndex, 2, 6);
  LedCubeStills::on(leds, planeIndex, 2, 5);

  LedCubeStills::on(leds, planeIndex, 5, 5);
  LedCubeStills::on(leds, planeIndex, 5, 6);
  LedCubeStills::on(leds, planeIndex, 6, 5);
  LedCubeStills::on(leds, planeIndex, 6, 6);

  LedCubeStills::on(leds, planeIndex, 0, 2);
  LedCubeStills::on(leds, planeIndex, 1, 1);

  LedCubeStills::on(leds, planeIndex, 2, 0);
  LedCubeStills::on(leds, planeIndex, 3, 0);
  LedCubeStills::on(leds, planeIndex, 4, 0);
  LedCubeStills::on(leds, planeIndex, 5, 0);

  LedCubeStills::on(leds, planeIndex, 6, 1);
  LedCubeStills::on(leds, planeIndex, 7, 2);
} 

void LedCubeStills::on(byte leds[8][8], int x, int y, int z)
{
  if (inBounds(x, y, z)) leds[z][y] |= 1<<x;
}

void LedCubeStills::off(byte leds[8][8], int x, int y, int z)
{
  if (inBounds(x, y, z)) leds[z][y] &= ~(1<<x);
}

// =====================================================================================================
// horizontalPlane() 
// Description: Turns on the ith xy plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::xyPlane(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(i == planeIndex)
      {
        leds[i][j] |= 0b11111111;
      } else 
      {
        //leds[i][j] |= 0b00000000;
      }
    }
  }
}

// =====================================================================================================
// horizontalPlane() 
// Description: Turns on the ith xy plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::xyPlaneOff(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(i == planeIndex)
      {
        leds[i][j] = 0b00000000;
      }
    }
  }
}

// =====================================================================================================
// xzPlane() 
// Description: Turns on the ith xz plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::xzPlane(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(j == planeIndex) 
      {
        leds[i][j] |= 0b11111111;
      } else
      {
        //leds[i][j] |= 0b00000000;
      }
    }
  }
}

// =====================================================================================================
// xzPlane() 
// Description: Turns on the ith xz plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::xzPlaneOff(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(j == planeIndex) 
      {
        leds[i][j] = 0b00000000;
      } else
      {
        //leds[i][j] |= 0b00000000;
      }
    }
  }
}


// =====================================================================================================
// yzPlane() 
// Description: Turns on the ith yz plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::yzPlane(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      leds[i][j] |= 1 << planeIndex;
    }
  }
}

// =====================================================================================================
// yzPlane() 
// Description: Turns on the ith yz plane.
// Parameters:
//  i - integer {0..7} - plane index starting from the bottom to the top
// =====================================================================================================
void LedCubeStills::yzPlaneOff(byte leds[8][8], int planeIndex)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      LedCubeStills::off(leds, planeIndex, j, i);
    }
  }
}


// =====================================================================================================
// flood() 
// Description: Turns on every LED
// =====================================================================================================
void LedCubeStills::flood(byte leds[8][8])
{
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      leds[i][j] = 255;
    }
  }
}

void LedCubeStills::wireFrame(byte leds[8][8])
{
  for(int z=0; z<8; z++)
  {
    for(int y=0; y<8; y=y+7)
    {
      leds[z][y] |= 1<<0;
      leds[z][y] |= 1<<7;
    }
  }
  for(int y=0; y<8; y++)
  {
    for(int x=0; x<8; x=x+7)
    {
      leds[0][y] |= 1<<x;
      leds[7][y] |= 1<<x;
    }
  }
  for(int x=0; x<8; x++)
  {
    for(int y=0; y<8; y=y+7)
    {
      leds[0][y] |= 1<<x;
      leds[7][y] |= 1<<x; 
    }
  }
}


// =====================================================================================================
// random() 
// Description: Turns on 'n' random LEDs
// =====================================================================================================
void LedCubeStills::randomLeds(byte leds[8][8], int n)
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
  for(int i=0; i<n; i++)
  {
    LedCubeStills::on(leds, randomizedLeds[i][0], randomizedLeds[i][1], randomizedLeds[i][2]);
  }
}


// =====================================================================================================
// clearLEDs() 
// Description: Turns off every LED.
// =====================================================================================================
void LedCubeStills::clearAll(byte leds[8][8])
{
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      leds[i][j] = 0;
    }
  }
}

void LedCubeStills::letter(byte leds[8][8], char letter, int planeIndex)
{
  switch(letter)
  {
    case ' ': // Turn plane off
      for(int z=0; z<8; z++)
      {
        for(int y=0; y<8; y++)
        {
          LedCubeStills::off(leds, planeIndex, y, z);
        }
      }
    case 'A':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;

      break;

    case 'B':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;

      break;

    case 'C':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      break;

    case 'D':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;

      break;

    case 'E':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;


      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;

      break;

    case 'F':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;


      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;

      break;

    case 'G':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      break;

    case 'H':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;


      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;

      break;

    case 'I':
      leds[0][3] |= 1 << planeIndex;
      leds[1][3] |= 1 << planeIndex;
      leds[2][3] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;
      leds[5][3] |= 1 << planeIndex;
      leds[6][3] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;

      leds[0][4] |= 1 << planeIndex;
      leds[1][4] |= 1 << planeIndex;
      leds[2][4] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;
      leds[5][4] |= 1 << planeIndex;
      leds[6][4] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;

      leds[7][1] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[0][1] |= 1 << planeIndex;
      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      break;

    case 'L':

      leds[0][2] |= 1 << planeIndex;
      leds[1][2] |= 1 << planeIndex;
      leds[2][2] |= 1 << planeIndex;
      leds[3][2] |= 1 << planeIndex;
      leds[4][2] |= 1 << planeIndex;
      leds[5][2] |= 1 << planeIndex;
      leds[6][2] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      break;

    case 'O':
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;

      break;

    case 'P':
      leds[0][2] |= 1 << planeIndex;
      leds[1][2] |= 1 << planeIndex;
      leds[2][2] |= 1 << planeIndex;
      leds[3][2] |= 1 << planeIndex;
      leds[4][2] |= 1 << planeIndex;
      leds[5][2] |= 1 << planeIndex;
      leds[6][2] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;      

      leds[6][5] |= 1 << planeIndex;
      leds[5][5] |= 1 << planeIndex;
      leds[4][5] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
 
      break;

    case 'R':
      leds[0][2] |= 1 << planeIndex;
      leds[1][2] |= 1 << planeIndex;
      leds[2][2] |= 1 << planeIndex;
      leds[3][2] |= 1 << planeIndex;
      leds[4][2] |= 1 << planeIndex;
      leds[5][2] |= 1 << planeIndex;
      leds[6][2] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;

      leds[0][7] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][5] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;
      leds[4][5] |= 1 << planeIndex;
      leds[5][5] |= 1 << planeIndex;
      leds[6][5] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;

      leds[3][2] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[3][5] |= 1 << planeIndex;

      break;

    case 'T':
      leds[0][3] |= 1 << planeIndex;
      leds[1][3] |= 1 << planeIndex;
      leds[2][3] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;
      leds[5][3] |= 1 << planeIndex;
      leds[6][3] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;

      leds[0][4] |= 1 << planeIndex;
      leds[1][4] |= 1 << planeIndex;
      leds[2][4] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;
      leds[5][4] |= 1 << planeIndex;
      leds[6][4] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;

      leds[7][1] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      break;

    case 'Y':
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[1][3] |= 1 << planeIndex;
      leds[1][4] |= 1 << planeIndex;
      leds[2][3] |= 1 << planeIndex;
      leds[2][4] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;

      leds[7][0] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[5][2] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;

      leds[7][7] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[5][5] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;

      break;
    
    case '0': // same as 'O'
      leds[0][1] |= 1 << planeIndex;
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[0][6] |= 1 << planeIndex;
      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;
      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[0][2] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][6] |= 1 << planeIndex;      
      break;

    case '1':
      leds[0][3] |= 1 << planeIndex;
      leds[1][3] |= 1 << planeIndex;
      leds[2][3] |= 1 << planeIndex;
      leds[3][3] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;
      leds[5][3] |= 1 << planeIndex;
      leds[6][3] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;

      leds[0][4] |= 1 << planeIndex;
      leds[1][4] |= 1 << planeIndex;
      leds[2][4] |= 1 << planeIndex;
      leds[3][4] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;
      leds[5][4] |= 1 << planeIndex;
      leds[6][4] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex; 
      break;

    case '2':
      leds[0][6] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][2] |= 1 << planeIndex;
      leds[0][1] |= 1 << planeIndex;
  
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;

      leds[4][2] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;
      leds[4][5] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;

      leds[5][6] |= 1 << planeIndex;
      leds[6][6] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      leds[7][5] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][2] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;
      break;

    case '6':
      leds[0][6] |= 1 << planeIndex;
      leds[0][5] |= 1 << planeIndex;
      leds[0][4] |= 1 << planeIndex;
      leds[0][3] |= 1 << planeIndex;
      leds[0][2] |= 1 << planeIndex;
      leds[0][1] |= 1 << planeIndex;
      
      leds[1][1] |= 1 << planeIndex;
      leds[2][1] |= 1 << planeIndex;
      leds[3][1] |= 1 << planeIndex;
      leds[4][1] |= 1 << planeIndex;
      leds[5][1] |= 1 << planeIndex;
      leds[6][1] |= 1 << planeIndex;
      leds[7][1] |= 1 << planeIndex;

      leds[1][6] |= 1 << planeIndex;
      leds[2][6] |= 1 << planeIndex;
      leds[3][6] |= 1 << planeIndex;
      leds[4][6] |= 1 << planeIndex;

      leds[4][2] |= 1 << planeIndex;
      leds[4][3] |= 1 << planeIndex;
      leds[4][4] |= 1 << planeIndex;
      leds[4][5] |= 1 << planeIndex;

      leds[7][2] |= 1 << planeIndex;
      leds[7][3] |= 1 << planeIndex;
      leds[7][4] |= 1 << planeIndex;
      leds[7][5] |= 1 << planeIndex;
      leds[7][6] |= 1 << planeIndex;

      break;

  };
}

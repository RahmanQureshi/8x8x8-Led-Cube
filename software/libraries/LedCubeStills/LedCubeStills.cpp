#include "LedCubeStills.h"

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
        leds[i][j] |= 0b00000000;
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
        leds[i][j] |= 0b00000000;
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
  for(int i = 0; i<n; i++)
  {
    int x = random(0, 8);
    int y = random(0, 8);
    int z = random(0, 8);
    leds[z][y] |= 1 << x;
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

  };
}
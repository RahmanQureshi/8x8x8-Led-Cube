#include <SPI.h>
#include <LedCubeStills.h>
#include <LedCubeSequences.h>

int clockPin = 13;
int dataPin = 11;
int latchEnablePin = 8;
int outputEnablePin = 10;

byte leds[8][8]; // [z],[y], 1<<x
int activeLayerIndex = 0;


void setup() 
{

  Serial.begin(9600);

  // Timer 2 Initialization for 125uS interrupt. 
  cli(); // Disable global interrupts
  TCCR2B = 0;
  TCCR2A = 0;
  TCNT2= 0; //  Set counter to 0;
  OCR2A = 250; // Output Compare Register set to 250
  TCCR2B |= 1 << CS21; // Set prescaler for 2MHz (16MHz/8). Error in documentation: not CA21.
  TCCR2A |= 1 << WGM21; // CTC Mode
  TIMSK2 |= 1 << OCIE1A; // Compare match A interrupt mask
  sei(); // Global interrupt enable (SREG[7] = 1)
  // Timer 2 Initialization End

  // SPI Initialization
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0)); // We never call endTransaction
  SPI.begin();
  // SPI Initialization end
  
  // Cube Initialization 
  pinMode(latchEnablePin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
  digitalWrite(outputEnablePin, LOW);
  // Cube Initialization End
  digitalWrite(latchEnablePin, LOW);
  LedCubeStills::clearAll(leds);
  // Cube Initialization End
}

void loop()
{
  
  LedCubeStills::clearAll(leds);
  LedCubeSequences::lettersAcrossPlanes(leds, "HELLO", 5);

  LedCubeStills::clearAll(leds);
  for(int i=0; i<3; i++)
  {
    LedCubeStills::clearAll(leds);
    LedCubeSequences::launchNFireworks(leds, 2);
  }
  LedCubeStills::clearAll(leds);
  LedCubeSequences::crossingxzPlanes(leds);

  for(int i=0; i<8; i++)
  {
    LedCubeStills::clearAll(leds);
    LedCubeStills::xyPlane(leds, i%8);
    LedCubeStills::xzPlane(leds, i%8);
    delay(100);
  }

  for(int i=0; i<8; i++)
  {
    LedCubeStills::clearAll(leds);
    LedCubeStills::xzPlane(leds, i%8);
    LedCubeStills::yzPlane(leds, i%8);
    delay(100);
  }
  
  for(int i=0; i<8; i++)
  {
    LedCubeStills::clearAll(leds);
    LedCubeStills::yzPlane(leds, i%8);
    LedCubeStills::xyPlane(leds, (7-i)%8);
    delay(100);
  }

  LedCubeStills::clearAll(leds);
  LedCubeSequences::xy0Toxz0(leds);
  
  for(int i=0; i<28; i++)
  {
    delay(100);
    LedCubeSequences::rotateCenterZ(leds);
  }

  LedCubeStills::clearAll(leds);
  LedCubeSequences::sinWave(leds, 10);

  LedCubeStills::clearAll(leds);
  LedCubeSequences::randomUntilAllOn(leds, 10);

  LedCubeStills::clearAll(leds);
  LedCubeSequences::flash(leds, 500, 5);
  
  LedCubeSequences::randomBursts(leds, 350, 10);
}

ISR(TIMER2_COMPA_vect) 
{
  digitalWrite(latchEnablePin, LOW);
  SPI.transfer(leds[activeLayerIndex][7]);
  SPI.transfer(leds[activeLayerIndex][6]);
  SPI.transfer(leds[activeLayerIndex][5]);
  SPI.transfer(leds[activeLayerIndex][4]);
  SPI.transfer(leds[activeLayerIndex][3]);
  SPI.transfer(leds[activeLayerIndex][2]);
  SPI.transfer(leds[activeLayerIndex][1]);
  SPI.transfer(leds[activeLayerIndex][0]);
  SPI.transfer(~((byte)1<<activeLayerIndex));
  activeLayerIndex = (activeLayerIndex+1)%8;
  digitalWrite(latchEnablePin, HIGH);
}

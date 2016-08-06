#include <SPI.h>
#include <LedCubeStills.h>
#include <LedCubeSequences.h>

int clockPin = 13;
int dataPin = 11;
int latchEnablePin = 8;
int outputEnablePin = 10;

byte leds[8][8]; // [z],[y],1<<x
int activeLayerIndex = 0;


void setup() 
{ 
  Serial.begin(9600);
  
  // SPI Initialization
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0)); // We never call endTransaction
  SPI.begin();
  // SPI Initialization end
  
  // Cube Initialization 
  pinMode(latchEnablePin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
  digitalWrite(outputEnablePin, LOW);
  digitalWrite(latchEnablePin, LOW);
  // Cube Initialization End
}

void loop()
{
  digitalWrite(latchEnablePin, LOW);
  SPI.transfer(255); // U8
  SPI.transfer(255); // U7
  SPI.transfer(255); // U6
  SPI.transfer(255); // U5
  SPI.transfer(255); // U4
  SPI.transfer(255); // U3
  SPI.transfer(255); // U2
  SPI.transfer(255); // U1
  SPI.transfer(0); // SN74HC595N
  activeLayerIndex = (activeLayerIndex+1)%8;
  digitalWrite(latchEnablePin, HIGH);
}


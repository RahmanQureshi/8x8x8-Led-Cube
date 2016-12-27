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
  // Cube Initialization End
  
  LedCubeSequences::lettersAcrossPlanes(leds, "PEY2016", 7);
}

void loop()
{
  // Random Bursts
  LedCubeSequences::randomBursts(leds, 125, 10, 350);
  LedCubeSequences::randomBursts(leds, 125, 10, 300);
  LedCubeSequences::randomBursts(leds, 125, 10, 250);
  LedCubeSequences::randomBursts(leds, 125, 10, 200);
  LedCubeSequences::randomBursts(leds, 125, 20, 100);
  
  // Random Until All On
  LedCubeSequences::randomUntilAllOn(leds);
  LedCubeSequences::randomUntilAllOff(leds);
  LedCubeSequences::randomUntilAllOn(leds);
  LedCubeSequences::randomUntilAllOff(leds);
  LedCubeSequences::randomUntilAllOn(leds);
  LedCubeSequences::randomUntilAllOff(leds);
  LedCubeSequences::randomUntilAllOn(leds);
  LedCubeSequences::randomUntilAllOff(leds);
  LedCubeSequences::randomUntilAllOn(leds);
  LedCubeSequences::randomUntilAllOff(leds);
  LedCubeSequences::randomUntilAllOn(leds);

  // Flashing
  for(int i=400; i>50; i=i-25)
  {
    LedCubeSequences::flash(leds, i, 1);
  }
  LedCubeSequences::flash(leds, 50, 40);
  delay(2000);
 
   // Rain
  LedCubeStills::clearAll(leds);
  LedCubeSequences::rain(leds);
  
  LedCubeStills::clearAll(leds);
  delay(1000);
  LedCubeSequences::shiftingCrystal(leds, 35);  
  
  //ShiftAcrossFreeze
  LedCubeStills::clearAll(leds);
  LedCubeStills::xyPlane(leds, 7);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 0, -1);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 0, 1);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 0, -1);
  delay(500);
  LedCubeSequences::xy0Toxz0(leds);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 1, 0); // To xz7
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, -1, 0);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 1, 0);
  delay(500);
  for(int i=0; i<(7*17); i++) { delay(25); LedCubeSequences::rotateCenterZ(leds); } 
  delay(1000);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, -1, 0, 0); 
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 1, 0, 0); 
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, -1, 0, 0); 
  delay(1000);
  for(int i=0; i<(7*17); i++) { delay(25); LedCubeSequences::rotateCenterZ(leds); } 
  delay(1000);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, -1, 0);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, 1, 0);
  delay(500);
  LedCubeSequences::shiftAcrossFreezeContinue(leds, 0, -1, 0);
  delay(1000);
  
  LedCubeStills::clearAll(leds);
  LedCubeSequences::rotatingSymbol(leds);
 
  LedCubeStills::clearAll(leds);
  LedCubeSequences::planarSinWave(leds, 30);
  
  LedCubeStills::clearAll(leds);
  LedCubeSequences::sinWave(leds, 30);
  
  LedCubeStills::clearAll(leds);
  delay(1000);
  LedCubeSequences::planeDance1(leds);
  LedCubeSequences::planeDance2(leds);
  LedCubeSequences::planeDance3(leds);
  delay(500);
  LedCubeSequences::miniCubeDance(leds);
  LedCubeSequences::miniCubeDance(leds);
  
  // Fireworks
  for(int i=0; i<10; i++) {
    LedCubeStills::clearAll(leds);
    LedCubeSequences::launchNFireworks(leds, random(1, 4));
    delay(200);
  }

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

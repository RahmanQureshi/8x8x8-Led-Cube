#include <SPI.h>

int clockPin = 13;
int dataPin = 11;
int latchEnablePin = 8;
int outputEnablePin = 10;

void setup() {
  // SPI Initialization
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0)); // We never call endTransaction
  SPI.begin();
  // SPI Initialization end
  
  pinMode(latchEnablePin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
  digitalWrite(outputEnablePin, LOW);
  digitalWrite(latchEnablePin, LOW);

  digitalWrite(latchEnablePin, LOW);
  SPI.transfer(255); // 1 to LED sink port 0
  SPI.transfer(0); //0 to first PMOS
  digitalWrite(latchEnablePin, HIGH);
}

void loop() {
}

#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int dataPin, int clockPin, int latchEnablePin, int outputEnablePin, int numBytes)
{
	this->dataPin = dataPin;
	this->clockPin = clockPin;
	this->latchEnablePin = latchEnablePin;
	this->outputEnablePin = outputEnablePin;
	this->numBytes = numBytes;
	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(latchEnablePin, OUTPUT);
	pinMode(outputEnablePin, OUTPUT);

	digitalWrite(latchEnablePin, LOW);
	digitalWrite(outputEnablePin, LOW);
}

void ShiftRegister::shift()
{
	digitalWrite(latchEnablePin, LOW);
	for (int i = numBytes-1; i >= 0; i--) 
	{
		shiftOut(dataPin, clockPin, MSBFIRST, bits[i]); // Found that this was far too slow
	}
	digitalWrite(latchEnablePin, HIGH);
}

void ShiftRegister::spiTransfer()
{
	SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
	digitalWrite(latchEnablePin, LOW);
	for (int i = numBytes-1; i >= 0; i--) 
	{
		SPI.transfer(bits[i]);
	}
	digitalWrite(latchEnablePin, HIGH);
	SPI.endTransaction();
}

void ShiftRegister::setByte(int ithByte, byte data)
{
	bits[ithByte] = data;
}

byte ShiftRegister::getByte(int ithByte)
{
	return bits[ithByte];
}
#include "Arduino.h"
#include "SPI.h"

#define MAX_NUM_BYTES 10

class ShiftRegister {
		volatile byte bits [MAX_NUM_BYTES];
		int dataPin;
		int clockPin;
		int latchEnablePin;
		int outputEnablePin;
		int numBytes;
	public:
		ShiftRegister(int dataPin, int clockPin, int latchEnablePin, int outputEnablePin, int numBytes); 
		void shift(); // Found that shiftOut was far too slow to use effectively with interrupts
		void spiTransfer(); // requires dataPin and clockPin must correspond to SPI pins on device
		void setByte(int ithByte, byte data);
		byte getByte(int ithByte);
};
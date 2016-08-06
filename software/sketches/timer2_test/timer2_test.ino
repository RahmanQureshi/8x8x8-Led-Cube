void setup() {

  Serial.begin(115200);

  cli(); // Disable global interrupts
  TCCR2B = 0;
  TCCR2A = 0;
  TCNT2= 0; //  Set counter to 0;
  OCR2A = 250; // 250 * 1/(16MHz/8) = delay = 125uS
  TCCR2B |= 1 << CS21; // Set prescaler to divide clock by 8.
  TCCR2A |= 1 << WGM21; // CTC Mode.
  TIMSK2 |= 1 << OCIE1A; // Compare match A interrupt mask
  sei(); // Global interrupt enable (SREG[7] = 1)

  pinMode(13, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

ISR(TIMER2_COMPA_vect) {
  Serial.println("Interrupt");
  TIFR2 |= 1 << 1; // Clear Match A flag by writing a 1. This is because another interrupt will have occurred because Serial.println takes so long.
  TCNT2 = 0; // Set timer to 0. Technically not necessary for the LED to blink.
}


void setup() {

  Serial.begin(9600);

  cli(); // Disable global interrupts
  TCCR1B = 0;
  TCCR1A = 0;
  TCNT1= 0; //  Set counter to 0;
  OCR1A = 60000; // 60000 * 1/(16MHz/1024) = delay = 4s
  TCCR1B |= 1 << CS12; // Set prescaler to divide clock by 1024.
  TCCR1B |= 1 << CS10;
  TCCR1A |= 1 << WGM12; // CTC Mode. For Timer 2, WGM21.
  TIMSK1 |= 1 << OCIE1A; // Compare match A interrupt mask
  sei(); // Global interrupt enable (SREG[7] = 1)

}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  delay(1000);
}

ISR(TIMER1_COMPA_vect) {
  Serial.println("Interrupt");
}


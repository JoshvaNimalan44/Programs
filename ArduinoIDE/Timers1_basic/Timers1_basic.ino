int value = 34285; // Variable to set the interval

void setup()
 {
  pinMode(13, OUTPUT); 
  TCCR1A = 0; // Clear Timer/Counter Control Register A
  TCCR1B = 0; // Clear Timer/Counter Control Register B
  TCNT1 = value; // Set initial value of Timer/Counter 1 to 'value'

  TCCR1B |= (1 << CS10) | (1 << CS12); // Set prescaler to 1024
}

void loop()
 {
  if ((TIFR1 & (1 << TOV1)) != 0)  // Check if Timer/Counter1 Overflow Flag is set
   { 
    TIFR1 |= (1 << TOV1);  // Clear Timer/Counter1 Overflow Flag
    TCNT1 = value;  // Reset Timer/Counter1 to 'value'

   
    if (digitalRead(13) == 1) {
      digitalWrite(13, 0); 
    } else {
      digitalWrite(13, 1); 
    }
  }
}

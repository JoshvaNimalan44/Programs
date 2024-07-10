
int value = 49910;

void setup()

{

  DDRB |= (1 << DDB5);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = value;

  TCCR1B |= (1 << CS10) | (1 << CS12);
}

void loop()

{
  static int count = 0;
  if ((TIFR1 & (1 << TOV1)) != 0) 
  {
    count++;
    TIFR1 |= (1 << TOV1);
    TCNT1 = value;
  }

  if (count >0 && count <=3) 
  {
    PORTB |= 1 << PORTB5;
  }
   else if(count >3 && count <= 5)
   {
    PORTB &= ~(1 << PORTB5);
  }
  else if(count == 6)
  {
    count = 0;
  }
}
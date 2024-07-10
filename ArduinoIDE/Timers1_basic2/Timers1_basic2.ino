
int value = 3039;                   

void setup()

{

   DDRB |= (1 << DDB5);


  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = value;             

  TCCR1B |= (1 << CS10)|(1 << CS12);  

}

void loop()

{

   if ((TIFR1 & (1 << TOV1)) != 0)
   {
        TIFR1 |= (1 << TOV1);
        TCNT1 = value;
        if (PINB & (1 << PINB5))
         {
            PORTB &= ~(1 << PORTB5);
        } 
        else
         {
             PORTB |= 1 << PORTB5;
        }
    }
}
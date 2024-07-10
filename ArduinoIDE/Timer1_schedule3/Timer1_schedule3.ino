



const int task1 = 2; 
const int task2 = 6;  
const int task3 = 15;  

int Task1_MS = 0;
int Task2_MS = 0;
int Task3_MS = 0;

int main() 
{
  DDRB |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = 250;
  interrupts();
}


ISR(TIMER1_COMPA_vect) {
  OCR1A += 250;
  Task1_MS++;
  Task2_MS++;
  Task3_MS++;
 
  if (Task1_MS >= task1)
  {
    PORTB ^= (1 << 5);
    Task1_MS=0;
  }
  
  
  if (Task2_MS >= task2)
   {
    PORTB ^= (1 << 4);
    Task2_MS=0;
  }
  
 
  if (Task3_MS >= task3)
   {
    PORTB ^= (1 << 3);
    Task3_MS=0;
  }
}




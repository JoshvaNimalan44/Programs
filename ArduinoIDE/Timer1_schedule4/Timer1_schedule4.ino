//Timer interrupt Scheduler 

typedef struct
{
  int userMS;
  void (*fptr) (void);
  int value;

} Schedule;

#define TASKS {2,&Task1,0}, \
              {2,&Task2,0}, \
              {5,&Task3,0}
              
Schedule data[] = {TASKS};


ISR(TIMER1_COMPA_vect) 
{
  OCR1A += 250;
  TIFR1 |= (1 << OCF1A);
  int size = sizeof(data) / sizeof(data[0]);
  for (int i = 0; i < size;i++) 
  {
    if (data[i].value >= data[i].userMS)
     {
      data[i].fptr();
      data[i].value = 0; 
    }
    data[i].value++;
  }
 
}

void setup() 
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


void Task1()
 {
  PORTB ^= (1 << 5);
}

void Task2()
 {
  PORTB ^= (1 << 4);
}

void Task3() 
{
  PORTB ^= (1 << 3);
}

void loop() 
{
}



//Timer interrupt Scheduler 4


//64 - 250000


#define TASKS {2,&Task1,0}, \
              {5,&Task2,0}, \
              {10,&Task3,0}

#define STATES {&Task4},\
               {&Task5}


typedef struct
{
  int userMS;
  void (*fptr) (void);
  int value;
} Schedule;

typedef struct
{
  void (*st_ptr) (void);
}state;

Schedule data1[] = {TASKS};

state data2[] = {STATES};


ISR(TIMER1_COMPA_vect) {
  
  OCR1A += 250;
  TIFR1 |= (1 << OCF1A);
  int size = sizeof(data1) / sizeof(data1[0]);
  for (int i = 0; i < size;i++) 
  {
    if (data1[i].value >= data1[i].userMS)
     {
      data1[i].fptr();
      data1[i].value = 0; 
    }
    data1[i].value++;
  }
 
}

void setup() {
  DDRB |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3) | (1 << DDB2) | (1 << DDB1);

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

void Task4()
 {
  PORTB ^= (1 << 2);
}

void Task5()
 {
  PORTB ^= (1 << 1);
}

void loop() 
{

  int size = sizeof(data2) / sizeof(data2[0]);
  for (int i = 0; i < size;i++) 
  {
      data2[i].st_ptr();
      delay(50);
      PORTB &= ~((1 << 1) | (1 << 2));
  }
}



void  setup()
 {
   //connect pin 2-9 to the 8 R2R inputs
  //pin 9 as the input nearest to the output wire of the R2R
  //set pin 2-7 as output, 1 as output (serial communication to pc), 0 as input (serial communication from pc to board)
  DDRD = DDRD | B11111110;
  
  //set pin 8-9 as outout
  DDRB = DDRB | B00000011;

  pinMode(A0, INPUT);

  Serial.begin(9600);
  } 
  
  //try this first
  void loop()
  {
    Serial.println(analogRead(A0)/4);
 
    DAC(250);
    delay(1000);


 
  }
  
 void DAC (int desired_analog)
{
  PORTD = B00000010 | desired_analog << 2;
  PORTB = desired_analog >> 6;  
}

/*
int sensorPin = A0;
int ledPin = 3;
int ledPin2 = 5;
int sensorValue = 0;
*/
/*
const int motorPin1  = 3;  // Pin 14 of L293
const int motorPin2  = 5;  // Pin 10 of L293
bool toggler = false;
*/

/*
void setup()
{
  /*
    //setup timers for interrupts
    cli();//stop interrupts
    //Timer 0 - Read Light Intensity Sensor music notes, Read Light Intensity Sensor line following, Read Encoder
    
    //set timer0 interrupt at 1kHz
    TCCR0A = 0;// set entire TCCR0A register to 0
    TCCR0B = 0;// same for TCCR0B
    TCNT0  = 0;//initialize counter value to 0
    // set compare match register for 1khz increments
    OCR0A = 62; // = (16*10^6) / (1000*256) - 1 (must be <256)
    // turn on CTC mode
    TCCR0A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR0B |= (1 << CS01) | (1 << CS00);   
    // enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);
    */
    
  /*
    //Timer 1 - Output to R-2R bridge - speaker
    //set timer1 interrupt at 1kHz
    TCCR1A = 0;// set entire TCCR0A register to 0
    TCCR1B = 0;// same for TCCR0B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1khz increments
    OCR1A = 62; // = (16*10^6) / (1000*256) - 1 (must be <256)
    // turn on CTC mode
    TCCR1A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR1B |= (1 << CS01) | (1 << CS00);   
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE0A);

   //Timer 2 - Output to motor controller
   //set timer2 interrupt at 1kHz
    TCCR2A = 0;// set entire TCCR0A register to 0
    TCCR2B = 0;// same for TCCR0B
    TCNT2  = 0;//initialize counter value to 0
    // set compare match register for 1khz increments
    OCR2A = 62; // = (16*10^6) / (1000*256) - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR2B |= (1 << CS01) | (1 << CS00);   
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE0A);
   
    sei();//allow interrupts

    //setup input and output pins

*/
    /*
   pinMode(ledPin, OUTPUT);
   pinMode(ledPin2, OUTPUT);
   pinMode(sensorPin, INPUT);

  /* pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   */
/*
     Serial.begin(9600);
       Serial.println("HELLO WORLD");
       */

/*
  pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     */
/*
}

/*
void DAC (int desired_analog)
{
  
  byte digital_value = (byte)desired_analog;

  PORTD = B00000010 | (digital_value << 2);
}
*/
/*
void loop()
{
  cli();//stop interrupts
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);


  /*
  for(int i = 0; i<16; i++)
  {
    DAC(i);
    delay(1000);
  }
  */

  /*
  toggler = false;
  digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
  if (toggler){
    delay(100);
   // digitalWrite(motorPin2, LOW);
  }
  else
  {
    digitalWrite(motorPin2, HIGH);
  }
 */
 /*
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    delay(1000);
    digitalWrite(ledPin,LOW);
    digitalWrite(ledPin2,LOW);
      if(sensorValue > 900)
       { analogWrite(ledPin, 50);}
      else
      {analogWrite(ledPin2, 50);}
   // analogWrite(ledPin, sensorValue);
*/
/*
  sei();//allow interrupts
}

*/
/*
ISR(TIMER0_COMPA_vect)
{//timer0 interrupt 1kHz toggles pin 8
    toggler = true;
  
}
*/

/*
//output to motor controller
void set_motor(float motor1, float motor2 )
{
  
}

//output to motor controller, robot go staright
void robot_straight(float velocity)
{
  
}

//output to motor controller, robot turn
void robot_turn(float velocity, float turn_degree, int right_or_left)
{
  
}

//read from the light sensor, for music notes
void read_notes()
{
  
}


//output a music note
void play_note(short note_number, short duration)
{
  
}
*/



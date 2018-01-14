/*
 * The first iteration of the algorithm to output a sound using interrupts and DAC
 * Can only ooutput a sound of a specific frequency
 * How can I ouput sounds of different frequency??? multiple arrays? will there by enough memory?
 */

boolean toggle1 = 0;

//light sensors
int sensor_mid = A0;
int sensor_right = A1;
int sensor_left = A2;

//motorpins for motor driver
int motor_l_1 = 10;
int motor_l_2 = 11;
int motor_r_1 = 12;
int motor_r_2 = 13;

//output pins for R-2R bridge
int R_bridge [8] = {2,3,4,5,6,7,8,9};

//music notes number: C,D,E,F,G,A,B,C
int music_notes [8] ={0,1,2,3,4,5,6,7};

int t = 0;
//for f = 10hz
int  sin_val [100] = {127, 
134, 142, 150, 158, 166, 173, 181, 188, 195, 201, 
207, 213, 219, 224, 229, 234, 238, 241, 245, 247, 
249, 251, 252, 253, 253, 253, 253, 251, 250, 247, 
245, 241, 238, 234, 229, 224, 219, 214, 208, 201, 
195, 188, 181, 173, 166, 158, 150, 143, 135, 127, 
119, 111, 103, 95, 87, 80, 73, 66, 59, 52, 
46, 40, 34, 29, 24, 19, 15, 12, 9, 6, 
4, 2, 1, 0, 0, 0, 0, 2, 3, 6, 
8, 11, 15, 19, 24, 28, 34, 39, 45, 52, 
58, 65, 72, 79, 87, 95, 102, 110, 118};

const float pi = 3.14;

void setup()
{
  //cli();//stop interrupts
  //set pin 2-7 as output, 1 as output (serial communication to pc), 0 as input (serial communication from pc to board)
  //DDRD = DDRD | B11111110;
  pinMode(2, OUTPUT);
  
  //set pin 8-13 as outout
//  DDRB = DDRB | B00111111;
 

  //set A0,A1,A2 as input
 // DDRC = DDRC | B00000000;

  //fill in the sine value array
/*
  for (int index = 0; index<8000; index++)
  {
    sin_val[index] = sin(index*0.1);
  }
  */
  
   //setup timers for interrupt
   
   //Timer 0 - Read Light Intensity Sensor music notes, Read Light Intensity Sensor line following
   //set timer0 interrupt at 8kHz
   TCCR0A = 0;// set entire TCCR0A register to 0
   TCCR0B = 0;// same for TCCR0B
   TCNT0  = 0;//initialize counter value to 0
   // set compare match register for 8khz increments
   OCR0A = 249; // = (16*10^6) / (8000*8) - 1 (must be <256)
   // turn on CTC mode
   TCCR0A |= (1 << WGM01);
   // Set CS01 and CS00 bits for 64 prescaler
   TCCR0B |= (1 << CS01) | (1 << CS00);   
   // enable timer compare interrupt
   TIMSK0 |= (1 << OCIE0A);

   
   //Timer 1 - Output to R-2R bridge - speaker
   
   //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 249;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

   //Timer 2 - Output to motor controller


   //setup input and output pins

    Serial.begin(9600);
   
}

void loop()
{
  /*
  for (int i = 2; i < 10; i++)
  {
    pinMode(i, HIGH);
  }
  */

Serial.println(analogRead(A0)/4);
 analogWrite(2,sin_val[t]);

// digitalWrite(2, HIGH);
// delay(1000);

  
}

//interrupt commands for timer 0

ISR(TIMER0_COMPA_vect)
{
  /*
  t+=1;
  if(t == 100) //8000/100= 80hz, base frequency
  t = 0;
  */
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
/*
  if (toggle1){
    digitalWrite(2,HIGH);
    toggle1 = 0;
  }
  else{
    digitalWrite(2,LOW);
    toggle1 = 1;
  }
  */
  t+=1;
  if(t == 100) //8000/100= 80hz, base frequency
  t = 0;
}

/*
//interrupt commands for timer 1
ISR(TIMER1_COMPA_vect)
{
  
}

//interrupt commands for timer 2
ISR(TIMER2_COMPA_vect)
{
  
}
*/

//takes in an interger from 1 - 255 analog value and converts it to digital signals
void DAC (int desired_analog)
{
  PORTD = desired_analog << 2;
  PORTB = desired_analog >> 6;  
}


float sine(float num)
{
  int i = num/0.01;
  int index = i%628;
  return sin_val[index];
}


//output a music note at a specific frenquency for a certain duration
//Low E: 165Hz, High G: 784Hz
void play_note(int frequency)
{
 // int base_multi = frequency/10;
 // DAC(sin_val[t]);
}

/*
//play C
void play_C_L(short duration)
{
  
}

//play D
void play_D(short duration)
{
  
}

//play E
void play_E(short duration)
{
  
}

//play F
void play_F(short duration)
{
  
}

//play G
void play_G(short duration)
{
 
}

//play A
void play_A(short duration)
{
  
}

//play B
void play_B(short duration)
{
  
}

//play C higher octave
void play_C_H(short duration)
{
  
}


//% Duty cycle = (TON/(TON + TOFF)) *100
//output to motor controller, define clockwise as positive, counter clockwise as negative
void motor_set_v(float motor1_v, float motor2_v)
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
*/


// Arduino Robot Solving Maze using One Ultrasonic Sensor
// Dr. Ahmad Faisal Mohamad Ayob
// July 2018
// Petrosains Robotics Competition 2018


// Motor Codes
int S1 = 6; //M1 Speed Control 
int S2 = 5; //M2 Speed Control 
int M1 = 2; //M1 Direction Control 
int M2 = 3; //M2 Direction Control 

void stop() //Stop 
{ 
analogWrite(S1, 0); 
analogWrite(S2, 0); 
} 
void advance(int a,int b) //Move forward 
{ 
analogWrite (S1,a); //PWM Speed Control 
digitalWrite(M1,LOW); 
analogWrite (S2,b); 
digitalWrite(M2,LOW); 
} 
void back_off (int a,int b) //Move backward 
{analogWrite (S1,a); 
digitalWrite(M1,HIGH); 
analogWrite (S2,b); 
digitalWrite(M2,HIGH); 
}   
void turn_R (int a, int b) //Turn Left 
{ 
analogWrite (S1,a); 
digitalWrite(M1,HIGH); 
analogWrite (S2,b); 
digitalWrite(M2,LOW); 
} 

void turn_L (int a,int b) //Turn Right 
{ 
analogWrite (S1,a); 
digitalWrite(M1,LOW); 
analogWrite (S2,b); 
digitalWrite(M2,HIGH); 
}   

// Pin Codes
const int TRIG_PIN = 16; // A2
const int ECHO_PIN = 15; // A1
// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;

void setup() {
  Serial.begin (9600);
  // Motor Codes
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {

//---Pin Code Start---
unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;

  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed 
  //of sound in air at sea level (~340 m/s).
  cm = pulse_width / 58.0;
  inches = pulse_width / 148.0;

  // Print out results
  if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm);
    Serial.print(" cm \n");

  }
  
  // Wait at least 60ms before next measurement
  delay(60);
//---Pin Code End---


// -- Motor Code Start
    if (cm >= 10) 
    {
     // turn_R (100,100); //50,255
     advance (50,150); //50,255
     Serial.print(" turning right \n");
    }
    else 
    {
     turn_L (80,80); //recommended: 80
     Serial.print(" turning left \n");
    }

//advance (0,0);
//turn_R (0,0);
// -- Motor Code End
}

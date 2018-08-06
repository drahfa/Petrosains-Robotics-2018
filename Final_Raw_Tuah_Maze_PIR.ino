
// Arduino Robot Solving Maze using One Infrared Sensor
// Dr. Ahmad Faisal Mohamad Ayob
// July 2018
// Petrosains Robotics Competition 2018

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

void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
 
  pinMode(10,INPUT);
}

void loop()
{
    int R = digitalRead(10);//RIGHT
    
    if (R == 1) // R==1 means far from wall, so turn right to get close to wall
    {
     advance (50,255); //50,255
    }
    else // R == 0 means very close to wall, so turn left 
    {
     //advance (150,80); //50,255
     turn_L (80,80); //80
    }
  }


/*
Adam & OJ
*/

#include <Servo.h>

Servo servo1;
int mouts2 = 5;
int mouts3 = 8;
int aouts4 = 11;
int ines1 = 4;
int ines2 = 6;
String compromp[] = {"b21", "b01","b20" , "b00"};
int max_servo = 180;
int min_servo = 0;
int pin1 = 7;
int pin2 = 9;
char da;
String comm;

int i = 0;

void setup() 
{  
  Serial.begin(9600);
  servo1.attach(3);
  pinMode(mouts2, OUTPUT);
  pinMode(mouts3, OUTPUT);
  pinMode(aouts4, OUTPUT);
  
  pinMode(ines1, INPUT);
  pinMode(ines2, INPUT); 
}

void loop() 
{
  if(Serial.available() > 0) 
  {
    comm = "";
    for(i = 0; i<3; i++ )
    {
      da = Serial.read();
      comm += da;  
      delay(10);
    }
    if((compromp[0] == comm)&&(servo1.read() == min_servo))
    {
      servo1.write(max_servo);  
    }
    else if((compromp[1] == comm)&&(servo1.read() == max_servo))
    { 
      servo1.write(min_servo);
    }  
    else if((compromp[2] == comm))
    {
      if(digitalRead(aouts4)== LOW)
      {
        digitalWrite(aouts4,HIGH);
      }
      else
      {
        digitalWrite(aouts4,LOW);
      }
    }
    else if(compromp[3] == comm)
    {
      if(digitalRead(mounts2)==LOW)
      {
        digitalWrite(mouts2, HIGH);
      }
      else
      {
        digitalWrite(mouts2, LOW);
      }
    }
    else
    {
      comm == "";
    }
    if(servo1.read() != max_servo || (servo1.read() != min_servo))
    {
      servo1.write(max_servo); 
    }
  }
}

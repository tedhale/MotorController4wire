/*
    MotorPair4wire.cpp  -  Library for handling a dual motor controller
	using only 4 wires. The Enable pins should be tied high. Connections 
	are to IN_!, IN_2, IN_3 and IN_4 only. These must be connected to 
	PWM capable outputs.
	
	Ted.B.Hale@gmail.com  4-May-2017   Released into the public domain
*/

#include "MotorPair4wire.h"

#define LEFT 1
#define RIGHT 2

MotorPair4wire::MotorPair4wire(int a, int b, int c, int d)
{
	IN_1 = a;
	IN_2 = b;
	IN_3 = c;
	IN_4 = d;
	pinMode(IN_1,OUTPUT);
	pinMode(IN_2,OUTPUT);
	pinMode(IN_3,OUTPUT);
	pinMode(IN_4,OUTPUT);
	stop();
}

//********************************************************************************
void MotorPair4wire::forward(int powerRight, int powerLeft)
{
  setMotor(RIGHT,powerRight);
  setMotor(LEFT,powerLeft);
}

//********************************************************************************
void MotorPair4wire::reverse(int powerRight, int powerLeft)
{
  setMotor(RIGHT,-1*powerRight);
  setMotor(LEFT,-1*powerLeft);
}

//********************************************************************************
void MotorPair4wire::turnLeft(int powerLevel)
{
  setMotor(RIGHT,-1*powerLevel);
  setMotor(LEFT,powerLevel);
}

//********************************************************************************
void MotorPair4wire::turnRight(int powerLevel)
{
  setMotor(RIGHT,powerLevel);
  setMotor(LEFT,-1*powerLevel);
}

//********************************************************************************
void MotorPair4wire::brake()
{
  analogWrite(IN_1,255);
  analogWrite(IN_2,255);
  analogWrite(IN_3,255);
  analogWrite(IN_4,255);
}

//********************************************************************************
void MotorPair4wire::stop()
{
  setMotor(RIGHT,0);
  setMotor(LEFT,0);
}

//********************************************************************************
// control motor speed and direction  (- speed for reverse)
void MotorPair4wire::setMotor(int motor, int powerLevel)
{
  int i1, i2, pwr;
  if (motor == LEFT)
  {
    i1 = IN_3;
    i2 = IN_4;
  }
  else
  {
    i1 = IN_1;
    i2 = IN_2;
  }
  pwr = (powerLevel * 255) / 100;
  if (pwr<0) pwr = pwr*-1;
  if (powerLevel == 0)
  {
    analogWrite(i1, 0);
    analogWrite(i2, 0);
  }
  else if (powerLevel > 0)
  {
    analogWrite(i1, pwr);
    analogWrite(i2, 0);
  }
  else if (powerLevel < 0)
  {
    analogWrite(i1, 0);
    analogWrite(i2, pwr);
  }
}

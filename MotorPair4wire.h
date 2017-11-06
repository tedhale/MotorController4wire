#ifndef MotorPair4wire_h
#define MotorPair4wire_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class MotorPair4wire
{
  public:
    MotorPair4wire(int a, int b, int c, int d);
	void forward(int powerRight, int powerLeft);
	void reverse(int powerRight, int powerLeft);
	void turnRight(int powerLevel);
	void turnLeft(int powerLevel);
	void stop();
	void brake();
	
  private:
    int IN_1;
    int IN_2;
    int IN_3;
    int IN_4;
	
	void setMotor(int motor, int powerLevel);

};

#endif
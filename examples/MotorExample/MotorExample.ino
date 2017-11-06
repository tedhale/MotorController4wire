/*  Simple example of how to use the library  */

#include <MotorPair4wire.h>

// motor controller pins  These MUST be PWM pins
#define IN_1 6
#define IN_2 9
#define IN_3 10
#define IN_4 11

// the motors
MotorPair4wire motor(IN_1, IN_2, IN_3, IN_4);

void setup() {

}

void loop() {

  // forward 2/3 of full speed
  motor.forward(66,66);
  delay(2000);

  // quick stop using motor for braking
  motor.brake();

  // turn to the right at full speed
  motor.turnRight(100);
  delay(1000);

  // turn to the left at full speed
  motor.turnLeft(100);
  delay(1000);

  // reverse at 1/3 speed
  motor.reverse(33,33);
  delay(1000);

  // by setting different speeds for each motor
  // it can more forward curving to the right
  motor.forward(66,33);
  delay(2000);

  // turn motors off
  motor.stop();
  delay(5000);

}

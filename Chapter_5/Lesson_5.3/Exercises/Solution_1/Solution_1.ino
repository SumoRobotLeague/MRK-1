/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 5.3, Solution 1, Speed Control Improvements
********************************************************************/

// Implement error checking to make sure speed is never greater
// than 255 or less than -255.
// These code improvements will be put inside Motor.cpp.

#include "Motor.h"

#define rightMotorSpeed 10
#define rightMotorDirection 8
#define leftMotorSpeed 9
#define leftMotorDirection 4

// Create a new motor object from our class
Motor motor;

void setup() {
	motor.setupRight(rightMotorSpeed, rightMotorDirection);
	motor.setupLeft(leftMotorSpeed, leftMotorDirection);

	// 5000 is much higher than 255, but Motor.cpp will
	// automatically set it to the maximum possible value
	// or 255.
	motor.left(5000);
	motor.right(-5000);
}

void loop() {
	// Do nothing but spin (configured in setup())
}

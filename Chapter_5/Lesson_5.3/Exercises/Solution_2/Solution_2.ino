/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 5.3, Solution 2, Attack Method
********************************************************************/

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

	// Implement a method in motor called Attack() that will
	// drive forward at full speed.
	motor.attack();
}

void loop() {
	// Do nothing but spin (configured in setup())
}

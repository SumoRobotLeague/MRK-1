/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 5.3, A Motor Control Library
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

	motor.left(255);
	motor.right(-255);
}

void loop() {
	// Do nothing but spin (configured in setup())
}

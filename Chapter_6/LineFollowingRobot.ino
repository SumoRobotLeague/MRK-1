/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 6, Bot: Line Following
********************************************************************/

#include "Motor.h"

// Pin definitions
// IR Sensors and IR Emitter
#define leftSensor  A1
#define rightSensor A2
#define IREmitter   6

// Motor pins
#define rightMotorSpeed     10
#define rightMotorDirection 8
#define leftMotorSpeed      9
#define leftMotorDirection  4

// Robot configuration
#define MOVE_SPEED 125
#define LINE_VALUE 1010
#define DELAY_TIME 300

// Create our motor object
Motor motor;

void setup() {
	Serial.begin(9600);
	pinMode(IREmitter,   OUTPUT);
	pinMode(leftSensor,  INPUT);
	pinMode(rightSensor, INPUT);

	motor.setupRight(rightMotorSpeed, rightMotorDirection);
	motor.setupLeft(leftMotorSpeed,   leftMotorDirection);
}

void loop() {
	// Turn on our IREmitter so that our line sensors will get
	// a strong signal.
	digitalWrite(IREmitter, HIGH);

	// Move forward at our pre-defined speed.
	motor.left(MOVE_SPEED);
	motor.right(MOVE_SPEED);

	// Read our line sensor values.
	int leftReading = analogRead(leftSensor);
	int rightReading = analogRead(rightSensor);

	if ( leftReading < LINE_VALUE ) {
		motor.right(MOVE_SPEED + 10);
		motor.left(MOVE_SPEED - 10);
	}

	if ( rightReading < LINE_VALUE ) {
		motor.right(MOVE_SPEED - 10);
		motor.left(MOVE_SPEED + 10);
	}

	// Give our motors a small amount of time to
	// change our robot's course.
	delay(DELAY_TIME);
}

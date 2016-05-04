/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 7, Exercise 1, Bot: Fun Demo Robot
  - search_and_avoid()
  - search_and_destroy()
********************************************************************/

#include "Motor.h"

// Define pins and configuration for managing state
#define button 2
#define led 7
#define stateSwitchDelay 3000

// Define pins to control the sonar sensor
#define echoPin A0
#define pingPin 3

// Motor pins
#define rightMotorSpeed     10
#define rightMotorDirection 8
#define leftMotorSpeed      9
#define leftMotorDirection  4

// Initialize state variables
const int states = 2;
int state = 1;
bool buttonPressed = false;

// Global operational variables
long cm = 0;
const int turnDuration = 600;

// search_and_destroy() attack configuration
const int stopDistance   = 1; // Distance in centimeters
const int attackDistance = 15;

// Create our motor object
Motor motor;

void setup() {
	Serial.begin(9600);
	pinMode(led,    OUTPUT);
	pinMode(button, INPUT_PULLUP);
	pinMode(echoPin, INPUT);
	pinMode(pingPin, OUTPUT);

	// Configure our motors
	motor.setupRight(rightMotorSpeed, rightMotorDirection);
	motor.setupLeft(leftMotorSpeed, leftMotorDirection);

	// Once setup is complete, start our robot in our
	// first operational state.
	blink(state);
	delay(stateSwitchDelay);
}

void loop() {
	if ( digitalRead(button) == 0 ) {
		// the button is being held down
		buttonPressed = true;
	}
	if ( buttonPressed && digitalRead(button) == 1 ) {
		// the button WAS held down and was just released
		buttonPressed = false;

		if ( state == states ) {
			// we've reached our maximum state, reset to 0
			// and pause until we press the button again
			state = 0;
		} else {
			state = state + 1;
		}

		blink(state);
		delay(stateSwitchDelay);
	}

	switch(state) {
		case 0:
			// Do nothing until the button is pressed again
			break;
		case 1:
			search_and_avoid();
			break;
		case 2:
			search_and_destroy();
			break;
	}
}

// Randomly drive around. If an object is detected closer than
// 10 cm, pick a new direction and drive away.
void search_and_avoid() {
	// get a random direction, 1 = left, 2 = right
	int turnDirection = 1;

	// get distance in centimeters
	cm = msToCm( ping() );

	// if distance is less than 10, pick a new random direction
	if ( cm < 10 ) {
		turnDirection = random(1, 3);

		if ( turnDirection == 1 ) {
			motor.left(255);
			motor.right(-255);
			delay(turnDuration);
		} else {
			motor.left(-255);
			motor.right(255);
			delay(turnDuration);
		}
	} else {
		// if distance is greater than 10, just drive forward
		motor.left(255);
		motor.right(255);
	}
}

// Randomly drive towards the nearest object. Stop when
// the distance to the object is 1cm or less. If the object moves,
// resume searching
void search_and_destroy() {
	// get a random direction, 1 = left, 2 = right
	int turnDirection = 1;

	// get distance in centimeters
	cm = msToCm( ping() );

	// if distance is less than 10, pick a new random direction
	if ( cm < attackDistance ) {
		// We have found an object, attack!
		motor.attack();

		// we are within 1 cm of our object, stop attacking
		// and blink at the target angrily. :)
		if ( cm <= stopDistance ) {
			motor.left(0);
			motor.right(0);

			blink(1);
		}

	} else {
		// We haven't found anything close to us, spin in place
		// until we find something.
		turnDirection = random(1, 3);

		if ( turnDirection == 1 ) {
			motor.left(255);
			motor.right(-255);
		} else {
			motor.left(-255);
			motor.right(255);
		}
	}
}

// Helper function to manage our ultrasonic sensor.
long ping() {
	long duration;
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);
	duration = pulseIn(echoPin, HIGH);

	return duration;
}

// Helper function to return the distance to an object
// detected by the ultrasonic sensor in centimeters.
long msToCm(long microseconds) {
	return microseconds / 29 / 2;
}

// Simple blink function called in loop() whenever a state
// change is made by a user button press.
void blink(int blinks) {
	for ( int i = 0; i <= blinks; i++ ) {
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		delay(500);
	}
}

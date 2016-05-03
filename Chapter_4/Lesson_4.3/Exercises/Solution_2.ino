/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.3, Exercise 2 Solution - Simple Motor Tests
********************************************************************/

// Pin definitions
#define rightMotorSpeed 10
#define rightMotorDirection 8
#define leftMotorSpeed 9
#define leftMotorDirection 4

void setup() {
	Serial.begin(9600);
	pinMode(rightMotorSpeed,     OUTPUT);
	pinMode(rightMotorDirection, OUTPUT);
	pinMode(leftMotorSpeed,      OUTPUT);
	pinMode(leftMotorDirection,  OUTPUT);
}

void loop() {
	/* Perform the following three tests and then repeat:
		1. Drive full speed ahead for 3 seconds.
		2. Drive full speed in reverse for 3 seconds.
		3. Spin in place for 3 seconds
	*/

	setSpeed(0, 255);
	setSpeed(1, 255);
	delay(3000);

	setSpeed(0, -255);
	setSpeed(1, -255);
	delay(3000);

	setSpeed(0, 255);
	setSpeed(1, -255);
	delay(3000);
}

// int motor defines which motor we want to control.
// motor 0 is our right motor, motor 1 is our left motor.
void setSpeed(int motor, int speed) {
	if ( motor == 0 ) {
		if ( motorspeed < 0 ) {
			digitalWrite(rightMotorDirection, LOW);
			analogWrite(rightMotorSpeed, abs(speed));
		} else {
			digitalWrite(rightMotorDirection, HIGH);
			analogWrite(rightMotorSpeed, speed);
		}
	} else {
		if ( motorspeed < 0 ) {
			digitalWrite(leftMotorDirection, HIGH);
			analogWrite(leftMotorSpeed, abs(speed));
		} else {
			digitalWrite(leftMotorDirection, LOW);
			analogWrite(leftMotorSpeed, speed);
		}
	}
}

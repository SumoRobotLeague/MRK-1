/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.3, Exercise 1 Solution - setSpeed Function
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
	// Have our robot spin in place at full speed

	// Right motor at full speed forward
	setSpeed(0, 255);

	// Left motor at full speed in reverse
	setSpeed(1, -255);
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

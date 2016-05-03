/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.3, Motor Control
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
	delay(1000);
}

void loop() {
	// Set our right motor to go full speed forward
	digitalWrite(rightMotorDirection, LOW);
	analogWrite(rightMotorSpeed, 255);

	// Set our left motor to go full speed in reverse
	// NOTE: The left motor is installed backwards, so
	// "forward" is the opposite motor direction from
	// your right motor.
	// LOW = reverse, HIGH = forward
	digitalWrite(leftMotorDirection, LOW);
	analogWrite(leftMotorSpeed, 255);
}

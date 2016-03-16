/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.2, Push Button
********************************************************************/

#define buttonPin 2
#define led       7

void setup() {
	Serial.begin(9600);
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(led, OUTPUT);
}

void loop() {
	if ( digitalRead(buttonPin) == 0 ) {
		// button is pressed, turn on LED
		digitalWrite(led, HIGH);
	} else {
		// button is not pressed, turn it off
		digitalWrite(led, LOW);
	}
}

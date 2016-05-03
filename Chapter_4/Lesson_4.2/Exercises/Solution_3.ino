/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.2, Exercise 3 Solution - Push Button
********************************************************************/

#define buttonPin 2
#define led       7

int lightState  = 0; // 0 = off, 1 = on
int buttonState = 1;

void setup() {
	Serial.begin(9600);
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(led, OUTPUT);
}

void loop() {
	if ( digitalRead(buttonPin) == 0 ) {
		// button is pressed
		buttonState = 0;
	}

	if ( buttonState == 0 && digitalRead(buttonPin) == 1 ) {
		// button was pressed but has just been released
		buttonState = 1;
		if ( lightState == 0 ) {
			// turn on our light
			lightState = 1;
			digitalWrite(led, HIGH);
		} else {
			// our light was on, turn it off.
			lightState = 0;
			digitalWrite(led, LOW);
		}
	}
}

/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.2, Exercise 1
********************************************************************/

void setup() {
	Serial.begin(9600);

	int height = 72;

	// 42 inches is 3.5 feet.
	if ( height > 42 ) {
		Serial.println("Climb aboard!");
	} else {
		Serial.println("Too short! Access denied!");
	}
}

void loop() {
}

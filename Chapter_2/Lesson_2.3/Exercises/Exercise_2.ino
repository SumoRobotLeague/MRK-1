/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 2.3, Exercise 2
********************************************************************/

void setup() {
	Serial.begin(9600);

	Serial.print("5000 microseconds distance in inches is: ");
	Serial.println( msToInches(5000) );
}

void loop() {
}

long msToInches(long microseconds) {
	return microseconds / 74 / 2;
}


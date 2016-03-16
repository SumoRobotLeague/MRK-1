/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.3, Exercise 1

  Write a function that will use a Switch statement to check an
  integer value named "state". Print to the Serial Monitor
  the message "Attack!" when state is 1, "Abort!" when state is 2
  and "Searching..." for any other value.
********************************************************************/

int state = 0; // default state is 0 for "searching"

void setup() {
	Serial.begin(9600);

	checkState();

}

void loop() {
}

void checkState() {
	/*
		States:
			1 = Attack
			2 = Abort
			Default = Searching
	*/

	switch(state) {
		case 1:
			Serial.println("Attack!");
			break;
		case 2:
			Serial.println("Abort!");
			break;
		default:
			Serial.println("Searching...");
			break;
	}

}

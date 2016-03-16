/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.3, Exercise 1
********************************************************************/

int state = 0; // 1 = attack, 2 = abort, default = searching

void setup() {
	Serial.begin(9600);
}

void loop() {
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

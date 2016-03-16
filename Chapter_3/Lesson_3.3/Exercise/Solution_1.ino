/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.3, Exercise 1
********************************************************************/

<<<<<<< HEAD:Chapter_3/Lesson_3.3/Exercise/Solution_1.ino
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
=======
/********************************************************************
Pseudo-code example solution for Exercise 2.

	DEFINE distanceLimit TO 10 CENTIMETERS

	SETUP FUNCTION:
		CONFIGURE ULTRASONIC SENSOR PINS FOR INPUT
		CONFIGURE LED PINS FOR OUTPUT

	LOOP FUNCTION:
		GET distance FROM ULTRASONIC DISTANCE SENSOR

		IF distance IS LESS THAN distanceLimit:
			TURN ON LED
		ELSE:
			TURN OFF LED
********************************************************************/
>>>>>>> master:Chapter_3/Lesson_3.2/Exercises/Solution_2.ino

/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.2, Exercise 3
********************************************************************/

String nameToCheck = String("Steve");
String myName = String("Eric");

void setup() {
	Serial.begin(9600);
	Serial.println("Hi, my name is " + nameToCheck);

	// Check if the two strings are the same using '=='
	if ( nameToCheck == myName ) {
		Serial.println("The names are the same!");
	} else {
		Serial.println("The names are NOT the same. :( ");
	}

	// Now check the strings using the equals() function
	if ( nameToCheck.equals(myName) ) {
		Serial.println("The names are still the same!");
	} else {
		Serial.println("They're not the same this way either.");
	}

}

void loop() {
}

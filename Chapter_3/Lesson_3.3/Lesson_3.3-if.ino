/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.3 - Using If Blocks
********************************************************************/

void setup() {
	Serial.begin(9600);

	int age = 23;

	// check the permissions using the integer variable "age" defined above
	// Try changing the age and seeing what happens at different ages.
	checkPermissions_if(age);
}

void loop() {
}

void checkPermissions_if(int age) {
	if ( age == 15 ) {
		Serial.println("learner's permit");
	}
	if ( age == 16 ) {
		Serial.println("driver's license");
	}
	if ( age == 18 ) {
		Serial.println("lottery tickets");
	}
	if ( age == 25 ) {
		Serial.println("insurance discount");
	}
}

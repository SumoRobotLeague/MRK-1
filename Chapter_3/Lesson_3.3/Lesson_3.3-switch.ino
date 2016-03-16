/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.3 - Using a Switch Statement
********************************************************************/

void setup() {
	Serial.begin(9600);

	int age = 23;

	// check the permissions using the integer variable "age" defined above
	// Try changing the age and seeing what happens at different ages.
	checkPermissions_switch(age);

	// Practical exercise: What is printed to the Serial Monitor with age 16?
	age = 16;
	checkPermissions_switch(age);

	// Practical exercise: What is printed to the Serial Monitor with age 21?
	age = 21;
	checkPermissions_switch(age);
}

void loop() {
}

void checkPermissions_switch(int age) {
	switch(age) {
		case 15:
			Serial.println("learner's permit");
			break;
		case 16:
			Serial.println("driver's license");
			break;
		case 18:
			Serial.println("lottery tickets");
			break;
		case 25:
			Serial.println("insurance discount");
			break;
		default:
			Serial.println("no permission change");
			break;
	}
}

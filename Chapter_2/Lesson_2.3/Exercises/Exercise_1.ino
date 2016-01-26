/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 2.3, Exercise 1
********************************************************************/

void setup() {
	Serial.begin(9600);
	
	Serial.print("9 * 13 = ");
	Serial.println( multiply(9, 13) );
}

void loop() {
}

int multiply(int A, int B) {
	return A * B;
}

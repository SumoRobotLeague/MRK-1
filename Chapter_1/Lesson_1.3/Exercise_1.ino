/********************************************************************
  Chapter 1, Lesson 3 Exercises
  Author - Eric Ryan Harrison <me@ericharrison.info>
********************************************************************/

void setup() {
	// initialize digital pin 7 as an output.
	pinMode(7, OUTPUT);
}

void loop() {
	digitalWrite(7, HIGH); // turn the LED on.
	delay(1000);           // wait for a second.
	digitalWrite(7, LOW);  // turn the LED off.
	delay(1000);           // wait for a second.
}

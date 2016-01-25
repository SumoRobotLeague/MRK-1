
// initialize our global variables
int delayMs = 1000; // delay time in milliseconds

void setup() {
	// initialize digital pin 7 as an output
	pinMode(7, OUTPUT);
}

void loop() {
	digitalWrite(7, HIGH); // turn the LED on
	delay(delayMs);
	digitalWrite(7, LOW);  // turn the LED off
	delay(delayMs); 
}

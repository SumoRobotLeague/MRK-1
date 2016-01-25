
// initialize our global variables
int durationOn  = 1000;
int durationOff = 1000;

void setup() {
	// initialize digital pin 7 as an output
	pinMode(7, OUTPUT);
}

void loop() {
	digitalWrite(7, HIGH); // turn the LED on
	delay(durationOn);
	digitalWrite(7, LOW);  // turn the LED off
	delay(durationOff); 
}

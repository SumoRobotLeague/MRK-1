
void setup() {
	// initialize digital pin 7 as an output
	Serial.begin(9600);
	pinMode(7, OUTPUT);
}

void loop() {
	blink(1000);
	blink(500);
	blink(1500);
	blink(250);
}

void blink(int delayMs) {
	digitalWrite(7, HIGH); // turn the LED on
	delay(delayMs);
	digitalWrite(7, LOW);  // turn the LED off
	delay(delayMs);
}

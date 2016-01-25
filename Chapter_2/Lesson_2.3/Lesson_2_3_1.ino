
void setup() {
	Serial.begin(9600);

	Serial.println( msToCm(5000) );
	Serial.println( msToCm(10000) );
}

void loop() {
}

long msToCm(long microseconds) {
	// returns centimeters a soundwave travels at sealevel 
	// after bouncing off an object and returning to the 
	// point of origin
	return microseconds / 29 / 2;
}

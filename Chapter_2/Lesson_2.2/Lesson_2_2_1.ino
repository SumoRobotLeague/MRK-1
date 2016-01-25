
void setup() {
	Serial.begin(9600);
}

void loop() {
	int seconds = 60; // seconds per minute
	int minutes = 60; // minutes per hour
	int hours   = 6;  // total number of hours
	int secondsPerDay = seconds * minutes * hours;

	Serial.println(secondsPerDay);
}

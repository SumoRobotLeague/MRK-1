/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.2, Practical Exercise
********************************************************************/

#define echoPin A0
#define pingPin 3

void setup() {
	Serial.begin(9600);
	pinMode(echoPin, INPUT);
	pinMode(pingPin, OUTPUT);
}

void loop() {
	// calling ping() inside msToCm() will convert the
	// microseconds ping() returns into centimeters.
	long cm = msToCm( ping() );
	delay(500); // We don't want this to run too fast
	Serial.println(cm);
}

long ping() {
	long duration;
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	return duration;
}

long msToCm(long microseconds) {
	return microseconds / 29 / 2;
}

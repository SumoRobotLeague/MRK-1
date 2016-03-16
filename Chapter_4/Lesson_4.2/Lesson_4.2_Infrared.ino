/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 4.2, Infrared Line Detection Sensors
********************************************************************/

#define leftSensor  A1
#define rightSensor A2
#define IREmitter   6

void setup() {
	Serial.begin(9600);
	pinMode(leftSensor, INPUT);
	pinMode(rightSensor, INPUT);
	pinMode(IREmitter, OUTPUT);
}

void loop() {
	digitalWrite(IREmitter, HIGH);
	int rightInput = analogRead(rightSensor);
	int leftInput  = analogRead(leftSensor);
	Serial.print("Left/");
	Serial.print(leftInput);
	Serial.print(" - Right/");
	Serial.println(rightInput);
	delay(500);
}

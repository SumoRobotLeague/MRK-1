/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 5.2, Musical Programming
********************************************************************/

#include "Pitches.h"

#define buzzer 5

void setup() {
	Serial.begin(9600);

	pinMode(buzzer, OUTPUT);
}

void loop() {
	// Let's play the first part of "Twinkle Twinkle Little Star"
	tone(buzzer, NOTE_C5, 250);
	delay(500);
	tone(buzzer, NOTE_C5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 250);
	delay(500);
	tone(buzzer, NOTE_A5, 250);
	delay(500);
	tone(buzzer, NOTE_A5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 500);
}

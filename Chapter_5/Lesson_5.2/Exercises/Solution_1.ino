/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 5.2, Solution 1, Musical Helper Function
********************************************************************/

/***************************************************
 * Functional Requirements
 *
 * 1. Develop a function that will take 3 arguments
 * play the note provided for the duration specified,
 * then pause for the time specified by the rest
 * duration argument.
 *
 * 2. Define an array format that will contain all
 * three of the required arguments.
 *
 * 3. Loop through this array to play a song.
 ***************************************************/

#include "Pitches.h"

#define buzzer 5

// Our musical notation array.
int notes[] = {
	// NOTE, DURATION, REST
	NOTE_C5, 250, 500,
	NOTE_C5, 250, 500,
	NOTE_G5, 250, 500,
	NOTE_G5, 250, 500,
	NOTE_A5, 250, 500,
	NOTE_A5, 250, 500,
	NOTE_G5, 500, 1000
};

void setup() {
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT);

	int arrayLength = (sizeof(notes)/sizeof(int));
	int notesToPlay = arrayLength / 3;

	Serial.println("Starting musical robot!");
	Serial.print("Your notes array contains '");
	Serial.print(notesToPlay);
	Serial.println("' total notes.");
}

void loop() {
	int arrayLength = (sizeof(notes)/sizeof(int));

	// NOTE: We are adding 3 to the loop index so that
	// we can always skip to the next note.
	for ( int i = 0; i < arrayLength; i = i + 3) {
		playNote(notes[i], notes[i+1], notes[i+2]);
	}

	// Once we've finished playing our melody, pause
	// for a few seconds and repeat. :)

	delay(3000);
}

void playNote(int note, int duration, int rest) {
	tone(buzzer, note, duration);
	delay(rest);
}

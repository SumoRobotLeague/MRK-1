/********************************************************************
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/

  Lesson 3.2, Exercise 2
********************************************************************/

/********************************************************************
Pseudo-code example solution for Exercise 2.

	DEFINE distanceLimit TO 10 CENTIMETERS

	SETUP FUNCTION:
		CONFIGURE ULTRASONIC SENSOR PINS FOR INPUT
		CONFIGURE LED PINS FOR OUTPUT

	LOOP FUNCTION:
		GET distance FROM ULTRASONIC DISTANCE SENSOR

		IF distance IS LESS THAN distanceLimit:
			TURN ON LED
		ELSE:
			TURN OFF LED
********************************************************************/

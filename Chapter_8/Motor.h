/********************************************************************
  Motor.h - A Library for Controlling the Motors of the MRK-1
  An Introduction to Robot Programming
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/SumoRobotLeague/MRK-1/
********************************************************************/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
	public:
		Motor();
		void setupRight(int rightSpeed_pin, int rightDirection_pin);
		void setupLeft(int leftSpeed_pin, int leftDirection_pin);
		void right(int speed);
		void left(int speed);
		void attack();
		void abort();
	private:
		int _rightMotorSpeedPin;
		int _rightMotorDirectionPin;
		int _leftMotorSpeedPin;
		int _leftMotorDirectionPin;
};

#endif

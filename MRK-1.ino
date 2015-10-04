/************************************************
* MRK-1 Sumo Robot Baseline
* Author: Eric Ryan Harrison
* eharrison@sumorobotleague.com
*
* COPYRIGHT 2015 SumoRobotLeague.com
*
* This sketch is designed to work with the SumoRobotLeague MRK-1
* sumo robot kit. For more information about the kit, please
* visit http://www.sumorobotleague.com/purchasekits/individual-kits
*/

// TODO(erh): Remove this library.
#include <Pushbutton.h>

// PIN Configurations
#define echoPin 2
#define triggerPin 3
#define rightBackMotor 4
#define rightMotorSpeed 5
#define leftMotorSpeed 6
#define leftForwardMotor 7  //if a motor goes backward swap the number on the FwdPin and BckPin
#define rightForwardMotor 8   //if a motor goes backward swap the number on the FwdPin and BckPin
#define leftBackMotor 11
#define LED 13
#define leftSensor A7
#define rightSensor A0

// Robot Configuration Parameters
// Speed range is -255 -> 255
#define MAX_SPEED 255
#define SEARCH_SPEED 255
#define QTR_Threshold 500
#define ATTACK_DISTANCE 25
#define BACKUP_DISTANCE 4000

// State variables
bool isBackup = false;
int backupTimer = 0;
long distance = 1000;
Pushbutton button(ZUMO_BUTTON);

void setSpeed(int speed, int motor);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup.");

  pinSetup();

  Serial.println("Waiting for button");
}

void loop() {
  if (button.isPressed()) {
    // if button is pressed, stop and wait for another press to go again
    button.waitForRelease();
    waitForButtonAndCountDown();
  }

  int leftInput = analogRead(leftSensor);
  int rightInput = analogRead(rightSensor);

  if ( isBackup ) {
    backupTimer = backupTimer + 1;
    setSpeed(-MAX_SPEED, 0);
    setSpeed(-MAX_SPEED + 20, 1);
    if (backupTimer >= BACKUP_DISTANCE ) {
      isBackup = false;
      backupTimer = 0;
    }
  } else {
    if ( leftInput <= 500 || rightInput <= 500 ) { // WHITE LINE ABORT!
      //Serial.println("Abort! - "); Serial.println(leftInput); Serial.println(rightInput);
      isBackup = true;
      setSpeed(-MAX_SPEED, 0);
      setSpeed(-MAX_SPEED, 1);
    } else {
      distance = getDistance();
      if ( distance <= ATTACK_DISTANCE ) { // ATTACK!
        Serial.println("Attack!");
        setSpeed(MAX_SPEED, 0);
        setSpeed(MAX_SPEED, 1);
      } else { // search
        // TODO(erh): implement other searching algorithms
        Serial.println("Search");
        setSpeed(-SEARCH_SPEED, 0);
        setSpeed(SEARCH_SPEED, 1);
      }
    }
  }
}

void pinSetup() {
  // motors!
  pinMode(leftMotorSpeed, OUTPUT);
  pinMode(rightMotorSpeed, OUTPUT);
  pinMode(leftForwardMotor, OUTPUT);
  pinMode(leftBackMotor, OUTPUT);
  pinMode(rightForwardMotor, OUTPUT);
  pinMode(rightBackMotor, OUTPUT);

  // sonar sensor
  pinMode(LED, HIGH);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // qtr light sensor
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void setSpeed(int speed, int motor = 0) {
  int speedPin, forwardPin, backPin;
  if ( motor == 0 ) {
    speedPin = leftMotorSpeed;
    forwardPin = leftForwardMotor;
    backPin = leftBackMotor;
  } else if ( motor == 1 ) {
    speedPin = rightMotorSpeed;
    forwardPin = rightForwardMotor;
    backPin = rightBackMotor;
  }

  if ( speed == 0 ) {
    analogWrite(speedPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backPin, LOW);
  } else if ( speed > 0 ) {
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backPin, LOW);
    analogWrite(speedPin, speed);
  } else if ( speed < 0 ) {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backPin, HIGH);
    analogWrite(speedPin, abs(speed));
  }
}

long getDistance() {
  long duration, distance;
  digitalWrite(triggerPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

void waitForButtonAndCountDown() {
  digitalWrite(LED, HIGH);
  button.waitForButton();
  digitalWrite(LED, LOW);

  for (int i = 0; i < 3; i++ ) {
    Serial.println(i);
    delay(1000);
  }

  delay(1000);
  Serial.println("ATTACK!");
  delay(1000);
}

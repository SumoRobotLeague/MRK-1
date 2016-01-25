
void setup() {
	Serial.begin(9600);

	int a = 5;
	int b = a + 12;
	a = 10;
	float c = 7.2;
	int d = c * a;
	int e = 9 / 4;
	int irSensors[] = { A1, A2, A3 };

	// Question 1 Solution
	Serial.print("Question 1: The current value of b is: ");
	Serial.println(b);

	// Question 2 Solution
	Serial.print("Question 2: The final value of a is: ");
	Serial.println(a);

	// Question 3 Solution
	Serial.print("Question 3: The final value of d is: ");
	Serial.println(d);

	// Question 4 Solution
	Serial.print("Question 4: The IR Sensor in irSensors[] at index 2 is: ");
	Serial.println(irSensors[2]);

	// Question 5 Solution
	Serial.print("Question 5: The IR Sensor in irSensors[] at index 0 is: ");
	Serial.println(irSensors[0]);
	
	// Question 6 Solution
	Serial.print("Question 6: The final value of e is: ");
	Serial.println(e);
}

void loop() {
}

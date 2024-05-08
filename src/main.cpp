#include <Arduino.h>
#define LED_PIN 1

int a = 22;
int b = 40;
int c = 0;

void sendResult(){
	//TODO: send email or push notification
}

// performs a rotation to the left by x numbers
void runPreTest(){
	//TODO: rotate to 90 and back to 0 to confirm functionality
}

void resetLock(){
	//TODO: rotate foure times left
}

void goTo(int n){
	//TODO: implement rotation
}

bool currentIsHigher(){
	//TODO: check current
	return false;
}

bool goToUnlock(){
	//TODO: move 1 rotation to rigth
	return currentIsHigher();
}

void setup() {
	// initialize GPIO 1 as an output.
	pinMode(LED_PIN, OUTPUT);

	runPreTest();

	//Plate B
	for (int i = 40; i < 50; i++){
		//Plate C
		for (int j = 0; j < 100; j++){
			resetLock();

			goTo(a);
			goTo(i);
			goTo(j);

			if (goToUnlock()){
				b = i;
				c = j;
				sendResult();
				return;
			}
		}
	}
}

void loop() {
	// indicate finish
	digitalWrite(LED_PIN, HIGH);	// turn the LED on (HIGH is the voltage level)
	delay(1000);					// wait for a second
	digitalWrite(LED_PIN, LOW);		// turn the LED off by making the voltage LOW
	delay(1000);					// wait for a second
}
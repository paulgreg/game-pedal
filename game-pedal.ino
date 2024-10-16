// https://www.youtube.com/watch?v=xoqoUR1JBr8
// https://www.partsnotincluded.com/how-to-emulate-an-xbox-controller-with-arduino-xinput/
// https://www.reddit.com/r/arduino/comments/1b9cq62/using_arduino_micro_as_a_game_controller_confused/

#include <XInput.h>

int analogPin = A5;

#define DEBUG 0

void setup() {
  Serial.begin(115200);
	XInput.begin();
  XInput.setTriggerRange(0, 512);
}
void loop() {
  int value = analogRead(analogPin);
  if (DEBUG) Serial.println(value);
  XInput.setTrigger(TRIGGER_RIGHT, value);
  delay(10);
}

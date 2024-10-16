// https://www.youtube.com/watch?v=xoqoUR1JBr8
// https://www.partsnotincluded.com/how-to-emulate-an-xbox-controller-with-arduino-xinput/
// https://www.reddit.com/r/arduino/comments/1b9cq62/using_arduino_micro_as_a_game_controller_confused/
// https://github.com/MHeironimus/ArduinoJoystickLibrary


#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, 4, 0,
  false, false, false, false, false, false,
  false, false, true, true, true);

int analogPin = A5;

#define DEBUG 0

void setup() {
  Serial.begin(115200);
	Joystick.begin();
  Joystick.setAcceleratorRange(0, 512);
}
void loop() {
  int value = analogRead(analogPin);
  if (DEBUG) Serial.println(value);
  Joystick.setAccelerator(value);
  delay(10);
}



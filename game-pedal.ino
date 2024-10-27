#include <Joystick.h>

Joystick_ Joystick(
  0x03, // HID report ID
  JOYSTICK_TYPE_JOYSTICK,
  3, // Number of buttons
  0, // Number of hat switches
  true, // X axis
  true, //Y axis
  true, // Z axis
  false, // X rotation
  false, // Y rotation
  false, // Z rotation
  false, // Rudder
  false, // Throttle
  true, // Accelerator pedal
  true, // Brake pedal
  false // Steering wheel
);

int acceleratorPin = A5;
int brakePin = A4;

#define DEBUG 0

void setup() {
  Serial.begin(115200);
	Joystick.begin();
  Joystick.setAcceleratorRange(0, 512);
  Joystick.setBrakeRange(0, 640);
}

int adaptBrakeValue(int v) {
  if (v > 700) return 0;
  return v;
}

void loop() {
  int acceleratorValue = analogRead(acceleratorPin);
  int brakeValue = analogRead(brakePin);
  int adaptedBrakeValue = adaptBrakeValue(brakeValue);

  if (DEBUG) {
    char buffer[50];
    sprintf(buffer, "Accelerator: %d - Brake %d (original: %d)", acceleratorValue, adaptedBrakeValue, brakeValue);
    Serial.println(buffer);
  }

  Joystick.setAccelerator(acceleratorValue);
  Joystick.setBrake(adaptedBrakeValue);

  delay(10);
}



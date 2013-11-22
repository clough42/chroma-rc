#include "hardware.h"
#include "hw_config.h"

const byte rgb_pins[] = {
		PIN_RGB1_R, PIN_RGB1_G, PIN_RGB1_B,
		PIN_RGB2_R, PIN_RGB2_G, PIN_RGB2_B,
		PIN_RGB3_R, PIN_RGB3_G, PIN_RGB3_B,
		PIN_RGB4_R, PIN_RGB4_G, PIN_RGB4_B
};

const int rgb_pins_size = sizeof(rgb_pins)/sizeof(rgb_pins[0]);

void initialize_hardware()
{
  pinMode(PIN_RGB1_R, OUTPUT);
  pinMode(PIN_RGB1_G, OUTPUT);
  pinMode(PIN_RGB1_B, OUTPUT);
  pinMode(PIN_RGB2_R, OUTPUT);
  pinMode(PIN_RGB2_G, OUTPUT);
  pinMode(PIN_RGB2_B, OUTPUT);
  pinMode(PIN_RGB3_R, OUTPUT);
  pinMode(PIN_RGB3_G, OUTPUT);
  pinMode(PIN_RGB3_B, OUTPUT);
  pinMode(PIN_RGB4_R, OUTPUT);
  pinMode(PIN_RGB4_G, OUTPUT);
  pinMode(PIN_RGB4_B, OUTPUT);
  pinMode(PIN_ORIENTATION, OUTPUT);
  pinMode(PIN_LANDING, OUTPUT);
  pinMode(PIN_SERVO_1, INPUT);
  pinMode(PIN_SERVO_2, INPUT);
  pinMode(PIN_JP1, INPUT);
  pinMode(PIN_JP2, INPUT);
  pinMode(PIN_BATT_V, INPUT);
}

void blackout(void) {
	for(int i=0; i < rgb_pins_size; i++) {
		digitalWrite(rgb_pins[i], LOW);
	}
}



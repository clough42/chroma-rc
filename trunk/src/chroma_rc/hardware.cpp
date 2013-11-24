#include "hardware.h"
#include "hw_config.h"
#include "SoftPWM.h"

const byte rgb_pins[] = {
		PIN_RGB1_R, PIN_RGB1_G, PIN_RGB1_B,
		PIN_RGB2_R, PIN_RGB2_G, PIN_RGB2_B,
		PIN_RGB3_R, PIN_RGB3_G, PIN_RGB3_B,
		PIN_RGB4_R, PIN_RGB4_G, PIN_RGB4_B
};

const int rgb_pins_size = sizeof(rgb_pins)/sizeof(rgb_pins[0]);

void blackout(void) {
	SoftPWMSetFadeTime(ALL, 1000, 1000);
	for(int i=0; i < rgb_pins_size; i++) {
		SoftPWMSet(rgb_pins[i],0);
	}
	delay(1100);
}

void self_test(void) {
	SoftPWMSetFadeTime(ALL, 0, 0);
	for(int i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSet(rgb_pins[i],0);
	}
	delay(200);
	for(int i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSet(rgb_pins[i],255);
		delay(100);
		SoftPWMSet(rgb_pins[i],0);
	}
	SoftPWMSetFadeTime(ALL, 200, 200);
	for(int i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSet(rgb_pins[i],255);
	}
	delay(250);
}

void initialize_hardware()
{
	SoftPWMBegin();
	for(int i=0; i < rgb_pins_size; i++ ) {
		pinMode(rgb_pins[i], OUTPUT);
		SoftPWMSet(rgb_pins[i], 0);
	}
	pinMode(PIN_ORIENTATION, OUTPUT);
	pinMode(PIN_LANDING, OUTPUT);
	pinMode(PIN_SERVO_1, INPUT);
	pinMode(PIN_SERVO_2, INPUT);
	pinMode(PIN_JP1, INPUT);
	pinMode(PIN_JP2, INPUT);
	pinMode(PIN_BATT_V, INPUT);
}


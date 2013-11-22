#include <Arduino.h>
#include "hardware.h"
#include "hw_config.h"



byte pins[] = {
		PIN_RGB1_R, PIN_RGB1_G, PIN_RGB1_B,
		PIN_RGB2_R, PIN_RGB2_G, PIN_RGB2_B,
		PIN_RGB3_R, PIN_RGB3_G, PIN_RGB3_B,
		PIN_RGB4_R, PIN_RGB4_G, PIN_RGB4_B
};

byte data[][12] = {
		{ 1,0,0, 1,0,0, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,0,0, 1,0,0 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 0,1,0, 0,1,0, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 0,1,0, 0,1,0 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 0,0,1, 0,0,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 0,0,1, 0,0,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 },
		{ 1,1,1, 1,1,1, 1,1,1, 1,1,1 }
};

byte pos = 0;

void setup()
{
	initialize_hardware();

	digitalWrite(PIN_MONO_X,1);
}

void loop()
{
	if( pos >= sizeof(data)/sizeof(data[0]) ) {
		pos = 0;
	}

	for( byte i=0; i < sizeof(pins)/sizeof(pins[0]); i++ ) {
		digitalWrite(pins[i], data[pos][i]);
	}

	delay(100);

	pos++;
}

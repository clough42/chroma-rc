/*
 * SequenceFixed.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#include "SequenceRedGreenFade.h"
#include "hardware.h"
#include "progmem.h"

static const byte PROGMEM data[][12] = {
		{ 255,0,0, 0,255,0, 0,255,255, 0,255,255 },
		{ 255,0,0, 0,255,0, 0,0,255, 0,0,255 },
		{ 255,0,0, 0,255,0, 255,0,255, 255,0,255 },
		{ 255,0,0, 0,255,0, 255,0,0, 255,0,0 },
		{ 255,0,0, 0,255,0, 255,255,0, 255,255,0 },
		{ 255,0,0, 0,255,0, 0,255,0, 0,255,0 },
};

int SequenceRedGreenFade::advance(void) {
	if( pos >= sizeof(data)/sizeof(data[0]) ) {
		pos = 0;
	}

	for( byte i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSetFadeTime(rgb_pins[i], 4000, 4000);
		SoftPWMSet(rgb_pins[i], readProgmemByte(data[pos],i));
	}

	pos++;

	return 4000;
}

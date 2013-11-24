/*
 * SequenceFixed.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#include "SequenceFixedRedGreenYellow.h"
#include "hardware.h"
#include "progmem.h"
#include "SoftPWM.h"

static const byte PROGMEM data[12] = { 255,0,0, 0,255,0, 255,255,0, 255,255,0 };

#define FADE_TIME 500

int SequenceFixedRedGreenYellow::advance(void) {
	for( byte i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSetFadeTime(rgb_pins[i], FADE_TIME, FADE_TIME);
		SoftPWMSet(rgb_pins[i], readProgmemByte(data,i));
	}

	return FADE_TIME + 100;
}

/*
 * SequenceB.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#include "SequencePulse.h"
#include "hardware.h"
#include "progmem.h"

#define FADE_TIME 1000

static const byte PROGMEM data[][12] = {
		{ 255,  0,  0, 255,  0,  0, 255,  0,255, 255,  0,255 },
		{ 255,  0,  0, 255,  0,  0, 255,  0,  0, 255,  0,  0 },
		{ 255,255,  0, 255,255,  0, 255,  0,  0, 255,  0,  0 },
		{ 255,255,  0, 255,255,  0, 255,255,  0, 255,255,  0 },
		{   0,255,  0,   0,255,  0, 255,255,  0, 255,255,  0 },
		{   0,255,  0,   0,255,  0,   0,255,  0,   0,255,  0 },
		{   0,255,255,   0,255,255,   0,255,  0,   0,255,  0 },
		{   0,255,255,   0,255,255,   0,255,255,   0,255,255 },
		{   0,  0,255,   0,  0,255,   0,255,255,   0,255,255 },
		{   0,  0,255,   0,  0,255,   0,  0,255,   0,  0,255 },
		{ 255,  0,255, 255,  0,255,   0,  0,255,   0,  0,255 },
		{ 255,  0,255, 255,  0,255, 255,  0,255, 255,  0,255 },
};

int SequencePulse::advance(void) {
	if( pos >= sizeof(data)/sizeof(data[0]) ) {
		pos = 0;
	}

	for( byte i=0; i < rgb_pins_size; i++ ) {
		SoftPWMSetFadeTime(rgb_pins[i], FADE_TIME, FADE_TIME);
		SoftPWMSet(rgb_pins[i], readProgmemByte(data[pos],i));
	}

	pos++;

	return FADE_TIME + 100;
}

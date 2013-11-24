/*
 * SequenceFixed.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#include "SequenceFixedA.h"
#include "hardware.h"
#include "progmem.h"

static const byte PROGMEM data[12] = { 1,0,0, 0,1,0, 0,0,1, 0,0,1 };

int SequenceFixedA::advance(void) {
	for( byte i=0; i < rgb_pins_size; i++ ) {
		digitalWrite(rgb_pins[i], readProgmemByte(data,i));
	}

	return 100;
}

/*
 * servo_input.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#include <Arduino.h>
#include "servo_input.h"

// servo values, to be read externally
volatile int servo_input_1_value = 0;
volatile int servo_input_2_value = 0;

void int0Vec(void) {
	static unsigned long startTime = 0;
	if( PIND & 4 ) {
		startTime = micros();
	} else {
		servo_input_1_value = micros() - startTime;
	}
}

void int1Vec(void) {
	static unsigned long startTime = 0;
	if( PIND & 8 ) {
		startTime = micros();
	} else {
		servo_input_2_value = micros() - startTime;
	}
}

void initialize_servo_input() {
	attachInterrupt(0, int0Vec, CHANGE);
	attachInterrupt(1, int1Vec, CHANGE);
}

int mapToRange(int value, int numRanges) {
	// note numRanges - 1
	// this is because we're centering the ranges, making this a fencepost problem
	int rangeSize = (SERVO_MAX-SERVO_MIN) / (numRanges-1);
	return ((value-SERVO_MIN) + (rangeSize/2)) / rangeSize;
}

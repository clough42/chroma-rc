#include <Arduino.h>
#include "hardware.h"
#include "hw_config.h"
#include "servo_input.h"
#include "LightSequence.h"
#include "sequences/SequenceA.h"
#include "sequences/SequenceB.h"

//SequenceA sequenceA;
//SequenceB sequenceB;

LightSequence *sequences[] = {
		new SequenceA(),
		new SequenceB()
};

void setup()
{
	initialize_hardware();
	initialize_servo_input();
}


void loop()
{
	int primaryMode = mapToRange(servo_input_1_value, 3);

	digitalWrite(PIN_ORIENTATION, primaryMode > 0 ? HIGH : LOW);
	digitalWrite(PIN_LANDING, primaryMode > 1 ? HIGH : LOW);

	int delayms = 100;

	if( primaryMode > 0 ) {
		int secondaryMode = mapToRange(servo_input_2_value, sizeof(sequences)/sizeof(sequences[0]));
		delayms = sequences[secondaryMode]->advance();
	} else {
		blackout();
	}

	delay(delayms);
}

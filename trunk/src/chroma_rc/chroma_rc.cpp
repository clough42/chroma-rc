#include <Arduino.h>
#include "hardware.h"
#include "hw_config.h"
#include "servo_input.h"
#include "LightSequence.h"
#include "SequencePulse.h"
#include "SequencePulseThruWhite.h"
#include "SequenceFixedRedGreenWhite.h"
#include "SequenceFixedRedGreenYellow.h"
#include "SequenceRedGreenFade.h"

LightSequence *sequences[] = {
		new SequenceRedGreenFade(),
		new SequencePulse(),
		new SequencePulseThruWhite(),
		new SequenceFixedRedGreenWhite(),
		new SequenceFixedRedGreenYellow(),
};

void setup()
{
	initialize_servo_input();
	initialize_hardware();
	self_test();
	blackout();
}

int getPrimaryMode() {
	return mapToRange(servo_input_1_value, 3);
}

int getSecondaryMode() {
	return mapToRange(servo_input_2_value, sizeof(sequences) / sizeof(sequences[0]));
}

void delayUnlessModeChanges(int primaryMode, int secondaryMode, int delayms) {
	unsigned long targetTime = millis() + delayms;

	while( millis() < targetTime && getPrimaryMode() == primaryMode && getSecondaryMode() == secondaryMode ) {
		delay(min(250, targetTime - millis()));
	}
}

void loop()
{
	int primaryMode = getPrimaryMode();
	int secondaryMode = getSecondaryMode();

	digitalWrite(PIN_ORIENTATION, primaryMode > 0 ? HIGH : LOW);
	digitalWrite(PIN_LANDING, primaryMode > 1 ? HIGH : LOW);

	int delayms = 1000;

	if( primaryMode > 0 ) {
		delayms = sequences[secondaryMode]->advance();
	} else {
		blackout();
	}

	delayUnlessModeChanges(primaryMode, secondaryMode, delayms);
}

#include <Arduino.h>
#include "hardware.h"
#include "hw_config.h"
#include "servo_input.h"
#include "LightSequence.h"
#include "SequenceA.h"
#include "SequenceB.h"
#include "SequenceFixedA.h"
#include "SequenceFixedB.h"
#include "SequenceRedGreenFade.h"

LightSequence *sequences[] = {
		new SequenceRedGreenFade(),
		new SequenceA(),
		new SequenceB(),
		new SequenceFixedA(),
		new SequenceFixedB()
};

void setup()
{
	initialize_hardware();
	initialize_servo_input();
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
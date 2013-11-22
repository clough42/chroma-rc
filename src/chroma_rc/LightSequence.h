/*
 * LightSequence.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef LIGHTSEQUENCE_H_
#define LIGHTSEQUENCE_H_

#include <Arduino.h>

class LightSequence {
protected:
	byte pos;

public:

	virtual ~LightSequence();

	/**
	 * Advance to the next state in the sequence.
	 * Returns the desired delay, in milliseconds.
	 */
	virtual int advance() = 0;
};

#endif /* LIGHTSEQUENCE_H_ */

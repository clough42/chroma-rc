/*
 * SequenceA.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEPULSETHRUWHITE_H_
#define SEQUENCEPULSETHRUWHITE_H_

#include <Arduino.h>
#include "LightSequence.h"

class SequencePulseThruWhite: public LightSequence {
public:
	virtual int advance(void);

};

#endif /* SEQUENCEPULSETHRUWHITE_H_ */

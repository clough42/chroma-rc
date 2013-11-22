/*
 * SequenceA.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEA_H_
#define SEQUENCEA_H_

#include <Arduino.h>
#include "LightSequence.h"

class SequenceA: public LightSequence {
public:
	virtual int advance(void);

};

#endif /* SEQUENCEA_H_ */

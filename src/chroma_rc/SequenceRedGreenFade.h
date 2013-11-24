/*
 * SequenceFixedB.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEREDGREENFADE_H_
#define SEQUENCEREDGREENFADE_H_

#include "LightSequence.h"

class SequenceRedGreenFade: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEREDGREENFADE_H_ */

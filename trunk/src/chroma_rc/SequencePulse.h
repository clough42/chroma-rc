/*
 * SequenceB.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEPULSE_H_
#define SEQUENCEPULSE_H_

#include "LightSequence.h"

class SequencePulse: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEPULSE_H_ */

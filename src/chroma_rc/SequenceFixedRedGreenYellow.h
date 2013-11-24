/*
 * SequenceFixed.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEFIXEDREDGREENYELLOW_H_
#define SEQUENCEFIXEDREDGREENYELLOW_H_

#include "LightSequence.h"

class SequenceFixedRedGreenYellow: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEFIXEDREDGREENYELLOW_H_ */

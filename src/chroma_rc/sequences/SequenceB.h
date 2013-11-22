/*
 * SequenceB.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEB_H_
#define SEQUENCEB_H_

#include "../LightSequence.h"

class SequenceB: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEB_H_ */

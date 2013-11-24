/*
 * SequenceFixedB.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEFIXEDB_H_
#define SEQUENCEFIXEDREDGREENWHITE_H_

#include "LightSequence.h"

class SequenceFixedRedGreenWhite: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEFIXEDB_H_ */

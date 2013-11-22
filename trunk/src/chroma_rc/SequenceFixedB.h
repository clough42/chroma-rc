/*
 * SequenceFixedB.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SEQUENCEFIXEDB_H_
#define SEQUENCEFIXEDB_H_

#include "LightSequence.h"

class SequenceFixedB: public LightSequence {
public:
	virtual int advance(void);
};

#endif /* SEQUENCEFIXEDB_H_ */

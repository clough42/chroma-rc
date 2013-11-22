/*
 * servo_input.h
 *
 *  Created on: Nov 21, 2013
 *      Author: clough
 */

#ifndef SERVO_INPUT_H_
#define SERVO_INPUT_H_

#define SERVO_MIN 1112
#define SERVO_MAX 1908

// globals that are maintained with the current servo values
extern volatile int servo_input_1_value;
extern volatile int servo_input_2_value;

void initialize_servo_input();
int mapToRange(int value, int numRanges);

#endif /* SERVO_INPUT_H_ */

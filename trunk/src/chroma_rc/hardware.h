#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <Arduino.h>

extern const byte rgb_pins[];
extern const int rgb_pins_size;

void initialize_hardware();
void blackout();

#endif // _HARDWARE_H_

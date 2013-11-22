#include <Arduino.h>

#ifndef _HW_CONFIG_H_
#define _HW_CONFIG_H_

/* RGB Channel 1 */
#define PIN_RGB1_R A2
#define PIN_RGB1_G A1
#define PIN_RGB1_B A3

/* RGB Channel 2 */
#define PIN_RGB2_R 12
#define PIN_RGB2_G 13
#define PIN_RGB2_B 11

/* RGB Channel 3 */
#define PIN_RGB3_R 5
#define PIN_RGB3_G 6
#define PIN_RGB3_B 4

/* RGB Channel 4 */
#define PIN_RGB4_R 9
#define PIN_RGB4_G 8
#define PIN_RGB4_B 10

/* Mono Channels */
#define PIN_ORIENTATION A0
#define PIN_LANDING 7

/* Servos */
#define PIN_SERVO_1 2
#define PIN_SERVO_2 3

/* Configuration Jumpers */
#define PIN_JP1 A7
#define PIN_JP2 A6

/* Battery Voltage Monitoring */
#define PIN_BATT_V A5

#endif

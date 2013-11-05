#include <Arduino.h>
#include "hw_config.h"

void setup()
{
  pinMode(PIN_RGB1_R, OUTPUT);
  pinMode(PIN_RGB1_G, OUTPUT);
  pinMode(PIN_RGB1_B, OUTPUT);
  pinMode(PIN_RGB2_R, OUTPUT);
  pinMode(PIN_RGB2_G, OUTPUT);
  pinMode(PIN_RGB2_B, OUTPUT);
  pinMode(PIN_RGB3_R, OUTPUT);
  pinMode(PIN_RGB3_G, OUTPUT);
  pinMode(PIN_RGB3_B, OUTPUT);
  pinMode(PIN_RGB4_R, OUTPUT);
  pinMode(PIN_RGB4_G, OUTPUT);
  pinMode(PIN_RGB4_B, OUTPUT);
  pinMode(PIN_MONO_X, OUTPUT);
  pinMode(PIN_MONO_Y, OUTPUT);
  pinMode(PIN_SERVO_1, INPUT);
  pinMode(PIN_SERVO_2, INPUT);
  pinMode(PIN_JP1, INPUT_PULLUP);
  pinMode(PIN_JP2, INPUT_PULLUP);
  pinMode(PIN_BATT_V, INPUT);
}


void loop()
{
  
}

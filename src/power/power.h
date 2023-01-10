#pragma once
#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_INA219.h"
#include "TeensyTimerTool.h"




using namespace TeensyTimerTool;




extern const float POWER_MON_FREQ;
extern const float POWER_MON_PERIOD;




extern PeriodicTimer powerMonTimer;
extern Adafruit_INA219 ina219;




extern float shuntvoltage;
extern float busvoltage;
extern float current_mA;
extern float loadvoltage;
extern float power_mW;




FASTRUN void powerMon();

void setupPowerMon();




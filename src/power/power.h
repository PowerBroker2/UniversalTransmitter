#pragma once
#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_INA219.h"
#include "TeensyTimerTool.h"




using namespace TeensyTimerTool;




const float POWER_MON_FREQ   = 2; // Hz
const float POWER_MON_PERIOD = 1.0 / POWER_MON_FREQ; // s




PeriodicTimer powerMonTimer;
Adafruit_INA219 ina219;




float shuntvoltage = 0;
float busvoltage   = 0;
float current_mA   = 0;
float loadvoltage  = 0;
float power_mW     = 0;




FASTRUN void powerMon()
{
    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage   = ina219.getBusVoltage_V();
    current_mA   = ina219.getCurrent_mA();
    power_mW     = ina219.getPower_mW();
    loadvoltage  = busvoltage + (shuntvoltage / 1000);
}




void setupPowerMon()
{
    ina219.begin();
    powerMonTimer.begin(powerMon, POWER_MON_PERIOD * 1e6);
}




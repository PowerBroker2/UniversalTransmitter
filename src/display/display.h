#pragma once
#include "Arduino.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "TeensyTimerTool.h"




using namespace TeensyTimerTool;




extern const float TOUCH_FREQ;
extern const float TOUCH_PERIOD;

extern const int DISP_CS_PIN;
extern const int DC_PIN;
extern const int T_CS_PIN;
extern const int T_IRQ_PIN;

extern volatile const int TOUCH_TIME_THRESH;




extern PeriodicTimer       touchTimer;
extern XPT2046_Touchscreen ts;
extern Adafruit_ILI9341    tft;
extern TS_Point            ts_point;




extern volatile long time_touched;
extern volatile bool touch_handled;




void enableTS();
void enableTFT();
void disableTS();
void disableTFT();
void disableDisp();

FASTRUN void __attribute__((weak)) whenTouched();

void setupDisplay();




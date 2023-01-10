#pragma once
#include "Arduino.h"




extern const volatile int BUDDY_PIN;
extern const volatile int MIN_PULSE_LEN;
extern const volatile int MAX_PULSE_LEN;
extern const volatile int MAX_TDIFF;
extern const int MAX_CHANNELS;
extern const volatile int MAX_CHANNELS_LESS_ONE;
extern volatile long buddy_channel[];
extern volatile int channel_num;
extern volatile int max_channel_num;
extern volatile long startMicros;
extern volatile bool state;




FASTRUN void BUDDY_ISR();

void setupBuddy();
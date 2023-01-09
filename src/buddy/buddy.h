#pragma once
#include "Arduino.h"




const volatile int BUDDY_PIN     = 26;
const volatile int MIN_PULSE_LEN = 600;
const volatile int MAX_PULSE_LEN = 1600;
const volatile int MAX_TDIFF     = MAX_PULSE_LEN * (1 + 0.1);
const int MAX_CHANNELS           = 32;
const volatile int MAX_CHANNELS_LESS_ONE = MAX_CHANNELS - 1;

volatile long buddy_channel[MAX_CHANNELS];
volatile int channel_num      = 0;
volatile int max_channel_num  = 0;
volatile long startMicros     = 0;
volatile bool state           = 0;




FASTRUN void BUDDY_ISR()
{
	state = digitalReadFast(BUDDY_PIN);
	
	if(state == HIGH)
	{
		startMicros = micros();
	}
	else
	{
		long tdiff = micros() - startMicros;
	
		if (tdiff > MAX_TDIFF)
		{
			if (channel_num < max_channel_num)
			{
				max_channel_num = channel_num;
			}

			channel_num = 0;
		}
		else if (channel_num < MAX_CHANNELS_LESS_ONE)
		{
			buddy_channel[channel_num] = tdiff;
			
			channel_num += 1;

			if (channel_num > max_channel_num)
			{
				max_channel_num = channel_num;
			}
		}
	}
}




void setupBuddy()
{
	pinMode(26, INPUT);
	attachInterrupt(26, BUDDY_ISR, CHANGE);
}




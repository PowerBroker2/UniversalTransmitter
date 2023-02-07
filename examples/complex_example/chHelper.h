#pragma once




int minPitchADC    = 420;
int maxPitchADC    = 3930;
int minRollADC     = 175;
int maxRollADC     = 3815;
int minYawADC      = 165;
int maxYawADC      = 3750;
int minThrottleADC = 430;
int maxThrottleADC = 4000;
int minKnob1ADC    = 0;
int maxKnob1ADC    = 4090;
int minKnob2ADC    = 0;
int maxKnob2ADC    = 4090;

int expoDiff = 10;
int mixDiff  = 5;

int chVal = 0;

bool chChangeFlag          = false;
bool chReverseChangeFlag   = false;
bool expoChangeFlag        = false;
bool chMixFirstChangeFlag  = false;
bool chMixSecondChangeFlag = false;
bool chMixValChangeFlag    = false;

int chVal1Mix = 0;
int chVal2Mix = 0;

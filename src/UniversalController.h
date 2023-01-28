#pragma once
#include "Arduino.h"




class UniversalController
{
public: // <<---------------------------------------//public




	void begin();

	int numBuddyChannels();
	int buddyChannel(const int& channelNum);

	int sw1State();
	int sw2State();
	int sw3State();
	int sw4State();
	int sw5State();
	int sw6State();
	int triSwAState();
	int triSwBState();
	
	bool sw1SwitchFlag();
	bool sw2SwitchFlag();
	bool sw3SwitchFlag();
	bool sw4SwitchFlag();
	bool sw5SwitchFlag();
	bool sw6SwitchFlag();
	bool triSwASwitchFlag();
	bool triSwBSwitchFlag();
	
	void clearsw1SwitchFlag();
	void clearsw2SwitchFlag();
	void clearsw3SwitchFlag();
	void clearsw4SwitchFlag();
	void clearsw5SwitchFlag();
	void clearsw6SwitchFlag();
	void cleartriSwASwitchFlag();
	void cleartriSwBSwitchFlag();

	float pitchTrim();
	float rollTrim();
	float yawTrim();
	float throttleTrim();

	bool pitchTrimFlag();
	bool rollTrimFlag();
	bool yawTrimFlag();
	bool throttleTrimFlag();

	void clearPitchTrimFlag();
	void clearRollTrimFlag();
	void clearYawTrimFlag();
	void clearThrottleTrimFlag();

	void setPitchADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));
	void setRollADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));
	void setYawADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));
	void setThrottleADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));
	void setKnob1ADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));
	void setKnob2ADCLimits(const int& minADC = 0, const int& maxADC = pow(2, 12));

	int minPitchADC();
	int maxPitchADC();
	int minRollADC();
	int maxRollADC();
	int minYawADC();
	int maxYawADC();
	int minThrottleADC();
	int maxThrottleADC();
	int minKnob1ADC();
	int maxKnob1ADC();
	int minKnob2ADC();
	int maxKnob2ADC();

	float pitchJoy();
	float rollJoy();
	float yawJoy();
	float throttleJoy();

	float knob1();
	float knob2();

	float shuntVoltage();
	float busVoltage();
	float current();
	float power();
	float loadVoltage();

	bool  wasTouched();
	void  clearTouch();
	float touchX();
	float touchY();
	float touchPressure();

	float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
	float expo(float input, float expo);




private: // <<---------------------------------------//private



	int _minPitchADC    = 0;
	int _maxPitchADC    = pow(2, 12);
	int _minRollADC     = 0;
	int _maxRollADC     = pow(2, 12);
	int _minYawADC      = 0;
	int _maxYawADC      = pow(2, 12);
	int _minThrottleADC = 0;
	int _maxThrottleADC = pow(2, 12);
	int _minKnob1ADC    = 0;
	int _maxKnob1ADC    = pow(2, 12);
	int _minKnob2ADC    = 0;
	int _maxKnob2ADC    = pow(2, 12);
};




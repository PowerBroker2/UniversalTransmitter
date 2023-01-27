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




private: // <<---------------------------------------//private



	float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
};




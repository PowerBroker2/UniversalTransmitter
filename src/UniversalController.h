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

	int pitchJoy();
	int rollJoy();
	int yawJoy();
	int throttleJoy();

	int knob1();
	int knob2();

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




};




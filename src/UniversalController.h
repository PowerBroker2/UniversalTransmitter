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




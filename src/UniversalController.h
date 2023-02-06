#pragma once
#include "Arduino.h"
#include "inputs/inputs.h"




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
	
	void clearSw1SwitchFlag();
	void clearSw2SwitchFlag();
	void clearSw3SwitchFlag();
	void clearSw4SwitchFlag();
	void clearSw5SwitchFlag();
	void clearSw6SwitchFlag();
	void clearTriSwASwitchFlag();
	void clearTriSwBSwitchFlag();

	void setPitchTrim(const float& trim);
	void setRollTrim(const float& trim);
	void setYawTrim(const float& trim);
	void setThrottleTrim(const float& trim);

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

	float getVal(channel& inputCh);

	float pitchJoy();
	float rollJoy();
	float yawJoy();
	float throttleJoy();

	float knob1();
	float knob2();

	void  useHighRates();
	void  setHighRates(const float& rate);
	float getHighRates();
	void  useLowRates();
	void  setLowRates(const float& rate);
	float getLowRates();

	void setPitchExpo(const float& _expo);
	void setRollExpo(const float& _expo);
	void setYawExpo(const float& _expo);
	void setThrottleExpo(const float& _expo);
	void setKnob1Expo(const float& _expo);
	void setKnob2Expo(const float& _expo);

	float getPitchExpo();
	float getRollExpo();
	float getYawExpo();
	float getThrottleExpo();
	float getKnob1Expo();
	float getKnob2Expo();

	void setPitchMixCh(const int& chNum);
	void setRollMixCh(const int& chNum);
	void setYawMixCh(const int& chNum);
	void setThrottleMixCh(const int& chNum);
	void setKnob1MixCh(const int& chNum);
	void setKnob2MixCh(const int& chNum);
	void setSw1MixCh(const int& chNum);
	void setSw2MixCh(const int& chNum);
	void setSw3MixCh(const int& chNum);
	void setSw4MixCh(const int& chNum);
	void setSw5MixCh(const int& chNum);
	void setSw6MixCh(const int& chNum);
	void setTriSwAMixCh(const int& chNum);
	void setTriSwBMixCh(const int& chNum);

	int getPitchMixCh();
	int getRollMixCh();
	int getYawMixCh();
	int getThrottleMixCh();
	int getKnob1MixCh();
	int getKnob2MixCh();
	int getSw1MixCh();
	int getSw2MixCh();
	int getSw3MixCh();
	int getSw4MixCh();
	int getSw5MixCh();
	int getSw6MixCh();
	int getTriSwAMixCh();
	int getTriSwBMixCh();

	void setPitchMix(const float& mix);
	void setRollMix(const float& mix);
	void setYawMix(const float& mix);
	void setThrottleMix(const float& mix);
	void setKnob1Mix(const float& mix);
	void setKnob2Mix(const float& mix);
	void setSw1Mix(const float& mix);
	void setSw2Mix(const float& mix);
	void setSw3Mix(const float& mix);
	void setSw4Mix(const float& mix);
	void setSw5Mix(const float& mix);
	void setSw6Mix(const float& mix);
	void setTriSwAMix(const float& mix);
	void setTriSwBMix(const float& mix);

	int getPitchMix();
	int getRollMix();
	int getYawMix();
	int getThrottleMix();
	int getKnob1Mix();
	int getKnob2Mix();
	int getSw1Mix();
	int getSw2Mix();
	int getSw3Mix();
	int getSw4Mix();
	int getSw5Mix();
	int getSw6Mix();
	int getTriSwAMix();
	int getTriSwBMix();

	void setPitchReverse(const bool& reverse);
	void setRollReverse(const bool& reverse);
	void setYawReverse(const bool& reverse);
	void setThrottleReverse(const bool& reverse);
	void setKnob1Reverse(const bool& reverse);
	void setKnob2Reverse(const bool& reverse);
	void setSw1Reverse(const bool& reverse);
	void setSw2Reverse(const bool& reverse);
	void setSw3Reverse(const bool& reverse);
	void setSw4Reverse(const bool& reverse);
	void setSw5Reverse(const bool& reverse);
	void setSw6Reverse(const bool& reverse);
	void setTriSwAReverse(const bool& reverse);
	void setTriSwBReverse(const bool& reverse);

	bool getPitchReverse();
	bool getRollReverse();
	bool getYawReverse();
	bool getThrottleReverse();
	bool getKnob1Reverse();
	bool getKnob2Reverse();
	bool getSw1Reverse();
	bool getSw2Reverse();
	bool getSw3Reverse();
	bool getSw4Reverse();
	bool getSw5Reverse();
	bool getSw6Reverse();
	bool getTriSwAReverse();
	bool getTriSwBReverse();

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

	float expo(const float& input, const float& expo);




private: // <<---------------------------------------//private
};




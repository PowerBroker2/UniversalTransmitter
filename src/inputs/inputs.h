#pragma once
#include "Arduino.h"
#include "OneButton.h"




/*
* ****************** Switches ******************
*/
extern const int SW_1_PIN;
extern const int SW_2_PIN;
extern const int SW_3_PIN;
extern const int SW_4_PIN;
extern const int SW_5_PIN;
extern const int SW_6_PIN;

extern const int TRI_SW_A_PIN;
extern const int TRI_SW_B_PIN;

extern int sw_1_state;
extern int sw_2_state;
extern int sw_3_state;
extern int sw_4_state;
extern int sw_5_state;
extern int sw_6_state;

extern int tri_sw_a_state;
extern int tri_sw_b_state;

extern volatile bool sw_1_switched;
extern volatile bool sw_2_switched;
extern volatile bool sw_3_switched;
extern volatile bool sw_4_switched;
extern volatile bool sw_5_switched;
extern volatile bool sw_6_switched;

extern volatile bool tri_sw_a_switched;
extern volatile bool tri_sw_b_switched;




FASTRUN void SW1ISR();
FASTRUN void SW2ISR();
FASTRUN void SW3ISR();
FASTRUN void SW4ISR();
FASTRUN void SW5ISR();
FASTRUN void SW6ISR();

FASTRUN void TRISWAISR();
FASTRUN void TRISWBISR();

void setupSwitches();




/*
* ****************** Buttons ******************
*/
extern const float TRIM_BTN_FREQ;
extern const float TRIM_BTN_PERIOD;

extern const int PITCH_TRIM_UP_PIN;
extern const int PITCH_TRIM_DOWN_PIN;
extern const int ROLL_TRIM_RIGHT_PIN;
extern const int ROLL_TRIM_LEFT_PIN;
extern const int YAW_TRIM_RIGHT_PIN;
extern const int YAW_TRIM_LEFT_PIN;
extern const int THROTTLE_TRIM_UP_PIN;
extern const int THROTTLE_TRIM_DOWN_PIN;

extern const int MAX_PITCH_TRIM;
extern const int MIN_PITCH_TRIM;

extern const int MAX_ROLL_TRIM;
extern const int MIN_ROLL_TRIM;

extern const int MAX_YAW_TRIM;
extern const int MIN_YAW_TRIM;

extern const int MAX_THROTTLE_TRIM;
extern const int MIN_THROTTLE_TRIM;

extern const float TRIM_UPDATE_VAL;




extern OneButton pitch_trim_up;
extern OneButton pitch_trim_down;
extern OneButton roll_trim_right;
extern OneButton roll_trim_left;
extern OneButton yaw_trim_right;
extern OneButton yaw_trim_left;
extern OneButton throttle_trim_up;
extern OneButton throttle_trim_down;




extern volatile float pitchTrimVal;
extern volatile float rollTrimVal;
extern volatile float yawTrimVal;
extern volatile float throttleTrimVal;

extern volatile bool pitchTrimValUpdated;
extern volatile bool rollTrimValUpdated;
extern volatile bool yawTrimValUpdated;
extern volatile bool throttleTrimValUpdated;




FASTRUN void CHECK_PITCH_TRIM_UP();
FASTRUN void CHECK_PITCH_TRIM_DOWN();
FASTRUN void CHECK_ROLL_TRIM_RIGHT();
FASTRUN void CHECK_ROLL_TRIM_LEFT();
FASTRUN void CHECK_YAW_TRIM_RIGHT();
FASTRUN void CHECK_YAW_TRIM_LEFT();
FASTRUN void CHECK_THROTTLE_TRIM_UP();
FASTRUN void CHECK_THROTTLE_TRIM_DOWN();

FASTRUN void checkTrimBtns();

FASTRUN void __attribute__((weak)) pitch_trim_up_click();
FASTRUN void __attribute__((weak)) pitch_trim_down_click();
FASTRUN void __attribute__((weak)) roll_trim_right_click();
FASTRUN void __attribute__((weak)) roll_trim_left_click();
FASTRUN void __attribute__((weak)) yaw_trim_right_click();
FASTRUN void __attribute__((weak)) yaw_trim_left_click();
FASTRUN void __attribute__((weak)) throttle_trim_up_click();
FASTRUN void __attribute__((weak)) throttle_trim_down_click();
FASTRUN void __attribute__((weak)) pitch_trim_up_long_click();
FASTRUN void __attribute__((weak)) pitch_trim_down_long_click();
FASTRUN void __attribute__((weak)) roll_trim_right_long_click();
FASTRUN void __attribute__((weak)) roll_trim_left_long_click();
FASTRUN void __attribute__((weak)) yaw_trim_right_long_click();
FASTRUN void __attribute__((weak)) yaw_trim_left_long_click();
FASTRUN void __attribute__((weak)) throttle_trim_up_long_click();
FASTRUN void __attribute__((weak)) throttle_trim_down_long_click();

void setupButtons();




/*
* ****************** Joysticks ******************
*/
extern const int PITCH_PIN;
extern const int ROLL_PIN;
extern const int YAW_PIN;
extern const int THROTTLE_PIN;




void setupJoys();




/*
* ****************** Knobs ******************
*/
extern const int KNOB_1_PIN;
extern const int KNOB_2_PIN;




void setupKnobs();




/*
* ****************** General ******************
*/
extern const int ANALOG_RESOLUTION;

extern const float INPUT_MON_FREQ;
extern const float INPUT_MON_PERIOD;

extern const int NUM_CHS;

extern const int PITCH_CH;
extern const int ROLL_CH;
extern const int YAW_CH;
extern const int THROTTLE_CH;
extern const int KNOB_1_CH;
extern const int KNOB_2_CH;
extern const int SW_1_CH;
extern const int SW_2_CH;
extern const int SW_3_CH;
extern const int SW_4_CH;
extern const int SW_5_CH;
extern const int SW_6_CH;
extern const int TRI_A_CH;
extern const int TRI_B_CH;

extern const float CH_MAX;
extern const float CH_MIN;

extern const float EXPO_MAX;
extern const float EXPO_MIN;

extern const float MIX_MAX;
extern const float MIX_MIN;




class channel
{
public: // <<---------------------------------------//public
	void  setPinNum(const int& _pinNum);
	int   getPinNum();
	void  setChNum(const int& _chNum);
	int   getChNum();
    void  setIsAn(const bool& _isAnalog);
    bool  getIsAn();
    void  setMaxADC(const int& _maxADC);
    int   getMaxADC();
    void  setMinADC(const int& _minADC);
    int   getMinADC();
	void  setMixChNum(const int& _mixChNum);
	float getMixChNum();
	void  setMix(const float& _mixVal);
	float getMix();
	void  setReverse(const bool& _reverse);
	bool  getReverse();
	void  setExpo(const float& _expo);
	float getExpo();
	void  update();
    float getRaw();
	float getReversed();
	float getReversed_expo();
	void  useHighRates();
	void  setHighRate(const float& _highRate);
	float getHighRate();
	void  useLowRates();
	void  setLowRate(const float& _lowRate);
	float getLowRate();

private: // <<---------------------------------------//private
	int pinNum;
	int chNum;

    bool isAnalog = true;
    int  maxADC   = pow(2, 12);
    int  minADC   = 0;

	int   mixChNum;
	float mixVal;
	bool  reverse;
	float expo;

	float raw;
	float reversed;
	float reversed_expo;

	bool  useLowRate = false;
	float lowRate    = 0.8;
	float highRate   = 1.0;
};

extern channel pitch_ch;
extern channel roll_ch;
extern channel yaw_ch;
extern channel throttle_ch;
extern channel knob1_ch;
extern channel knob2_ch;
extern channel sw_1_ch;
extern channel sw_2_ch;
extern channel sw_3_ch;
extern channel sw_4_ch;
extern channel sw_5_ch;
extern channel sw_6_ch;
extern channel tri_sw_a_ch;
extern channel tri_sw_b_ch;




void checkInputs();
void setupInputs();
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
float applyExpo(const float& input, const float& expo);




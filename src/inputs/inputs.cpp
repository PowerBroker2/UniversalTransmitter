#include "Arduino.h"
#include "OneButton.h"
#include "TeensyTimerTool.h"
#include "inputs.h"




using namespace TeensyTimerTool;




/*
* ****************** Switches ******************
*/
extern const int SW_1_PIN = 3;
extern const int SW_2_PIN = 4;
extern const int SW_3_PIN = 5;
extern const int SW_4_PIN = 6;
extern const int SW_5_PIN = 23;
extern const int SW_6_PIN = 22;

extern const int TRI_SW_A_PIN = 27;
extern const int TRI_SW_B_PIN = 28;




channel sw_1_ch;
channel sw_2_ch;
channel sw_3_ch;
channel sw_4_ch;
channel sw_5_ch;
channel sw_6_ch;
channel tri_sw_a_ch;
channel tri_sw_b_ch;




int sw_1_state = 0;
int sw_2_state = 0;
int sw_3_state = 0;
int sw_4_state = 0;
int sw_5_state = 0;
int sw_6_state = 0;

int tri_sw_a_state = 0;
int tri_sw_b_state = 0;

volatile bool sw_1_switched;
volatile bool sw_2_switched;
volatile bool sw_3_switched;
volatile bool sw_4_switched;
volatile bool sw_5_switched;
volatile bool sw_6_switched;

volatile bool tri_sw_a_switched;
volatile bool tri_sw_b_switched;




FASTRUN void SW1ISR()
{
	int prevState = sw_1_state;
	sw_1_state = digitalReadFast(SW_1_PIN);

	if (prevState != sw_1_state)
	{
		sw_1_switched = true;
	}
}

FASTRUN void SW2ISR()
{
	int prevState = sw_2_state;
	sw_2_state = digitalReadFast(SW_2_PIN);

	if (prevState != sw_2_state)
	{
		sw_2_switched = true;
	}
}

FASTRUN void SW3ISR()
{
	int prevState = sw_3_state;
	sw_3_state = digitalReadFast(SW_3_PIN);

	if (prevState != sw_3_state)
	{
		sw_3_switched = true;
	}
}

FASTRUN void SW4ISR()
{
	int prevState = sw_4_state;
	sw_4_state = digitalReadFast(SW_4_PIN);

	if (prevState != sw_4_state)
	{
		sw_4_switched = true;
	}
}

FASTRUN void SW5ISR()
{
	int prevState = sw_5_state;
	sw_5_state = digitalReadFast(SW_5_PIN);

	if (prevState != sw_5_state)
	{
		sw_5_switched = true;
	}
}

FASTRUN void SW6ISR()
{
	int prevState = sw_6_state;
	sw_6_state = digitalReadFast(SW_6_PIN);

	if (prevState != sw_6_state)
	{
		sw_6_switched = true;
	}
}


FASTRUN void TRISWAISR()
{
	int prevState = tri_sw_a_state;
	tri_sw_a_state = digitalReadFast(TRI_SW_A_PIN);

	if (prevState != tri_sw_a_state)
	{
		tri_sw_a_switched = true;
	}
}

FASTRUN void TRISWBISR()
{
	int prevState = tri_sw_b_state;
	tri_sw_b_state = digitalReadFast(TRI_SW_B_PIN);

	if (prevState != tri_sw_b_state)
	{
		tri_sw_b_switched = true;
	}
}





void setupSwitches()
{
	pinMode(SW_1_PIN, INPUT_PULLUP);
	pinMode(SW_2_PIN, INPUT_PULLUP);
	pinMode(SW_3_PIN, INPUT_PULLUP);
	pinMode(SW_4_PIN, INPUT_PULLUP);
	pinMode(SW_5_PIN, INPUT_PULLUP);
	pinMode(SW_6_PIN, INPUT_PULLUP);

	pinMode(TRI_SW_A_PIN, INPUT_PULLUP);
	pinMode(TRI_SW_B_PIN, INPUT_PULLUP);

	delay(1); // SW 4 doesn't initialize correctly without this for some reason

	sw_1_state = digitalReadFast(SW_1_PIN);
	sw_2_state = digitalReadFast(SW_2_PIN);
	sw_3_state = digitalReadFast(SW_3_PIN);
	sw_4_state = digitalReadFast(SW_4_PIN);
	sw_5_state = digitalReadFast(SW_5_PIN);
	sw_6_state = digitalReadFast(SW_6_PIN);

	tri_sw_a_state = digitalReadFast(TRI_SW_A_PIN);
	tri_sw_b_state = digitalReadFast(TRI_SW_B_PIN);
	
	attachInterrupt(SW_1_PIN, SW1ISR, CHANGE);
	attachInterrupt(SW_2_PIN, SW2ISR, CHANGE);
	attachInterrupt(SW_3_PIN, SW3ISR, CHANGE);
	attachInterrupt(SW_4_PIN, SW4ISR, CHANGE);
	attachInterrupt(SW_5_PIN, SW5ISR, CHANGE);
	attachInterrupt(SW_6_PIN, SW6ISR, CHANGE);

	attachInterrupt(TRI_SW_A_PIN, TRISWAISR, CHANGE);
	attachInterrupt(TRI_SW_B_PIN, TRISWBISR, CHANGE);

	sw_1_ch.setPinNum(SW_1_PIN);
	sw_1_ch.setChNum(SW_1_CH);
	sw_1_ch.setIsAn(false);

	sw_2_ch.setPinNum(SW_2_PIN);
	sw_2_ch.setChNum(SW_2_CH);
	sw_2_ch.setIsAn(false);

	sw_3_ch.setPinNum(SW_3_PIN);
	sw_3_ch.setChNum(SW_3_CH);
	sw_3_ch.setIsAn(false);

	sw_4_ch.setPinNum(SW_4_PIN);
	sw_4_ch.setChNum(SW_4_CH);
	sw_4_ch.setIsAn(false);

	sw_5_ch.setPinNum(SW_5_PIN);
	sw_5_ch.setChNum(SW_5_CH);
	sw_5_ch.setIsAn(false);

	sw_6_ch.setPinNum(SW_6_PIN);
	sw_6_ch.setChNum(SW_6_CH);
	sw_6_ch.setIsAn(false);

	tri_sw_a_ch.setPinNum(TRI_SW_A_PIN);
	tri_sw_a_ch.setChNum(TRI_A_CH);
	tri_sw_a_ch.setIsAn(false);

	tri_sw_b_ch.setPinNum(TRI_SW_B_PIN);
	tri_sw_b_ch.setChNum(TRI_B_CH);
	tri_sw_b_ch.setIsAn(false);
}




/*
* ****************** Buttons ******************
*/
extern const int PITCH_TRIM_UP_PIN      = 34;
extern const int PITCH_TRIM_DOWN_PIN    = 33;
extern const int ROLL_TRIM_RIGHT_PIN    = 31;
extern const int ROLL_TRIM_LEFT_PIN     = 32;
extern const int YAW_TRIM_RIGHT_PIN     = 36;
extern const int YAW_TRIM_LEFT_PIN      = 35;
extern const int THROTTLE_TRIM_UP_PIN   = 38;
extern const int THROTTLE_TRIM_DOWN_PIN = 37;

extern const int MAX_PITCH_TRIM =  1;
extern const int MIN_PITCH_TRIM = -1;

extern const int MAX_ROLL_TRIM =  1;
extern const int MIN_ROLL_TRIM = -1;

extern const int MAX_YAW_TRIM =  1;
extern const int MIN_YAW_TRIM = -1;

extern const int MAX_THROTTLE_TRIM =  1;
extern const int MIN_THROTTLE_TRIM = -1;

extern const float TRIM_UPDATE_VAL = 0.01;




OneButton pitch_trim_up = OneButton(
	PITCH_TRIM_UP_PIN,    // Input pin for the button
	true,                 // Button is active LOW
	true                  // Enable internal pull-up resistor
);

OneButton pitch_trim_down = OneButton(
	PITCH_TRIM_DOWN_PIN,    // Input pin for the button
	true,                   // Button is active LOW
	true                    // Enable internal pull-up resistor
);

OneButton roll_trim_right = OneButton(
	ROLL_TRIM_RIGHT_PIN,   // Input pin for the button
	true,                  // Button is active LOW
	true                   // Enable internal pull-up resistor
);

OneButton roll_trim_left = OneButton(
	ROLL_TRIM_LEFT_PIN,    // Input pin for the button
	true,                  // Button is active LOW
	true                   // Enable internal pull-up resistor
);

OneButton yaw_trim_right = OneButton(
	YAW_TRIM_RIGHT_PIN,   // Input pin for the button
	true,                 // Button is active LOW
	true                  // Enable internal pull-up resistor
);

OneButton yaw_trim_left = OneButton(
	YAW_TRIM_LEFT_PIN,    // Input pin for the button
	true,                 // Button is active LOW
	true                  // Enable internal pull-up resistor
);

OneButton throttle_trim_up = OneButton(
	THROTTLE_TRIM_UP_PIN,    // Input pin for the button
	true,                    // Button is active LOW
	true                     // Enable internal pull-up resistor
);

OneButton throttle_trim_down = OneButton(
	THROTTLE_TRIM_DOWN_PIN,    // Input pin for the button
	true,                      // Button is active LOW
	true                       // Enable internal pull-up resistor
);




volatile float pitchTrimVal    = 0;
volatile float rollTrimVal     = 0;
volatile float yawTrimVal      = 0;
volatile float throttleTrimVal = 0;

volatile bool pitchTrimValUpdated;
volatile bool rollTrimValUpdated;
volatile bool yawTrimValUpdated;
volatile bool throttleTrimValUpdated;




FASTRUN void CHECK_PITCH_TRIM_UP()      { pitch_trim_up.tick();      }
FASTRUN void CHECK_PITCH_TRIM_DOWN()    { pitch_trim_down.tick();    }
FASTRUN void CHECK_ROLL_TRIM_RIGHT()    { roll_trim_right.tick();    }
FASTRUN void CHECK_ROLL_TRIM_LEFT()     { roll_trim_left.tick();     }
FASTRUN void CHECK_YAW_TRIM_RIGHT()     { yaw_trim_right.tick();     }
FASTRUN void CHECK_YAW_TRIM_LEFT()      { yaw_trim_left.tick();      }
FASTRUN void CHECK_THROTTLE_TRIM_UP()   { throttle_trim_up.tick();   }
FASTRUN void CHECK_THROTTLE_TRIM_DOWN() { throttle_trim_down.tick(); }




FASTRUN void checkTrimBtns()
{
	CHECK_PITCH_TRIM_UP();
	CHECK_PITCH_TRIM_DOWN();
	CHECK_ROLL_TRIM_RIGHT();
	CHECK_ROLL_TRIM_LEFT();
	CHECK_YAW_TRIM_RIGHT();
	CHECK_YAW_TRIM_LEFT();
	CHECK_THROTTLE_TRIM_UP();
	CHECK_THROTTLE_TRIM_DOWN();
}




FASTRUN void __attribute__((weak)) pitch_trim_up_click()           { pitchTrimVal     = constrain(pitchTrimVal    + TRIM_UPDATE_VAL, MIN_PITCH_TRIM,    MAX_PITCH_TRIM);    pitchTrimValUpdated    = true; }
FASTRUN void __attribute__((weak)) pitch_trim_down_click()         { pitchTrimVal     = constrain(pitchTrimVal    - TRIM_UPDATE_VAL, MIN_PITCH_TRIM,    MAX_PITCH_TRIM);    pitchTrimValUpdated    = true; }
FASTRUN void __attribute__((weak)) roll_trim_right_click()         { rollTrimVal      = constrain(rollTrimVal     + TRIM_UPDATE_VAL, MIN_ROLL_TRIM,     MAX_ROLL_TRIM);     rollTrimValUpdated     = true; }
FASTRUN void __attribute__((weak)) roll_trim_left_click()          { rollTrimVal      = constrain(rollTrimVal     - TRIM_UPDATE_VAL, MIN_ROLL_TRIM,     MAX_ROLL_TRIM);     rollTrimValUpdated     = true; }
FASTRUN void __attribute__((weak)) yaw_trim_right_click()          { yawTrimVal       = constrain(yawTrimVal      + TRIM_UPDATE_VAL, MIN_YAW_TRIM,      MAX_YAW_TRIM);      yawTrimValUpdated      = true; }
FASTRUN void __attribute__((weak)) yaw_trim_left_click()           { yawTrimVal       = constrain(yawTrimVal      - TRIM_UPDATE_VAL, MIN_YAW_TRIM,      MAX_YAW_TRIM);      yawTrimValUpdated      = true; }
FASTRUN void __attribute__((weak)) throttle_trim_up_click()        { throttleTrimVal  = constrain(throttleTrimVal + TRIM_UPDATE_VAL, MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM); throttleTrimValUpdated = true; }
FASTRUN void __attribute__((weak)) throttle_trim_down_click()      { throttleTrimVal  = constrain(throttleTrimVal - TRIM_UPDATE_VAL, MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM); throttleTrimValUpdated = true; }
FASTRUN void __attribute__((weak)) pitch_trim_up_long_click()      { pitchTrimVal     = constrain(pitchTrimVal    + TRIM_UPDATE_VAL, MIN_PITCH_TRIM,    MAX_PITCH_TRIM);    pitchTrimValUpdated    = true; }
FASTRUN void __attribute__((weak)) pitch_trim_down_long_click()    { pitchTrimVal     = constrain(pitchTrimVal    - TRIM_UPDATE_VAL, MIN_PITCH_TRIM,    MAX_PITCH_TRIM);    pitchTrimValUpdated    = true; }
FASTRUN void __attribute__((weak)) roll_trim_right_long_click()    { rollTrimVal      = constrain(rollTrimVal     + TRIM_UPDATE_VAL, MIN_ROLL_TRIM,     MAX_ROLL_TRIM);     rollTrimValUpdated     = true; }
FASTRUN void __attribute__((weak)) roll_trim_left_long_click()     { rollTrimVal      = constrain(rollTrimVal     - TRIM_UPDATE_VAL, MIN_ROLL_TRIM,     MAX_ROLL_TRIM);     rollTrimValUpdated     = true; }
FASTRUN void __attribute__((weak)) yaw_trim_right_long_click()     { yawTrimVal       = constrain(yawTrimVal      + TRIM_UPDATE_VAL, MIN_YAW_TRIM,      MAX_YAW_TRIM);      yawTrimValUpdated      = true; }
FASTRUN void __attribute__((weak)) yaw_trim_left_long_click()      { yawTrimVal       = constrain(yawTrimVal      - TRIM_UPDATE_VAL, MIN_YAW_TRIM,      MAX_YAW_TRIM);      yawTrimValUpdated      = true; }
FASTRUN void __attribute__((weak)) throttle_trim_up_long_click()   { throttleTrimVal  = constrain(throttleTrimVal + TRIM_UPDATE_VAL, MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM); throttleTrimValUpdated = true; }
FASTRUN void __attribute__((weak)) throttle_trim_down_long_click() { throttleTrimVal  = constrain(throttleTrimVal - TRIM_UPDATE_VAL, MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM); throttleTrimValUpdated = true; }




void setupButtons()
{
	pitch_trim_up.attachClick(pitch_trim_up_click);
	pitch_trim_down.attachClick(pitch_trim_down_click);
	roll_trim_right.attachClick(roll_trim_right_click);
	roll_trim_left.attachClick(roll_trim_left_click);
	yaw_trim_right.attachClick(yaw_trim_right_click);
	yaw_trim_left.attachClick(yaw_trim_left_click);
	throttle_trim_up.attachClick(throttle_trim_up_click);
	throttle_trim_down.attachClick(throttle_trim_down_click);

	pitch_trim_up.attachDuringLongPress(pitch_trim_up_long_click);
	pitch_trim_down.attachDuringLongPress(pitch_trim_down_long_click);
	roll_trim_right.attachDuringLongPress(roll_trim_right_long_click);
	roll_trim_left.attachDuringLongPress(roll_trim_left_long_click);
	yaw_trim_right.attachDuringLongPress(yaw_trim_right_long_click);
	yaw_trim_left.attachDuringLongPress(yaw_trim_left_long_click);
	throttle_trim_up.attachDuringLongPress(throttle_trim_up_long_click);
	throttle_trim_down.attachDuringLongPress(throttle_trim_down_long_click);
}




/*
* ****************** Joysticks ******************
*/
extern const int ANALOG_RESOLUTION = 12;

extern const int PITCH_PIN    = A1; // Pin 15
extern const int ROLL_PIN     = A0; // Pin 14
extern const int YAW_PIN      = A2; // Pin 16
extern const int THROTTLE_PIN = A3; // Pin 17




channel pitch_ch;
channel roll_ch;
channel yaw_ch;
channel throttle_ch;




void setupJoys()
{
	analogReadResolution(ANALOG_RESOLUTION);

	pitch_ch.setPinNum(PITCH_PIN);
	pitch_ch.setChNum(PITCH_CH);

	roll_ch.setPinNum(ROLL_PIN);
	roll_ch.setChNum(ROLL_CH);

	yaw_ch.setPinNum(YAW_PIN);
	yaw_ch.setChNum(YAW_CH);

	throttle_ch.setPinNum(THROTTLE_PIN);
	throttle_ch.setChNum(THROTTLE_CH);
}




/*
* ****************** Knobs ******************
*/
extern const int KNOB_1_PIN = A17; // Pin 41
extern const int KNOB_2_PIN = A16; // Pin 40




channel knob1_ch;
channel knob2_ch;




void setupKnobs()
{
	analogReadResolution(ANALOG_RESOLUTION);

	knob1_ch.setPinNum(KNOB_1_PIN);
	knob1_ch.setChNum(KNOB_1_CH);

	knob2_ch.setPinNum(KNOB_2_PIN);
	knob1_ch.setChNum(KNOB_2_CH);
}




/*
* ****************** General ******************
*/
extern const float INPUT_MON_FREQ   = 200; // Hz
extern const float INPUT_MON_PERIOD = 1.0 / INPUT_MON_FREQ; // s

extern const int NUM_CHS = 12; // TODO: change to 14?

extern const int PITCH_CH    = 0;
extern const int ROLL_CH     = 1;
extern const int YAW_CH      = 2;
extern const int THROTTLE_CH = 3;
extern const int KNOB_1_CH   = 4;
extern const int KNOB_2_CH   = 5;
extern const int SW_1_CH     = 6;
extern const int SW_2_CH     = 7;
extern const int SW_3_CH     = 8;
extern const int SW_4_CH     = 9;
extern const int SW_5_CH     = 10;
extern const int SW_6_CH     = 11;
extern const int TRI_A_CH    = 12;
extern const int TRI_B_CH    = 13;

extern const float ABSOLUTE_CH_MAX =  2.0;
extern const float ABSOLUTE_CH_MIN = -2.0;
extern const float CH_MAX          =  1.0;
extern const float CH_MIN          = -1.0;

extern const float EXPO_MAX = 100.0;
extern const float EXPO_MIN = 0.0;

extern const float MIX_MAX =  100.0;
extern const float MIX_MIN = -100.0;




PeriodicTimer checkInputsTimer;




void channel::setPinNum(const int& _pinNum)
{
	if (_pinNum >= 0)
		pinNum = _pinNum;
}

int channel::getPinNum()
{
	return pinNum;
}

void channel::setChNum(const int& _chNum)
{
	if ((_chNum >= 0) && (_chNum < NUM_CHS))
		chNum = _chNum;
}

int channel::getChNum()
{
	return chNum;
}

void channel::setIsAn(const bool& _isAnalog)
{
	isAnalog = _isAnalog;
}

bool channel::getIsAn()
{
	return isAnalog;
}

void channel::setMaxADC(const int& _maxADC)
{
	if (_maxADC >= 0)
		maxADC = _maxADC;
}

int channel::getMaxADC()
{
	return maxADC;
}

void channel::setMinADC(const int& _minADC)
{
	if (_minADC >= 0)
		minADC = _minADC;
}

int channel::getMinADC()
{
	return minADC;
}

void channel::setMixChNum(const int& _mixChNum)
{
	if ((_mixChNum >= 0) && (_mixChNum < NUM_CHS))
		mixChNum = _mixChNum;
}

float channel::getMixChNum()
{
	return mixChNum;
}

void channel::setMix(const float& _mixVal)
{
	mixVal = constrain(_mixVal, MIX_MIN, MIX_MAX);
}

float channel::getMix()
{
	return mixVal;
}

void channel::setReverse(const bool& _reverse)
{
	reverse = _reverse;
}

bool channel::getReverse()
{
	return reverse;
}

void channel::setExpo(const float& _expo)
{
	expo = constrain(_expo, EXPO_MIN, EXPO_MAX);
}

float channel::getExpo()
{
	return expo;
}

void channel::update()
{
	if (isAnalog)
		raw = constrain(mapfloat(analogRead(pinNum), minADC, maxADC, CH_MIN, CH_MAX), CH_MIN, CH_MAX);
	else
		raw = (float)digitalReadFast(pinNum);

	reversed = raw;

	if (reverse)
	{
		if (isAnalog)
			reversed *= -1;
		else
		{
			if (reversed >= 0.5)
				reversed = 0;
			else
				reversed = 1;
		}
	}
	
	reversed_expo = constrain(applyExpo(reversed, expo), CH_MIN, CH_MAX);

	if (useLowRate)
		reversed_expo *= lowRate;
	else
		reversed_expo *= highRate;
}

float channel::getRaw()
{
	return raw;
}

float channel::getReversed()
{
	return reversed;
}

float channel::getReversed_expo()
{
	return reversed_expo;
}

void channel::useHighRates()
{
	useLowRate = false;
}

void channel::setHighRate(const float& _highRate)
{
	if ((_highRate > 0) && (_highRate >= 1))
		highRate = _highRate;
}

float channel::getHighRate()
{
	return highRate;
}

void channel::useLowRates()
{
	useLowRate = true;
}

void channel::setLowRate(const float& _lowRate)
{
	if ((_lowRate > 0) && (_lowRate >= 1))
		lowRate = _lowRate;
}

float channel::getLowRate()
{
	return lowRate;
}




void checkInputs()
{
	checkTrimBtns();

	pitch_ch.update();
	roll_ch.update();
	yaw_ch.update();
	throttle_ch.update();
	knob1_ch.update();
	knob2_ch.update();
	sw_1_ch.update();
	sw_2_ch.update();
	sw_3_ch.update();
	sw_4_ch.update();
	sw_5_ch.update();
	sw_6_ch.update();
	tri_sw_a_ch.update();
	tri_sw_b_ch.update();
}




void setupInputs()
{
	setupSwitches();
	setupButtons();
	setupJoys();
	setupKnobs();

	checkInputsTimer.begin(checkInputs, INPUT_MON_PERIOD * 1e6);
}




float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




float applyExpo(const float& input, const float& expo)
{
  // https://www.rcgroups.com/forums/showthread.php?375044-what-is-the-formula-for-the-expo-function/page2
  // https://www.desmos.com/calculator/5wktdeykaj

  float output = -(((1.0 - ((100.0 - expo) / 100.0)) * pow(input, 3.0)) + (input * ((100.0 - expo) / 100.0)));

  return constrain(output, -1.0, 1.0);
}




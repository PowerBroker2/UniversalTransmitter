#include "UniversalController.h"
#include "buddy/buddy.h"
#include "display/display.h"
#include "inputs/inputs.h"
#include "radios/radios.h"
#include "sound/sound.h"
#include "power/power.h"




void UniversalController::begin()
{
  Serial.begin(2000000);

  setupSwitches();
  setupBuddy();
  setupButtons();
  setupKnobs();
  setupJoys();
  setupRadios();
  setupDisplay();
  setupPowerMon();
}




int UniversalController::numBuddyChannels()
{
  return max_channel_num;
}




int UniversalController::buddyChannel(const int& channelNum)
{
  if (channelNum < MAX_CHANNELS)
  {
    return buddy_channel[channelNum];
  }

  return 0;
}




int UniversalController::sw1State()
{
  return sw_1_state;
}




int UniversalController::sw2State()
{
  return sw_2_state;
}




int UniversalController::sw3State()
{
  return sw_3_state;
}




int UniversalController::sw4State()
{
  return sw_4_state;
}




int UniversalController::sw5State()
{
  return sw_5_state;
}




int UniversalController::sw6State()
{
  return sw_6_state;
}




int UniversalController::triSwAState()
{
  return tri_sw_a_state;
}




int UniversalController::triSwBState()
{
  return tri_sw_b_state;
}




bool UniversalController::sw1SwitchFlag()
{
  return sw_1_switched;
}




bool UniversalController::sw2SwitchFlag()
{
  return sw_2_switched;
}




bool UniversalController::sw3SwitchFlag()
{
  return sw_3_switched;
}




bool UniversalController::sw4SwitchFlag()
{
  return sw_4_switched;
}




bool UniversalController::sw5SwitchFlag()
{
  return sw_5_switched;
}




bool UniversalController::sw6SwitchFlag()
{
  return sw_6_switched;
}




bool UniversalController::triSwASwitchFlag()
{
  return tri_sw_a_switched;
}




bool UniversalController::triSwBSwitchFlag()
{
  return tri_sw_b_switched;
}




void UniversalController::clearsw1SwitchFlag()
{
  sw_1_switched = false;
}




void UniversalController::clearsw2SwitchFlag()
{
  sw_2_switched = false;
}




void UniversalController::clearsw3SwitchFlag()
{
  sw_3_switched = false;
}




void UniversalController::clearsw4SwitchFlag()
{
  sw_4_switched = false;
}




void UniversalController::clearsw5SwitchFlag()
{
  sw_5_switched = false;
}




void UniversalController::clearsw6SwitchFlag()
{
  sw_6_switched = false;
}




void UniversalController::cleartriSwASwitchFlag()
{
  tri_sw_a_switched = false;
}




void UniversalController::cleartriSwBSwitchFlag()
{
  tri_sw_b_switched = false;
}




float UniversalController::pitchTrim()
{
  return pitchTrimVal;
}




float UniversalController::rollTrim()
{
  return rollTrimVal;
}




float UniversalController::yawTrim()
{
  return yawTrimVal;
}




float UniversalController::throttleTrim()
{
  return throttleTrimVal;
}




bool UniversalController::pitchTrimFlag()
{
  return pitchTrimValUpdated;
}




bool UniversalController::rollTrimFlag()
{
  return rollTrimValUpdated;
}




bool UniversalController::yawTrimFlag()
{
  return yawTrimValUpdated;
}




bool UniversalController::throttleTrimFlag()
{
  return throttleTrimValUpdated;
}




void UniversalController::clearPitchTrimFlag()
{
  pitchTrimValUpdated = false;
}




void UniversalController::clearRollTrimFlag()
{
  rollTrimValUpdated = false;
}




void UniversalController::clearYawTrimFlag()
{
  yawTrimValUpdated = false;
}




void UniversalController::clearThrottleTrimFlag()
{
  throttleTrimValUpdated = false;
}




void UniversalController::setPitchADCLimits(const int& minADC, const int& maxADC)
{
  _minPitchADC = minADC;
  _maxPitchADC = maxADC;
}




void UniversalController::setRollADCLimits(const int& minADC, const int& maxADC)
{
  _minRollADC = minADC;
  _maxRollADC = maxADC;
}




void UniversalController::setYawADCLimits(const int& minADC, const int& maxADC)
{
  _minYawADC = minADC;
  _maxYawADC = maxADC;
}




void UniversalController::setThrottleADCLimits(const int& minADC, const int& maxADC)
{
  _minThrottleADC = minADC;
  _maxThrottleADC = maxADC;
}




void UniversalController::setKnob1ADCLimits(const int& minADC, const int& maxADC)
{
  _minKnob1ADC = minADC;
  _maxKnob1ADC = maxADC;
}




void UniversalController::setKnob2ADCLimits(const int& minADC, const int& maxADC)
{
  _minKnob2ADC = minADC;
  _maxKnob2ADC = maxADC;
}




int UniversalController::minPitchADC()
{
  return _minPitchADC;
}




int UniversalController::maxPitchADC()
{
  return _maxPitchADC;
}




int UniversalController::minRollADC()
{
  return _minRollADC;
}




int UniversalController::maxRollADC()
{
  return _maxRollADC;
}




int UniversalController::minYawADC()
{
  return _minYawADC;
}




int UniversalController::maxYawADC()
{
  return _maxYawADC;
}




int UniversalController::minThrottleADC()
{
  return _minThrottleADC;
}




int UniversalController::maxThrottleADC()
{
  return _maxThrottleADC;
}




int UniversalController::minKnob1ADC()
{
  return _minKnob1ADC;
}




int UniversalController::maxKnob1ADC()
{
  return _maxKnob1ADC;
}




int UniversalController::minKnob2ADC()
{
  return _minKnob2ADC;
}




int UniversalController::maxKnob2ADC()
{
  return _maxKnob2ADC;
}




float UniversalController::pitchJoy()
{
  return constrain(mapfloat(analogRead(PITCH_PIN), _minPitchADC, _maxPitchADC, -1, 1), -1, 1);
}




float UniversalController::rollJoy()
{
  return constrain(mapfloat(analogRead(ROLL_PIN), _minRollADC, _maxRollADC, -1, 1), -1, 1);
}




float UniversalController::yawJoy()
{
  return constrain(mapfloat(analogRead(YAW_PIN), _minYawADC, _maxYawADC, -1, 1), -1, 1);
}




float UniversalController::throttleJoy()
{
  return constrain(mapfloat(analogRead(THROTTLE_PIN), _minThrottleADC, _maxThrottleADC, -1, 1), -1, 1);
}




float UniversalController::knob1()
{
  return constrain(mapfloat(analogRead(KNOB_1_PIN), _minKnob1ADC, _maxKnob1ADC, -1, 1), -1, 1);
}




float UniversalController::knob2()
{
  return constrain(mapfloat(analogRead(KNOB_2_PIN), _minKnob2ADC, _maxKnob2ADC, -1, 1), -1, 1);
}




float UniversalController::shuntVoltage()
{
  return shuntvoltage;
}




float UniversalController::busVoltage()
{
  return busvoltage;
}




float UniversalController::current()
{
  return current_mA;
}




float UniversalController::power()
{
  return power_mW;
}




float UniversalController::loadVoltage()
{
  return loadvoltage;
}




bool UniversalController::wasTouched()
{
  return !touch_handled;
}




void UniversalController::clearTouch()
{
  touch_handled = true;
}




float UniversalController::touchX()
{
  return ts_point.x;
}




float UniversalController::touchY()
{
  return ts_point.y;
}




float UniversalController::touchPressure()
{
  return ts_point.z;
}




float UniversalController::mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




float UniversalController::expo(float input, float expo)
{
  // https://www.rcgroups.com/forums/showthread.php?375044-what-is-the-formula-for-the-expo-function/page2
  // https://www.desmos.com/calculator/5wktdeykaj

  float constrainedInput = constrain(input, -1.0, 1.0);

  float output = ((1.0 - ((100.0 - expo) / 100.0)) * pow(constrainedInput, 3.0)) + (constrainedInput * ((100.0 - expo) / 100.0));

  return constrain(output, -1.0, 1.0);
}




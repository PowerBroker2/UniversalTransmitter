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

  setupInputs();
  setupBuddy();
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




void UniversalController::clearSw1SwitchFlag()
{
  sw_1_switched = false;
}




void UniversalController::clearSw2SwitchFlag()
{
  sw_2_switched = false;
}




void UniversalController::clearSw3SwitchFlag()
{
  sw_3_switched = false;
}




void UniversalController::clearSw4SwitchFlag()
{
  sw_4_switched = false;
}




void UniversalController::clearSw5SwitchFlag()
{
  sw_5_switched = false;
}




void UniversalController::clearSw6SwitchFlag()
{
  sw_6_switched = false;
}




void UniversalController::clearTriSwASwitchFlag()
{
  tri_sw_a_switched = false;
}




void UniversalController::clearTriSwBSwitchFlag()
{
  tri_sw_b_switched = false;
}




void UniversalController::setPitchTrim(const float& trim)
{
  pitchTrimVal = constrain(trim - fmod(pitchTrimVal, TRIM_UPDATE_VAL), MIN_PITCH_TRIM, MAX_PITCH_TRIM);
}




void UniversalController::setRollTrim(const float& trim)
{
  rollTrimVal = constrain(trim - fmod(rollTrimVal, TRIM_UPDATE_VAL), MIN_ROLL_TRIM, MAX_ROLL_TRIM);
}




void UniversalController::setYawTrim(const float& trim)
{
  yawTrimVal = constrain(trim - fmod(yawTrimVal, TRIM_UPDATE_VAL), MIN_YAW_TRIM, MAX_YAW_TRIM);
}




void UniversalController::setThrottleTrim(const float& trim)
{
  throttleTrimVal = constrain(trim - fmod(throttleTrimVal, TRIM_UPDATE_VAL), MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM);
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
  pitch_ch.setMinADC(minADC);
  pitch_ch.setMaxADC(maxADC);
}




void UniversalController::setRollADCLimits(const int& minADC, const int& maxADC)
{
  roll_ch.setMinADC(minADC);
  roll_ch.setMaxADC(maxADC);
}




void UniversalController::setYawADCLimits(const int& minADC, const int& maxADC)
{
  yaw_ch.setMinADC(minADC);
  yaw_ch.setMaxADC(maxADC);
}




void UniversalController::setThrottleADCLimits(const int& minADC, const int& maxADC)
{
  throttle_ch.setMinADC(minADC);
  throttle_ch.setMaxADC(maxADC);
}




void UniversalController::setKnob1ADCLimits(const int& minADC, const int& maxADC)
{
  knob1_ch.setMinADC(minADC);
  knob1_ch.setMaxADC(maxADC);
}




void UniversalController::setKnob2ADCLimits(const int& minADC, const int& maxADC)
{
  knob2_ch.setMinADC(minADC);
  knob2_ch.setMaxADC(maxADC);
}




int UniversalController::minPitchADC()
{
  return pitch_ch.getMinADC();
}




int UniversalController::maxPitchADC()
{
  return pitch_ch.getMaxADC();
}




int UniversalController::minRollADC()
{
  return roll_ch.getMinADC();
}




int UniversalController::maxRollADC()
{
  return roll_ch.getMaxADC();
}




int UniversalController::minYawADC()
{
  return yaw_ch.getMinADC();
}




int UniversalController::maxYawADC()
{
  return yaw_ch.getMaxADC();
}




int UniversalController::minThrottleADC()
{
  return throttle_ch.getMinADC();
}




int UniversalController::maxThrottleADC()
{
  return throttle_ch.getMaxADC();
}




int UniversalController::minKnob1ADC()
{
  return knob1_ch.getMinADC();
}




int UniversalController::maxKnob1ADC()
{
  return knob1_ch.getMaxADC();
}




int UniversalController::minKnob2ADC()
{
  return knob2_ch.getMinADC();
}




int UniversalController::maxKnob2ADC()
{
  return knob2_ch.getMaxADC();
}




float UniversalController::getVal(channel& inputCh)
{
  float output   = inputCh.getReversed_expo();
  int   mixChNum = inputCh.getMixChNum();
  float mixVal   = inputCh.getMix() / 100.0;

  if (mixChNum == PITCH_CH)
    output += mixVal * pitch_ch.getReversed_expo();
  else if (mixChNum == ROLL_CH)
    output += mixVal * roll_ch.getReversed_expo();
  else if (mixChNum == YAW_CH)
    output += mixVal * yaw_ch.getReversed_expo();
  else if (mixChNum == THROTTLE_CH)
    output += mixVal * throttle_ch.getReversed_expo();
  else if (mixChNum == KNOB_1_CH)
    output += mixVal * knob1_ch.getReversed_expo();
  else if (mixChNum == KNOB_2_CH)
    output += mixVal * knob2_ch.getReversed_expo();
  else if (mixChNum == SW_1_CH)
    output += mixVal * sw_1_ch.getReversed_expo();
  else if (mixChNum == SW_2_CH)
    output += mixVal * sw_2_ch.getReversed_expo();
  else if (mixChNum == SW_3_CH)
    output += mixVal * sw_3_ch.getReversed_expo();
  else if (mixChNum == SW_4_CH)
    output += mixVal * sw_4_ch.getReversed_expo();
  else if (mixChNum == SW_5_CH)
    output += mixVal * sw_5_ch.getReversed_expo();
  else if (mixChNum == SW_6_CH)
    output += mixVal * sw_6_ch.getReversed_expo();
  else if (mixChNum == TRI_A_CH)
    output += mixVal * tri_sw_a_ch.getReversed_expo();
  else if (mixChNum == TRI_B_CH)
    output += mixVal * tri_sw_b_ch.getReversed_expo();
  
  return constrain(output, CH_MIN, CH_MAX);
}




float UniversalController::pitchJoy()
{
  return getVal(pitch_ch);
}




float UniversalController::rollJoy()
{
  return getVal(roll_ch);
}




float UniversalController::yawJoy()
{
  return getVal(yaw_ch);
}




float UniversalController::throttleJoy()
{
  return getVal(throttle_ch);
}




float UniversalController::knob1()
{
  return getVal(knob1_ch);
}




float UniversalController::knob2()
{
  return getVal(knob2_ch);
}




void  UniversalController::useHighRates()
{
  pitch_ch.useHighRates();
	roll_ch.useHighRates();
	yaw_ch.useHighRates();
}




void  UniversalController::setHighRates(const float& rate)
{
  pitch_ch.setHighRate(rate);
	roll_ch.setHighRate(rate);
	yaw_ch.setHighRate(rate);
}




float UniversalController::getHighRates()
{
  return pitch_ch.getHighRate();
}




void  UniversalController::useLowRates()
{
  pitch_ch.useLowRates();
	roll_ch.useLowRates();
	yaw_ch.useLowRates();
}




void  UniversalController::setLowRates(const float& rate)
{
  pitch_ch.setLowRate(rate);
	roll_ch.setLowRate(rate);
	yaw_ch.setLowRate(rate);
}




float UniversalController::getLowRates()
{
  return pitch_ch.getLowRate();
}




void UniversalController::setPitchExpo(const float& _expo)
{
  pitch_ch.setExpo(_expo);
}




void UniversalController::setRollExpo(const float& _expo)
{
  roll_ch.setExpo(_expo);
}




void UniversalController::setYawExpo(const float& _expo)
{
  yaw_ch.setExpo(_expo);
}




void UniversalController::setThrottleExpo(const float& _expo)
{
  throttle_ch.setExpo(_expo);
}




void UniversalController::setKnob1Expo(const float& _expo)
{
  knob1_ch.setExpo(_expo);
}




void UniversalController::setKnob2Expo(const float& _expo)
{
  knob2_ch.setExpo(_expo);
}




float UniversalController::getPitchExpo()
{
  return pitch_ch.getExpo();
}




float UniversalController::getRollExpo()
{
  return roll_ch.getExpo();
}




float UniversalController::getYawExpo()
{
  return yaw_ch.getExpo();
}




float UniversalController::getThrottleExpo()
{
  return throttle_ch.getExpo();
}




float UniversalController::getKnob1Expo()
{
  return knob1_ch.getExpo();
}




float UniversalController::getKnob2Expo()
{
  return knob2_ch.getExpo();
}




void UniversalController::setPitchMixCh(const int& chNum)
{
  pitch_ch.setMixChNum(chNum);
}




void UniversalController::setRollMixCh(const int& chNum)
{
  roll_ch.setMixChNum(chNum);
}




void UniversalController::setYawMixCh(const int& chNum)
{
  yaw_ch.setMixChNum(chNum);
}




void UniversalController::setThrottleMixCh(const int& chNum)
{
  throttle_ch.setMixChNum(chNum);
}




void UniversalController::setKnob1MixCh(const int& chNum)
{
  knob1_ch.setMixChNum(chNum);
}




void UniversalController::setKnob2MixCh(const int& chNum)
{
  knob2_ch.setMixChNum(chNum);
}




void UniversalController::setSw1MixCh(const int& chNum)
{
  sw_1_ch.setMixChNum(chNum);
}




void UniversalController::setSw2MixCh(const int& chNum)
{
  sw_2_ch.setMixChNum(chNum);
}




void UniversalController::setSw3MixCh(const int& chNum)
{
  sw_3_ch.setMixChNum(chNum);
}




void UniversalController::setSw4MixCh(const int& chNum)
{
  sw_4_ch.setMixChNum(chNum);
}




void UniversalController::setSw5MixCh(const int& chNum)
{
  sw_5_ch.setMixChNum(chNum);
}




void UniversalController::setSw6MixCh(const int& chNum)
{
  sw_6_ch.setMixChNum(chNum);
}




void UniversalController::setTriSwAMixCh(const int& chNum)
{
  tri_sw_a_ch.setMixChNum(chNum);
}




void UniversalController::setTriSwBMixCh(const int& chNum)
{
  tri_sw_b_ch.setMixChNum(chNum);
}




int UniversalController::getPitchMixCh()
{
  return pitch_ch.getMixChNum();
}




int UniversalController::getRollMixCh()
{
  return roll_ch.getMixChNum();
}




int UniversalController::getYawMixCh()
{
  return yaw_ch.getMixChNum();
}




int UniversalController::getThrottleMixCh()
{
  return throttle_ch.getMixChNum();
}




int UniversalController::getKnob1MixCh()
{
  return knob1_ch.getMixChNum();
}




int UniversalController::getKnob2MixCh()
{
  return knob2_ch.getMixChNum();
}




int UniversalController::getSw1MixCh()
{
  return sw_1_ch.getMixChNum();
}




int UniversalController::getSw2MixCh()
{
  return sw_2_ch.getMixChNum();
}




int UniversalController::getSw3MixCh()
{
  return sw_3_ch.getMixChNum();
}




int UniversalController::getSw4MixCh()
{
  return sw_4_ch.getMixChNum();
}




int UniversalController::getSw5MixCh()
{
  return sw_5_ch.getMixChNum();
}




int UniversalController::getSw6MixCh()
{
  return sw_6_ch.getMixChNum();
}




int UniversalController::getTriSwAMixCh()
{
  return tri_sw_a_ch.getMixChNum();
}




int UniversalController::getTriSwBMixCh()
{
  return tri_sw_b_ch.getMixChNum();
}




void UniversalController::setPitchMix(const float& mix)
{
  pitch_ch.setMix(mix);
}




void UniversalController::setRollMix(const float& mix)
{
  roll_ch.setMix(mix);
}




void UniversalController::setYawMix(const float& mix)
{
  yaw_ch.setMix(mix);
}




void UniversalController::setThrottleMix(const float& mix)
{
  throttle_ch.setMix(mix);
}




void UniversalController::setKnob1Mix(const float& mix)
{
  knob1_ch.setMix(mix);
}




void UniversalController::setKnob2Mix(const float& mix)
{
  knob2_ch.setMix(mix);
}




void UniversalController::setSw1Mix(const float& mix)
{
  sw_1_ch.setMix(mix);
}




void UniversalController::setSw2Mix(const float& mix)
{
  sw_2_ch.setMix(mix);
}




void UniversalController::setSw3Mix(const float& mix)
{
  sw_3_ch.setMix(mix);
}




void UniversalController::setSw4Mix(const float& mix)
{
  sw_4_ch.setMix(mix);
}




void UniversalController::setSw5Mix(const float& mix)
{
  sw_5_ch.setMix(mix);
}




void UniversalController::setSw6Mix(const float& mix)
{
  sw_6_ch.setMix(mix);
}




void UniversalController::setTriSwAMix(const float& mix)
{
  tri_sw_a_ch.setMix(mix);
}




void UniversalController::setTriSwBMix(const float& mix)
{
  tri_sw_b_ch.setMix(mix);
}




int UniversalController::getPitchMix()
{
  return pitch_ch.getMix();
}




int UniversalController::getRollMix()
{
  return roll_ch.getMix();
}




int UniversalController::getYawMix()
{
  return yaw_ch.getMix();
}




int UniversalController::getThrottleMix()
{
  return throttle_ch.getMix();
}




int UniversalController::getKnob1Mix()
{
  return knob1_ch.getMix();
}




int UniversalController::getKnob2Mix()
{
  return knob1_ch.getMix();
}




int UniversalController::getSw1Mix()
{
  return sw_1_ch.getMix();
}




int UniversalController::getSw2Mix()
{
  return sw_2_ch.getMix();
}




int UniversalController::getSw3Mix()
{
  return sw_3_ch.getMix();
}




int UniversalController::getSw4Mix()
{
  return sw_4_ch.getMix();
}




int UniversalController::getSw5Mix()
{
  return sw_5_ch.getMix();
}




int UniversalController::getSw6Mix()
{
  return sw_6_ch.getMix();
}




int UniversalController::getTriSwAMix()
{
  return tri_sw_a_ch.getMix();
}




int UniversalController::getTriSwBMix()
{
  return tri_sw_b_ch.getMix();
}




void UniversalController::setPitchReverse(const bool& reverse)
{
  pitch_ch.setReverse(reverse);
}




void UniversalController::setRollReverse(const bool& reverse)
{
  roll_ch.setReverse(reverse);
}




void UniversalController::setYawReverse(const bool& reverse)
{
  yaw_ch.setReverse(reverse);
}




void UniversalController::setThrottleReverse(const bool& reverse)
{
  throttle_ch.setReverse(reverse);
}




void UniversalController::setKnob1Reverse(const bool& reverse)
{
  knob1_ch.setReverse(reverse);
}




void UniversalController::setKnob2Reverse(const bool& reverse)
{
  knob2_ch.setReverse(reverse);
}




void UniversalController::setSw1Reverse(const bool& reverse)
{
  sw_1_ch.setReverse(reverse);
}




void UniversalController::setSw2Reverse(const bool& reverse)
{
  sw_2_ch.setReverse(reverse);
}




void UniversalController::setSw3Reverse(const bool& reverse)
{
  sw_3_ch.setReverse(reverse);
}




void UniversalController::setSw4Reverse(const bool& reverse)
{
  sw_4_ch.setReverse(reverse);
}




void UniversalController::setSw5Reverse(const bool& reverse)
{
  sw_5_ch.setReverse(reverse);
}




void UniversalController::setSw6Reverse(const bool& reverse)
{
  sw_6_ch.setReverse(reverse);
}




void UniversalController::setTriSwAReverse(const bool& reverse)
{
  tri_sw_a_ch.setReverse(reverse);
}




void UniversalController::setTriSwBReverse(const bool& reverse)
{
  tri_sw_b_ch.setReverse(reverse);
}




bool UniversalController::getPitchReverse()
{
  return pitch_ch.getReverse();
}




bool UniversalController::getRollReverse()
{
  return roll_ch.getReverse();
}




bool UniversalController::getYawReverse()
{
  return yaw_ch.getReverse();
}




bool UniversalController::getThrottleReverse()
{
  return throttle_ch.getReverse();
}




bool UniversalController::getKnob1Reverse()
{
  return knob1_ch.getReverse();
}




bool UniversalController::getKnob2Reverse()
{
  return knob2_ch.getReverse();
}




bool UniversalController::getSw1Reverse()
{
  return sw_1_ch.getReverse();
}




bool UniversalController::getSw2Reverse()
{
  return sw_2_ch.getReverse();
}




bool UniversalController::getSw3Reverse()
{
  return sw_3_ch.getReverse();
}




bool UniversalController::getSw4Reverse()
{
  return sw_4_ch.getReverse();
}




bool UniversalController::getSw5Reverse()
{
  return sw_5_ch.getReverse();
}




bool UniversalController::getSw6Reverse()
{
  return sw_6_ch.getReverse();
}




bool UniversalController::getTriSwAReverse()
{
  return tri_sw_a_ch.getReverse();
}




bool UniversalController::getTriSwBReverse()
{
  return tri_sw_b_ch.getReverse();
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




float UniversalController::expo(const float& input, const float& expo)
{
  return applyExpo(input, expo);
}




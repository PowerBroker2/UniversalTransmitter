#include "UniversalTransmitter.h"
#include "buddy/buddy.h"
#include "display/display.h"
#include "inputs/inputs.h"
#include "radios/radios.h"
#include "sound/sound.h"
#include "power/power.h"




void UniversalTransmitter::begin()
{
  Serial.begin(2000000);

  setupInputs();
  setupBuddy();
  setupRadios();
  setupDisplay();
  setupPowerMon();
}




int UniversalTransmitter::numBuddyChannels()
{
  return max_channel_num;
}




int UniversalTransmitter::buddyChannel(const int& channelNum)
{
  if (channelNum < MAX_CHANNELS)
  {
    return buddy_channel[channelNum];
  }

  return 0;
}




float UniversalTransmitter::sw1State()
{
  return getVal(sw_1_ch);
}




float UniversalTransmitter::sw2State()
{
  return getVal(sw_2_ch);
}




float UniversalTransmitter::sw3State()
{
  return getVal(sw_3_ch);
}




float UniversalTransmitter::sw4State()
{
  return getVal(sw_4_ch);
}




float UniversalTransmitter::sw5State()
{
  return getVal(sw_5_ch);
}




float UniversalTransmitter::sw6State()
{
  return getVal(sw_6_ch);
}




float UniversalTransmitter::triSwAState()
{
  return getVal(tri_sw_a_ch);
}




float UniversalTransmitter::triSwBState()
{
  return getVal(tri_sw_b_ch);
}




bool UniversalTransmitter::sw1SwitchFlag()
{
  return sw_1_switched;
}




bool UniversalTransmitter::sw2SwitchFlag()
{
  return sw_2_switched;
}




bool UniversalTransmitter::sw3SwitchFlag()
{
  return sw_3_switched;
}




bool UniversalTransmitter::sw4SwitchFlag()
{
  return sw_4_switched;
}




bool UniversalTransmitter::sw5SwitchFlag()
{
  return sw_5_switched;
}




bool UniversalTransmitter::sw6SwitchFlag()
{
  return sw_6_switched;
}




bool UniversalTransmitter::triSwASwitchFlag()
{
  return tri_sw_a_switched;
}




bool UniversalTransmitter::triSwBSwitchFlag()
{
  return tri_sw_b_switched;
}




void UniversalTransmitter::clearSw1SwitchFlag()
{
  sw_1_switched = false;
}




void UniversalTransmitter::clearSw2SwitchFlag()
{
  sw_2_switched = false;
}




void UniversalTransmitter::clearSw3SwitchFlag()
{
  sw_3_switched = false;
}




void UniversalTransmitter::clearSw4SwitchFlag()
{
  sw_4_switched = false;
}




void UniversalTransmitter::clearSw5SwitchFlag()
{
  sw_5_switched = false;
}




void UniversalTransmitter::clearSw6SwitchFlag()
{
  sw_6_switched = false;
}




void UniversalTransmitter::clearTriSwASwitchFlag()
{
  tri_sw_a_switched = false;
}




void UniversalTransmitter::clearTriSwBSwitchFlag()
{
  tri_sw_b_switched = false;
}




void UniversalTransmitter::setPitchTrim(const float& trim)
{
  pitchTrimVal = constrain(trim - fmod(pitchTrimVal, TRIM_UPDATE_VAL), MIN_PITCH_TRIM, MAX_PITCH_TRIM);
}




void UniversalTransmitter::setRollTrim(const float& trim)
{
  rollTrimVal = constrain(trim - fmod(rollTrimVal, TRIM_UPDATE_VAL), MIN_ROLL_TRIM, MAX_ROLL_TRIM);
}




void UniversalTransmitter::setYawTrim(const float& trim)
{
  yawTrimVal = constrain(trim - fmod(yawTrimVal, TRIM_UPDATE_VAL), MIN_YAW_TRIM, MAX_YAW_TRIM);
}




void UniversalTransmitter::setThrottleTrim(const float& trim)
{
  throttleTrimVal = constrain(trim - fmod(throttleTrimVal, TRIM_UPDATE_VAL), MIN_THROTTLE_TRIM, MAX_THROTTLE_TRIM);
}




float UniversalTransmitter::pitchTrim()
{
  return pitchTrimVal;
}




float UniversalTransmitter::rollTrim()
{
  return rollTrimVal;
}




float UniversalTransmitter::yawTrim()
{
  return yawTrimVal;
}




float UniversalTransmitter::throttleTrim()
{
  return throttleTrimVal;
}




bool UniversalTransmitter::pitchTrimFlag()
{
  return pitchTrimValUpdated;
}




bool UniversalTransmitter::rollTrimFlag()
{
  return rollTrimValUpdated;
}




bool UniversalTransmitter::yawTrimFlag()
{
  return yawTrimValUpdated;
}




bool UniversalTransmitter::throttleTrimFlag()
{
  return throttleTrimValUpdated;
}




void UniversalTransmitter::clearPitchTrimFlag()
{
  pitchTrimValUpdated = false;
}




void UniversalTransmitter::clearRollTrimFlag()
{
  rollTrimValUpdated = false;
}




void UniversalTransmitter::clearYawTrimFlag()
{
  yawTrimValUpdated = false;
}




void UniversalTransmitter::clearThrottleTrimFlag()
{
  throttleTrimValUpdated = false;
}




void UniversalTransmitter::setPitchADCLimits(const int& minADC, const int& maxADC)
{
  pitch_ch.setMinADC(minADC);
  pitch_ch.setMaxADC(maxADC);
}




void UniversalTransmitter::setRollADCLimits(const int& minADC, const int& maxADC)
{
  roll_ch.setMinADC(minADC);
  roll_ch.setMaxADC(maxADC);
}




void UniversalTransmitter::setYawADCLimits(const int& minADC, const int& maxADC)
{
  yaw_ch.setMinADC(minADC);
  yaw_ch.setMaxADC(maxADC);
}




void UniversalTransmitter::setThrottleADCLimits(const int& minADC, const int& maxADC)
{
  throttle_ch.setMinADC(minADC);
  throttle_ch.setMaxADC(maxADC);
}




void UniversalTransmitter::setKnob1ADCLimits(const int& minADC, const int& maxADC)
{
  knob1_ch.setMinADC(minADC);
  knob1_ch.setMaxADC(maxADC);
}




void UniversalTransmitter::setKnob2ADCLimits(const int& minADC, const int& maxADC)
{
  knob2_ch.setMinADC(minADC);
  knob2_ch.setMaxADC(maxADC);
}




int UniversalTransmitter::minPitchADC()
{
  return pitch_ch.getMinADC();
}




int UniversalTransmitter::maxPitchADC()
{
  return pitch_ch.getMaxADC();
}




int UniversalTransmitter::minRollADC()
{
  return roll_ch.getMinADC();
}




int UniversalTransmitter::maxRollADC()
{
  return roll_ch.getMaxADC();
}




int UniversalTransmitter::minYawADC()
{
  return yaw_ch.getMinADC();
}




int UniversalTransmitter::maxYawADC()
{
  return yaw_ch.getMaxADC();
}




int UniversalTransmitter::minThrottleADC()
{
  return throttle_ch.getMinADC();
}




int UniversalTransmitter::maxThrottleADC()
{
  return throttle_ch.getMaxADC();
}




int UniversalTransmitter::minKnob1ADC()
{
  return knob1_ch.getMinADC();
}




int UniversalTransmitter::maxKnob1ADC()
{
  return knob1_ch.getMaxADC();
}




int UniversalTransmitter::minKnob2ADC()
{
  return knob2_ch.getMinADC();
}




int UniversalTransmitter::maxKnob2ADC()
{
  return knob2_ch.getMaxADC();
}




float UniversalTransmitter::getVal(channel& inputCh)
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




float UniversalTransmitter::pitchJoy()
{
  return getVal(pitch_ch);
}




float UniversalTransmitter::rollJoy()
{
  return getVal(roll_ch);
}




float UniversalTransmitter::yawJoy()
{
  return getVal(yaw_ch);
}




float UniversalTransmitter::throttleJoy()
{
  return getVal(throttle_ch);
}




float UniversalTransmitter::knob1()
{
  return getVal(knob1_ch);
}




float UniversalTransmitter::knob2()
{
  return getVal(knob2_ch);
}




void  UniversalTransmitter::useHighRates()
{
  pitch_ch.useHighRates();
	roll_ch.useHighRates();
	yaw_ch.useHighRates();
}




void  UniversalTransmitter::setHighRates(const float& rate)
{
  pitch_ch.setHighRate(rate);
	roll_ch.setHighRate(rate);
	yaw_ch.setHighRate(rate);
}




float UniversalTransmitter::getHighRates()
{
  return pitch_ch.getHighRate();
}




void  UniversalTransmitter::useLowRates()
{
  pitch_ch.useLowRates();
	roll_ch.useLowRates();
	yaw_ch.useLowRates();
}




void  UniversalTransmitter::setLowRates(const float& rate)
{
  pitch_ch.setLowRate(rate);
	roll_ch.setLowRate(rate);
	yaw_ch.setLowRate(rate);
}




float UniversalTransmitter::getLowRates()
{
  return pitch_ch.getLowRate();
}




void UniversalTransmitter::setPitchExpo(const float& _expo)
{
  pitch_ch.setExpo(_expo);
}




void UniversalTransmitter::setRollExpo(const float& _expo)
{
  roll_ch.setExpo(_expo);
}




void UniversalTransmitter::setYawExpo(const float& _expo)
{
  yaw_ch.setExpo(_expo);
}




void UniversalTransmitter::setThrottleExpo(const float& _expo)
{
  throttle_ch.setExpo(_expo);
}




void UniversalTransmitter::setKnob1Expo(const float& _expo)
{
  knob1_ch.setExpo(_expo);
}




void UniversalTransmitter::setKnob2Expo(const float& _expo)
{
  knob2_ch.setExpo(_expo);
}




float UniversalTransmitter::getPitchExpo()
{
  return pitch_ch.getExpo();
}




float UniversalTransmitter::getRollExpo()
{
  return roll_ch.getExpo();
}




float UniversalTransmitter::getYawExpo()
{
  return yaw_ch.getExpo();
}




float UniversalTransmitter::getThrottleExpo()
{
  return throttle_ch.getExpo();
}




float UniversalTransmitter::getKnob1Expo()
{
  return knob1_ch.getExpo();
}




float UniversalTransmitter::getKnob2Expo()
{
  return knob2_ch.getExpo();
}




void UniversalTransmitter::setPitchMixCh(const int& chNum)
{
  pitch_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setRollMixCh(const int& chNum)
{
  roll_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setYawMixCh(const int& chNum)
{
  yaw_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setThrottleMixCh(const int& chNum)
{
  throttle_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setKnob1MixCh(const int& chNum)
{
  knob1_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setKnob2MixCh(const int& chNum)
{
  knob2_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw1MixCh(const int& chNum)
{
  sw_1_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw2MixCh(const int& chNum)
{
  sw_2_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw3MixCh(const int& chNum)
{
  sw_3_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw4MixCh(const int& chNum)
{
  sw_4_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw5MixCh(const int& chNum)
{
  sw_5_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setSw6MixCh(const int& chNum)
{
  sw_6_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setTriSwAMixCh(const int& chNum)
{
  tri_sw_a_ch.setMixChNum(chNum);
}




void UniversalTransmitter::setTriSwBMixCh(const int& chNum)
{
  tri_sw_b_ch.setMixChNum(chNum);
}




int UniversalTransmitter::getPitchMixCh()
{
  return pitch_ch.getMixChNum();
}




int UniversalTransmitter::getRollMixCh()
{
  return roll_ch.getMixChNum();
}




int UniversalTransmitter::getYawMixCh()
{
  return yaw_ch.getMixChNum();
}




int UniversalTransmitter::getThrottleMixCh()
{
  return throttle_ch.getMixChNum();
}




int UniversalTransmitter::getKnob1MixCh()
{
  return knob1_ch.getMixChNum();
}




int UniversalTransmitter::getKnob2MixCh()
{
  return knob2_ch.getMixChNum();
}




int UniversalTransmitter::getSw1MixCh()
{
  return sw_1_ch.getMixChNum();
}




int UniversalTransmitter::getSw2MixCh()
{
  return sw_2_ch.getMixChNum();
}




int UniversalTransmitter::getSw3MixCh()
{
  return sw_3_ch.getMixChNum();
}




int UniversalTransmitter::getSw4MixCh()
{
  return sw_4_ch.getMixChNum();
}




int UniversalTransmitter::getSw5MixCh()
{
  return sw_5_ch.getMixChNum();
}




int UniversalTransmitter::getSw6MixCh()
{
  return sw_6_ch.getMixChNum();
}




int UniversalTransmitter::getTriSwAMixCh()
{
  return tri_sw_a_ch.getMixChNum();
}




int UniversalTransmitter::getTriSwBMixCh()
{
  return tri_sw_b_ch.getMixChNum();
}




void UniversalTransmitter::setPitchMix(const float& mix)
{
  pitch_ch.setMix(mix);
}




void UniversalTransmitter::setRollMix(const float& mix)
{
  roll_ch.setMix(mix);
}




void UniversalTransmitter::setYawMix(const float& mix)
{
  yaw_ch.setMix(mix);
}




void UniversalTransmitter::setThrottleMix(const float& mix)
{
  throttle_ch.setMix(mix);
}




void UniversalTransmitter::setKnob1Mix(const float& mix)
{
  knob1_ch.setMix(mix);
}




void UniversalTransmitter::setKnob2Mix(const float& mix)
{
  knob2_ch.setMix(mix);
}




void UniversalTransmitter::setSw1Mix(const float& mix)
{
  sw_1_ch.setMix(mix);
}




void UniversalTransmitter::setSw2Mix(const float& mix)
{
  sw_2_ch.setMix(mix);
}




void UniversalTransmitter::setSw3Mix(const float& mix)
{
  sw_3_ch.setMix(mix);
}




void UniversalTransmitter::setSw4Mix(const float& mix)
{
  sw_4_ch.setMix(mix);
}




void UniversalTransmitter::setSw5Mix(const float& mix)
{
  sw_5_ch.setMix(mix);
}




void UniversalTransmitter::setSw6Mix(const float& mix)
{
  sw_6_ch.setMix(mix);
}




void UniversalTransmitter::setTriSwAMix(const float& mix)
{
  tri_sw_a_ch.setMix(mix);
}




void UniversalTransmitter::setTriSwBMix(const float& mix)
{
  tri_sw_b_ch.setMix(mix);
}




int UniversalTransmitter::getPitchMix()
{
  return pitch_ch.getMix();
}




int UniversalTransmitter::getRollMix()
{
  return roll_ch.getMix();
}




int UniversalTransmitter::getYawMix()
{
  return yaw_ch.getMix();
}




int UniversalTransmitter::getThrottleMix()
{
  return throttle_ch.getMix();
}




int UniversalTransmitter::getKnob1Mix()
{
  return knob1_ch.getMix();
}




int UniversalTransmitter::getKnob2Mix()
{
  return knob1_ch.getMix();
}




int UniversalTransmitter::getSw1Mix()
{
  return sw_1_ch.getMix();
}




int UniversalTransmitter::getSw2Mix()
{
  return sw_2_ch.getMix();
}




int UniversalTransmitter::getSw3Mix()
{
  return sw_3_ch.getMix();
}




int UniversalTransmitter::getSw4Mix()
{
  return sw_4_ch.getMix();
}




int UniversalTransmitter::getSw5Mix()
{
  return sw_5_ch.getMix();
}




int UniversalTransmitter::getSw6Mix()
{
  return sw_6_ch.getMix();
}




int UniversalTransmitter::getTriSwAMix()
{
  return tri_sw_a_ch.getMix();
}




int UniversalTransmitter::getTriSwBMix()
{
  return tri_sw_b_ch.getMix();
}




void UniversalTransmitter::setPitchReverse(const bool& reverse)
{
  pitch_ch.setReverse(reverse);
}




void UniversalTransmitter::setRollReverse(const bool& reverse)
{
  roll_ch.setReverse(reverse);
}




void UniversalTransmitter::setYawReverse(const bool& reverse)
{
  yaw_ch.setReverse(reverse);
}




void UniversalTransmitter::setThrottleReverse(const bool& reverse)
{
  throttle_ch.setReverse(reverse);
}




void UniversalTransmitter::setKnob1Reverse(const bool& reverse)
{
  knob1_ch.setReverse(reverse);
}




void UniversalTransmitter::setKnob2Reverse(const bool& reverse)
{
  knob2_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw1Reverse(const bool& reverse)
{
  sw_1_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw2Reverse(const bool& reverse)
{
  sw_2_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw3Reverse(const bool& reverse)
{
  sw_3_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw4Reverse(const bool& reverse)
{
  sw_4_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw5Reverse(const bool& reverse)
{
  sw_5_ch.setReverse(reverse);
}




void UniversalTransmitter::setSw6Reverse(const bool& reverse)
{
  sw_6_ch.setReverse(reverse);
}




void UniversalTransmitter::setTriSwAReverse(const bool& reverse)
{
  tri_sw_a_ch.setReverse(reverse);
}




void UniversalTransmitter::setTriSwBReverse(const bool& reverse)
{
  tri_sw_b_ch.setReverse(reverse);
}




bool UniversalTransmitter::getPitchReverse()
{
  return pitch_ch.getReverse();
}




bool UniversalTransmitter::getRollReverse()
{
  return roll_ch.getReverse();
}




bool UniversalTransmitter::getYawReverse()
{
  return yaw_ch.getReverse();
}




bool UniversalTransmitter::getThrottleReverse()
{
  return throttle_ch.getReverse();
}




bool UniversalTransmitter::getKnob1Reverse()
{
  return knob1_ch.getReverse();
}




bool UniversalTransmitter::getKnob2Reverse()
{
  return knob2_ch.getReverse();
}




bool UniversalTransmitter::getSw1Reverse()
{
  return sw_1_ch.getReverse();
}




bool UniversalTransmitter::getSw2Reverse()
{
  return sw_2_ch.getReverse();
}




bool UniversalTransmitter::getSw3Reverse()
{
  return sw_3_ch.getReverse();
}




bool UniversalTransmitter::getSw4Reverse()
{
  return sw_4_ch.getReverse();
}




bool UniversalTransmitter::getSw5Reverse()
{
  return sw_5_ch.getReverse();
}




bool UniversalTransmitter::getSw6Reverse()
{
  return sw_6_ch.getReverse();
}




bool UniversalTransmitter::getTriSwAReverse()
{
  return tri_sw_a_ch.getReverse();
}




bool UniversalTransmitter::getTriSwBReverse()
{
  return tri_sw_b_ch.getReverse();
}




float UniversalTransmitter::shuntVoltage()
{
  return shuntvoltage;
}




float UniversalTransmitter::busVoltage()
{
  return busvoltage;
}




float UniversalTransmitter::current()
{
  return current_mA;
}




float UniversalTransmitter::power()
{
  return power_mW;
}




float UniversalTransmitter::loadVoltage()
{
  return loadvoltage;
}




bool UniversalTransmitter::wasTouched()
{
  return !touch_handled;
}




void UniversalTransmitter::clearTouch()
{
  touch_handled = true;
}




float UniversalTransmitter::touchX()
{
  return ts_point.x;
}




float UniversalTransmitter::touchY()
{
  return ts_point.y;
}




float UniversalTransmitter::touchPressure()
{
  return ts_point.z;
}




float UniversalTransmitter::expo(const float& input, const float& expo)
{
  return applyExpo(input, expo);
}




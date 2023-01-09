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




int UniversalController::pitchJoy()
{
  return analogRead(PITCH_PIN);
}




int UniversalController::rollJoy()
{
  return analogRead(ROLL_PIN);
}




int UniversalController::yawJoy()
{
  return analogRead(YAW_PIN);
}




int UniversalController::throttleJoy()
{
  return analogRead(THROTTLE_PIN);
}




int UniversalController::knob1()
{
  return analogRead(KNOB_1_PIN);
}




int UniversalController::knob2()
{
  return analogRead(KNOB_2_PIN);
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




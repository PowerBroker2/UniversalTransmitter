#pragma once
#include <EEPROM.h>
#include "chHelper.h"




extern UniversalController myController;




const float PREAMBLE = 11.8;




float readPreamble = 0;




template <typename T>
int putVal(const int& startAddr, const T& val)
{
  EEPROM.put(startAddr, val);
  return startAddr + sizeof(val);
}




template <typename T>
int pullVal(const int& startAddr, T& val)
{
  EEPROM.get(startAddr, val);
  return startAddr + sizeof(val);
}




void saveSettings()
{
  Serial.println("Saving");
  
  int i = 0;
  
  i = putVal(i, PREAMBLE);
  i = putVal(i, myController.getPitchExpo());
  i = putVal(i, myController.getRollExpo());
  i = putVal(i, myController.getYawExpo());
  i = putVal(i, myController.getThrottleExpo());
  i = putVal(i, myController.getKnob1Expo());
  i = putVal(i, myController.getKnob2Expo());
  i = putVal(i, myController.getPitchReverse());
  i = putVal(i, myController.getRollReverse());
  i = putVal(i, myController.getYawReverse());
  i = putVal(i, myController.getThrottleReverse());
  i = putVal(i, myController.getKnob1Reverse());
  i = putVal(i, myController.getKnob2Reverse());
  i = putVal(i, myController.getSw1Reverse());
  i = putVal(i, myController.getSw2Reverse());
  i = putVal(i, myController.getSw3Reverse());
  i = putVal(i, myController.getSw4Reverse());
  i = putVal(i, myController.getSw5Reverse());
  i = putVal(i, myController.getSw6Reverse());
  i = putVal(i, (float)myController.getPitchMix());
  i = putVal(i, (float)myController.getRollMix());
  i = putVal(i, (float)myController.getYawMix());
  i = putVal(i, (float)myController.getThrottleMix());
  i = putVal(i, (float)myController.getKnob1Mix());
  i = putVal(i, (float)myController.getKnob2Mix());
  i = putVal(i, (float)myController.getSw1Mix());
  i = putVal(i, (float)myController.getSw2Mix());
  i = putVal(i, (float)myController.getSw3Mix());
  i = putVal(i, (float)myController.getSw4Mix());
  i = putVal(i, (float)myController.getSw5Mix());
  i = putVal(i, (float)myController.getSw6Mix());
  i = putVal(i, myController.getPitchMixCh());
  i = putVal(i, myController.getRollMixCh());
  i = putVal(i, myController.getYawMixCh());
  i = putVal(i, myController.getThrottleMixCh());
  i = putVal(i, myController.getKnob1MixCh());
  i = putVal(i, myController.getKnob2MixCh());
  i = putVal(i, myController.getSw1MixCh());
  i = putVal(i, myController.getSw2MixCh());
  i = putVal(i, myController.getSw3MixCh());
  i = putVal(i, myController.getSw4MixCh());
  i = putVal(i, myController.getSw5MixCh());
  i = putVal(i, myController.getSw6MixCh());
  i = putVal(i, myController.pitchTrim());
  i = putVal(i, myController.rollTrim());
  i = putVal(i, myController.yawTrim());
  i = putVal(i, myController.throttleTrim());

  Serial.print("Saved "); Serial.print(i); Serial.println(" bytes");
}




void loadSettings()
{
  int i = 0;

  i = pullVal(i, readPreamble);

  if (readPreamble != PREAMBLE)
  {
    saveSettings();
  }
  else
  {
    Serial.println("Reading");

    float tempFloat;
    int   tempInt;
    bool  tempBool;

    i = pullVal(i, tempFloat);
    myController.setPitchExpo(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setRollExpo(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setYawExpo(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setThrottleExpo(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setKnob1Expo(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setKnob2Expo(tempFloat);
    
    i = pullVal(i, tempBool);
    myController.setPitchReverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setRollReverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setYawReverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setThrottleReverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setKnob1Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setKnob2Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw1Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw2Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw3Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw4Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw5Reverse(tempBool);
    
    i = pullVal(i, tempBool);
    myController.setSw6Reverse(tempBool);
    
    i = pullVal(i, tempFloat);
    myController.setPitchMix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setRollMix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setYawMix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setThrottleMix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setKnob1Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setKnob2Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw1Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw2Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw3Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw4Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw5Mix(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setSw6Mix(tempFloat);
    
    i = pullVal(i, tempInt);
    myController.setPitchMixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setRollMixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setYawMixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setThrottleMixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setKnob1MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setKnob2MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw1MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw2MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw3MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw4MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw5MixCh(tempInt);
    
    i = pullVal(i, tempInt);
    myController.setSw6MixCh(tempInt);
    
    i = pullVal(i, tempFloat);
    myController.setPitchTrim(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setRollTrim(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setYawTrim(tempFloat);
    
    i = pullVal(i, tempFloat);
    myController.setThrottleTrim(tempFloat);
    
    Serial.print("Read "); Serial.print(i); Serial.println(" bytes");
  }
}

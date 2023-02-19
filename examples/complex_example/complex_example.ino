#include "UniversalTransmitter.h"
#include "chHelper.h"
#include "tftHelper.h"
#include "settingsHelper.h"
#include "commsHelper.h"




UniversalTransmitter myController;




void setup()
{
  myController.begin();
  
  myController.setPitchADCLimits(minPitchADC, maxPitchADC);
  myController.setRollADCLimits(minRollADC, maxRollADC);
  myController.setYawADCLimits(minYawADC, maxYawADC);
  myController.setThrottleADCLimits(minThrottleADC, maxThrottleADC);
  myController.setKnob1ADCLimits(minKnob1ADC, maxKnob1ADC);
  myController.setKnob2ADCLimits(minKnob2ADC, maxKnob2ADC);

  //saveSettings();
  loadSettings();
  initMenu();
  setupComms();
}




void loop()
{
  sendData();
}

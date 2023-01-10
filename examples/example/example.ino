#include "UniversalController.h"




UniversalController myController;




void setup()
{
  Serial.begin(2000000);

  myController.begin();
}




void loop()
{
  Serial.println("**************************************************");
  Serial.println();
  
  testBuddy();
  testSwitches();
  testJoys();
  testKnobs();
  testPowerMon();
  testTouch();
  
  delay(10);
}




void testBuddy()
{
  int channels = myController.numBuddyChannels();
  Serial.print("Number of buddy channels: "); Serial.println(channels);

  for (int i=0; i<channels; i++)
  {
    Serial.print("Channel "); Serial.print(i + 1); Serial.print(": "); Serial.println(myController.buddyChannel(i));
  }
  
  Serial.println();
}




void testSwitches()
{
  Serial.print("SW 1 Was Switched: "); Serial.println(myController.sw1SwitchFlag());
  Serial.print("SW 2 Was Switched: "); Serial.println(myController.sw2SwitchFlag());
  Serial.print("SW 3 Was Switched: "); Serial.println(myController.sw3SwitchFlag());
  Serial.print("SW 4 Was Switched: "); Serial.println(myController.sw4SwitchFlag());
  Serial.print("SW 5 Was Switched: "); Serial.println(myController.sw5SwitchFlag());
  Serial.print("SW 6 Was Switched: "); Serial.println(myController.sw6SwitchFlag());
  
  Serial.print("Tri SW A Was Switched: "); Serial.println(myController.triSwASwitchFlag());
  Serial.print("Tri SW B Was Switched: "); Serial.println(myController.triSwBSwitchFlag());

  Serial.print("SW 1 State: "); Serial.println(myController.sw1State());
  Serial.print("SW 2 State: "); Serial.println(myController.sw2State());
  Serial.print("SW 3 State: "); Serial.println(myController.sw3State());
  Serial.print("SW 4 State: "); Serial.println(myController.sw4State());
  Serial.print("SW 5 State: "); Serial.println(myController.sw5State());
  Serial.print("SW 6 State: "); Serial.println(myController.sw6State());
  
  Serial.print("Tri SW A State: "); Serial.println(myController.triSwAState());
  Serial.print("Tri SW B State: "); Serial.println(myController.triSwBState());

  Serial.println();

  myController.clearsw1SwitchFlag();
  myController.clearsw2SwitchFlag();
  myController.clearsw3SwitchFlag();
  myController.clearsw4SwitchFlag();
  myController.clearsw5SwitchFlag();
  myController.clearsw6SwitchFlag();
  
  myController.cleartriSwASwitchFlag();
  myController.cleartriSwBSwitchFlag();
}




void testJoys()
{
  Serial.print("Pitch Joy: "); Serial.println(myController.pitchJoy());
  Serial.print("Roll Joy: ");  Serial.println(myController.rollJoy());
  Serial.print("Yaw Joy: ");   Serial.println(myController.yawJoy());
  Serial.print("Throttle: ");  Serial.println(myController.throttleJoy());

  Serial.println();
}




void testKnobs()
{
  Serial.print("Knob 1: "); Serial.println(myController.knob1());
  Serial.print("Knob 2: "); Serial.println(myController.knob2());

  Serial.println();
}




void testPowerMon()
{
  Serial.print("Shunt Voltage: "); Serial.println(myController.shuntVoltage());
  Serial.print("Bus Voltage: ");   Serial.println(myController.busVoltage());
  Serial.print("Current: ");       Serial.println(myController.current());
  Serial.print("Power: ");         Serial.println(myController.power());
  Serial.print("Load Voltage: ");  Serial.println(myController.loadVoltage());

  Serial.println();
}




void testTouch()
{
  Serial.print("Was Touched: ");    Serial.println(myController.wasTouched());
  Serial.print("Touch X: ");        Serial.println(myController.touchX());
  Serial.print("Touch Y: ");        Serial.println(myController.touchY());
  Serial.print("Touch Pressure: "); Serial.println(myController.touchPressure());

  Serial.println();

  myController.clearTouch();
}




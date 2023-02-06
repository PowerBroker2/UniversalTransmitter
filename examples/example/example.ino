#include "UniversalController.h"
#include "display/display.h"
#include "radios/radios.h"




UniversalController myController;




int minPitchADC    = 420;
int maxPitchADC    = 3930;
int minRollADC     = 175;
int maxRollADC     = 3815;
int minYawADC      = 165;
int maxYawADC      = 3750;
int minThrottleADC = 430;
int maxThrottleADC = 4000;
int minKnob1ADC    = 0;
int maxKnob1ADC    = 4090;
int minKnob2ADC    = 0;
int maxKnob2ADC    = 4090;




void setup()
{
  Serial.begin(2000000);
  BT.begin(38400);
  ESP.begin(115200);

  myController.begin();

  myController.setPitchADCLimits(minPitchADC, maxPitchADC);
  myController.setRollADCLimits(minRollADC, maxRollADC);
  myController.setYawADCLimits(minYawADC, maxYawADC);
  myController.setThrottleADCLimits(minThrottleADC, maxThrottleADC);
  myController.setKnob1ADCLimits(minKnob1ADC, maxKnob1ADC);
  myController.setKnob2ADCLimits(minKnob2ADC, maxKnob2ADC);

//  myController.setThrottleExpo(100);
//  myController.setThrottleReverse(true);
//  myController.setThrottleMixCh(SW_1_CH);
//  myController.setThrottleMix(50);
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
  testBT();
  testESP();
  
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

  Serial.println();
  
  Serial.print("SW 1 State: "); Serial.println(myController.sw1State());
  Serial.print("SW 2 State: "); Serial.println(myController.sw2State());
  Serial.print("SW 3 State: "); Serial.println(myController.sw3State());
  Serial.print("SW 4 State: "); Serial.println(myController.sw4State());
  Serial.print("SW 5 State: "); Serial.println(myController.sw5State());
  Serial.print("SW 6 State: "); Serial.println(myController.sw6State());
  
  Serial.print("Tri SW A State: "); Serial.println(myController.triSwAState());
  Serial.print("Tri SW B State: "); Serial.println(myController.triSwBState());

  Serial.println();

  myController.clearSw1SwitchFlag();
  myController.clearSw2SwitchFlag();
  myController.clearSw3SwitchFlag();
  myController.clearSw4SwitchFlag();
  myController.clearSw5SwitchFlag();
  myController.clearSw6SwitchFlag();
  
  myController.clearTriSwASwitchFlag();
  myController.clearTriSwBSwitchFlag();
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




FASTRUN void whenTouched()
{
    if (ts.tirqTouched())
    {
        enableTS();
      
        if (ts.touched())
        {
            long currTime = micros();

            if ((currTime - time_touched) >= TOUCH_TIME_THRESH)
            {
                ts_point      = ts.getPoint();
                touch_handled = false;
                time_touched  = currTime;
            }
            else
            {
                ts.getPoint();
            }
        }
        
        disableTS();
    }
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




void testBT()
{
  if (BT.available())
  {
    Serial.println("BlueTooth Message: ");
    
    while (BT.available())
    {
      char c = BT.read();
      
      Serial.write(c);
      BT.write(c);
    }
  }
}




void testESP()
{
  if (Serial.available())
  {
    String instr = Serial.readString();
    
    Serial.print(instr);
    ESP.print(instr);
  }
  
  if (ESP.available())
  {
    delay(10);
    Serial.println("ESP Message: ");
    
    while (ESP.available())
    {
      Serial.write(ESP.read());
    }
  }
}
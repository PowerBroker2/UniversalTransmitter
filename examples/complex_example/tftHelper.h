#pragma once
#include "TeensyTimerTool.h"
#include "FireTimer.h"
#include "UniversalController.h"
#include "display/display.h"
#include "radios/radios.h"
#include "inputs/inputs.h"
#include "tftHelper.h"
#include "chHelper.h"
#include "settingsHelper.h"
#include "button.h"
#include "wide_button.h"
#include "UpButton.h"
#include "DownButton.h"
#include "XButton.h"
#include "CheckButton.h"
#include "SaveButton.h"




using namespace TeensyTimerTool;




// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 300
#define TS_MAXX 3800
#define TS_MAXY 3900




const float MENU_FREQ   = 10.0;
const float MENU_PERIOD = 1.0 / MENU_FREQ;

const int VOLTAGE_PERIOD_MS = 30000;




FireTimer voltTimer;
PeriodicTimer menuTimer;
extern UniversalController myController;




void drawColorImg(const uint16_t pixMap[], const uint16_t alphaMask[], const int& h, const int& w, const int& startCol = 0, const int& startRow = 0)
{
  int buffidx = 0;
  
  for (int row = 0; row < h; row++)
  {
    for (int col = 0; col < w; col++)
    {
      uint16_t pixVal = pgm_read_word(pixMap + buffidx);

      if (pgm_read_word(alphaMask + buffidx) >= 210)
      {
        tft.drawPixel(startCol + col, startRow + row, pixVal);
      }
        
      buffidx++;
    }
  }
}




void drawBox(const int& h, const int& w, const int& startCol, const int& startRow, const int& lineWidth = 5, const int& lineColor = ILI9341_WHITE)
{
  for (int row = 0; row < h; row++)
  {
    for (int col = 0; col < w; col++)
    {
      if ((row < lineWidth) || ((h - row) <= lineWidth))
      {
        tft.drawPixel(startCol + col, startRow + row, lineColor);
      }
      else if ((col < lineWidth) || ((w - col) <= lineWidth))
      {
        tft.drawPixel(startCol + col, startRow + row, lineColor);
      }
    }
  }
}




class tftArea
{
public: // <<---------------------------------------//public
  bool enable    = false;
  bool usePixmap = false;
  bool useBorder = false;
  
  const uint16_t* pixMap    = NULL;
  const uint16_t* alphaMask = NULL;
  
  int backgroundColor = ILI9341_NAVY;
  int clearColor      = ILI9341_NAVY;
  int borderColor     = ILI9341_WHITE;
  int textColor       = ILI9341_WHITE;
  
  int h = 0;
  int w = 0;
  
  int startCol = 0;
  int startRow = 0;
  
  int borderWidth = 1;
  
  char text[50]     = "\0";
  int textSize      = 1;
  int textCursorRow = 0;
  int textCursorCol = 0;
  int textRowNudge  = 0;
  int textColNudge  = 0;




  void clearText()
  {
    tft.setCursor(textCursorRow, textCursorCol);
    tft.setTextColor(clearColor);
    tft.setTextSize(textSize);
    tft.print(text);
  }




  void drawText()
  {
    tft.setCursor(textCursorRow, textCursorCol);
    tft.setTextColor(textColor);
    tft.setTextSize(textSize);
    tft.print(text);
  }



  
  void draw()
  {
    enable = true;

    if (usePixmap && (pixMap != NULL) && (alphaMask != NULL))
    {
      drawColorImg(pixMap, alphaMask, h, w, startCol, startRow);
    }
    else
    {
      tft.fillRect(startCol, startRow, w, h, backgroundColor);
    }

    if (useBorder)
    {
      drawBox(h, w, startCol, startRow, borderWidth, borderColor);
    }

    if (text[0] != '\0')
    {
      textCursorRow = (w / 2.0) - ((strlen(text) * textSize * 12.0) / 4.0) + startCol + textColNudge;
      textCursorCol = (h / 2.0) - (textSize * 10.0 / 2.0) + startRow + textRowNudge;
      
      drawText();
    }
  }


  

  void clear()
  {
    enable = false;
    tft.fillRect(startCol, startRow, w, h, clearColor);
  }


  

  bool inArea(const int& row, const int& col)
  {
    if (enable)
    {
      int minRow = startRow;
      int maxRow = minRow + h;
      int minCol = startCol;
      int maxCol = minCol + w;
  
      if ((row >= minRow) && (row <= maxRow) && (col >= minCol) && (col <= maxCol))
      {
        return true;
      }
    }
    
    return false;
  }
};




tftArea backButton;
tftArea voltageDisp;

tftArea channelEditButton;
tftArea channelMixesButton;
tftArea ioMonButton;

tftArea pitchTrimMarker;
tftArea pitchTrimCenterMarker;
tftArea rollTrimMarker;
tftArea rollTrimCenterMarker;
tftArea yawTrimMarker;
tftArea yawTrimCenterMarker;
tftArea throttleTrimMarker;
tftArea throttleTrimCenterMarker;

tftArea sw1StateArea;
tftArea sw2StateArea;
tftArea sw3StateArea;
tftArea sw4StateArea;
tftArea sw5StateArea;
tftArea sw6StateArea;
tftArea triSwAStateArea;
tftArea triSwBStateArea;

tftArea pitchJoyArea;
tftArea rollJoyArea;
tftArea yawJoyArea;
tftArea throttleJoyArea;

tftArea knob1Area;
tftArea knob2Area;

tftArea shuntVoltageArea;
tftArea busVoltageArea;
tftArea currentArea;
tftArea loadVoltageArea;

tftArea buddy1Area;
tftArea buddy2Area;
tftArea buddy3Area;
tftArea buddy4Area;
tftArea buddy5Area;
tftArea buddy6Area;
tftArea buddy7Area;
tftArea buddy8Area;

tftArea chEditNumArea;
tftArea chEditNumUpArea;
tftArea chEditNumDownArea;
tftArea chReverseArea;
tftArea chReverseChangeArea;
tftArea chExpoArea;
tftArea chExpoUpArea;
tftArea chExpoDownArea;
tftArea chExpoGraphArea;

tftArea chMixFirstNumArea;
tftArea chMixFirstNumUpArea;
tftArea chMixFirstNumDownArea;
tftArea chMixSecondNumArea;
tftArea chMixSecondNumUpArea;
tftArea chMixSecondNumDownArea;
tftArea chMixArea;
tftArea chMixUpArea;
tftArea chMixDownArea;

tftArea saveArea;




char tempStr[6];




bool ioMonFlag  = false;
bool chEditFlag = false;
bool chMixFlag  = false;




void updateMenu()
{
  if (voltTimer.fire())
  {
    noInterrupts();
    voltageDisp.clearText();
    dtostrf(myController.busVoltage(), 4, 2, tempStr);
    sprintf(voltageDisp.text, "Batt: %sV", tempStr);
    voltageDisp.drawText();
    interrupts();
  }
  
  if (myController.pitchTrimFlag())
  {
    myController.clearPitchTrimFlag();
    
    noInterrupts();
    pitchTrimMarker.clear();
    pitchTrimCenterMarker.draw();
    tft.drawLine(ILI9341_TFTWIDTH - 10, ILI9341_TFTHEIGHT - 60, ILI9341_TFTWIDTH - 10, 60, ILI9341_WHITE);
    interrupts();
    
    pitchTrimMarker.startRow = map(myController.pitchTrim(), -1, 1, ILI9341_TFTHEIGHT - 60 - pitchTrimMarker.h, 60);
    
    noInterrupts();
    pitchTrimMarker.draw();
    interrupts();
  }
  
  if (myController.rollTrimFlag())
  {
    myController.clearRollTrimFlag();
    
    noInterrupts();
    rollTrimMarker.clear();
    rollTrimCenterMarker.draw();
    tft.drawLine(20, 10, ILI9341_TFTWIDTH - 20, 10, ILI9341_WHITE);
    interrupts();
    
    rollTrimMarker.startCol = map(myController.rollTrim(), -1, 1, 20, ILI9341_TFTWIDTH - 20 - rollTrimMarker.w);
    
    noInterrupts();
    rollTrimMarker.draw();
    interrupts();
  }
  
  if (myController.yawTrimFlag())
  {
    myController.clearYawTrimFlag();
    
    noInterrupts();
    yawTrimMarker.clear();
    yawTrimCenterMarker.draw();
    tft.drawLine(20, ILI9341_TFTHEIGHT - 10, ILI9341_TFTWIDTH - 20, ILI9341_TFTHEIGHT - 10, ILI9341_WHITE);
    interrupts();
    
    yawTrimMarker.startCol = map(myController.yawTrim(), -1, 1, 20, ILI9341_TFTWIDTH - 20 - yawTrimMarker.w);
    
    noInterrupts();
    yawTrimMarker.draw();
    interrupts();
  }
  
  if (myController.throttleTrimFlag())
  {
    myController.clearThrottleTrimFlag();
    
    noInterrupts();
    throttleTrimMarker.clear();
    throttleTrimCenterMarker.draw();
    tft.drawLine(10, ILI9341_TFTHEIGHT - 60, 10, 60, ILI9341_WHITE);
    interrupts();
    
    throttleTrimMarker.startRow = map(myController.throttleTrim(), -1, 1, ILI9341_TFTHEIGHT - 60 - throttleTrimMarker.h, 60);
    
    noInterrupts();
    throttleTrimMarker.draw();
    interrupts();
  }


  if (ioMonFlag)
  {
    if (myController.sw1SwitchFlag())
    {
      myController.clearSw1SwitchFlag();
      
      noInterrupts();
      sw1StateArea.clearText();
      sprintf(sw1StateArea.text, "SW 1: %d", (int)round(myController.sw1State()));
      sw1StateArea.drawText();
      interrupts();
    }
    
    if (myController.sw2SwitchFlag())
    {
      myController.clearSw2SwitchFlag();
      
      noInterrupts();
      sw2StateArea.clearText();
      sprintf(sw2StateArea.text, "SW 2: %d", (int)round(myController.sw2State()));
      sw2StateArea.drawText();
      interrupts();
    }
    
    if (myController.sw3SwitchFlag())
    {
      myController.clearSw3SwitchFlag();
      
      noInterrupts();
      sw3StateArea.clearText();
      sprintf(sw3StateArea.text, "SW 3: %d", (int)round(myController.sw3State()));
      sw3StateArea.drawText();
      interrupts();
    }
    
    if (myController.sw4SwitchFlag())
    {
      myController.clearSw4SwitchFlag();
      
      noInterrupts();
      sw4StateArea.clearText();
      sprintf(sw4StateArea.text, "SW 4: %d", (int)round(myController.sw4State()));
      sw4StateArea.drawText();
      interrupts();
    }
    
    if (myController.sw5SwitchFlag())
    {
      myController.clearSw5SwitchFlag();
      
      noInterrupts();
      sw5StateArea.clearText();
      sprintf(sw5StateArea.text, "SW 5: %d", (int)round(myController.sw5State()));
      sw5StateArea.drawText();
      interrupts();
    }
    
    if (myController.sw6SwitchFlag())
    {
      myController.clearSw6SwitchFlag();
      
      noInterrupts();
      sw6StateArea.clearText();
      sprintf(sw6StateArea.text, "SW 6: %d", (int)round(myController.sw6State()));
      sw6StateArea.drawText();
      interrupts();
    }
    
    if (myController.triSwASwitchFlag())
    {
      myController.clearTriSwASwitchFlag();
      
      noInterrupts();
      triSwAStateArea.clearText();
      sprintf(triSwAStateArea.text, "TSW A: %d", (int)round(myController.triSwAState()));
      triSwAStateArea.drawText();
      interrupts();
    }
    
    if (myController.triSwBSwitchFlag())
    {
      myController.clearTriSwBSwitchFlag();
      
      noInterrupts();
      triSwBStateArea.clearText();
      sprintf(triSwBStateArea.text, "TSW B: %d", (int)round(myController.triSwBState()));
      triSwBStateArea.drawText();
      interrupts();
    }
    
    noInterrupts();
    pitchJoyArea.clearText();
    dtostrf(myController.pitchJoy(), 4, 2, tempStr);
    sprintf(pitchJoyArea.text, "Pitch: %s", tempStr);
    pitchJoyArea.drawText();
    
    rollJoyArea.clearText();
    dtostrf(myController.rollJoy(), 4, 2, tempStr);
    sprintf(rollJoyArea.text, "Roll: %s", tempStr);
    rollJoyArea.drawText();
    
    yawJoyArea.clearText();
    dtostrf(myController.yawJoy(), 4, 2, tempStr);
    sprintf(yawJoyArea.text, "Yaw: %s", tempStr);
    yawJoyArea.drawText();
    
    throttleJoyArea.clearText();
    dtostrf(myController.throttleJoy(), 4, 2, tempStr);
    sprintf(throttleJoyArea.text, "Trtl: %s", tempStr);
    throttleJoyArea.drawText();
    
    knob1Area.clearText();
    dtostrf(myController.knob1(), 4, 2, tempStr);
    sprintf(knob1Area.text, "kb 1: %s", tempStr);
    knob1Area.drawText();
    
    knob2Area.clearText();
    dtostrf(myController.knob2(), 4, 2, tempStr);
    sprintf(knob2Area.text, "kb 2: %s", tempStr);
    knob2Area.drawText();
    
    shuntVoltageArea.clearText();
    dtostrf(myController.shuntVoltage(), 4, 2, tempStr);
    sprintf(shuntVoltageArea.text, "Shunt: %s", tempStr);
    shuntVoltageArea.drawText();
    
    busVoltageArea.clearText();
    dtostrf(myController.busVoltage(), 4, 2, tempStr);
    sprintf(busVoltageArea.text, "Bus: %s", tempStr);
    busVoltageArea.drawText();
    
    currentArea.clearText();
    dtostrf(myController.current(), 4, 2, tempStr);
    sprintf(currentArea.text, "Cur: %s", tempStr);
    currentArea.drawText();
    
    loadVoltageArea.clearText();
    dtostrf(myController.loadVoltage(), 4, 2, tempStr);
    sprintf(loadVoltageArea.text, "Load: %s", tempStr);
    loadVoltageArea.drawText();
    interrupts();

    if (myController.numBuddyChannels() == SW_3_CH)
    {
      noInterrupts();
      buddy1Area.clearText();
      sprintf(buddy1Area.text, "Bud 1: %d", myController.buddyChannel(0));
      buddy1Area.drawText();
      
      buddy2Area.clearText();
      sprintf(buddy2Area.text, "Bud 2: %d", myController.buddyChannel(1));
      buddy2Area.drawText();
      
      buddy3Area.clearText();
      sprintf(buddy3Area.text, "Bud 3: %d", myController.buddyChannel(2));
      buddy3Area.drawText();
      
      buddy4Area.clearText();
      sprintf(buddy4Area.text, "Bud 4: %d", myController.buddyChannel(3));
      buddy4Area.drawText();
      
      buddy5Area.clearText();
      sprintf(buddy5Area.text, "Bud 5: %d", myController.buddyChannel(4));
      buddy5Area.drawText();
      
      buddy6Area.clearText();
      sprintf(buddy6Area.text, "Bud 6: %d", myController.buddyChannel(5));
      buddy6Area.drawText();
      
      buddy7Area.clearText();
      sprintf(buddy7Area.text, "Bud 7: %d", myController.buddyChannel(6));
      buddy7Area.drawText();
      
      buddy8Area.clearText();
      sprintf(buddy8Area.text, "Bud 8: %d", myController.buddyChannel(7));
      buddy8Area.drawText();
      interrupts();
    }
  }

  if (chEditFlag)
  {
    if (chReverseChangeFlag || chChangeFlag || expoChangeFlag)
    {
      noInterrupts();
      chExpoGraphArea.draw();
      interrupts();
      
      float expo = 0;
      
      if (chVal == PITCH_CH)
        expo = myController.getPitchExpo();
      else if (chVal == ROLL_CH)
        expo = myController.getRollExpo();
      else if (chVal == YAW_CH)
        expo = myController.getYawExpo();
      else if (chVal == THROTTLE_CH)
        expo = myController.getThrottleExpo();
      else if (chVal == KNOB_1_CH)
        expo = myController.getKnob1Expo();
      else if (chVal == KNOB_2_CH)
        expo = myController.getKnob2Expo();
      
      bool reverse = false;

      if (chVal == PITCH_CH)
        reverse = myController.getPitchReverse();
      else if (chVal == ROLL_CH)
        reverse = myController.getRollReverse();
      else if (chVal == YAW_CH)
        reverse = myController.getYawReverse();
      else if (chVal == THROTTLE_CH)
        reverse = myController.getThrottleReverse();
      else if (chVal == KNOB_1_CH)
        reverse = myController.getKnob1Reverse();
      else if (chVal == KNOB_2_CH)
        reverse = myController.getKnob2Reverse();
      else if (chVal == SW_1_CH)
        reverse = myController.getSw1Reverse();
      else if (chVal == SW_2_CH)
        reverse = myController.getSw2Reverse();
      else if (chVal == SW_3_CH)
        reverse = myController.getSw3Reverse();
      else if (chVal == SW_4_CH)
        reverse = myController.getSw4Reverse();
      else if (chVal == SW_5_CH)
        reverse = myController.getSw5Reverse();
      else if (chVal == SW_6_CH)
        reverse = myController.getSw6Reverse();
      
      for (int i = 0; i < (chExpoGraphArea.w - 2); i++)
      {
        int col = i + chExpoGraphArea.startCol;

        float input = 0;

        if (reverse)
          input = mapfloat(i, 0.0, chExpoGraphArea.w - 2.0, 1.0, -1.0);
        else
          input = mapfloat(i, 0.0, chExpoGraphArea.w - 2.0, -1.0, 1.0);
        
        int row = (int)((chExpoGraphArea.h / 2.0) * myController.expo(input, expo)) + chExpoGraphArea.startRow + (int)(chExpoGraphArea.h / 2);

        noInterrupts();
        tft.drawPixel(col, row, ILI9341_WHITE);
        interrupts();
      }
    }
    
    if (chReverseChangeFlag || chChangeFlag)
    {
      chReverseChangeFlag = false;
      
      if (((chVal == PITCH_CH)    && myController.getPitchReverse())    ||
          ((chVal == ROLL_CH)     && myController.getRollReverse())     ||
          ((chVal == YAW_CH)      && myController.getYawReverse())      ||
          ((chVal == THROTTLE_CH) && myController.getThrottleReverse()) ||
          ((chVal == KNOB_1_CH)   && myController.getKnob1Reverse())    ||
          ((chVal == KNOB_2_CH)   && myController.getKnob2Reverse())    ||
          ((chVal == SW_1_CH)     && myController.getSw1Reverse())      ||
          ((chVal == SW_2_CH)     && myController.getSw2Reverse())      ||
          ((chVal == SW_3_CH)     && myController.getSw3Reverse())      ||
          ((chVal == SW_4_CH)     && myController.getSw4Reverse())      ||
          ((chVal == SW_5_CH)     && myController.getSw5Reverse())      ||
          ((chVal == SW_6_CH)     && myController.getSw6Reverse()))
      {
        chReverseChangeArea.pixMap    = checkButtonPixMap;
        chReverseChangeArea.alphaMask = checkButtonAlphaMask;
      }
      else
      {
        chReverseChangeArea.pixMap    = xButtonPixMap;
        chReverseChangeArea.alphaMask = xButtonAlphaMask;
      }

      noInterrupts();
      chReverseChangeArea.clear();
      chReverseChangeArea.draw();
      interrupts();
    }

    if (expoChangeFlag || chChangeFlag)
    {
      expoChangeFlag = false;
      
      noInterrupts();
      chExpoArea.clearText();
  
      if (chVal == PITCH_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getPitchExpo());
      else if (chVal == ROLL_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getRollExpo());
      else if (chVal == YAW_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getYawExpo());
      else if (chVal == THROTTLE_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getThrottleExpo());
      else if (chVal == KNOB_1_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getKnob1Expo());
      else if (chVal == KNOB_2_CH)
        sprintf(chExpoArea.text, "Expo: %d", (int)myController.getKnob2Expo());
      else
        sprintf(chExpoArea.text, "Expo: %d", 0);
      
      chExpoArea.drawText();
      interrupts();
    }
    
    if (chChangeFlag)
    {
      chChangeFlag = false;
    
      noInterrupts();
      chEditNumArea.clear();
      
      if (chVal == PITCH_CH)
        sprintf(chEditNumArea.text, "Pitch");
      else if (chVal == ROLL_CH)
        sprintf(chEditNumArea.text, "Roll");
      else if (chVal == YAW_CH)
        sprintf(chEditNumArea.text, "Yaw");
      else if (chVal == THROTTLE_CH)
        sprintf(chEditNumArea.text, "Thrtl");
      else if (chVal == KNOB_1_CH)
        sprintf(chEditNumArea.text, "Knob1");
      else if (chVal == KNOB_2_CH)
        sprintf(chEditNumArea.text, "Knob2");
      else if (chVal == SW_1_CH)
        sprintf(chEditNumArea.text, "SW1");
      else if (chVal == SW_2_CH)
        sprintf(chEditNumArea.text, "SW2");
      else if (chVal == SW_3_CH)
        sprintf(chEditNumArea.text, "SW3");
      else if (chVal == SW_4_CH)
        sprintf(chEditNumArea.text, "SW4");
      else if (chVal == SW_5_CH)
        sprintf(chEditNumArea.text, "SW5");
      else if (chVal == SW_6_CH)
        sprintf(chEditNumArea.text, "SW6");
  
      chEditNumArea.draw();
      interrupts();
    }
  }
  
  if (chMixFirstChangeFlag)
  {
    chMixFirstChangeFlag  = false;
    chMixSecondChangeFlag = true; // Need to reset other channel text
  
    noInterrupts();
    chMixFirstNumArea.clear();
    
    if (chVal1Mix == PITCH_CH)
    {
      chVal2Mix = myController.getPitchMixCh();
      sprintf(chMixFirstNumArea.text, "Pitch");
    }
    else if (chVal1Mix == ROLL_CH)
    {
      chVal2Mix = myController.getRollMixCh();
      sprintf(chMixFirstNumArea.text, "Roll");
    }
    else if (chVal1Mix == YAW_CH)
    {
      chVal2Mix = myController.getYawMixCh();
      sprintf(chMixFirstNumArea.text, "Yaw");
    }
    else if (chVal1Mix == THROTTLE_CH)
    {
      chVal2Mix = myController.getThrottleMixCh();
      sprintf(chMixFirstNumArea.text, "Thrtl");
    }
    else if (chVal1Mix == KNOB_1_CH)
    {
      chVal2Mix = myController.getKnob1MixCh();
      sprintf(chMixFirstNumArea.text, "Knob1");
    }
    else if (chVal1Mix == KNOB_2_CH)
    {
      chVal2Mix = myController.getKnob2MixCh();
      sprintf(chMixFirstNumArea.text, "Knob2");
    }
    else if (chVal1Mix == SW_1_CH)
    {
      chVal2Mix = myController.getSw1MixCh();
      sprintf(chMixFirstNumArea.text, "SW1");
    }
    else if (chVal1Mix == SW_2_CH)
    {
      chVal2Mix = myController.getSw2MixCh();
      sprintf(chMixFirstNumArea.text, "SW2");
    }
    else if (chVal1Mix == SW_3_CH)
    {
      chVal2Mix = myController.getSw3MixCh();
      sprintf(chMixFirstNumArea.text, "SW3");
    }
    else if (chVal1Mix == SW_4_CH)
    {
      chVal2Mix = myController.getSw4MixCh();
      sprintf(chMixFirstNumArea.text, "SW4");
    }
    else if (chVal1Mix == SW_5_CH)
    {
      chVal2Mix = myController.getSw5MixCh();
      sprintf(chMixFirstNumArea.text, "SW5");
    }
    else if (chVal1Mix == SW_6_CH)
    {
      chVal2Mix = myController.getSw6MixCh();
      sprintf(chMixFirstNumArea.text, "SW6");
    }

    chMixFirstNumArea.draw();
    interrupts();
  }

  if (chMixValChangeFlag || chMixFirstChangeFlag || chMixSecondChangeFlag)
  {
    chMixValChangeFlag = false;
  
    noInterrupts();
    chMixArea.clearText();
    
    if (chVal1Mix == PITCH_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getPitchMix());
    else if (chVal1Mix == ROLL_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getRollMix());
    else if (chVal1Mix == YAW_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getYawMix());
    else if (chVal1Mix == THROTTLE_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getThrottleMix());
    else if (chVal1Mix == KNOB_1_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getKnob1Mix());
    else if (chVal1Mix == KNOB_2_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getKnob2Mix());
    else if (chVal1Mix == SW_1_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw1Mix());
    else if (chVal1Mix == SW_2_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw2Mix());
    else if (chVal1Mix == SW_3_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw3Mix());
    else if (chVal1Mix == SW_4_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw4Mix());
    else if (chVal1Mix == SW_5_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw5Mix());
    else if (chVal1Mix == SW_6_CH)
      sprintf(chMixArea.text, "Mix: %d", (int)myController.getSw6Mix());
    
    chMixArea.drawText();
    interrupts();
  }
  
  if (chMixSecondChangeFlag)
  {
    chMixSecondChangeFlag = false;
  
    noInterrupts();
    chMixSecondNumArea.clear();

    if (chVal2Mix == PITCH_CH)
      sprintf(chMixSecondNumArea.text, "Pitch");
    else if (chVal2Mix == ROLL_CH)
      sprintf(chMixSecondNumArea.text, "Roll");
    else if (chVal2Mix == YAW_CH)
      sprintf(chMixSecondNumArea.text, "Yaw");
    else if (chVal2Mix == THROTTLE_CH)
      sprintf(chMixSecondNumArea.text, "Thrtl");
    else if (chVal2Mix == KNOB_1_CH)
      sprintf(chMixSecondNumArea.text, "Knob1");
    else if (chVal2Mix == KNOB_2_CH)
      sprintf(chMixSecondNumArea.text, "Knob2");
    else if (chVal2Mix == SW_1_CH)
      sprintf(chMixSecondNumArea.text, "SW1");
    else if (chVal2Mix == SW_2_CH)
      sprintf(chMixSecondNumArea.text, "SW2");
    else if (chVal2Mix == SW_3_CH)
      sprintf(chMixSecondNumArea.text, "SW3");
    else if (chVal2Mix == SW_4_CH)
      sprintf(chMixSecondNumArea.text, "SW4");
    else if (chVal2Mix == SW_5_CH)
      sprintf(chMixSecondNumArea.text, "SW5");
    else if (chVal2Mix == SW_6_CH)
      sprintf(chMixSecondNumArea.text, "SW6");

    chMixSecondNumArea.draw();
    interrupts();
  }
}




void initMenu()
{
  disableTS();
  enableTFT();

  voltTimer.begin(VOLTAGE_PERIOD_MS);

  noInterrupts();
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.fillScreen(ILI9341_NAVY);
  interrupts();
  
  saveArea.usePixmap = true;
  saveArea.pixMap    = saveButtonPixMap;
  saveArea.alphaMask = saveButtonAlphaMask;
  saveArea.h         = SAVE_BUTTON_H;
  saveArea.w         = SAVE_BUTTON_W;
  saveArea.startCol  = (ILI9341_TFTWIDTH / 2.0) - (saveArea.w / 2.0);
  saveArea.startRow  = 40;
  noInterrupts();
  saveArea.draw();
  interrupts();
  
  backButton.backgroundColor = ILI9341_MAGENTA;
  backButton.h               = 25;
  backButton.w               = 80;
  backButton.startCol        = saveArea.startCol - backButton.w;
  backButton.startRow        = saveArea.startRow + 5;
  backButton.textSize        = 2;
  backButton.textRowNudge    = 2;
  backButton.textColNudge    = 3;
  backButton.textColor       = ILI9341_BLACK;
  strcpy(backButton.text, "Back");
  
  voltageDisp.useBorder   = true;
  voltageDisp.borderWidth = 1;
  voltageDisp.h           = 25;
  voltageDisp.w           = backButton.w;
  voltageDisp.startCol    = saveArea.startCol + saveArea.w;
  voltageDisp.startRow    = saveArea.startRow + 5;
  dtostrf(myController.busVoltage(), 4, 2, tempStr);
  sprintf(voltageDisp.text, "Batt: %sV", tempStr);
  noInterrupts();
  voltageDisp.draw();
  interrupts();

  int buttonsStartRow = 100;
  
  channelEditButton.usePixmap = true;
  channelEditButton.pixMap    = wideButtonPixMap;
  channelEditButton.alphaMask = wideButtonAlphaMask;
  channelEditButton.h         = WIDE_BUTTON_H;
  channelEditButton.w         = WIDE_BUTTON_W;
  channelEditButton.startCol  = 30;
  channelEditButton.startRow  = buttonsStartRow;
  channelEditButton.textSize  = 2;
  strcpy(channelEditButton.text, "Ch Edit");
  noInterrupts();
  channelEditButton.draw();
  interrupts();

  channelMixesButton.usePixmap = true;
  channelMixesButton.pixMap    = wideButtonPixMap;
  channelMixesButton.alphaMask = wideButtonAlphaMask;
  channelMixesButton.h         = WIDE_BUTTON_H;
  channelMixesButton.w         = WIDE_BUTTON_W;
  channelMixesButton.startCol  = 30;
  channelMixesButton.startRow  = buttonsStartRow + (1 * WIDE_BUTTON_H);
  channelMixesButton.textSize  = 2;
  strcpy(channelMixesButton.text, "Ch Mixes");
  noInterrupts();
  channelMixesButton.draw();
  interrupts();

  ioMonButton.usePixmap = true;
  ioMonButton.pixMap    = wideButtonPixMap;
  ioMonButton.alphaMask = wideButtonAlphaMask;
  ioMonButton.h         = WIDE_BUTTON_H;
  ioMonButton.w         = WIDE_BUTTON_W;
  ioMonButton.startCol  = 30;
  ioMonButton.startRow  = buttonsStartRow + (2 * WIDE_BUTTON_H);
  ioMonButton.textSize  = 2;
  strcpy(ioMonButton.text, "I/O Mon");
  noInterrupts();
  ioMonButton.draw();
  interrupts();

  pitchTrimCenterMarker.useBorder   = true;
  pitchTrimCenterMarker.borderWidth = 1;
  pitchTrimCenterMarker.h           = 5;
  pitchTrimCenterMarker.w           = 20;
  pitchTrimCenterMarker.startCol    = ILI9341_TFTWIDTH - 20;
  pitchTrimCenterMarker.startRow    = (ILI9341_TFTHEIGHT / 2) - (pitchTrimCenterMarker.h / 2);
  noInterrupts();
  pitchTrimCenterMarker.draw();
  interrupts();
  
  rollTrimCenterMarker.useBorder   = true;
  rollTrimCenterMarker.borderWidth = 1;
  rollTrimCenterMarker.h           = 20;
  rollTrimCenterMarker.w           = 5;
  rollTrimCenterMarker.startCol    = (ILI9341_TFTWIDTH / 2) - (rollTrimCenterMarker.w / 2);
  rollTrimCenterMarker.startRow    = 0;
  noInterrupts();
  rollTrimCenterMarker.draw();
  interrupts();
  
  yawTrimCenterMarker.useBorder   = true;
  yawTrimCenterMarker.borderWidth = 1;
  yawTrimCenterMarker.h           = 20;
  yawTrimCenterMarker.w           = 5;
  yawTrimCenterMarker.startCol    = (ILI9341_TFTWIDTH / 2) - (yawTrimCenterMarker.w / 2);
  yawTrimCenterMarker.startRow    = ILI9341_TFTHEIGHT - 20;
  noInterrupts();
  yawTrimCenterMarker.draw();
  interrupts();

  throttleTrimCenterMarker.useBorder   = true;
  throttleTrimCenterMarker.borderWidth = 1;
  throttleTrimCenterMarker.h           = 5;
  throttleTrimCenterMarker.w           = 20;
  throttleTrimCenterMarker.startCol    = 0;
  throttleTrimCenterMarker.startRow    = (ILI9341_TFTHEIGHT / 2) - (throttleTrimCenterMarker.h / 2);
  noInterrupts();
  throttleTrimCenterMarker.draw();
  interrupts();

  pitchTrimMarker.backgroundColor = ILI9341_RED;
  pitchTrimMarker.h               = 5;
  pitchTrimMarker.w               = 20;
  pitchTrimMarker.startCol        = ILI9341_TFTWIDTH - 20;
  pitchTrimMarker.startRow        = map(myController.pitchTrim(), -1, 1, ILI9341_TFTHEIGHT - 60 - pitchTrimMarker.h, 60);
  noInterrupts();
  tft.drawLine(ILI9341_TFTWIDTH - 10, ILI9341_TFTHEIGHT - 60, ILI9341_TFTWIDTH - 10, 60, ILI9341_WHITE);
  pitchTrimMarker.draw();
  interrupts();

  rollTrimMarker.backgroundColor = ILI9341_RED;
  rollTrimMarker.h               = 20;
  rollTrimMarker.w               = 5;
  rollTrimMarker.startCol        = map(myController.rollTrim(), -1, 1, 20, ILI9341_TFTWIDTH - 20 - rollTrimMarker.w);
  rollTrimMarker.startRow        = 0;
  noInterrupts();
  tft.drawLine(20, 10, ILI9341_TFTWIDTH - 20, 10, ILI9341_WHITE);
  rollTrimMarker.draw();
  interrupts();
  
  yawTrimMarker.backgroundColor = ILI9341_RED;
  yawTrimMarker.h               = 20;
  yawTrimMarker.w               = 5;
  yawTrimMarker.startCol        = map(myController.yawTrim(), -1, 1, 20, ILI9341_TFTWIDTH - 20 - yawTrimMarker.w);
  yawTrimMarker.startRow        = ILI9341_TFTHEIGHT - yawTrimMarker.h;
  noInterrupts();
  tft.drawLine(20, ILI9341_TFTHEIGHT - 10, ILI9341_TFTWIDTH - 20, ILI9341_TFTHEIGHT - 10, ILI9341_WHITE);
  yawTrimMarker.draw();
  interrupts();

  throttleTrimMarker.backgroundColor = ILI9341_RED;
  throttleTrimMarker.h               = 5;
  throttleTrimMarker.w               = 20;
  throttleTrimMarker.startCol        = 0;
  throttleTrimMarker.startRow        = map(myController.throttleTrim(), -1, 1, ILI9341_TFTHEIGHT - 60 - throttleTrimMarker.h, 60);
  noInterrupts();
  tft.drawLine(10, ILI9341_TFTHEIGHT - 60, 10, 60, ILI9341_WHITE);
  throttleTrimMarker.draw();
  interrupts();

  sw1StateArea.useBorder   = true;
  sw1StateArea.borderWidth = 1;
  sw1StateArea.h           = 20;
  sw1StateArea.w           = 50;
  sw1StateArea.startCol    = 20;
  sw1StateArea.startRow    = 100;
  sprintf(sw1StateArea.text, "SW 1: %d", (int)round(myController.sw1State()));

  sw2StateArea.useBorder   = true;
  sw2StateArea.borderWidth = sw1StateArea.borderWidth;
  sw2StateArea.h           = sw1StateArea.h;
  sw2StateArea.w           = sw1StateArea.w;
  sw2StateArea.startCol    = sw1StateArea.startCol;
  sw2StateArea.startRow    = sw1StateArea.startRow + sw1StateArea.h - sw1StateArea.borderWidth;
  sprintf(sw2StateArea.text, "SW 2: %d", (int)round(myController.sw2State()));

  sw3StateArea.useBorder   = true;
  sw3StateArea.borderWidth = sw2StateArea.borderWidth;
  sw3StateArea.h           = sw2StateArea.h;
  sw3StateArea.w           = sw2StateArea.w;
  sw3StateArea.startCol    = sw2StateArea.startCol;
  sw3StateArea.startRow    = sw2StateArea.startRow + sw2StateArea.h - sw2StateArea.borderWidth;
  sprintf(sw3StateArea.text, "SW 3: %d", (int)round(myController.sw3State()));

  sw4StateArea.useBorder   = true;
  sw4StateArea.borderWidth = sw3StateArea.borderWidth;
  sw4StateArea.h           = sw3StateArea.h;
  sw4StateArea.w           = sw3StateArea.w;
  sw4StateArea.startCol    = sw3StateArea.startCol;
  sw4StateArea.startRow    = sw3StateArea.startRow + sw3StateArea.h - sw3StateArea.borderWidth;
  sprintf(sw4StateArea.text, "SW 4: %d", (int)round(myController.sw4State()));

  sw5StateArea.useBorder   = true;
  sw5StateArea.borderWidth = sw4StateArea.borderWidth;
  sw5StateArea.h           = sw4StateArea.h;
  sw5StateArea.w           = sw4StateArea.w;
  sw5StateArea.startCol    = sw4StateArea.startCol;
  sw5StateArea.startRow    = sw4StateArea.startRow + sw4StateArea.h - sw4StateArea.borderWidth;
  sprintf(sw5StateArea.text, "SW 5: %d", (int)round(myController.sw5State()));

  sw6StateArea.useBorder   = true;
  sw6StateArea.borderWidth = sw5StateArea.borderWidth;
  sw6StateArea.h           = sw5StateArea.h;
  sw6StateArea.w           = sw5StateArea.w;
  sw6StateArea.startCol    = sw5StateArea.startCol;
  sw6StateArea.startRow    = sw5StateArea.startRow + sw5StateArea.h - sw5StateArea.borderWidth;
  sprintf(sw6StateArea.text, "SW 6: %d", (int)round(myController.sw6State()));

  triSwAStateArea.useBorder   = true;
  triSwAStateArea.borderWidth = sw6StateArea.borderWidth;
  triSwAStateArea.h           = sw6StateArea.h;
  triSwAStateArea.w           = sw6StateArea.w;
  triSwAStateArea.startCol    = sw6StateArea.startCol;
  triSwAStateArea.startRow    = sw6StateArea.startRow + sw6StateArea.h - sw6StateArea.borderWidth;
  sprintf(triSwAStateArea.text, "TSW A: %d", (int)round(myController.triSwAState()));

  triSwBStateArea.useBorder   = true;
  triSwBStateArea.borderWidth = triSwAStateArea.borderWidth;
  triSwBStateArea.h           = triSwAStateArea.h;
  triSwBStateArea.w           = triSwAStateArea.w;
  triSwBStateArea.startCol    = triSwAStateArea.startCol;
  triSwBStateArea.startRow    = triSwAStateArea.startRow + triSwAStateArea.h - triSwAStateArea.borderWidth;
  sprintf(triSwBStateArea.text, "TSW B: %d", (int)round(myController.triSwBState()));
  
  pitchJoyArea.useBorder   = true;
  pitchJoyArea.borderWidth = 1;
  pitchJoyArea.h           = 20;
  pitchJoyArea.w           = 80;
  pitchJoyArea.startCol    = triSwBStateArea.startCol + triSwBStateArea.w - 1;
  pitchJoyArea.startRow    = 100;
  dtostrf(myController.pitchJoy(), 4, 2, tempStr);
  sprintf(pitchJoyArea.text, "Pitch: %s", tempStr);
  
  rollJoyArea.useBorder   = true;
  rollJoyArea.borderWidth = pitchJoyArea.borderWidth;
  rollJoyArea.h           = pitchJoyArea.h;
  rollJoyArea.w           = pitchJoyArea.w;
  rollJoyArea.startCol    = pitchJoyArea.startCol;
  rollJoyArea.startRow    = pitchJoyArea.startRow + pitchJoyArea.h - pitchJoyArea.borderWidth;
  dtostrf(myController.rollJoy(), 4, 2, tempStr);
  sprintf(rollJoyArea.text, "Roll: %s", tempStr);
  
  yawJoyArea.useBorder   = true;
  yawJoyArea.borderWidth = rollJoyArea.borderWidth;
  yawJoyArea.h           = rollJoyArea.h;
  yawJoyArea.w           = rollJoyArea.w;
  yawJoyArea.startCol    = rollJoyArea.startCol;
  yawJoyArea.startRow    = rollJoyArea.startRow + rollJoyArea.h - rollJoyArea.borderWidth;
  dtostrf(myController.yawJoy(), 4, 2, tempStr);
  sprintf(yawJoyArea.text, "Yaw: %s", tempStr);
  
  throttleJoyArea.useBorder   = true;
  throttleJoyArea.borderWidth = yawJoyArea.borderWidth;
  throttleJoyArea.h           = yawJoyArea.h;
  throttleJoyArea.w           = yawJoyArea.w;
  throttleJoyArea.startCol    = yawJoyArea.startCol;
  throttleJoyArea.startRow    = yawJoyArea.startRow + yawJoyArea.h - yawJoyArea.borderWidth;
  dtostrf(myController.yawJoy(), 4, 2, tempStr);
  sprintf(throttleJoyArea.text, "Trtl: %s", tempStr);
  
  knob1Area.useBorder   = true;
  knob1Area.borderWidth = throttleJoyArea.borderWidth;
  knob1Area.h           = throttleJoyArea.h;
  knob1Area.w           = throttleJoyArea.w;
  knob1Area.startCol    = throttleJoyArea.startCol;
  knob1Area.startRow    = throttleJoyArea.startRow + throttleJoyArea.h - throttleJoyArea.borderWidth;
  dtostrf(myController.knob1(), 4, 2, tempStr);
  sprintf(knob1Area.text, "kb 1: %s", tempStr);
  
  knob2Area.useBorder   = true;
  knob2Area.borderWidth = knob1Area.borderWidth;
  knob2Area.h           = knob1Area.h;
  knob2Area.w           = knob1Area.w;
  knob2Area.startCol    = knob1Area.startCol;
  knob2Area.startRow    = knob1Area.startRow + knob1Area.h - knob1Area.borderWidth;
  dtostrf(myController.knob2(), 4, 2, tempStr);
  sprintf(knob2Area.text, "kb 2: %s", tempStr);
  
  shuntVoltageArea.useBorder   = true;
  shuntVoltageArea.borderWidth = 1;
  shuntVoltageArea.h           = 20;
  shuntVoltageArea.w           = 80;
  shuntVoltageArea.startCol    = knob2Area.startCol;
  shuntVoltageArea.startRow    = knob2Area.startRow + knob2Area.h - knob2Area.borderWidth;
  dtostrf(myController.shuntVoltage(), 4, 2, tempStr);
  sprintf(shuntVoltageArea.text, "Shunt: %s", tempStr);
  
  busVoltageArea.useBorder   = true;
  busVoltageArea.borderWidth = shuntVoltageArea.borderWidth;
  busVoltageArea.h           = shuntVoltageArea.h;
  busVoltageArea.w           = shuntVoltageArea.w;
  busVoltageArea.startCol    = shuntVoltageArea.startCol;
  busVoltageArea.startRow    = shuntVoltageArea.startRow + shuntVoltageArea.h - shuntVoltageArea.borderWidth;
  dtostrf(myController.busVoltage(), 4, 2, tempStr);
  sprintf(busVoltageArea.text, "Bus: %s", tempStr);
  
  currentArea.useBorder   = true;
  currentArea.borderWidth = busVoltageArea.borderWidth;
  currentArea.h           = busVoltageArea.h;
  currentArea.w           = busVoltageArea.w;
  currentArea.startCol    = busVoltageArea.startCol;
  currentArea.startRow    = busVoltageArea.startRow + busVoltageArea.h - busVoltageArea.borderWidth;
  dtostrf(myController.busVoltage(), 4, 2, tempStr);
  sprintf(currentArea.text, "Cur: %s", tempStr);
  
  loadVoltageArea.useBorder   = true;
  loadVoltageArea.borderWidth = currentArea.borderWidth;
  loadVoltageArea.h           = currentArea.h;
  loadVoltageArea.w           = currentArea.w;
  loadVoltageArea.startCol    = currentArea.startCol;
  loadVoltageArea.startRow    = currentArea.startRow + currentArea.h - currentArea.borderWidth;
  dtostrf(myController.loadVoltage(), 4, 2, tempStr);
  sprintf(loadVoltageArea.text, "Load: %s", tempStr);
  
  buddy1Area.useBorder   = true;
  buddy1Area.borderWidth = 1;
  buddy1Area.h           = 20;
  buddy1Area.w           = 72;
  buddy1Area.startCol    = pitchJoyArea.startCol + pitchJoyArea.w - 1;
  buddy1Area.startRow    = 100;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy1Area.text, "Bud 1: %d", myController.buddyChannel(0));
  else
    sprintf(buddy1Area.text, "Bud 1: ----");
  
  buddy2Area.useBorder   = true;
  buddy2Area.borderWidth = buddy1Area.borderWidth;
  buddy2Area.h           = buddy1Area.h;
  buddy2Area.w           = buddy1Area.w;
  buddy2Area.startCol    = buddy1Area.startCol;
  buddy2Area.startRow    = buddy1Area.startRow + buddy1Area.h - buddy1Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy2Area.text, "Bud 2: %d", myController.buddyChannel(1));
  else
    sprintf(buddy2Area.text, "Bud 2: ----");
  
  buddy3Area.useBorder   = true;
  buddy3Area.borderWidth = buddy2Area.borderWidth;
  buddy3Area.h           = buddy2Area.h;
  buddy3Area.w           = buddy2Area.w;
  buddy3Area.startCol    = buddy2Area.startCol;
  buddy3Area.startRow    = buddy2Area.startRow + buddy2Area.h - buddy2Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy3Area.text, "Bud 3: %d", myController.buddyChannel(2));
  else
    sprintf(buddy3Area.text, "Bud 3: ----");
  
  buddy4Area.useBorder   = true;
  buddy4Area.borderWidth = buddy3Area.borderWidth;
  buddy4Area.h           = buddy3Area.h;
  buddy4Area.w           = buddy3Area.w;
  buddy4Area.startCol    = buddy3Area.startCol;
  buddy4Area.startRow    = buddy3Area.startRow + buddy3Area.h - buddy3Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy4Area.text, "Bud 4: %d", myController.buddyChannel(3));
  else
    sprintf(buddy4Area.text, "Bud 4: ----");
  
  buddy5Area.useBorder   = true;
  buddy5Area.borderWidth = buddy4Area.borderWidth;
  buddy5Area.h           = buddy4Area.h;
  buddy5Area.w           = buddy4Area.w;
  buddy5Area.startCol    = buddy4Area.startCol;
  buddy5Area.startRow    = buddy4Area.startRow + buddy4Area.h - buddy4Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy5Area.text, "Bud 5: %d", myController.buddyChannel(4));
  else
    sprintf(buddy5Area.text, "Bud 5: ----");
  
  buddy6Area.useBorder   = true;
  buddy6Area.borderWidth = buddy5Area.borderWidth;
  buddy6Area.h           = buddy5Area.h;
  buddy6Area.w           = buddy5Area.w;
  buddy6Area.startCol    = buddy5Area.startCol;
  buddy6Area.startRow    = buddy5Area.startRow + buddy5Area.h - buddy5Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy6Area.text, "Bud 6: %d", myController.buddyChannel(5));
  else
    sprintf(buddy6Area.text, "Bud 6: ----");
  
  buddy7Area.useBorder   = true;
  buddy7Area.borderWidth = buddy6Area.borderWidth;
  buddy7Area.h           = buddy6Area.h;
  buddy7Area.w           = buddy6Area.w;
  buddy7Area.startCol    = buddy6Area.startCol;
  buddy7Area.startRow    = buddy6Area.startRow + buddy6Area.h - buddy6Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy7Area.text, "Bud 7: %d", myController.buddyChannel(6));
  else
    sprintf(buddy7Area.text, "Bud 7: ----");
  
  buddy8Area.useBorder   = true;
  buddy8Area.borderWidth = buddy7Area.borderWidth;
  buddy8Area.h           = buddy7Area.h;
  buddy8Area.w           = buddy7Area.w;
  buddy8Area.startCol    = buddy7Area.startCol;
  buddy8Area.startRow    = buddy7Area.startRow + buddy7Area.h - buddy7Area.borderWidth;

  if (myController.numBuddyChannels() == SW_3_CH)
    sprintf(buddy8Area.text, "Bud 8: %d", myController.buddyChannel(7));
  else
    sprintf(buddy8Area.text, "Bud 8: ----");
  
  chEditNumArea.usePixmap = true;
  chEditNumArea.pixMap    = buttonPixMap;
  chEditNumArea.alphaMask = buttonAlphaMask;
  chEditNumArea.h         = BUTTON_H;
  chEditNumArea.w         = BUTTON_W;
  chEditNumArea.startCol  = 30;
  chEditNumArea.startRow  = (ILI9341_TFTHEIGHT / 2) - (chEditNumArea.h / 2) - 20;
  chEditNumArea.textSize  = 2;

  if (chVal == PITCH_CH)
    sprintf(chEditNumArea.text, "Pitch");
  else if (chVal == ROLL_CH)
    sprintf(chEditNumArea.text, "Roll");
  else if (chVal == YAW_CH)
    sprintf(chEditNumArea.text, "Yaw");
  else if (chVal == THROTTLE_CH)
    sprintf(chEditNumArea.text, "Thrtl");
  else if (chVal == KNOB_1_CH)
    sprintf(chEditNumArea.text, "Knob1");
  else if (chVal == KNOB_2_CH)
    sprintf(chEditNumArea.text, "Knob2");
  else if (chVal == SW_1_CH)
    sprintf(chEditNumArea.text, "SW1");
  else if (chVal == SW_2_CH)
    sprintf(chEditNumArea.text, "SW2");
  else if (chVal == SW_3_CH)
    sprintf(chEditNumArea.text, "SW3");
  else if (chVal == SW_4_CH)
    sprintf(chEditNumArea.text, "SW4");
  else if (chVal == SW_5_CH)
    sprintf(chEditNumArea.text, "SW5");
  else if (chVal == SW_6_CH)
    sprintf(chEditNumArea.text, "SW6");

  chEditNumUpArea.usePixmap = true;
  chEditNumUpArea.pixMap    = upButtonPixMap;
  chEditNumUpArea.alphaMask = upButtonAlphaMask;
  chEditNumUpArea.h         = UP_BUTTON_H;
  chEditNumUpArea.w         = UP_BUTTON_W;
  chEditNumUpArea.startCol  = chEditNumArea.startCol + (chEditNumArea.w / 2) - (chEditNumUpArea.w / 2);
  chEditNumUpArea.startRow  = chEditNumArea.startRow - chEditNumUpArea.h - 5;
  chEditNumUpArea.textSize  = 2;

  chEditNumDownArea.usePixmap = true;
  chEditNumDownArea.pixMap    = downButtonPixMap;
  chEditNumDownArea.alphaMask = downButtonAlphaMask;
  chEditNumDownArea.h         = DOWN_BUTTON_H;
  chEditNumDownArea.w         = DOWN_BUTTON_W;
  chEditNumDownArea.startCol  = chEditNumArea.startCol + (chEditNumArea.w / 2) - (chEditNumUpArea.w / 2);
  chEditNumDownArea.startRow  = chEditNumArea.startRow + chEditNumArea.h + 5;
  chEditNumDownArea.textSize  = 2;
  
  chReverseArea.borderWidth = 1;
  chReverseArea.h           = 20;
  chReverseArea.w           = 70;
  chReverseArea.startCol    = chEditNumArea.startCol + (chEditNumArea.w / 2) - (chReverseArea.w / 2);
  chReverseArea.startRow    = chEditNumDownArea.startRow + chEditNumDownArea.h + 10;
  sprintf(chReverseArea.text, "Reverse:");
  
  chReverseChangeArea.usePixmap = true;
  chReverseChangeArea.h         = 20;
  chReverseChangeArea.w         = 20;
  chReverseChangeArea.startCol  = chReverseArea.startCol + chReverseArea.w;
  chReverseChangeArea.startRow  = chReverseArea.startRow;
  
  if (((chVal == PITCH_CH)    && myController.getPitchReverse())    ||
      ((chVal == ROLL_CH)     && myController.getRollReverse())     ||
      ((chVal == YAW_CH)      && myController.getYawReverse())      ||
      ((chVal == THROTTLE_CH) && myController.getThrottleReverse()) ||
      ((chVal == KNOB_1_CH)   && myController.getKnob1Reverse())    ||
      ((chVal == KNOB_2_CH)   && myController.getKnob2Reverse())    ||
      ((chVal == SW_1_CH)     && myController.getSw1Reverse())      ||
      ((chVal == SW_2_CH)     && myController.getSw2Reverse())      ||
      ((chVal == SW_3_CH)     && myController.getSw3Reverse())      ||
      ((chVal == SW_4_CH)     && myController.getSw4Reverse())      ||
      ((chVal == SW_5_CH)     && myController.getSw5Reverse())      ||
      ((chVal == SW_6_CH)     && myController.getSw6Reverse()))
  {
    chReverseChangeArea.pixMap    = checkButtonPixMap;
    chReverseChangeArea.alphaMask = checkButtonAlphaMask;
  }
  else
  {
    chReverseChangeArea.pixMap    = xButtonPixMap;
    chReverseChangeArea.alphaMask = xButtonAlphaMask;
  }
  
  chExpoArea.useBorder   = true;
  chExpoArea.borderWidth = 1;
  chExpoArea.h           = 20;
  chExpoArea.w           = 80;
  chExpoArea.startCol    = (ILI9341_TFTWIDTH / 2.0) - (chExpoArea.w / 2.0);
  chExpoArea.startRow    = chReverseArea.startRow + chReverseArea.h + 10;
  
  if (chVal == PITCH_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getPitchExpo());
  else if (chVal == ROLL_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getRollExpo());
  else if (chVal == YAW_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getYawExpo());
  else if (chVal == THROTTLE_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getThrottleExpo());
  else if (chVal == KNOB_1_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getKnob1Expo());
  else if (chVal == KNOB_2_CH)
    sprintf(chExpoArea.text, "Expo: %d", (int)myController.getKnob2Expo());
  else
    sprintf(chExpoArea.text, "Expo: %d", 0);

  chExpoUpArea.usePixmap = true;
  chExpoUpArea.pixMap    = upButtonPixMap;
  chExpoUpArea.alphaMask = upButtonAlphaMask;
  chExpoUpArea.h         = UP_BUTTON_H;
  chExpoUpArea.w         = UP_BUTTON_W;
  chExpoUpArea.startCol  = chExpoArea.startCol + chExpoArea.w + 10;
  chExpoUpArea.startRow  = chExpoArea.startRow;
  chExpoUpArea.textSize  = 2;

  chExpoDownArea.usePixmap = true;
  chExpoDownArea.pixMap    = downButtonPixMap;
  chExpoDownArea.alphaMask = downButtonAlphaMask;
  chExpoDownArea.h         = DOWN_BUTTON_H;
  chExpoDownArea.w         = DOWN_BUTTON_W;
  chExpoDownArea.startCol  = chExpoArea.startCol - chExpoDownArea.w - 10;
  chExpoDownArea.startRow  = chExpoArea.startRow;
  chExpoDownArea.textSize  = 2;
  
  chExpoGraphArea.useBorder   = true;
  chExpoGraphArea.borderWidth = 1;
  chExpoGraphArea.h           = 91;
  chExpoGraphArea.w           = 91;
  chExpoGraphArea.startCol    = chEditNumArea.startCol + chEditNumArea.w + 10;
  chExpoGraphArea.startRow    = chEditNumUpArea.startRow;
  
  chMixFirstNumArea.usePixmap = true;
  chMixFirstNumArea.pixMap    = buttonPixMap;
  chMixFirstNumArea.alphaMask = buttonAlphaMask;
  chMixFirstNumArea.h         = BUTTON_H;
  chMixFirstNumArea.w         = BUTTON_W;
  chMixFirstNumArea.startCol  = 30;
  chMixFirstNumArea.startRow  = (ILI9341_TFTHEIGHT / 2) - (chMixFirstNumArea.h / 2) - 20;
  chMixFirstNumArea.textSize  = 2;

  if (chVal1Mix == PITCH_CH)
  {
    chVal2Mix = myController.getPitchMixCh();
    sprintf(chMixFirstNumArea.text, "Pitch");
  }
  else if (chVal1Mix == ROLL_CH)
  {
    chVal2Mix = myController.getRollMixCh();
    sprintf(chMixFirstNumArea.text, "Roll");
  }
  else if (chVal1Mix == YAW_CH)
  {
    chVal2Mix = myController.getYawMixCh();
    sprintf(chMixFirstNumArea.text, "Yaw");
  }
  else if (chVal1Mix == THROTTLE_CH)
  {
    chVal2Mix = myController.getThrottleMixCh();
    sprintf(chMixFirstNumArea.text, "Thrtl");
  }
  else if (chVal1Mix == KNOB_1_CH)
  {
    chVal2Mix = myController.getKnob1MixCh();
    sprintf(chMixFirstNumArea.text, "Knob1");
  }
  else if (chVal1Mix == KNOB_2_CH)
  {
    chVal2Mix = myController.getKnob2MixCh();
    sprintf(chMixFirstNumArea.text, "Knob2");
  }
  else if (chVal1Mix == SW_1_CH)
  {
    chVal2Mix = myController.getSw1MixCh();
    sprintf(chMixFirstNumArea.text, "SW1");
  }
  else if (chVal1Mix == SW_2_CH)
  {
    chVal2Mix = myController.getSw2MixCh();
    sprintf(chMixFirstNumArea.text, "SW2");
  }
  else if (chVal1Mix == SW_3_CH)
  {
    chVal2Mix = myController.getSw3MixCh();
    sprintf(chMixFirstNumArea.text, "SW3");
  }
  else if (chVal1Mix == SW_4_CH)
  {
    chVal2Mix = myController.getSw4MixCh();
    sprintf(chMixFirstNumArea.text, "SW4");
  }
  else if (chVal1Mix == SW_5_CH)
  {
    chVal2Mix = myController.getSw5MixCh();
    sprintf(chMixFirstNumArea.text, "SW5");
  }
  else if (chVal1Mix == SW_6_CH)
  {
    chVal2Mix = myController.getSw6MixCh();
    sprintf(chMixFirstNumArea.text, "SW6");
  }
  
  chMixFirstNumUpArea.usePixmap = true;
  chMixFirstNumUpArea.pixMap    = upButtonPixMap;
  chMixFirstNumUpArea.alphaMask = upButtonAlphaMask;
  chMixFirstNumUpArea.h         = UP_BUTTON_H;
  chMixFirstNumUpArea.w         = UP_BUTTON_W;
  chMixFirstNumUpArea.startCol  = chMixFirstNumArea.startCol + (chMixFirstNumArea.w / 2) - (chMixFirstNumUpArea.w / 2);
  chMixFirstNumUpArea.startRow  = chMixFirstNumArea.startRow - chMixFirstNumUpArea.h - 5;
  chMixFirstNumUpArea.textSize  = 2;
  
  chMixFirstNumDownArea.usePixmap = true;
  chMixFirstNumDownArea.pixMap    = downButtonPixMap;
  chMixFirstNumDownArea.alphaMask = downButtonAlphaMask;
  chMixFirstNumDownArea.h         = DOWN_BUTTON_H;
  chMixFirstNumDownArea.w         = DOWN_BUTTON_W;
  chMixFirstNumDownArea.startCol  = chMixFirstNumUpArea.startCol;
  chMixFirstNumDownArea.startRow  = chMixFirstNumArea.startRow + chMixFirstNumArea.h + 5;
  chMixFirstNumDownArea.textSize  = 2;
  
  chMixSecondNumArea.usePixmap = true;
  chMixSecondNumArea.pixMap    = buttonPixMap;
  chMixSecondNumArea.alphaMask = buttonAlphaMask;
  chMixSecondNumArea.h         = BUTTON_H;
  chMixSecondNumArea.w         = BUTTON_W;
  chMixSecondNumArea.startCol  = chMixFirstNumUpArea.startCol + chMixFirstNumUpArea.w + 40;
  chMixSecondNumArea.startRow  = (ILI9341_TFTHEIGHT / 2) - (chMixFirstNumArea.h / 2) - 20;
  chMixSecondNumArea.textSize  = 2;

  if (chVal2Mix == PITCH_CH)
    sprintf(chMixSecondNumArea.text, "Pitch");
  else if (chVal2Mix == ROLL_CH)
    sprintf(chMixSecondNumArea.text, "Roll");
  else if (chVal2Mix == YAW_CH)
    sprintf(chMixSecondNumArea.text, "Yaw");
  else if (chVal2Mix == THROTTLE_CH)
    sprintf(chMixSecondNumArea.text, "Thrtl");
  else if (chVal2Mix == KNOB_1_CH)
    sprintf(chMixSecondNumArea.text, "Knob1");
  else if (chVal2Mix == KNOB_2_CH)
    sprintf(chMixSecondNumArea.text, "Knob2");
  else if (chVal2Mix == SW_1_CH)
    sprintf(chMixSecondNumArea.text, "SW1");
  else if (chVal2Mix == SW_2_CH)
    sprintf(chMixSecondNumArea.text, "SW2");
  else if (chVal2Mix == SW_3_CH)
    sprintf(chMixSecondNumArea.text, "SW3");
  else if (chVal2Mix == SW_4_CH)
    sprintf(chMixSecondNumArea.text, "SW4");
  else if (chVal2Mix == SW_5_CH)
    sprintf(chMixSecondNumArea.text, "SW5");
  else if (chVal2Mix == SW_6_CH)
    sprintf(chMixSecondNumArea.text, "SW6");
  
  chMixSecondNumUpArea.usePixmap = true;
  chMixSecondNumUpArea.pixMap    = upButtonPixMap;
  chMixSecondNumUpArea.alphaMask = upButtonAlphaMask;
  chMixSecondNumUpArea.h         = UP_BUTTON_H;
  chMixSecondNumUpArea.w         = UP_BUTTON_W;
  chMixSecondNumUpArea.startCol  = chMixSecondNumArea.startCol + (chMixSecondNumArea.w / 2) - (chMixSecondNumUpArea.w / 2);
  chMixSecondNumUpArea.startRow  = chMixSecondNumArea.startRow - chMixSecondNumUpArea.h - 5;
  chMixSecondNumUpArea.textSize  = 2;
  
  chMixSecondNumDownArea.usePixmap = true;
  chMixSecondNumDownArea.pixMap    = downButtonPixMap;
  chMixSecondNumDownArea.alphaMask = downButtonAlphaMask;
  chMixSecondNumDownArea.h         = DOWN_BUTTON_H;
  chMixSecondNumDownArea.w         = DOWN_BUTTON_W;
  chMixSecondNumDownArea.startCol  = chMixSecondNumArea.startCol + (chMixSecondNumArea.w / 2) - (chMixSecondNumDownArea.w / 2);
  chMixSecondNumDownArea.startRow  = chMixSecondNumArea.startRow + chMixSecondNumArea.h + 5;
  chMixSecondNumDownArea.textSize  = 2;
  
  chMixArea.useBorder   = true;
  chMixArea.borderWidth = 1;
  chMixArea.h           = 20;
  chMixArea.w           = 80;
  chMixArea.startCol    = (ILI9341_TFTWIDTH / 2.0) - (chExpoArea.w / 2.0);
  chMixArea.startRow    = chMixFirstNumArea.startRow + chMixFirstNumArea.h + 60;
  
  if (chVal1Mix == PITCH_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getPitchMix());
  else if (chVal1Mix == ROLL_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getRollMix());
  else if (chVal1Mix == YAW_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getYawMix());
  else if (chVal1Mix == THROTTLE_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getThrottleMix());
  else if (chVal1Mix == KNOB_1_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getKnob1Mix());
  else if (chVal1Mix == KNOB_2_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getKnob2Mix());
  else if (chVal1Mix == SW_1_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw1Mix());
  else if (chVal1Mix == SW_2_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw2Mix());
  else if (chVal1Mix == SW_3_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw3Mix());
  else if (chVal1Mix == SW_4_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw4Mix());
  else if (chVal1Mix == SW_5_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw5Mix());
  else if (chVal1Mix == SW_6_CH)
    sprintf(chMixArea.text, "Mix: %d", myController.getSw6Mix());
  
  chMixUpArea.usePixmap = true;
  chMixUpArea.pixMap    = upButtonPixMap;
  chMixUpArea.alphaMask = upButtonAlphaMask;
  chMixUpArea.h         = UP_BUTTON_H;
  chMixUpArea.w         = UP_BUTTON_W;
  chMixUpArea.startCol  = chMixArea.startCol + chMixArea.w + 10;
  chMixUpArea.startRow  = chMixArea.startRow;
  chMixUpArea.textSize  = 2;
  
  chMixDownArea.usePixmap = true;
  chMixDownArea.pixMap    = downButtonPixMap;
  chMixDownArea.alphaMask = downButtonAlphaMask;
  chMixDownArea.h         = DOWN_BUTTON_H;
  chMixDownArea.w         = DOWN_BUTTON_W;
  chMixDownArea.startCol  = chMixArea.startCol - chMixDownArea.w - 10;
  chMixDownArea.startRow  = chMixArea.startRow;
  chMixDownArea.textSize  = 2;
  
  disableTFT();
  enableTS();

  menuTimer.begin(updateMenu, MENU_PERIOD * 1e6);
}




FASTRUN void whenTouched()
{
  if (ts.tirqTouched())
  {
    disableTFT();
    enableTS();
  
    if (ts.touched())
    {
      long currTime = micros();
      auto next_ts_point = ts.getPoint();
      disableTS();

      if ((currTime - time_touched) >= TOUCH_TIME_THRESH)
      {
        if (next_ts_point.z < 4000)
        {
          ts_point      = ts.getPoint();
          touch_handled = false;
          time_touched  = currTime;                
          disableTS();

          int x = map(ts_point.y, TS_MINX, TS_MAXX, 0, ILI9341_TFTWIDTH);
          int y = map(ts_point.x, TS_MAXY, TS_MINY, 0, ILI9341_TFTHEIGHT);

          if (saveArea.inArea(y, x))
          {
            saveSettings();
          }

          if (backButton.inArea(y, x))
          {
            noInterrupts();
            backButton.clear();
            interrupts();
            
            if (ioMonFlag)
            {
              ioMonFlag = false;
              
              // clear all current buttons
              noInterrupts();
              sw1StateArea.clear();
              sw2StateArea.clear();
              sw3StateArea.clear();
              sw4StateArea.clear();
              sw5StateArea.clear();
              sw6StateArea.clear();
              triSwAStateArea.clear();
              triSwBStateArea.clear();
              pitchJoyArea.clear();
              rollJoyArea.clear();
              yawJoyArea.clear();
              throttleJoyArea.clear();
              knob1Area.clear();
              knob2Area.clear();
              shuntVoltageArea.clear();
              busVoltageArea.clear();
              currentArea.clear();
              loadVoltageArea.clear();
              buddy1Area.clear();
              buddy2Area.clear();
              buddy3Area.clear();
              buddy4Area.clear();
              buddy5Area.clear();
              buddy6Area.clear();
              buddy7Area.clear();
              buddy8Area.clear();
              interrupts();
              
              // draw all main buttons
              noInterrupts();
              channelEditButton.draw();
              channelMixesButton.draw();
              ioMonButton.draw();
              interrupts();
            }
            else if (chEditFlag)
            {
              chEditFlag = false;
              
              // clear all current buttons
              noInterrupts();
              chEditNumArea.clear();
              chEditNumUpArea.clear();
              chEditNumDownArea.clear();
              chReverseArea.clear();
              chReverseChangeArea.clear();
              chExpoArea.clear();
              chExpoUpArea.clear();
              chExpoDownArea.clear();
              chExpoGraphArea.clear();
              interrupts();
              
              // draw all main buttons
              noInterrupts();
              channelEditButton.draw();
              channelMixesButton.draw();
              ioMonButton.draw();
              interrupts();
            }
            else if (chMixFlag)
            {
              chMixFlag = false;
              
              // clear all current buttons
              noInterrupts();
              chMixFirstNumArea.clear();
              chMixFirstNumUpArea.clear();
              chMixFirstNumDownArea.clear();
              chMixSecondNumArea.clear();
              chMixSecondNumUpArea.clear();
              chMixSecondNumDownArea.clear();
              chMixArea.clear();
              chMixUpArea.clear();
              chMixDownArea.clear();
              interrupts();
              
              // draw all main buttons
              noInterrupts();
              channelEditButton.draw();
              channelMixesButton.draw();
              ioMonButton.draw();
              interrupts();
            }
          }
          
          if (channelEditButton.inArea(y, x))
          {
            // clear all buttons
            noInterrupts();
            channelEditButton.clear();
            channelMixesButton.clear();
            ioMonButton.clear();
            interrupts();
            
            // set iomon flag
            chEditFlag = true;
            
            // initialize io fields
            noInterrupts();
            backButton.draw();
            chEditNumArea.draw();
            chEditNumUpArea.draw();
            chEditNumDownArea.draw();
            chReverseArea.draw();
            chReverseChangeArea.draw();
            chExpoArea.draw();
            chExpoGraphArea.draw();
            chExpoUpArea.draw();
            chExpoDownArea.draw();
            interrupts();

            float expo = 0;
            
            if (chVal == PITCH_CH)
              expo = myController.getPitchExpo();
            else if (chVal == ROLL_CH)
              expo = myController.getRollExpo();
            else if (chVal == YAW_CH)
              expo = myController.getYawExpo();
            else if (chVal == THROTTLE_CH)
              expo = myController.getThrottleExpo();
            else if (chVal == KNOB_1_CH)
              expo = myController.getKnob1Expo();
            else if (chVal == KNOB_2_CH)
              expo = myController.getKnob2Expo();
            
            bool reverse = false;
      
            if (chVal == PITCH_CH)
              reverse = myController.getPitchReverse();
            else if (chVal == ROLL_CH)
              reverse = myController.getRollReverse();
            else if (chVal == YAW_CH)
              reverse = myController.getYawReverse();
            else if (chVal == THROTTLE_CH)
              reverse = myController.getThrottleReverse();
            else if (chVal == KNOB_1_CH)
              reverse = myController.getKnob1Reverse();
            else if (chVal == KNOB_2_CH)
              reverse = myController.getKnob2Reverse();
            else if (chVal == SW_1_CH)
              reverse = myController.getSw1Reverse();
            else if (chVal == SW_2_CH)
              reverse = myController.getSw2Reverse();
            else if (chVal == SW_3_CH)
              reverse = myController.getSw3Reverse();
            else if (chVal == SW_4_CH)
              reverse = myController.getSw4Reverse();
            else if (chVal == SW_5_CH)
              reverse = myController.getSw5Reverse();
            else if (chVal == SW_6_CH)
              reverse = myController.getSw6Reverse();
            
            for (int i = 0; i < (chExpoGraphArea.w - 2); i++)
            {
              int col = i + chExpoGraphArea.startCol;
      
              float input = 0;
      
              if (reverse)
                input = mapfloat(i, 0.0, chExpoGraphArea.w - 2.0, 1.0, -1.0);
              else
                input = mapfloat(i, 0.0, chExpoGraphArea.w - 2.0, -1.0, 1.0);
              
              int row = (int)((chExpoGraphArea.h / 2.0) * myController.expo(input, expo)) + chExpoGraphArea.startRow + (int)(chExpoGraphArea.h / 2);

              noInterrupts();
              tft.drawPixel(col, row, ILI9341_WHITE);
              interrupts();
            }
          }

          if (chEditNumUpArea.inArea(y, x))
          {
            chChangeFlag = true;
            
            if (chVal < (NUM_CHS - 1))
            {
              chVal++;
            }
          }

          if (chEditNumDownArea.inArea(y, x))
          {
            chChangeFlag = true;
            
            if (chVal > 0)
            {
              chVal--;
            }
          }

          if (chReverseArea.inArea(y, x) || chReverseChangeArea.inArea(y, x))
          {
            chReverseChangeFlag = true;
            
            if (chVal == PITCH_CH)
              myController.setPitchReverse(!myController.getPitchReverse());
            if (chVal == ROLL_CH)
              myController.setRollReverse(!myController.getRollReverse());
            if (chVal == YAW_CH)
              myController.setYawReverse(!myController.getYawReverse());
            if (chVal == THROTTLE_CH)
              myController.setThrottleReverse(!myController.getThrottleReverse());
            if (chVal == KNOB_1_CH)
              myController.setKnob1Reverse(!myController.getKnob1Reverse());
            if (chVal == KNOB_2_CH)
              myController.setKnob2Reverse(!myController.getKnob2Reverse());
            if (chVal == SW_1_CH)
              myController.setSw1Reverse(!myController.getSw1Reverse());
            if (chVal == SW_2_CH)
              myController.setSw2Reverse(!myController.getSw2Reverse());
            if (chVal == SW_3_CH)
              myController.setSw3Reverse(!myController.getSw3Reverse());
            if (chVal == SW_4_CH)
              myController.setSw4Reverse(!myController.getSw4Reverse());
            if (chVal == SW_5_CH)
              myController.setSw5Reverse(!myController.getSw5Reverse());
            if (chVal == SW_6_CH)
              myController.setSw6Reverse(!myController.getSw6Reverse());
          }

          if (chExpoUpArea.inArea(y, x))
          {
            expoChangeFlag = true;
            
            if (chVal == PITCH_CH)
              myController.setPitchExpo(myController.getPitchExpo() + expoDiff);
            if (chVal == ROLL_CH)
              myController.setRollExpo(myController.getRollExpo() + expoDiff);
            if (chVal == YAW_CH)
              myController.setYawExpo(myController.getYawExpo() + expoDiff);
            if (chVal == THROTTLE_CH)
              myController.setThrottleExpo(myController.getThrottleExpo() + expoDiff);
            if (chVal == KNOB_1_CH)
              myController.setKnob1Expo(myController.getKnob1Expo() + expoDiff);
            if (chVal == KNOB_2_CH)
              myController.setKnob2Expo(myController.getKnob2Expo() + expoDiff);
          }

          if (chExpoDownArea.inArea(y, x))
          {
            expoChangeFlag = true;
            
            if (chVal == PITCH_CH)
              myController.setPitchExpo(myController.getPitchExpo() - expoDiff);
            if (chVal == ROLL_CH)
              myController.setRollExpo(myController.getRollExpo() - expoDiff);
            if (chVal == YAW_CH)
              myController.setYawExpo(myController.getYawExpo() - expoDiff);
            if (chVal == THROTTLE_CH)
              myController.setThrottleExpo(myController.getThrottleExpo() - expoDiff);
            if (chVal == KNOB_1_CH)
              myController.setKnob1Expo(myController.getKnob1Expo() - expoDiff);
            if (chVal == KNOB_2_CH)
              myController.setKnob2Expo(myController.getKnob2Expo() - expoDiff);
          }

          if (channelMixesButton.inArea(y, x))
          {
            // clear all buttons
            noInterrupts();
            channelEditButton.clear();
            channelMixesButton.clear();
            ioMonButton.clear();
            interrupts();
            
            // set chMix flag
            chMixFlag = true;
            
            // initialize mixes fields
            noInterrupts();
            backButton.draw();
            chMixFirstNumArea.draw();
            chMixFirstNumUpArea.draw();
            chMixFirstNumDownArea.draw();
            chMixSecondNumArea.draw();
            chMixSecondNumUpArea.draw();
            chMixSecondNumDownArea.draw();
            chMixArea.draw();
            chMixUpArea.draw();
            chMixDownArea.draw();
            interrupts();
          }

          if (chMixFirstNumUpArea.inArea(y, x))
          {
            chMixFirstChangeFlag = true;
            chVal1Mix = constrain(chVal1Mix + 1, 0, 11);
          }

          if (chMixFirstNumDownArea.inArea(y, x))
          {
            chMixFirstChangeFlag = true;
            chVal1Mix = constrain(chVal1Mix - 1, 0, 11);
          }

          if (chMixSecondNumUpArea.inArea(y, x))
          {
            chMixSecondChangeFlag = true;
            chVal2Mix = constrain(chVal2Mix + 1, 0, 11);
            
            if (chVal1Mix == PITCH_CH)
              myController.setPitchMixCh(chVal2Mix);
            else if (chVal1Mix == ROLL_CH)
              myController.setRollMixCh(chVal2Mix);
            else if (chVal1Mix == YAW_CH)
              myController.setYawMixCh(chVal2Mix);
            else if (chVal1Mix == THROTTLE_CH)
              myController.setThrottleMixCh(chVal2Mix);
            else if (chVal1Mix == KNOB_1_CH)
              myController.setKnob1MixCh(chVal2Mix);
            else if (chVal1Mix == KNOB_2_CH)
              myController.setKnob2MixCh(chVal2Mix);
            else if (chVal1Mix == SW_1_CH)
              myController.setSw1MixCh(chVal2Mix);
            else if (chVal1Mix == SW_2_CH)
              myController.setSw2MixCh(chVal2Mix);
            else if (chVal1Mix == SW_3_CH)
              myController.setSw3MixCh(chVal2Mix);
            else if (chVal1Mix == SW_4_CH)
              myController.setSw4MixCh(chVal2Mix);
            else if (chVal1Mix == SW_5_CH)
              myController.setSw5MixCh(chVal2Mix);
            else if (chVal1Mix == SW_6_CH)
              myController.setSw6MixCh(chVal2Mix);
          }

          if (chMixSecondNumDownArea.inArea(y, x))
          {
            chMixSecondChangeFlag = true;
            chVal2Mix = constrain(chVal2Mix - 1, 0, 11);
            
            if (chVal1Mix == PITCH_CH)
              myController.setPitchMixCh(chVal2Mix);
            else if (chVal1Mix == ROLL_CH)
              myController.setRollMixCh(chVal2Mix);
            else if (chVal1Mix == YAW_CH)
              myController.setYawMixCh(chVal2Mix);
            else if (chVal1Mix == THROTTLE_CH)
              myController.setThrottleMixCh(chVal2Mix);
            else if (chVal1Mix == KNOB_1_CH)
              myController.setKnob1MixCh(chVal2Mix);
            else if (chVal1Mix == KNOB_2_CH)
              myController.setKnob2MixCh(chVal2Mix);
            else if (chVal1Mix == SW_1_CH)
              myController.setSw1MixCh(chVal2Mix);
            else if (chVal1Mix == SW_2_CH)
              myController.setSw2MixCh(chVal2Mix);
            else if (chVal1Mix == SW_3_CH)
              myController.setSw3MixCh(chVal2Mix);
            else if (chVal1Mix == SW_4_CH)
              myController.setSw4MixCh(chVal2Mix);
            else if (chVal1Mix == SW_5_CH)
              myController.setSw5MixCh(chVal2Mix);
            else if (chVal1Mix == SW_6_CH)
              myController.setSw6MixCh(chVal2Mix);
          }

          if (chMixUpArea.inArea(y, x))
          {
            chMixValChangeFlag = true;

            if (chVal1Mix != chVal2Mix)
            {
              if (chVal1Mix == PITCH_CH)
                myController.setPitchMix(myController.getPitchMix() + mixDiff);
              else if (chVal1Mix == ROLL_CH)
                myController.setRollMix(myController.getRollMix() + mixDiff);
              else if (chVal1Mix == YAW_CH)
                myController.setYawMix(myController.getYawMix() + mixDiff);
              else if (chVal1Mix == THROTTLE_CH)
                myController.setThrottleMix(myController.getThrottleMix() + mixDiff);
              else if (chVal1Mix == KNOB_1_CH)
                myController.setKnob1Mix(myController.getKnob1Mix() + mixDiff);
              else if (chVal1Mix == KNOB_2_CH)
                myController.setKnob2Mix(myController.getKnob2Mix() + mixDiff);
              else if (chVal1Mix == SW_1_CH)
                myController.setSw1Mix(myController.getSw1Mix() + mixDiff);
              else if (chVal1Mix == SW_2_CH)
                myController.setSw2Mix(myController.getSw2Mix() + mixDiff);
              else if (chVal1Mix == SW_3_CH)
                myController.setSw3Mix(myController.getSw3Mix() + mixDiff);
              else if (chVal1Mix == SW_4_CH)
                myController.setSw4Mix(myController.getSw4Mix() + mixDiff);
              else if (chVal1Mix == SW_5_CH)
                myController.setSw5Mix(myController.getSw5Mix() + mixDiff);
              else if (chVal1Mix == SW_6_CH)
                myController.setSw6Mix(myController.getSw6Mix() + mixDiff);
            }
          }

          if (chMixDownArea.inArea(y, x))
          {
            chMixValChangeFlag = true;

            if (chVal1Mix != chVal2Mix)
            {
              if (chVal1Mix == PITCH_CH)
                myController.setPitchMix(myController.getPitchMix() - mixDiff);
              else if (chVal1Mix == ROLL_CH)
                myController.setRollMix(myController.getRollMix() - mixDiff);
              else if (chVal1Mix == YAW_CH)
                myController.setYawMix(myController.getYawMix() - mixDiff);
              else if (chVal1Mix == THROTTLE_CH)
                myController.setThrottleMix(myController.getThrottleMix() - mixDiff);
              else if (chVal1Mix == KNOB_1_CH)
                myController.setKnob1Mix(myController.getKnob1Mix() - mixDiff);
              else if (chVal1Mix == KNOB_2_CH)
                myController.setKnob2Mix(myController.getKnob2Mix() - mixDiff);
              else if (chVal1Mix == SW_1_CH)
                myController.setSw1Mix(myController.getSw1Mix() - mixDiff);
              else if (chVal1Mix == SW_2_CH)
                myController.setSw2Mix(myController.getSw2Mix() - mixDiff);
              else if (chVal1Mix == SW_3_CH)
                myController.setSw3Mix(myController.getSw3Mix() - mixDiff);
              else if (chVal1Mix == SW_4_CH)
                myController.setSw4Mix(myController.getSw4Mix() - mixDiff);
              else if (chVal1Mix == SW_5_CH)
                myController.setSw5Mix(myController.getSw5Mix() - mixDiff);
              else if (chVal1Mix == SW_6_CH)
                myController.setSw6Mix(myController.getSw6Mix() - mixDiff);
            }
          }
          
          if (ioMonButton.inArea(y, x))
          {
            // clear all buttons
            noInterrupts();
            channelEditButton.clear();
            channelMixesButton.clear();
            ioMonButton.clear();
            interrupts();
            
            // set iomon flag
            ioMonFlag = true;
            
            // initialize io fields
            noInterrupts();
            backButton.draw();
            sw1StateArea.draw();
            sw2StateArea.draw();
            sw3StateArea.draw();
            sw4StateArea.draw();
            sw5StateArea.draw();
            sw6StateArea.draw();
            triSwAStateArea.draw();
            triSwBStateArea.draw();
            pitchJoyArea.draw();
            rollJoyArea.draw();
            yawJoyArea.draw();
            throttleJoyArea.draw();
            knob1Area.draw();
            knob2Area.draw();
            shuntVoltageArea.draw();
            busVoltageArea.draw();
            currentArea.draw();
            loadVoltageArea.draw();
            buddy1Area.draw();
            buddy2Area.draw();
            buddy3Area.draw();
            buddy4Area.draw();
            buddy5Area.draw();
            buddy6Area.draw();
            buddy7Area.draw();
            buddy8Area.draw();
            interrupts();
          }
        }
      }
    }
    
    disableTS();
    enableTFT();
  }
}

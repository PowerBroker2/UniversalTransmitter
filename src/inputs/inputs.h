#pragma once
#include "Arduino.h"
#include "OneButton.h"




/*
* ****************** Switches ******************
*/
const volatile int SW_1_PIN = 3;
const volatile int SW_2_PIN = 4;
const volatile int SW_3_PIN = 5;
const volatile int SW_4_PIN = 6;
const volatile int SW_5_PIN = 23;
const volatile int SW_6_PIN = 22;

const volatile int TRI_SW_A_PIN = 27;
const volatile int TRI_SW_B_PIN = 28;

volatile int sw_1_state = 0;
volatile int sw_2_state = 0;
volatile int sw_3_state = 0;
volatile int sw_4_state = 0;
volatile int sw_5_state = 0;
volatile int sw_6_state = 0;

volatile int tri_sw_a_state = 0;
volatile int tri_sw_b_state = 0;




FASTRUN void SW1ISR() { sw_1_state = digitalReadFast(SW_1_PIN); }
FASTRUN void SW2ISR() { sw_2_state = digitalReadFast(SW_2_PIN); }
FASTRUN void SW3ISR() { sw_3_state = digitalReadFast(SW_3_PIN); }
FASTRUN void SW4ISR() { sw_4_state = digitalReadFast(SW_4_PIN); }
FASTRUN void SW5ISR() { sw_5_state = digitalReadFast(SW_5_PIN); }
FASTRUN void SW6ISR() { sw_6_state = digitalReadFast(SW_6_PIN); }

FASTRUN void TRISWAISR() { tri_sw_a_state = digitalReadFast(TRI_SW_A_PIN); }
FASTRUN void TRISWBISR() { tri_sw_b_state = digitalReadFast(TRI_SW_B_PIN); }




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

	
	attachInterrupt(SW_1_PIN, SW1ISR, CHANGE);
	attachInterrupt(SW_2_PIN, SW2ISR, CHANGE);
	attachInterrupt(SW_3_PIN, SW3ISR, CHANGE);
	attachInterrupt(SW_4_PIN, SW4ISR, CHANGE);
	attachInterrupt(SW_5_PIN, SW5ISR, CHANGE);
	attachInterrupt(SW_6_PIN, SW6ISR, CHANGE);

	attachInterrupt(TRI_SW_A_PIN, TRISWAISR, CHANGE);
	attachInterrupt(TRI_SW_B_PIN, TRISWBISR, CHANGE);
}




/*
* ****************** Buttons ******************
*/
const int PITCH_TRIM_UP_PIN      = 34;
const int PITCH_TRIM_DOWN_PIN    = 33;
const int ROLL_TRIM_RIGHT_PIN    = 31;
const int ROLL_TRIM_LEFT_PIN     = 32;
const int YAW_TRIM_RIGHT_PIN     = 36;
const int YAW_TRIM_LEFT_PIN      = 35;
const int THROTTLE_TRIM_UP_PIN   = 38;
const int THROTTLE_TRIM_DOWN_PIN = 37;




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




FASTRUN void PITCH_TRIM_UP_ISR()      { pitch_trim_up.tick();      }
FASTRUN void PITCH_TRIM_DOWN_ISR()    { pitch_trim_down.tick();    }
FASTRUN void ROLL_TRIM_RIGHT_ISR()    { roll_trim_right.tick();    }
FASTRUN void ROLL_TRIM_LEFT_ISR()     { roll_trim_left.tick();     }
FASTRUN void YAW_TRIM_RIGHT_ISR()     { yaw_trim_right.tick();     }
FASTRUN void YAW_TRIM_LEFT_ISR()      { yaw_trim_left.tick();      }
FASTRUN void THROTTLE_TRIM_UP_ISR()   { throttle_trim_up.tick();   }
FASTRUN void THROTTLE_TRIM_DOWN_ISR() { throttle_trim_down.tick(); }




void pitch_trim_up_click()           { Serial.println("Pitch Trim Up Click");           }
void pitch_trim_down_click()         { Serial.println("Pitch Trim Down Click");         }
void roll_trim_right_click()         { Serial.println("Roll Trim Right Click");         }
void roll_trim_left_click()          { Serial.println("Roll Trim Left Click");          }
void yaw_trim_right_click()          { Serial.println("Yaw Trim Right Click");          }
void yaw_trim_left_click()           { Serial.println("Yaw Trim Left Click");           }
void throttle_trim_up_click()        { Serial.println("Throttle Trim Up Click");        }
void throttle_trim_down_click()      { Serial.println("Throttle Trim Down Click");      }
void pitch_trim_up_long_click()      { Serial.println("Pitch Trim Up Long Click");      }
void pitch_trim_down_long_click()    { Serial.println("Pitch Trim Down Long Click");    }
void roll_trim_right_long_click()    { Serial.println("Roll Trim Right Long Click");    }
void roll_trim_left_long_click()     { Serial.println("Roll Trim Left Long Click");     }
void yaw_trim_right_long_click()     { Serial.println("Yaw Trim Right Long Click");     }
void yaw_trim_left_long_click()      { Serial.println("Yaw Trim Left Long Click");      }
void throttle_trim_up_long_click()   { Serial.println("Throttle Trim Up Long Click");   }
void throttle_trim_down_long_click() { Serial.println("Throttle Trim Down Long Click"); }




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

	attachInterrupt(PITCH_TRIM_UP_PIN,      PITCH_TRIM_UP_ISR,      CHANGE);
	attachInterrupt(PITCH_TRIM_DOWN_PIN,    PITCH_TRIM_DOWN_ISR,    CHANGE);
	attachInterrupt(ROLL_TRIM_RIGHT_PIN,    ROLL_TRIM_RIGHT_ISR,    CHANGE);
	attachInterrupt(ROLL_TRIM_LEFT_PIN,     ROLL_TRIM_LEFT_ISR,     CHANGE);
	attachInterrupt(YAW_TRIM_RIGHT_PIN,     YAW_TRIM_RIGHT_ISR,     CHANGE);
	attachInterrupt(YAW_TRIM_LEFT_PIN,      YAW_TRIM_LEFT_ISR,      CHANGE);
	attachInterrupt(THROTTLE_TRIM_UP_PIN,   THROTTLE_TRIM_UP_ISR,   CHANGE);
	attachInterrupt(THROTTLE_TRIM_DOWN_PIN, THROTTLE_TRIM_DOWN_ISR, CHANGE);
}




/*
* ****************** Joysticks ******************
*/
const int PITCH_PIN    = A1; // Pin 15
const int ROLL_PIN     = A0; // Pin 14
const int YAW_PIN      = A2; // Pin 16
const int THROTTLE_PIN = A3; // Pin 17




void setupJoys()
{
	analogReadResolution(16);
}




/*
* ****************** Knobs ******************
*/
const int KNOB_1_PIN = A17; // Pin 41
const int KNOB_2_PIN = A16; // Pin 40




void setupKnobs()
{
	analogReadResolution(16);
}




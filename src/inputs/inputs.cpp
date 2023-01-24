#include "Arduino.h"
#include "OneButton.h"
#include "TeensyTimerTool.h"




using namespace TeensyTimerTool;




/*
* ****************** Switches ******************
*/
extern const volatile int SW_1_PIN = 3;
extern const volatile int SW_2_PIN = 4;
extern const volatile int SW_3_PIN = 5;
extern const volatile int SW_4_PIN = 6;
extern const volatile int SW_5_PIN = 23;
extern const volatile int SW_6_PIN = 22;

extern const volatile int TRI_SW_A_PIN = 27;
extern const volatile int TRI_SW_B_PIN = 28;

volatile int sw_1_state = 0;
volatile int sw_2_state = 0;
volatile int sw_3_state = 0;
volatile int sw_4_state = 0;
volatile int sw_5_state = 0;
volatile int sw_6_state = 0;

volatile int tri_sw_a_state = 0;
volatile int tri_sw_b_state = 0;

volatile bool sw_1_switched;
volatile bool sw_2_switched;
volatile bool sw_3_switched;
volatile bool sw_4_switched;
volatile bool sw_5_switched;
volatile bool sw_6_switched;

volatile bool tri_sw_a_switched;
volatile bool tri_sw_b_switched;




FASTRUN void SW1ISR()
{
	int prevState = sw_1_state;
	sw_1_state = digitalReadFast(SW_1_PIN);

	if (prevState != sw_1_state)
	{
		sw_1_switched = true;
	}
}

FASTRUN void SW2ISR()
{
	int prevState = sw_2_state;
	sw_2_state = digitalReadFast(SW_2_PIN);

	if (prevState != sw_2_state)
	{
		sw_2_switched = true;
	}
}

FASTRUN void SW3ISR()
{
	int prevState = sw_3_state;
	sw_3_state = digitalReadFast(SW_3_PIN);

	if (prevState != sw_3_state)
	{
		sw_3_switched = true;
	}
}

FASTRUN void SW4ISR()
{
	int prevState = sw_4_state;
	sw_4_state = digitalReadFast(SW_4_PIN);

	if (prevState != sw_4_state)
	{
		sw_4_switched = true;
	}
}

FASTRUN void SW5ISR()
{
	int prevState = sw_5_state;
	sw_5_state = digitalReadFast(SW_5_PIN);

	if (prevState != sw_5_state)
	{
		sw_5_switched = true;
	}
}

FASTRUN void SW6ISR()
{
	int prevState = sw_6_state;
	sw_6_state = digitalReadFast(SW_6_PIN);

	if (prevState != sw_6_state)
	{
		sw_6_switched = true;
	}
}


FASTRUN void TRISWAISR()
{
	int prevState = tri_sw_a_state;
	tri_sw_a_state = digitalReadFast(TRI_SW_A_PIN);

	if (prevState != tri_sw_a_state)
	{
		tri_sw_a_switched = true;
	}
}

FASTRUN void TRISWBISR()
{
	int prevState = tri_sw_b_state;
	tri_sw_b_state = digitalReadFast(TRI_SW_B_PIN);

	if (prevState != tri_sw_b_state)
	{
		tri_sw_b_switched = true;
	}
}





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

	delay(1); // SW 4 doesn't initialize correctly without this for some reason

	sw_1_state = digitalReadFast(SW_1_PIN);
	sw_2_state = digitalReadFast(SW_2_PIN);
	sw_3_state = digitalReadFast(SW_3_PIN);
	sw_4_state = digitalReadFast(SW_4_PIN);
	sw_5_state = digitalReadFast(SW_5_PIN);
	sw_6_state = digitalReadFast(SW_6_PIN);

	tri_sw_a_state = digitalReadFast(TRI_SW_A_PIN);
	tri_sw_b_state = digitalReadFast(TRI_SW_B_PIN);
	
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
extern const float TRIM_BTN_FREQ   = 1000; // Hz
extern const float TRIM_BTN_PERIOD = 1.0 / TRIM_BTN_FREQ; // s

extern const int PITCH_TRIM_UP_PIN      = 34;
extern const int PITCH_TRIM_DOWN_PIN    = 33;
extern const int ROLL_TRIM_RIGHT_PIN    = 31;
extern const int ROLL_TRIM_LEFT_PIN     = 32;
extern const int YAW_TRIM_RIGHT_PIN     = 36;
extern const int YAW_TRIM_LEFT_PIN      = 35;
extern const int THROTTLE_TRIM_UP_PIN   = 38;
extern const int THROTTLE_TRIM_DOWN_PIN = 37;




PeriodicTimer trimBtnTimer;

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




FASTRUN void CHECK_PITCH_TRIM_UP()      { pitch_trim_up.tick();      }
FASTRUN void CHECK_PITCH_TRIM_DOWN()    { pitch_trim_down.tick();    }
FASTRUN void CHECK_ROLL_TRIM_RIGHT()    { roll_trim_right.tick();    }
FASTRUN void CHECK_ROLL_TRIM_LEFT()     { roll_trim_left.tick();     }
FASTRUN void CHECK_YAW_TRIM_RIGHT()     { yaw_trim_right.tick();     }
FASTRUN void CHECK_YAW_TRIM_LEFT()      { yaw_trim_left.tick();      }
FASTRUN void CHECK_THROTTLE_TRIM_UP()   { throttle_trim_up.tick();   }
FASTRUN void CHECK_THROTTLE_TRIM_DOWN() { throttle_trim_down.tick(); }




FASTRUN void checkTrimBtns()
{
	CHECK_PITCH_TRIM_UP();
	CHECK_PITCH_TRIM_DOWN();
	CHECK_ROLL_TRIM_RIGHT();
	CHECK_ROLL_TRIM_LEFT();
	CHECK_YAW_TRIM_RIGHT();
	CHECK_YAW_TRIM_LEFT();
	CHECK_THROTTLE_TRIM_UP();
	CHECK_THROTTLE_TRIM_DOWN();
}




FASTRUN void __attribute__((weak)) pitch_trim_up_click()           { Serial.println("Pitch Trim Up Click");           }
FASTRUN void __attribute__((weak)) pitch_trim_down_click()         { Serial.println("Pitch Trim Down Click");         }
FASTRUN void __attribute__((weak)) roll_trim_right_click()         { Serial.println("Roll Trim Right Click");         }
FASTRUN void __attribute__((weak)) roll_trim_left_click()          { Serial.println("Roll Trim Left Click");          }
FASTRUN void __attribute__((weak)) yaw_trim_right_click()          { Serial.println("Yaw Trim Right Click");          }
FASTRUN void __attribute__((weak)) yaw_trim_left_click()           { Serial.println("Yaw Trim Left Click");           }
FASTRUN void __attribute__((weak)) throttle_trim_up_click()        { Serial.println("Throttle Trim Up Click");        }
FASTRUN void __attribute__((weak)) throttle_trim_down_click()      { Serial.println("Throttle Trim Down Click");      }
FASTRUN void __attribute__((weak)) pitch_trim_up_long_click()      { Serial.println("Pitch Trim Up Long Click");      }
FASTRUN void __attribute__((weak)) pitch_trim_down_long_click()    { Serial.println("Pitch Trim Down Long Click");    }
FASTRUN void __attribute__((weak)) roll_trim_right_long_click()    { Serial.println("Roll Trim Right Long Click");    }
FASTRUN void __attribute__((weak)) roll_trim_left_long_click()     { Serial.println("Roll Trim Left Long Click");     }
FASTRUN void __attribute__((weak)) yaw_trim_right_long_click()     { Serial.println("Yaw Trim Right Long Click");     }
FASTRUN void __attribute__((weak)) yaw_trim_left_long_click()      { Serial.println("Yaw Trim Left Long Click");      }
FASTRUN void __attribute__((weak)) throttle_trim_up_long_click()   { Serial.println("Throttle Trim Up Long Click");   }
FASTRUN void __attribute__((weak)) throttle_trim_down_long_click() { Serial.println("Throttle Trim Down Long Click"); }




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

	trimBtnTimer.begin(checkTrimBtns, TRIM_BTN_PERIOD * 1e6);
}




/*
* ****************** Joysticks ******************
*/
extern const int PITCH_PIN    = A1; // Pin 15
extern const int ROLL_PIN     = A0; // Pin 14
extern const int YAW_PIN      = A2; // Pin 16
extern const int THROTTLE_PIN = A3; // Pin 17




void setupJoys()
{
	analogReadResolution(16);
}




/*
* ****************** Knobs ******************
*/
extern const int KNOB_1_PIN = A17; // Pin 41
extern const int KNOB_2_PIN = A16; // Pin 40




void setupKnobs()
{
	analogReadResolution(16);
}




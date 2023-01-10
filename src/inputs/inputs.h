#pragma once
#include "Arduino.h"
#include "OneButton.h"




/*
* ****************** Switches ******************
*/
extern const volatile int SW_1_PIN;
extern const volatile int SW_2_PIN;
extern const volatile int SW_3_PIN;
extern const volatile int SW_4_PIN;
extern const volatile int SW_5_PIN;
extern const volatile int SW_6_PIN;

extern const volatile int TRI_SW_A_PIN;
extern const volatile int TRI_SW_B_PIN;

extern volatile int sw_1_state;
extern volatile int sw_2_state;
extern volatile int sw_3_state;
extern volatile int sw_4_state;
extern volatile int sw_5_state;
extern volatile int sw_6_state;

extern volatile int tri_sw_a_state;
extern volatile int tri_sw_b_state;

extern volatile bool sw_1_switched;
extern volatile bool sw_2_switched;
extern volatile bool sw_3_switched;
extern volatile bool sw_4_switched;
extern volatile bool sw_5_switched;
extern volatile bool sw_6_switched;

extern volatile bool tri_sw_a_switched;
extern volatile bool tri_sw_b_switched;




FASTRUN void SW1ISR();
FASTRUN void SW2ISR();
FASTRUN void SW3ISR();
FASTRUN void SW4ISR();
FASTRUN void SW5ISR();
FASTRUN void SW6ISR();

FASTRUN void TRISWAISR();
FASTRUN void TRISWBISR();

void setupSwitches();




/*
* ****************** Buttons ******************
*/
extern const int PITCH_TRIM_UP_PIN;
extern const int PITCH_TRIM_DOWN_PIN;
extern const int ROLL_TRIM_RIGHT_PIN;
extern const int ROLL_TRIM_LEFT_PIN;
extern const int YAW_TRIM_RIGHT_PIN;
extern const int YAW_TRIM_LEFT_PIN;
extern const int THROTTLE_TRIM_UP_PIN;
extern const int THROTTLE_TRIM_DOWN_PIN;




extern OneButton pitch_trim_up;
extern OneButton pitch_trim_down;
extern OneButton roll_trim_right;
extern OneButton roll_trim_left;
extern OneButton yaw_trim_right;
extern OneButton yaw_trim_left;
extern OneButton throttle_trim_up;
extern OneButton throttle_trim_down;




FASTRUN void PITCH_TRIM_UP_ISR();
FASTRUN void PITCH_TRIM_DOWN_ISR();
FASTRUN void ROLL_TRIM_RIGHT_ISR();
FASTRUN void ROLL_TRIM_LEFT_ISR();
FASTRUN void YAW_TRIM_RIGHT_ISR();
FASTRUN void YAW_TRIM_LEFT_ISR();
FASTRUN void THROTTLE_TRIM_UP_ISR();
FASTRUN void THROTTLE_TRIM_DOWN_ISR();

void pitch_trim_up_click();
void pitch_trim_down_click();
void roll_trim_right_click();
void roll_trim_left_click();
void yaw_trim_right_click();
void yaw_trim_left_click();
void throttle_trim_up_click();
void throttle_trim_down_click();
void pitch_trim_up_long_click();
void pitch_trim_down_long_click();
void roll_trim_right_long_click();
void roll_trim_left_long_click();
void yaw_trim_right_long_click();
void yaw_trim_left_long_click();
void throttle_trim_up_long_click();
void throttle_trim_down_long_click();

void setupButtons();




/*
* ****************** Joysticks ******************
*/
extern const int PITCH_PIN;
extern const int ROLL_PIN;
extern const int YAW_PIN;
extern const int THROTTLE_PIN;




void setupJoys();




/*
* ****************** Knobs ******************
*/
extern const int KNOB_1_PIN;
extern const int KNOB_2_PIN;




void setupKnobs();




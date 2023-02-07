#pragma once
#include "SerialTransfer.h"
#include "UniversalController.h"
#include "radios/radios.h"
#include "chHelper.h"
#include "settingsHelper.h"




#define COMMS_PORT      BT
#define COMMS_PORT_BAUD 115200




SerialTransfer commsTransfer;
extern UniversalController myController;




struct __attribute__((packed)) TX_STRUCT
{
  float pitchJoy;
  float rollJoy;
  float yawJoy;
  float throttleJoy;
  float knob1;
  float knob2;
  float sw1State;
  float sw2State;
  float sw3State;
  float sw4State;
  float sw5State;
  float sw6State;
  float triSwAState;
  float triSwBState;
} txStruct;




void setupComms()
{
  COMMS_PORT.begin(COMMS_PORT_BAUD);
  commsTransfer.begin(COMMS_PORT);
}




void sendData()
{
  txStruct.pitchJoy    = myController.pitchJoy();
  txStruct.rollJoy     = myController.rollJoy();
  txStruct.yawJoy      = myController.yawJoy();
  txStruct.throttleJoy = myController.throttleJoy();
  txStruct.knob1       = myController.knob1();
  txStruct.knob2       = myController.knob2();
  txStruct.sw1State    = myController.sw1State();
  txStruct.sw2State    = myController.sw2State();
  txStruct.sw3State    = myController.sw3State();
  txStruct.sw4State    = myController.sw4State();
  txStruct.sw5State    = myController.sw5State();
  txStruct.sw6State    = myController.sw6State();
  txStruct.triSwAState = myController.triSwAState();
  txStruct.triSwBState = myController.triSwBState();
  
  uint16_t sendSize = 0;
  
  COMMS_PORT.flush();
  sendSize = commsTransfer.txObj(txStruct);
  commsTransfer.sendData(sendSize);
}

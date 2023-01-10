#pragma once
#include "Arduino.h"
#include "SPI.h"
#include "WiFiEspAT.h"
#include "RF24.h"




/*
* ****************** ESP8266 ******************
*/
#define ESP Serial1




/*
* ****************** NRF24 ******************
*/
extern const int NRF_CE_PIN;
extern const int NRF_CSN_PIN;
extern const int NRF_IRQ_PIN;




extern RF24 radio;




FASTRUN void __attribute__((weak)) NRFISR();

void enableNRF();
void disableNRF();




/*
* ****************** Bluetooth ******************
*/
#define BT Serial6




/*
* ****************** Breakout UARTs ******************
*/
#define UART_1 Serial1
#define UART_2 Serial6




void setupRadios();




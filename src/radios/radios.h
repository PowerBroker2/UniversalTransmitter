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
const int NRF_CE_PIN  = 29;
const int NRF_CSN_PIN = 30;
const int NRF_IRQ_PIN = 39;




RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);




FASTRUN void __attribute__((weak)) NRFISR()
{
    // print IRQ status and all masking flags' states
    Serial.println(F("IRQ pin is actively LOW"));  // show that this function was called

    delayMicroseconds(250);

    bool tx_ds, tx_df, rx_dr;  
                   // declare variables for IRQ masks
    radio.whatHappened(tx_ds, tx_df, rx_dr);  // get values for IRQ masks

    // whatHappened() clears the IRQ masks also. This is required for
    // continued TX operations when a transmission fails.
    // clearing the IRQ masks resets the IRQ pin to its inactive state (HIGH)

    Serial.print("\tdata_sent: ");
    Serial.print(tx_ds);  // print "data sent" mask state
    Serial.print(", data_fail: ");
    Serial.print(tx_df);  // print "data fail" mask state
    Serial.print(", data_ready: ");
    Serial.println(rx_dr);  // print "data ready" mask state
}

void enableNRF()  { digitalWriteFast(NRF_CE_PIN, LOW);  }
void disableNRF() { digitalWriteFast(NRF_CE_PIN, HIGH); }




/*
* ****************** Bluetooth ******************
*/
#define BT Serial6




/*
* ****************** Breakout UARTs ******************
*/
#define UART_1 Serial1
#define UART_2 Serial6




void setupRadios()
{
    attachInterrupt(NRF_IRQ_PIN, NRFISR, FALLING);

    enableNRF();
    radio.begin();
    disableNRF();
}




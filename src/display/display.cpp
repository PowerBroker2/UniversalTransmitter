#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "TeensyTimerTool.h"




using namespace TeensyTimerTool;




extern const float TOUCH_FREQ   = 30; // Hz
extern const float TOUCH_PERIOD = 1.0 / TOUCH_FREQ; // s

extern const int DISP_CS_PIN = 10;
extern const int DC_PIN      = 9;
extern const int T_CS_PIN    = 8;
extern const int T_IRQ_PIN   = 2;

extern volatile const int TOUCH_TIME_THRESH = 0.2 * 1e6; // us




PeriodicTimer       touchTimer;
XPT2046_Touchscreen ts(T_CS_PIN, T_IRQ_PIN);
Adafruit_ILI9341    tft(DISP_CS_PIN, DC_PIN);
TS_Point            ts_point;




volatile long time_touched  = 0;
volatile bool touch_handled = true;




void enableTS()    { digitalWriteFast(DISP_CS_PIN, HIGH);  digitalWriteFast(T_CS_PIN, LOW);  }
void enableTFT()   { digitalWriteFast(DISP_CS_PIN, LOW);   digitalWriteFast(T_CS_PIN, HIGH); }
void disableTS()   { digitalWriteFast(T_CS_PIN,    HIGH);                                    }
void disableTFT()  { digitalWriteFast(DISP_CS_PIN, HIGH);                                    }
void disableDisp() { digitalWriteFast(DISP_CS_PIN, HIGH);  digitalWriteFast(T_CS_PIN, HIGH); }

FASTRUN void __attribute__((weak)) whenTouched()
{
    if (ts.tirqTouched())
    {
        disableTFT();
        enableTS();
      
        if (ts.touched())
        {
            long currTime = micros();

            if ((currTime - time_touched) >= TOUCH_TIME_THRESH)
            {
                ts_point      = ts.getPoint();
                touch_handled = false;
                time_touched  = currTime;
                
                Serial.print("Pressure = ");
                Serial.print(ts_point.z);
                Serial.print(", x = ");
                Serial.print(ts_point.x);
                Serial.print(", y = ");
                Serial.print(ts_point.y);
                Serial.println();
            }
            else
            {
                ts.getPoint();
            }
        }
        
        disableTS();
    }
}




void setupDisplay()
{
    pinMode(DISP_CS_PIN, OUTPUT);
    pinMode(T_CS_PIN, OUTPUT);

    enableTS();
    ts.begin();
    
    enableTFT();
    tft.begin();

    disableDisp();

    touchTimer.begin(whenTouched, TOUCH_PERIOD * 1e6);
}




/*
  Tmp36.h - Library for reading temperature from the Tmp36 Temperature sensor.
  Created by Kyle O'Shaughnessy, December 28, 2014.

              Flat Side
         +-----------------+      
         |TMP36 Temperature|      
         |     Sensor      |      
         +-+------+------+-+      
           |      |      |        
           |      |      |        
     +-----+      |      +-----+  
     |            |            |  
     |            |            |  
     |            |            |  
     +            +            +  
  3.3/5V      Analog In     Ground
*/

#ifndef Tmp36_h
#define Tmp36_h

#include "Arduino.h"

class Tmp36 {
  public:
    Tmp36(int pin, float pinVoltage);
    void setPin(int pin);
    void setPinVoltage(int pinVoltage);
    float getTempC();
    float getTempF();
  protected:
    float readVoltage();
  private:
    int _pin;
    int _pinVoltage;
};

#endif
/*
  Pir.h - Library for reading motion from the Pir Motion sensor.
  Created by Kyle O'Shaughnessy, December 28, 2014.

  5V       Digital In   Ground
   +           +          +   
   |           |          |   
   |     +-----+----+     |   
   +-----+Pir Motion+-----+   
         |Sensor    |         
         +----------+         
*/

#ifndef Pir_h
#define Pir_h

#include "Arduino.h"

class Pir {
  public:
    Pir(int pin);
    void setPin(int pin);
    bool isMotion();
  private:
    int _pin;
};

#endif
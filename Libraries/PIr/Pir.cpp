/*
  Pir.cpp - Library for reading motion from the Pir Motion sensor.
  Created by Kyle O'Shaughnessy, December 28, 2014.

  5V       Digital In   Ground
   +           +          +   
   |           |          |   
   |     +-----+----+     |   
   +-----+Pir Motion+-----+   
         |Sensor    |         
         +----------+         
*/

#include "Arduino.h"
#include "Pir.h"

Pir::Pir(int pin) {
  pinMode(pin, INPUT);
  _pin = pin;
}

void Pir::setPin(int pin) {
  _pin = pin;
}

bool Pir::isMotion() { 
  return (digitalRead(_pin) == HIGH);
}
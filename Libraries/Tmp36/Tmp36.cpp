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

#include "Arduino.h"
#include "Tmp36.h"

Tmp36::Tmp36(int pin, float pinVoltage) {
  _pin = pin;
  _pinVoltage = pinVoltage;
}

void Tmp36::setPin(int pin) {
  _pin = pin;
}

void Tmp36::setPinVoltage(int pinVoltage) {
  _pinVoltage = pinVoltage;
}

float Tmp36::getTempC() {
  return (readVoltage() - 0.5) * 100;
}

float Tmp36::getTempF() {
  return ((getTempC() * 9.0) / 5.0)  + 32;
}

float Tmp36::readVoltage() {
  return (analogRead(_pin) * _pinVoltage) / 1024.0; 
}
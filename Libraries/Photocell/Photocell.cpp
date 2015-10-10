/*
  Photocell.cpp - Library for reading light intensity from a photocell.
  Created by Kyle O'Shaughnessy, December 28, 2014.

  5/3.3V OUT          Analog In                          
      +                   +                              
      |                   |                              
      |  +---------+      |      +-------------+         
      +--+Photocell+------+------+~10K Resistor+------+  
         +---------+             +-------------+      |  
                                                      |  
                                                      +  
                                                    Ground         
*/

#include "Arduino.h"
#include "Photocell.h"

Photocell::Photocell(int pin) {
  _pin = pin;
}

void Photocell::setPin(int pin) {
  _pin = pin;
}

int Photocell::getIntensity1023() {
  return analogRead(_pin);
}

int Photocell::getIntensity255() {
  return map(getIntensity1023(), 0, 1023, 0, 255);
}

float Photocell::getIntensity() {
  return getIntensity1023() / 1023.0;
}
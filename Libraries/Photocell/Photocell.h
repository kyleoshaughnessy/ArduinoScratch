/*
  Photocell.h - Library for reading light intensity from a photocell.
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

#ifndef Photocell_h
#define Photocell_h

#include "Arduino.h"

class Photocell {
  public:
    Photocell(int pin);
    void setPin(int pin);
    /*
      Value between 0-1023
    */
    int getIntensity1023();
    /*
      Value between 0-255
    */
    int getIntensity255();
    /*
      Value between 0-1
    */
    float getIntensity();
  private:
    int _pin;
};

#endif
/*
  LCDBackpack.h -
*/

#ifndef LCDBackpack_h
#define LCDBackpack_h

#include "Arduino.h"
#include "SoftwareSerial.h"

// tx on pin 2
// LCDBackpack myLCD(0,2)

//inherits write(), print(), println()
class LCDBackpack: public SoftwareSerial {
  public:
    LCDBackpack(int rx, int tx);
    void quickSetup();
    void setSize(int cols, int rows);
    void setContrast(int con);
    void setBrightness(int bri);
    void backlightOn();
    void backlightOff();
    void autoscrollOn();
    void autoscrollOff();
    void clearScreen();
    void setCursor(int col, int row);
    void home();
    void back();
    void forward();
    void underlineCursorOn();
    void underlineCursorOff();
    void blockCursorOn();
    void blockCursorOff();
    void setColor(int red, int green, int blue);
    void setRed();
    void setGreen();
    void setBlue();
  private:
    void sendCmd(int cmd);
    void sendOneParam(int cmd, int p1);
    void sendTwoParam(int cmd, int p1, int p2);
    void sendThreeParam(int cmd, int p1, int p2, int p3);
};

#endif

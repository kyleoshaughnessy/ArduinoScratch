/*
  LCDBackpack.cpp -
*/

#include "Arduino.h"
#include "LCDBackpack.h"
#include "SoftwareSerial.h"

LCDBackpack::LCDBackpack(int rx, int tx): SoftwareSerial(rx, tx) {

}

void LCDBackpack::quickSetup() {
  begin(9600);
  setSize(16,2);
  backlightOn();
  setContrast(255);
  setBrightness(255);
  clearScreen();
  home();
}

void LCDBackpack::setSize(int cols, int rows) {
  sendTwoParam(0xD1, cols, rows);
}

void LCDBackpack::setContrast(int con) {
  sendOneParam(0x50, con);
}

void LCDBackpack::setBrightness(int bri) {
  sendOneParam(0x99, bri);
}

void LCDBackpack::backlightOn() {
  sendOneParam(0x42, 0);
}

void LCDBackpack::backlightOff() {
  sendCmd(0x46);
  delay(10);
}

void LCDBackpack::autoscrollOn() {
  sendCmd(0x51);
  delay(10);
}

void LCDBackpack::autoscrollOff() {
  sendCmd(0x52);
  delay(10);
}

void LCDBackpack::clearScreen() {
  sendCmd(0x58);
  delay(10);
}

void LCDBackpack::setCursor(int col, int row) {
  sendTwoParam(0x47, col, row);
}

void LCDBackpack::home() {
  sendCmd(0x48);
  delay(10);
}

void LCDBackpack::back() {
  sendCmd(0x4C);
  delay(10);
}

void LCDBackpack::forward() {
  sendCmd(0x4D);
  delay(10);
}

void LCDBackpack::underlineCursorOn() {
  sendCmd(0x4A);
  delay(10);
}

void LCDBackpack::underlineCursorOff() {
  sendCmd(0x4B);
  delay(10);
}

void LCDBackpack::blockCursorOn() {
  sendCmd(0x53);
  delay(10);
}

void LCDBackpack::blockCursorOff() {
  sendCmd(0x54);
  delay(10);
}

void LCDBackpack::setColor(int red, int green, int blue) {
  sendThreeParam(0xD0, red, green, blue);
}

void LCDBackpack::setRed() {
  setColor(255, 0, 0);
}

void LCDBackpack::setGreen() {
  setColor(0, 255, 0);
}

void LCDBackpack::setBlue() {
  setColor(0, 0, 255);
}

void LCDBackpack::sendCmd(int cmd) {
  write(0xFE);
  write(cmd);
}

void LCDBackpack::sendOneParam(int cmd, int p1) {
  sendCmd(cmd);
  write(p1);
  delay(10);
}

void LCDBackpack::sendTwoParam(int cmd, int p1, int p2) {
  sendCmd(cmd);
  write(p1);
  write(p2);
  delay(10);
}

void LCDBackpack::sendThreeParam(int cmd, int p1, int p2, int p3) {
  sendCmd(cmd);
  write(p1);
  write(p2);
  write(p3);
  delay(10);
}

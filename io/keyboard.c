#include "include/keyboard.h"
#include "include/ports_io.h"

char kscan(void)
{
  char key = 0;           /* Reading key code                           */
  if (inb(0x64) & 0x01) {
    key = inb(0x60);
  }

  if (key == 0xE) {       /* Decode the scan code to ascii              */
    return '\r';
  } else if (key == 0x1C) {
    return '\n';
  } else if (key == 0x52) {
    return '0';
  } else if (key == 0x39) {
    return ' ';
  } else if (key == 0x34) {
    return '.';
  } else if (key == 0xB5) {
    return '/';
  } else if (key >= 0x2 && key <= 0xA) {
    return _num[key - 0x2];
  } else if (key >= 0x10 && key <= 0x1C) {
    return _qwertzuiop[key - 0x10];
  } else if (key >= 0x1E && key <= 0x26) {
    return _asdfghjkl[key - 0x1E];
  } else if (key >= 0x2C && key <= 0x32) {
    return _yxcvbnm[key - 0x2C];
  }
  return 0;
}

/* Basic assembler functions defination */

#include <stdint.h>
#include "lib.h"


uint8_t inb(uint32_t port)
{
  unsigned char result;
  __asm__("inb %%dx, %%al" : "=a" (result) : "d" (port));
  return result;
}

uint8_t inw(uint32_t port)
{
  unsigned char result;
  __asm__("inw %%dx, %%ax" : "=a" (result) : "d" (port));
  return result;
}

void outb(uint32_t port, uint8_t data)
{
  __asm__("outb %%al, %%dx" : : "a" (data), "d" (port));
}

void outw(uint32_t port, uint16_t data)
{
  __asm__("outw %%ax, %%dx" : : "a" (data), "d" (port));
}

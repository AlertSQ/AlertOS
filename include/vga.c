#include "vga.h"
#include "lib.h"

uint16_t get_offset(uint16_t col, uint16_t row)
{
  return 2 * (row * width + col);
}

uint16_t get_offset_row(uint16_t offset)
{
  return offset / (2 * width);
}

uint16_t get_cursor_offset()
{
  outb(0x3D4, 14);
  uint16_t offset = inb(0x3D5) << 8;
  outb(0x3D4, 15);
  offset += inb(0x3D5);
  return offset * 2;
}

void set_cursor_offset(uint16_t offset)
{
  offset /= 2;
  outb(0x3D4, 14);
  outb(0x3D5, (uint8_t)(offset >> 8));
  outb(0x3D4, 15);
  outb(0x3D5, (uint8_t)(offset & 0xFF));
}

void putc(uint8_t ch, uint8_t attr)
{
  uint8_t *vidmem = (uint8_t*) video_address;
  uint16_t offset = get_cursor_offset();
  if (ch == '\n') {
    uint16_t row = get_offset_row(offset);
    offset = get_offset(0, row + 1);
  } else if (ch == '\r') {
    offset -=2;
  } else {
    vidmem[offset] = ch;
    vidmem[offset + 1] = attr;
    offset += 2;
  }
  set_cursor_offset(offset);
}

void vga_print(char *s)
{
  int i = 0;
  while (s[i] != '\0') {
    putc(s[i], 0x07);
    i++;
  }
}

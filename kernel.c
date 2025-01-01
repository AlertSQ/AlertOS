#include "include/gdt.h"
#include "include/vga.h"
#include "include/keyboard.h"


void kmain()
{
  init_gdt();
  putc('x', 0x07);
  putc('s', 0x07);
  putc('h', 0x07);
  putc('>', 0x07);
  for (;;) {
   char a = kscan();
   if (a != 0) {
     putc(a, 0x07);
   }
  }
}

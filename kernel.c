#include "include/gdt.h"
#include "include/vga.h"

void kmain()
{
  init_gdt();
  putc('L', 0x07);
  putc('O', 0x07);
  putc('X', 0x07);
}

#include "include/gdt.h"
#include "include/idt.h"
#include "../io/include/vga.h"
#include "../io/include/keyboard.h"

void kmain(void)
{
  init_gdt();
  init_idt();
  vga_print("Hello World!");
  for (;;) {         /* цикл чтения клавишы из клавиатуры */
   char a = kscan(); /* само чтение  */
   if (a != 0) {     /* проверка нажатия клавишы  */
     vga_putc(a, 0x07);  /* вывод символа на экран    */
   }
  }
}

#include "include/gdt.h"
#include "include/vga.h"
#include "include/keyboard.h"


void kmain()
{
  init_gdt();
  vga_print("Hello World!");
  for (;;) {         /* цикл чтения клавишы из клавиатуры */
   char a = kscan(); /* само чтение  */
   if (a != 0) {     /* проверка нажатия клавишы  */
     putc(a, 0x07);  /* вывод символа на экран    */
   }
  }
}

#include "include/gdt.h"
#include "include/idt.h"
#include "include/syscalls.h"
#include "../io/include/vga.h"

void kmain(void)
{
  init_gdt();
  init_idt();
  vga_print("Ascertain kernel\n");
  idt_set_descriptor(0x80, dispather, 0xEE); /* Load syscall dispather to IDT */
  __asm__ __volatile__("movl $0, %eax; int $0x80"); /* Testing syscall */
}

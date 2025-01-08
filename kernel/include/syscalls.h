#include "../../io/include/vga.h"
#include "../../io/include/ports_io.h"

#define SYSCALL_COUNT 2

void syscall_open()
{
  vga_print("SYSCALL : Open()");
}

void syscall_poweroff()
{
  vga_print("SYSCALL : POWEROFF()");
  outw(0x604, 0x2000);
}

void syscall_print()
{
  vga_print("");
}

void *syscalls[SYSCALL_COUNT] = {
  syscall_open,
  syscall_poweroff
};

__attribute__ ((naked)) void dispather(void)
{
  __asm__ __volatile__(".intel_syntax noprefix\n"
                       ".equ SYSCALL_COUNT, 2\n"
                       "cmp eax, SYSCALL_COUNT - 1\n"
                       "ja error \n"
                       "push eax\n"
                       "push gs\n"
                       "push fs\n"
                       "push es\n"
                       "push ds\n"
                       "push ebp\n"
                       "push edi\n"
                       "push esi\n"
                       "push edx\n"
                       "push ecx\n"
                       "push ebx\n"
                       "push esp\n"
                       "call [syscalls+eax*4]\n"
                       "add esp, 4\n"
                       "pop ebx\n"
                       "pop ecx\n"
                       "pop edx\n"
                       "pop esi\n"
                       "pop edi\n"
                       "pop ebp\n"
                       "pop ds\n"
                       "pop es\n"
                       "pop fs\n"
                       "pop gs\n"
                       "add esp, 4\n"
                       "iretd\n"
                       "error:\n"
                       "iretd");
}

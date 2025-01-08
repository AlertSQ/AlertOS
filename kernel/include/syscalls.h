#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "../../io/include/vga.h"
#include "../../io/include/ports_io.h"

#define SYSCALL_COUNT 2

__attribute__ ((naked)) void dispather(void);
void syscall_open(void);
void syscall_poweroff(void);
void syscall_print(void);

#endif

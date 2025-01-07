#ifndef PORTS_IO_H
#define PORTS_IO_H

#include <stdint.h>

uint8_t inb(uint32_t port);
uint8_t inw (uint32_t port);
void outb(uint32_t port, uint8_t data);
void outw (uint32_t port, uint16_t data);
#endif

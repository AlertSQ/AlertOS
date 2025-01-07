#ifndef IDT_H
#define IDT_H

#include "../../IO/include/vga.h"

typedef struct {
  uint16_t isr_low;
  uint16_t kernel_cs;
  uint8_t reserved;
  uint8_t attributes;
  uint16_t isr_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) idtr_t;

idt_entry_t idt[256];
idtr_t idtr;

typedef struct {
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
  uint32_t sp;
  uint32_t ss;
} __attribute__((packed)) frame;

__attribute__((interrupt)) void exception_handler(frame *f)
{
  vga_print("Exception detected!");
}

__attribute__((interrupt)) void exception_handler_err(frame *f, uint32_t code)
{
  vga_print("Kernel panic!");
}

__attribute__((interrupt)) void interrupt_handler(frame *f)
{
  vga_print("INT 0x80 ; INTERRUPT !");
}

void init_idt(void);
void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
#endif

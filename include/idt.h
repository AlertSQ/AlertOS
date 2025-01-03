#include "vga.h"

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

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags)
{
  idt_entry_t* descriptor = &idt[vector];
  descriptor->isr_low = (uint32_t)isr & 0xFFFF;
  descriptor->kernel_cs = 0x08;
  descriptor->attributes = flags;
  descriptor->isr_high = (uint32_t)isr >> 16;
  descriptor->reserved = 0;
}

void init_idt()
{
  idtr.base = (uintptr_t)&idt[0];
  idtr.limit = (uint16_t)(8 * 256);
  
  for (uint8_t vector = 0; vector < 32; vector++) {
    if (vector == 8 || vector == 10 || vector == 11 || vector == 12 || vector == 13 || vector == 14 || vector == 17 || vector == 30) {
      idt_set_descriptor(vector, exception_handler_err, 0x8E);
    } else {
      idt_set_descriptor(vector, exception_handler, 0x8E);
    }
  }

  for (uint8_t vector = 0; vector < 32; vector++) {
    idt_set_descriptor(vector, interrupt_handler, 0x8E);
  }
  __asm__ volatile ("lidt %0" : : "m"(idtr));

}
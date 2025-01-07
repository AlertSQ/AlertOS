#include "include/gdt.h"

extern void gdt_flush(addr_t);

struct gdt_entry gdtr[5];
struct gdt_ptr ptr;

void init_gdt(void)
{
  ptr.limit = (sizeof(struct gdt_entry) * 5) - 1;
  ptr.base = &gdtr;
  
  set_gdt_gate(0, 0, 0, 0, 0); /* Null segment */
  set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* Kernel segment */
  set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
  set_gdt_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
  set_gdt_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
  
  gdt_flush(&ptr);
}

void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
  gdtr[num].base_low = (base & 0xFFFF);
  gdtr[num].base_middle = (base >> 16) & 0xFF;
  gdtr[num].base_high = (base >> 24) & 0xFF;

  gdtr[num].limit = (limit & 0xFFFF);
  gdtr[num].flags = (limit >> 16) & 0x0F;
  gdtr[num].flags |= (gran & 0xF0);

  gdtr[num].access = access;
}

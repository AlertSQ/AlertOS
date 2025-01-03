#define video_address 0xb8000
#define width 80
#define height 25

#include <stdint.h>

uint16_t get_offset(uint16_t col, uint16_t row);
uint16_t get_offset_row(uint16_t offset);
uint16_t get_cursor_offset();
void set_cursor_offset(uint16_t offset);
void vga_putc(uint8_t ch, uint8_t attr);
void vga_print(char *s);

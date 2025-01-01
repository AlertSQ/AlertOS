include config.mk

build:
	mkdir $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/lib.o include/lib.c
	$(CC) $(CFLAGS) -o $(BUILD)/keyboard.o include/keyboard.c
	$(CC) $(CFLAGS) -o $(BUILD)/vga.o include/vga.c
	gcc $(CFLAGS) -o $(BUILD)/gdtc.o include/gdt.c
	$(CC) $(CFLAGS) -o $(BUILD)/kernel.o kernel.c
	$(AS) $(ASFLAGS) -o $(BUILD)/header.o header.s
	$(AS) $(ASFLAGS) -o $(BUILD)/gdt.o gdt.s
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(BUILD)/*.o 
	@echo kernel.elf: done
clean:
	rm -rf $(BUILD)

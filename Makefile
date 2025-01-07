# MakeFile </Build>

include config.mk

build: $(OBJS)
	gcc $(CFLAGS) -c -o gdtc.o $(KDIR)/gdt.c
	$(AS) $(ASFLAGS) -o gdt.o $(KDIR)/gdt.s
	$(AS) $(ASFLAGS) -o header.o header.s
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(OBJS) gdtc.o gdt.o
	@echo kernel.elf: done

$(IODIR)/%.o: $(IOSRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(KDIR)/%.o: $(KSRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm $(OBJS) *.o
	@echo clean: false

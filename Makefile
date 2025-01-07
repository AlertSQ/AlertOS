include config.mk

build: $(OBJS) 
	@echo objs are: $(OBJS)
	gcc $(CFLAGS) -c -o $(KDIR)/gdtc.o $(KDIR)/gdt.c
	$(AS) $(ASFLAGS) -o $(KDIR)/gdt.o $(KDIR)/gdt.s
	$(AS) $(ASFLAGS) -o header.o header.s
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(KDIR)/gdtc.o $(KDIR)/gdt.o header.o
	@echo kernel.elf: done
	
$(IODIR)/%.o: $(IOSRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(KDIR)/%.o: $(KSRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm $(OBJS) $(KDIR)/gdtc.o $(KDIR)/gdt.o header.o 
	@echo clean: done

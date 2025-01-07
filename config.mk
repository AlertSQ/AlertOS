# options
CC = clang
AS = nasm
LD = ld#.lld

# Paths
VERSION = 1.0
PREFIX = ./boot
KDIR = ./kernel
IODIR = ./io

#flags
CFLAGS = -g -m32 -std=c11 -fno-pie -Wall -Wextra -Wno-unused-parameter -nostdlib -ffreestanding 
LDFLAGS = -m elf_i386 -T link.ld 
ASFLAGS = -f elf32

#sources
HEADER = header.asm
OUTPUT = kernel.elf

KSRC := $(filter-out $(KDIR)/gdt.c, $(wildcard $(KDIR)/*.c))
KOBJS := $(patsubst $(KDIR)/%.c, $(KDIR)/%.o, $(KSRC))

IOSRC := $(wildcard $(IODIR)/*.c)
IOOBJS := $(patsubst $(IODIR)/%.c, $(IODIR)/%.o, $(IOSRC))

OBJS := $(KOBJS) $(IOOBJS) 

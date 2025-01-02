# options
CC = clang
AS = nasm
LD = ld#.lld

# Paths
VERSION = 1.0
PREFIX = ./boot
BUILD = build

#flags
CFLAGS = -g -c -m32 -std=c11 -fno-pie -Wall -Wextra -Wno-unused-parameter -O3 -nostdlib -ffreestanding -fno-stack-protector
LDFLAGS = -m elf_i386 -T link.ld 
ASFLAGS = -f elf32

#sources
HEADER = header.asm
OUTPUT = kernel.elf

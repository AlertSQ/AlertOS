bits	32
section .multiboot
align 4
	dd 0x1BADB002
	dd 0x0
	dd - ( 0x1BADB002 + 0x0 )

section	.text

extern	kmain

global	_start

_start:
	cli
	mov	esp,	stack
	call	kmain
	hlt

section	.bss
resb	8192
stack:

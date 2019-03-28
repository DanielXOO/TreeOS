bits 32
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum

global start
global keyboard_decoder
global read_port
global write_port
global load_idt

extern kdecoder
extern main
read_port:
  mov edx, [esp + 4]
  in al, dx   
  ret
write_port:
  mov   edx, [esp + 4]    
  mov   al, [esp + 4 + 4]  
  out   dx, al  
  ret
load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret
keyboard_decoder:
  call kdecoder
  iretd  
start:
  cli
  mov esp, stack_space
  call main
  hlt

section .bss
resb 8192
stack_space:

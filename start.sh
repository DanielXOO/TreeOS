nasm -f elf32 kernel.asm -o kasm.o
g++ -c kernel.cpp -o kernel.o -fno-stack-protector  -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ld -m elf_i386 -T  link.ld -o kernel kasm.o kc.o
qemu-system-i386 -kernel kernel

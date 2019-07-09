nasm -f elf32 kernel.asm -o kasm.o
g++ -ffreestanding -fno-stack-protector -m32 -c kernel.cpp -o kc.o
ld -m elf_i386 -T  link.ld -o kernel kasm.o kc.o
qemu-system-i386 -kernel kernel
rm -f kasm.o kc.o kernel 
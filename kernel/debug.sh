nasm -f elf32 kernel.asm -o kasm.o
g++ -ffreestanding -fno-stack-protector -m32 -c keybord/keybord.cpp -o kb.o 
g++ -ffreestanding -m32 -c main.cpp -o kc.o
g++ -ffreestanding -m32 -c terminal/terminal.cpp -o sc.o
ld -m elf_i386 -T  link.ld -o kernel-001 kasm.o kc.o kb.o sc.o
qemu-system-i386 -kernel kernel-001
rm -f kasm.o kc.o kb.o sc.o kernel-001

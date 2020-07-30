#include "keybord.hpp"
#include "k_array.hpp"
#include "../terminal/terminal.hpp"
IDT_entry IDT[256];
static char *vidptr = (char*)0xb8000; 

void idt_init()
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    keyboard_address = (unsigned long)keyboard_decoder;
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08; 
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e; 
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);

    write_port(0x21, 0x20);
    write_port(0xA1, 0x28);

    write_port(0x21, 0x00);
    write_port(0xA1, 0x00);

    write_port(0x21, 0x01);
    write_port(0xA1, 0x01);

    write_port(0x21, 0xff);
    write_port(0xA1, 0xff);

    idt_address = (unsigned long)IDT;
    idt_ptr[0] = (sizeof(struct IDT_entry) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16;

    load_idt(idt_ptr);
}

void kdecoder()
{
    unsigned char status;
    char code;
    write_port(0x20, 0x20);
    status = read_port(0x64);
    if (status & 0x01)
    {
        code = read_port(0x60);
        if (code < 0)
            return;
        outp(k_array[code]);
    }
}

void kb_init()
{
    write_port(0x21, 0xFD);
}

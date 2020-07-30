#pragma once 
#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define BACKSPACE 0x0E
#define ENTER 0x1C

extern "C"
{
    void keyboard_decoder();
    void kdecoder();
    char read_port(unsigned short port);
    void write_port(unsigned short port, unsigned char data);
    void load_idt(unsigned long *idt_ptr);
    void kb_init();
    void idt_init();
}

struct IDT_entry
{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

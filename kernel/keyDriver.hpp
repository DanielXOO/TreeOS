#include "k_array.hpp"
#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES
#define BACKSPACE 0x0E
#define ENTER 0x1C
extern unsigned char k_array[128];
extern "C"{
    void keyboard_decoder(void);
    char read_port(unsigned short port);
    void write_port(unsigned short port, unsigned char data);
    void load_idt(unsigned long *idt_ptr);
}
unsigned int current_loc = 0;
char *vidptr = (char*)0xb8000;
void BACK2SPACE(void){
    if (vidptr[current_loc - 2] != '>'){ // КОСТЫЛЬ
    vidptr[current_loc - 2] = ' ';
    current_loc = current_loc - 2;
    }
}
void enter(){
    current_loc = current_loc + ( (COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT) - current_loc %(COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT) );
}
struct IDT_entry{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};
struct IDT_entry IDT[256];

void idt_init(void)
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    keyboard_address = (unsigned long)keyboard_decoder; 
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    write_port(0x20 , 0x11);
    write_port(0xA0 , 0x11);

    write_port(0x21 , 0x20);
    write_port(0xA1 , 0x28);

    write_port(0x21 , 0x00);  
    write_port(0xA1 , 0x00);  

    write_port(0x21 , 0x01);
    write_port(0xA1 , 0x01);

    write_port(0x21 , 0xff);
    write_port(0xA1 , 0xff);

    idt_address = (unsigned long)IDT ;
    idt_ptr[0] = (sizeof (struct IDT_entry) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16 ;

    load_idt(idt_ptr);
}

void kb_init(void)
{
    write_port(0x21 , 0xFD);
} 

void combinations (char code){
    switch (code)
        {
        case BACKSPACE:
            BACK2SPACE();
            break;
        case ENTER:
            enter();
            break;
        default: 
            vidptr[current_loc++] = k_array[code];
            vidptr[current_loc++] = 0x04;
            break;
        }
}
extern "C" void kdecoder(void)
{
    unsigned char status;
    char code;
    write_port (0x20 , 0x20);
    status = read_port(0x64);
    if (status & 0x01) {
        code = read_port (0x60);
        if (code < 0) 
        return;
        combinations(code);
    }
    
}
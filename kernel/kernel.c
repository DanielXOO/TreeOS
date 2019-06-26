#include "keyDriver.h"
void clean(void) 
{
    unsigned int i = 0;
    while(i < COLUMNS_IN_LINE * LINES * BYTES_FOR_EACH_ELEMENT)
    {
    vidptr[i] = ' ';
    vidptr[i + 1] = 0x07;
    i = i + 2;
    }
}
void main(void)
{
    clean();
    idt_init();
    kb_init(); 
    while(true);
}

    




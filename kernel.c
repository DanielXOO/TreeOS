#include "I_Olib.h"
void main(void)
{
    char *str = "its better than windows ";
    proper();
    out(str);  
    idt_init();
    kb_init(); 
    while(true);
}

    




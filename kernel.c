#include "I_Olib.h"
void main(void)
{
    char *str = "TREE_OS v 0.0.0.1";
    proper();
    out(str);
    NEXTL(1);  
    idt_init();
    kb_init(); 
    while(true);
}

    




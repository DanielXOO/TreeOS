#include "terminal.hpp"
#include "../sys_vars.hpp"
unsigned int current_loc = 0;
static char *vidptr = (char*)0xb8000; 
void clean()
{
    unsigned int i = 0;
    while (i < COLUMNS_IN_LINE * LINES * BYTES_FOR_EACH_ELEMENT)
    {
        vidptr[i] = ' ';
        vidptr[i + 1] = 0x07;
        i = i + 2;
    }
}

bool kb_check()
{
    return true;
}

void outp(char *out)
{
    unsigned int j = 0;
    while (out[j] != '\0')
    {
        vidptr[current_loc] = out[j];
        vidptr[current_loc + 1] = 0x07;
        ++j;
        current_loc = current_loc + 2;
    }
}

void outp(unsigned char out)
{
    vidptr[current_loc] = out;
    vidptr[current_loc + 1] = 0x07;
    current_loc = current_loc + 2;
}
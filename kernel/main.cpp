#include "keybord/keybord.hpp"
#include "terminal/terminal.hpp"

void main()
{
    clean();
    const char *out = "my first";
    outp("my first");
    idt_init();
    kb_init();
    while (true)
        ;
}
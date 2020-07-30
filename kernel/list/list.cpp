#include "list.hpp"
#include "../terminal/terminal.hpp"
struct var
{
    char data;
    var *next;
};

void list::add(struct var **top, char D)
{
    var *el;
    el = new var(); //add support operator new or realize func malloc()
    el->data = D;
    if (top == nullptr)
    {
        *top = el;
    }
    else
    {
        el->next = *top;
        *top = el;
    }
}

void list::out(struct var *top)
{
    var *el = top;
    while (el)
    {
        outp (el->data);
        el = el->next;
    }
}


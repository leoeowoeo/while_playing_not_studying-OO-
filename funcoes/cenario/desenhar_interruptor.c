#include "oo.h"
void desenhar_interruptor(Cenario *objetos, int *interruptorON, int *interagirInt, int par, int cor)
{
    if (*interagirInt == 1 && cor == 1) 
    {
        wattron(stdscr, COLOR_PAIR(par) | A_BOLD);
    }

    if (*interruptorON == 1) 
    {
        mvprintw(objetos->interruptor.y+1, objetos->interruptor.x, "O");
    }
    else 
    {
        mvprintw(objetos->interruptor.y+1, objetos->interruptor.x, "0"); 
    }
    if (*interagirInt == 1 && cor == 1) 
    {
        wattroff(stdscr, COLOR_PAIR(par) | A_BOLD);
    }
}

#include "oo.h"
void desenhar_interruptor(int interruptorX, int interruptorY, int *interruptorON, int *interagirInt, int par, int cor)
{
    if (*interagirInt == 1 && cor == 1) 
    {
        wattron(stdscr, COLOR_PAIR(par) | A_BOLD);
    }

    if (*interruptorON == 1) 
    {
        mvprintw(interruptorY+1, interruptorX, "O");
    }
    else 
    {
        mvprintw(interruptorY+1, interruptorX, "0"); 
    }
    if (*interagirInt == 1 && cor == 1) 
    {
        wattroff(stdscr, COLOR_PAIR(par) | A_BOLD);
    }
}

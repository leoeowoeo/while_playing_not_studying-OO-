#include "oo.h"
void desenhanafrente(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par,int lixoY, int lixoX)
{
    int armarioY = 14 + Yall, armarioX = 19 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (armarioaberto == 1)
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));

    }
    else
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));

    }
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(6));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(15));
    mvprintw(lixoY+1, lixoX,  "|###|");
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(15));
}
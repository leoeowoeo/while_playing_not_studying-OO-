#include "oo.h"
void caicaixa(int Xall, int Yall, int cor, int interagirCaixa, int par, SAVE *save)
{
    int caixaY = 5 + Yall, caixaX = 34 + Xall;
if (interagirCaixa == 1 && cor == 1)
wattron(stdscr, COLOR_PAIR(par));
if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
    mvprintw(caixaY-4, caixaX+6+3,     "_____");
    mvprintw(caixaY-3, caixaX+6+2,    "/    /|");
    mvprintw(caixaY-2, caixaX+6+1,   "|\"\"\"\"| |");
    mvprintw(caixaY-1, caixaX+6+1,   "|____|/");
    
if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
wattroff(stdscr, COLOR_PAIR(par));
}

#include "oo.h"
void desenhar_lixo(Cenario *objetos, int cor)
{
    wattron(stdscr, A_ITALIC);
    int lixoY = objetos->lixo.y, lixoX = objetos->lixo.x;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(15));
    mvprintw(lixoY+1, lixoX,  "|###|");
    mvprintw(lixoY+2, lixoX, " \\#/");
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(15));
    wattroff(stdscr, A_ITALIC);
}
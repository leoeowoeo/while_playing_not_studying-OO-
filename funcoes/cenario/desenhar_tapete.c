#include "oo.h"
void desenhar_tapete(Cenario *objetos, int cor)
{
    int tapetey = objetos->tapete.y, tapetex = objetos->tapete.x;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(8));
    mvprintw(tapetey, tapetex,        ",~~~~~~~~~~~~~,");
    mvprintw(tapetey+1, tapetex-1,     "/    ~~~      /");
    mvprintw(tapetey+2, tapetex-2,    "/       ~~~~  /");
    mvprintw(tapetey+3, tapetex-3,   "/  ~~~        /");
    mvprintw(tapetey+4, tapetex-4,  "/      ~~~~   /");
    mvprintw(tapetey+5, tapetex-5, "'~~~~~~~~~~~~~'");
    wattroff(stdscr, COLOR_PAIR(8));
}
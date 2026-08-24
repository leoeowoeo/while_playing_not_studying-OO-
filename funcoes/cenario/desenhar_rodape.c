#include "oo.h"
void desenhar_rodape(int Xall, int Yall, int cor)
{
    int rodapey = 9 + Yall, rodapex = 41 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    mvprintw(rodapey+21, rodapex-41, "_______________________________________________________________________");
    for (rodapex=Xall+24; rodapex < 93 + Xall; rodapex++)
    {
        if(rodapex < 92 + Xall)
        mvprintw(rodapey, rodapex, "_");
        mvprintw(rodapey-11, rodapex-2, "_");
    }
    wattroff(stdscr, COLOR_PAIR(9));

    int rodape2y = 10 + Yall, rodape2x = 21 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    for (; rodape2y < 31 + Yall; rodape2y++,rodape2x--)
    {
        if (rodape2y < 31 + Yall)
        mvprintw(rodape2y, rodape2x, "/");
        mvprintw(rodape2y, rodape2x+70, "/");
        mvprintw(rodape2y-11, rodape2x-1, "/");
    }
    wattroff(stdscr, COLOR_PAIR(9));

    int quinay = 10 + Yall, quinax = 21 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    for (; quinay < 21 + Yall; quinay++)
    {

        mvprintw(quinay+10, quinax-21, "|");
        mvprintw(quinay-11, quinax+70, "|");
        mvprintw(quinay-11, quinax, "|");
    }
    wattroff(stdscr, COLOR_PAIR(9));
}
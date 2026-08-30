#include "oo.h"
void desenhar_cama(Cenario *objetos, int cor, int interagirCam, int par)
{
    int camaY = objetos->cama.y, camaX = objetos->cama.x;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(1));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(4));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY, camaX,          "._______.");
    mvprintw(camaY+1, camaX-1,     "/~~     /|");
    mvprintw(camaY+2, camaX-2,    "/       //");
    mvprintw(camaY+3, camaX-3,   "/    ~~ //");
    mvprintw(camaY+4, camaX-4,  "/_______//");
    mvprintw(camaY+5, camaX-5, "|_______|/");


    wattroff(stdscr, COLOR_PAIR(4));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY, camaX,   ".");
    mvprintw(camaY, camaX+8,   ".");
    mvprintw(camaY+1, camaX+8, "|");
    mvprintw(camaY+2, camaX+8, "|");
    mvprintw(camaY+6, camaX-5, "||     ||");
    wattroff(stdscr, COLOR_PAIR(6));
    wattron(stdscr, A_ITALIC);
    mvprintw(camaY+1, camaX+1, "(   )");
    wattroff(stdscr, A_ITALIC);
    wattroff(stdscr, COLOR_PAIR(12));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(7));


}
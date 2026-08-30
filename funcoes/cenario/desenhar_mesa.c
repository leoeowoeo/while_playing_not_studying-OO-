#include "oo.h"
void desenhar_mesa(Cenario *objetos, int cor)
{
    int mesaY = objetos->mesa.y, mesaX = objetos->mesa.x;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    
    mvprintw(mesaY, mesaX,      " _____");
    mvprintw(mesaY+1, mesaX,    "/    /");
    mvprintw(mesaY+2, mesaX-1, "/____/|");
    mvprintw(mesaY+3, mesaX-1, "|   | ");
    wattroff(stdscr, COLOR_PAIR(6));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
    mvaddch(mesaY+3, mesaX, ACS_LLCORNER);
    mvaddch(mesaY+3, mesaX+1, ACS_HLINE);
    mvaddch(mesaY+3, mesaX+2, ACS_LRCORNER);
    wattroff(stdscr, COLOR_PAIR(59));
}
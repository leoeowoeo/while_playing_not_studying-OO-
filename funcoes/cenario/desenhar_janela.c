#include "oo.h"
void desenhar_janela(Cenario *objetos, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check)
{
    (void)chuvax;
    (void)chuvay;
    int janelaY = objetos->janela.y, janelaX = objetos->janela.x;
    if (janelaaberta == 0)
    {
        
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX,   "|\\ _______ /| ");
        mvprintw(janelaY+1, janelaX,  "| |       | | ");
        mvprintw(janelaY+2, janelaX,  "| |       | | ");
        mvprintw(janelaY+3, janelaX, " \\|       |/  ");
        mvprintw(janelaY+4, janelaX, "  ---------   ");
        wattroff(stdscr, COLOR_PAIR(2));
        wattroff(stdscr, COLOR_PAIR(par));
        desenhar_chuva(objetos, cor, pos, pos2, pos3, check);
    }
    else
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX,   "   _______    ");
        mvprintw(janelaY+1, janelaX, "  |   |   |   ");
        mvprintw(janelaY+2, janelaX, "  |   |   |   ");
        mvprintw(janelaY+3, janelaX, "  |   |   |   ");
        mvprintw(janelaY+4, janelaX, "  ---------");
        wattroff(stdscr, COLOR_PAIR(par));
        wattroff(stdscr, COLOR_PAIR(2));
    }
}
#include "oo.h"
void desenhar_celular_mesa(int Xall, int Yall,SAVE *save, int celularX, int celularY, int interagirCel, int par)
{
    if (save->celularpickup == 0)
    {
        if (save->depoisprova == 0)
        {wattron(stdscr, A_ITALIC);
            if (interagirCel == 1 && save->cor == 1) wattron(stdscr, COLOR_PAIR(par));
            if (save->celularpos == 1) mvprintw(celularY, celularX-2, "[]");
            else if (save->celularpos == 2) mvprintw(celularY+1, celularX-2, "[]");
            else if (save->celularpos == 3) mvprintw(celularY+1, celularX-2-1, "[]");
            wattroff(stdscr, COLOR_PAIR(par));
        wattron(stdscr, A_ITALIC);
        }
    }
}
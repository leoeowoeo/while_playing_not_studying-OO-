#include "oo.h"
void desenhar_celular_mesa(Cenario *objetos, SAVE *save, int interagirCel, int par)
{
    if (save->celularpickup == 0)
    {
        if (save->depoisprova == 0)
        {wattron(stdscr, A_ITALIC);
            if (interagirCel == 1 && save->cor == 1) wattron(stdscr, COLOR_PAIR(par));
            if (save->celularpos == 1) mvprintw(objetos->celular.y, objetos->celular.x-2, "[]");
            else if (save->celularpos == 2) mvprintw(objetos->celular.y+1, objetos->celular.x-2, "[]");
            else if (save->celularpos == 3) mvprintw(objetos->celular.y+1, objetos->celular.x-3, "[]");
            wattroff(stdscr, COLOR_PAIR(par));
        wattron(stdscr, A_ITALIC);
        }
    }
}
#include "oo.h"
void desenhar_gato(Cenario *objetos, int vontadedepisca, int depoisprova)
{
    int gatoy = objetos->gato.y, gatox = objetos->gato.x;
    if (depoisprova == 0)
    {wattron(stdscr, A_ITALIC);
        mvprintw(gatoy, gatox, "(\\   /)");
        mvprintw(gatoy+1, gatox, "(=*.*=)");
        mvprintw(gatoy+2, gatox, " (\") (\")_/");
        if (vontadedepisca >= 300 && vontadedepisca <= 390)
        {
            static int meow = 0;
            meow++;
            if (meow >= 3 && meow <= 4) { mvprintw(gatoy-1, gatox+3, "MEOW"); meow = 0; }
        }
        wattron(stdscr, A_ITALIC);
    }
}
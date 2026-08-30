#include "oo.h"
void desenhar_estante(Cenario *objetos, int cor, int interagirEst, int par, SAVE *save)
{ 
    int estanteY = objetos->estante.y, estanteX = objetos->estante.x;
    if (interagirEst == 1 && cor == 1)
    wattron(stdscr, COLOR_PAIR(par));
    if (cor == 1)  wattron(stdscr, COLOR_PAIR(7));
    mvprintw(estanteY-2, estanteX+2,   "_____________.");
    mvprintw(estanteY-1, estanteX+1,  "/            /|");
    mvprintw(estanteY, estanteX,     "/____________/ |");
    mvprintw(estanteY+1, estanteX,   "|_[]_!!__||[]| |");
    mvprintw(estanteY+2, estanteX,   "|!!_[]_!!_!!_| |");
    mvprintw(estanteY+3, estanteX,   "|!!_!!__||[]_| |");
    mvprintw(estanteY+4, estanteX,   "|__!!_!!___!!| |");
    mvprintw(estanteY+5, estanteX,   "|_||!![]_!![]| /");
    mvprintw(estanteY+6, estanteX,   "|_!!_!!_[]_|||/");
    wattroff(stdscr, COLOR_PAIR(7));
    wattroff(stdscr, COLOR_PAIR(par));
    gravar_imagem_do_momento(save->x, save->y, save->imagem);
    printar_imagem_do_momento(objetos->celular.x+18, objetos->celular.y, save->imagem);
}
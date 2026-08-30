#include "oo.h"

void desenhar_caixa(Cenario *objetos, int cor, int interagirCaixa, int par, SAVE *save)
{
    int caixaY = objetos->caixa.y, caixaX = objetos->caixa.x;

    if (save->caixacaindo == 0)
    {
        if (interagirCaixa == 1 && cor == 1)
            wattron(stdscr, COLOR_PAIR(par));
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 1 ( padrão antes de interagir)
        mvprintw(caixaY-4, caixaX+6+3,  "_____");
        mvprintw(caixaY-3, caixaX+6+2, "/    /|");
        mvprintw(caixaY-2, caixaX+6+1,"|\"\"\"\"| |");
        mvprintw(caixaY-1, caixaX+6+1,"|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
        wattroff(stdscr, COLOR_PAIR(par));
    }
    else if (save->caixacaindo > 0 && save->caixacaindo < 100)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 2 (inicio da animação)
        mvprintw(caixaY+1-4, caixaX+5+3,  "_____");
        mvprintw(caixaY+1-3, caixaX+5+2, "/    /|");
        mvprintw(caixaY+1-2, caixaX+5+1,"|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+5+1,"|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }
    else if (save->caixacaindo >= 100 && save->caixacaindo < 200)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 3
        mvprintw(caixaY+2-4, caixaX+4+3,  "_____");
        mvprintw(caixaY+2-3, caixaX+4+2, "/    /|");
        mvprintw(caixaY+2-2, caixaX+4+1,"|\"\"\"\"| |");
        mvprintw(caixaY+2-1, caixaX+4+1,"|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }
    else if (save->caixacaindo >= 200 && save->caixacaindo < 300)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 4
        mvprintw(caixaY+1-4, caixaX+3+3,  "_____");
        mvprintw(caixaY+1-3, caixaX+3+2, "/    /|");
        mvprintw(caixaY+1-2, caixaX+3+1,"|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+3+1,"|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }
    else if (save->caixacaindo >= 300 && save->caixacaindo < 400)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 5
        mvprintw(caixaY+1-4, caixaX+2+3,  "_____");
        mvprintw(caixaY+1-3, caixaX+2+2, "/    /|");
        mvprintw(caixaY+1-2, caixaX+2+1,"|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+2+1,"|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }

    if (save->caixacaindo > 0 && save->caixacaindo < 100)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 6
        mvwprintw(stdscr, caixaY+2 - 4, caixaX + 2, " ,-\"'\\");
        mvwprintw(stdscr, caixaY+2 - 3, caixaX + 2, "|    |\\");
        mvwprintw(stdscr, caixaY+2 - 2, caixaX + 2, "|,-\"'\\|");
        mvwprintw(stdscr, caixaY+2 - 1, caixaX + 2, "\\    '\\");
        mvwprintw(stdscr, caixaY+2,     caixaX + 2, " \\,-\"\"");
    }
    else if (save->caixacaindo >= 100 && save->caixacaindo < 200)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 7
        mvwprintw(stdscr, caixaY+3 - 4, caixaX + 2, "  /\\\"'>,");
        mvwprintw(stdscr, caixaY+3 - 3, caixaX + 2, " / |_  |");
        mvwprintw(stdscr, caixaY+3 - 2, caixaX + 2, "| /  '>|");
        mvwprintw(stdscr, caixaY+3 - 1, caixaX + 2, "|/     ;");
        mvwprintw(stdscr, caixaY+3,     caixaX + 2, " '*,  /");
        mvwprintw(stdscr, caixaY+3 + 1, caixaX + 2, "    \"/");
    }
    else if (save->caixacaindo >= 200 && save->caixacaindo < 300)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 8
        mvwprintw(stdscr, caixaY+4 - 4, caixaX + 2, "  /;--,__  ");
        mvwprintw(stdscr, caixaY+4 - 3, caixaX + 2, " / |    |");
        mvwprintw(stdscr, caixaY+4 - 2, caixaX + 2, "| /'--,_|");
        mvwprintw(stdscr, caixaY+4 - 1, caixaX + 2, "|/      /");
        mvwprintw(stdscr, caixaY+4,     caixaX + 2, " '--,__/");
    }
    else if (save->caixacaindo >= 300 && save->caixacaindo < 400)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame 9
        mvwprintw(stdscr, caixaY+5 - 4, caixaX + 2,   ";--,__ ");
        mvwprintw(stdscr, caixaY+5 - 3, caixaX + 2,  "/     /|");
        mvwprintw(stdscr, caixaY+5 - 2, caixaX + 2, "/'--,_/ |");
        mvwprintw(stdscr, caixaY+5 - 1, caixaX + 2, "|     | /");
        mvwprintw(stdscr, caixaY+5,     caixaX + 2, "'-,,__|/");
    }
    else if (save->caixacaindo >= 400 && save->caixacaindo < 500)
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        // frame  ( funal da animação e padrão após a interação)
        mvwprintw(stdscr, +6 - 4, caixaX + 2,       "/\"\"\"\"\"/|");
        mvwprintw(stdscr, +6 - 3, caixaX + 2,     "_;_____; |");
        mvwprintw(stdscr, +6 - 2, caixaX + 2, "-* / |     | /");
        mvwprintw(stdscr, +6 - 1, caixaX + 2,   "/__|_____|/");
    }
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
}
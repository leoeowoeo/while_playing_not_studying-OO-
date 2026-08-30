#include "oo.h"
void desenhanafrente(Cenario *objetos, int cor, int armarioaberto, int interagirArm, int par)
{
    int Xall = objetos->armario.x - 19;
    int Yall = objetos->armario.y - 14;
    int lixoY = objetos->lixo.y, lixoX = objetos->lixo.x;
    int armarioY = objetos->armario.y - 2, armarioX = objetos->armario.x - 13;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (armarioaberto == 1)
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        armarioY = 11+Yall;
        mvprintw(armarioY+1, armarioX+2+11,      ",-'|");
        mvprintw(armarioY+2, armarioX+2+4,      "/\"\"\"\"/|   |");
        mvprintw(armarioY+3, armarioX+2+3,     "/    / |   |");
        mvprintw(armarioY+4, armarioX+2+2,    "/    /  |   |");
        mvprintw(armarioY+5, armarioX+2+1,   "/    /   |   |");
        mvprintw(armarioY+6, armarioX+2,    "|\"\"\"\"|   /|   |");
        mvprintw(armarioY+7, armarioX+2,   "|    |'-',|   |");
        mvprintw(armarioY+8, armarioX+2,   "|    |   \";,-'\"");
        mvprintw(armarioY+9, armarioX+2,   "|    |    |");
        mvprintw(armarioY+10, armarioX+2,  "|    |   (| ");


        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(armarioY+6, armarioX+11,    "/");
        mvprintw(armarioY+7, armarioX+10,   "'");

        mvprintw(armarioY+2+2, armarioX+5+2+4,      "/");
        mvprintw(armarioY+2+3, armarioX+5+2+3,     "/");
        mvprintw(armarioY+2+4, armarioX+5+2+2,    "/");

        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }
    else
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
                    if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        armarioY = 12+Yall;
        mvprintw(armarioY+1, armarioX+3+3, "/\"\"\"\"/|");
        mvprintw(armarioY+2, armarioX+3+2, "/    / |");
        mvprintw(armarioY+3, armarioX+3+1, "/    /| |");
        mvprintw(armarioY+4, armarioX+3, "/    / | |");
        mvprintw(armarioY+5, armarioX+2, "|\"\"\"\"|  | |");
        mvprintw(armarioY+6, armarioX+2, "|    |  |)|");
        mvprintw(armarioY+7, armarioX+2, "|    | )| |");
        mvprintw(armarioY+8, armarioX+2, "|    |");
        mvprintw(armarioY+9, armarioX+2, "|    |");

    }
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(6));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(15));
    mvprintw(lixoY+1, lixoX,  "|###|");
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(15));
}
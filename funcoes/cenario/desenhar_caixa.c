#include "oo.h"
void desenhar_caixa(int Xall, int Yall, int cor, int interagirCaixa, int par, SAVE *save, int caixacaindo)
{
    int caixaY = 5 + Yall, caixaX = 34 + Xall;
    if(caixacaindo==0)
    {
if (interagirCaixa == 1 && cor == 1)
wattron(stdscr, COLOR_PAIR(par));
if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
    mvprintw(caixaY-4, caixaX+6+3,     "_____");
    mvprintw(caixaY-3, caixaX+6+2,    "/    /|");
    mvprintw(caixaY-2, caixaX+6+1,   "|\"\"\"\"| |");
    mvprintw(caixaY-1, caixaX+6+1,   "|____|/");
if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
wattroff(stdscr, COLOR_PAIR(par));
    }
    else if ( caixacaindo<0&&caixacaindo>=100)
    {
        wattron(stdscr, COLOR_PAIR(par));
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(caixaY+1-4, caixaX+5+3,     "_____");
        mvprintw(caixaY+1-3, caixaX+5+2,    "/    /|");
        mvprintw(caixaY+1-2, caixaX+5+1,   "|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+5+1,   "|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
        wattroff(stdscr, COLOR_PAIR(par));
    }
        else if ( caixacaindo<0&&caixacaindo>=200)
    {
        wattron(stdscr, COLOR_PAIR(par));
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(caixaY+2-4, caixaX+4+3,     "_____");
        mvprintw(caixaY+2-3, caixaX+4+2,    "/    /|");
        mvprintw(caixaY+2-2, caixaX+4+1,   "|\"\"\"\"| |");
        mvprintw(caixaY+2-1, caixaX+4+1,   "|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
        wattroff(stdscr, COLOR_PAIR(par));
    }
        else if ( caixacaindo<0&&caixacaindo>=300)
    {
        wattron(stdscr, COLOR_PAIR(par));
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(caixaY+1-4, caixaX+5+3,     "_____");
        mvprintw(caixaY+1-3, caixaX+5+2,    "/    /|");
        mvprintw(caixaY+1-2, caixaX+5+1,   "|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+5+1,   "|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
        wattroff(stdscr, COLOR_PAIR(par));
    }
        else if ( caixacaindo<0&&caixacaindo>=50)
    {
        wattron(stdscr, COLOR_PAIR(par));
        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(caixaY+1-4, caixaX+5+3,     "_____");
        mvprintw(caixaY+1-3, caixaX+5+2,    "/    /|");
        mvprintw(caixaY+1-2, caixaX+5+1,   "|\"\"\"\"| |");
        mvprintw(caixaY+1-1, caixaX+5+1,   "|____|/");
        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
        wattroff(stdscr, COLOR_PAIR(par));
    }
    /*
        if (caixacaindo < 100)
    {
        mvwprintw(stdscr, caixaY - 4, caixaX + 6, "     ,-\"'\\");
        mvwprintw(stdscr, caixaY - 3, caixaX + 6, "    |    |\\");
        mvwprintw(stdscr, caixaY - 2, caixaX + 6, "    |,-\"'\\|");
        mvwprintw(stdscr, caixaY - 1, caixaX + 6, "    \\    '\\");
        mvwprintw(stdscr, caixaY,     caixaX + 6, "     \\,-\"\"");
    }
    else if (caixacaindo < 200)
    {
        mvwprintw(stdscr, caixaY - 4, caixaX + 5, "        /\\\"'>,");
        mvwprintw(stdscr, caixaY - 3, caixaX + 5, "       / |_  |");
        mvwprintw(stdscr, caixaY - 2, caixaX + 5, "      | /  '>|");
        mvwprintw(stdscr, caixaY - 1, caixaX + 5, "      |/     ;");
        mvwprintw(stdscr, caixaY,     caixaX + 5, "       '*,  /");
        mvwprintw(stdscr, caixaY + 1, caixaX + 5, "          \"/");
    }
    else if (caixacaindo < 300)
    {
        mvwprintw(stdscr, caixaY - 4, caixaX + 4, "          /;--,__  ");
        mvwprintw(stdscr, caixaY - 3, caixaX + 4, "         / |    |");
        mvwprintw(stdscr, caixaY - 2, caixaX + 4, "        | /'--,_|");
        mvwprintw(stdscr, caixaY - 1, caixaX + 4, "        |/      /");
        mvwprintw(stdscr, caixaY,     caixaX + 4, "         '--,__/ ");
    }
}
/*
  _____
 /    /|
|""""| |
|____|/

     ,-"'\
    |    |\
    |,-"'\| 
    \    '\
     \,-""
        
          
        /\"'>,
       / |_  |
      | /  '>|
      |/     ;
       '*,  /
          "/

          /;--,__  
         / |    |
        | /'--,_|
        |/      /
         '--,__/


         
























*/
    /*
    
    mvprintw(estanteY-2, estanteX+2,   "_____________.");
    mvprintw(estanteY-1, estanteX+1,  "/            /|");
    mvprintw(estanteY, estanteX,     "/____________/ |");
    mvprintw(estanteY+1, estanteX,   "|_[]_!!__||[]| |");
    mvprintw(estanteY+2, estanteX,   "|!!_[]_!!_!!_| |");
    mvprintw(estanteY+3, estanteX,   "|!!_!!__||[]_| |");
    mvprintw(estanteY+4, estanteX,   "|__!!_!!___!!| |");
    mvprintw(estanteY+5, estanteX,   "|_||!![]_!![]| /");
    mvprintw(estanteY+6, estanteX,   "|_!!_!!_[]_|||/");
    
    */
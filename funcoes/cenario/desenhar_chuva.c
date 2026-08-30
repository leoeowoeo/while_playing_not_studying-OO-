#include "oo.h"
void desenhar_chuva(Cenario *objetos, int cor, int *pos, int *pos2, int *pos3,int check)
{
        int chuvax = objetos->chuva.x;
        int chuvay = objetos->chuva.y;
        if (cor == 1) wattron(stdscr, COLOR_PAIR(5));
        mvprintw(chuvay+*pos, chuvax, ",;';,,;");
        mvprintw(chuvay+*pos2, chuvax, " ';.;.'");
        mvprintw(chuvay+*pos3, chuvax, ".,.,'' ");
        wattroff(stdscr, COLOR_PAIR(5));
     if(check%5==0)  
            {(*pos)++; (*pos2)++; (*pos3)++;}
        if((*pos)>2) {*pos=0;} 
        if((*pos2)>2){*pos2=0;} 
        if((*pos3)>2){*pos3=0;}
            
}
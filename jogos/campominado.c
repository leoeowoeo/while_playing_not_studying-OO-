#include "jogos.h"
int campominado()
{
    WINDOW *campominado = newwin(31, 91, 3, 15);

    


    chtype matriz[32][92];
    #define COR_CIANO          1
    #define COR_CINZAESCURO    2
    #define COR_VERDEFOLHA     3
    #define COR_VERDECOBRA    10
    #define COR_CINZACLARO    40
    
    init_color(COR_CINZAESCURO, 900, 900, 900);
    init_color(COR_CINZACLARO, 950, 950, 950);
    
    int i,j,tecla,c=0;
    flushinp();
    while(tecla!='p')
    {               
        
        werase(campominado);
        
        tecla=getch();
        
    
    wrefresh(campominado);
    wrefresh(campominado);

        for(i=1;i<91;i+=3,c++)
            for(j=1;j<37;j++,c++)
            {   
                if((c)%2==1)
                wattron(campominado,COLOR_PAIR(COR_CINZAESCURO));
                else
                {
                wattron(campominado,COLOR_PAIR(COR_CINZACLARO));
                mvwprintw(campominado,j,i,"   ");
                wattroff(campominado,COLOR_PAIR(COR_CINZAESCURO));
                wattroff(campominado,COLOR_PAIR(COR_CINZACLARO));
                }
            }
        box(campominado, 0, 0);
        wrefresh(campominado);
            napms(60);
        }
    }
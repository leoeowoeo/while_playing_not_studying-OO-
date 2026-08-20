#include "jogos.h"

#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO     21

#define PAR_CINZAESCURO    26
#define PAR_CINZACLARO     27
#define PAR_VERMELHO       42

int campominado()
{
    WINDOW *campominado = newwin(31, 92, 3, 15);
    
    keypad(campominado, TRUE); 
    nodelay(campominado, TRUE);

    int matriz[29][30] = {0};

    int selecaoX = 0; 
    int selecaoY = 0;
    int tecla = 0;
    
    int timer = 0;
    int velocidade = 0;

    flushinp();

    while (tecla != 'p')
    {
        tecla = wgetch(campominado);
        werase(campominado);

        for (int j = 1; j < 30; j++)
        {
            for (int i = 1; i < 90; i += 3)
            {
                // Converte a posição física da tela (i, j) para a posição lógica da matriz
                int atualX = i / 3;
                int atualY = j - 1;

                // Lógica de cores alternadas (xadrez)
                int par_de_cores;
                if ((atualX + atualY) % 2 == 0) {
                    par_de_cores = PAR_CINZAESCURO;
                } else {
                    par_de_cores = PAR_CINZACLARO;
                }

                // Verifica se o cursor do jogador está nesta célula
                if (atualX == selecaoX && atualY == selecaoY)
                {
                    wattron(campominado, COLOR_PAIR(par_de_cores) | A_REVERSE); 
                    mvwprintw(campominado, j, i, "   "); 
                    wattroff(campominado, COLOR_PAIR(par_de_cores) | A_REVERSE);
                }
                else
                {
                    wattron(campominado, COLOR_PAIR(par_de_cores));
                    mvwprintw(campominado, j, i, "   ");
                    wattroff(campominado, COLOR_PAIR(par_de_cores));
                }
            }
        }

        // Impressão do Timer
        wattron(campominado, COLOR_PAIR(PAR_VERMELHO));
        mvwprintw(campominado, 0, 2, " Timer: %d ", timer); 
        wattroff(campominado, COLOR_PAIR(PAR_VERMELHO));
        
        velocidade++;
        if (velocidade % 33 == 0) {
            timer++;
        }

        box(campominado, 0, 0);
        wrefresh(campominado);

        // Movimentação
        switch (tecla)
        {
            case KEY_LEFT:
            case 'a':
                selecaoX--;
                if (selecaoX < 0) selecaoX = 30 - 1;
                break;

            case KEY_RIGHT:
            case 'd':
                selecaoX++;
                if (selecaoX >= 30) selecaoX = 0;
                break;

            case KEY_UP:
            case 'w':
                selecaoY--;
                if (selecaoY < 0) selecaoY = 29 - 1;
                break;

            case KEY_DOWN:
            case 's':
                selecaoY++;
                if (selecaoY >= 29) selecaoY = 0;
                break;

            case '\n':
            case ' ':
                matriz[selecaoY][selecaoX] = 1; 
                break;
        }

        napms(30);
    }

    delwin(campominado);
    return 0;
}

/*#include "jogos.h"

#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO     21

#define PAR_CINZAESCURO    26
#define PAR_CINZACLARO     27
#define COR_VERMELHO       42

int campominado()
{
    WINDOW *campominado = newwin(30, 92, 3, 15);

    init_color(COR_CINZAESCURO, 700, 700, 700);
    init_color(COR_CINZACLARO, 800, 800, 800);
    init_color(COR_VERMELHO,1000,0,0);
    
    int i, j, tecla = 0,timer=0,velocidade=0;
    flushinp();

    while (tecla != 'p')
    {               
        werase(campominado);

        for (j = 1; j < 30; j++)
        {
            for (i = 1; i < 90; i += 3)
            {   
                int par = ((i / 3 + j) % 2 == 0) ? PAR_CINZAESCURO : PAR_CINZACLARO;

                wattron(campominado, COLOR_PAIR(par));
                mvwprintw(campominado, j, i, "   "); 
                wattroff(campominado, COLOR_PAIR(par));
            }
        }
        watrron(campominado,COLOR_PAIR(COR_VERMELHO));
        mvprintw(0,0,"%d",timer);
        watrroff(campominado,COLOR_PAIR(COR_VERMELHO));
        velocidade++;
        if(velocidade%18==0){
            timer++;
        }
        box(campominado, 0, 0);
        wrefresh(campominado);
        
        tecla = getch();
        napms(60);
    }
    return 0;
}*/
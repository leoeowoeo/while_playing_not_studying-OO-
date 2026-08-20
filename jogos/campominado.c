#include "oo.h"
#include <stdlib.h>
#include <time.h>

#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO     21

#define PAR_CINZAESCURO    26
#define PAR_CINZACLARO     27
#define PAR_VERMELHO       42

typedef struct A_{
    int bomba;
    int pertobomba;
    char sprite;
}campo;

void geracampo(campo campo[30][30]){
    int i,j;
    int bomba=20;//diff facil
    int bomba2=30;//diff medio
    int bomba3=90;//diff dificil
    while(bomba!=0)
    {
        i=rand() % 30;
        j=rand() % 30;
        if(campo[i][j].bomba==0)
        {
            campo[i][j].bomba=1;
           
            if(i-1>=0)
                campo[i-1][j].pertobomba++;
            if(i+1<=29)
                campo[i+1][j].pertobomba++;
            if(j-1>=0)
                campo[i][j-1].pertobomba++;
            if(j+1<=29)
                campo[i][j+1].pertobomba++;
            
            if(i+1<=29&&j+1<=29)
                campo[i+1][j+1].pertobomba++;
            if(i-1>=0&&j+1<=29)
                campo[i-1][j+1].pertobomba++;
            if(i+1<=29&&j-1>=0)
                campo[i+1][j-1].pertobomba++;
            if(i-1>=0&&j-1>=0)
                campo[i-1][j-1].pertobomba++;
        }
        else
            bomba++;
        bomba--;
    }
}
int campominado()
{
    srand(time(NULL));
    WINDOW *campominado = newwin(17, 49, 6, 30);
    

    //31, 92, 3, 15

    keypad(campominado, TRUE); 
    nodelay(campominado, TRUE);

    int matriz[15][16] = {0};
    // int matriz[29][30] = {0};
    campo campo[30][30];
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            campo[i][j].bomba=0;
            campo[i][j].pertobomba=0;
        }
    }
    geracampo(campo);
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


        /*for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                if(campo[i][j].bomba==1)

                mvwprintw(campominado,j,i,"%d",campo[i][j].bomba);
            }
        }*/
        for (int j = 1; j < 16; j++)
        {
            for (int i = 1; i < 49; i += 3)
            {// o i ta vezes 3 pra ficar proximo de um quadrado, mas não pode ser 2 pq os numeros não
                int atualX = i / 3;// vao ficar centralizados.
                int atualY = j - 1;// ta nesse modelo de i/3 pra isso, já que a movimentação não vai contar  
                                   // com os espaços, já que eu to fazendo uma matriz 30/30 mas a linha tem "3X" mais do que a coluna so pelo front, mas no fundo ele tem que ser 30x30 msm
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
                    if(campo[j-1][i/3].bomba==1){
                    mvwprintw(campominado,j,i," @ ");
                    if(campo[j-1][i/3].pertobomba > 0 && campo[j-1][i/3].bomba != 1){
                        mvwprintw(campominado, j, i, " %d ", campo[j-1][i/3].pertobomba);
                    }

                }
                }
            }
        }
        
        box(campominado, 0, 0);
        wrefresh(campominado);

        wattron(campominado,COLOR_PAIR(PAR_VERMELHO));
        mvwprintw(campominado,0,0,"timer:%d",timer);
        wattroff(campominado,COLOR_PAIR(PAR_VERMELHO));

        // Movimentação
        switch (tecla)
        {
            case KEY_LEFT:
            case 'a':
                selecaoX--;
                if (selecaoX < 0) selecaoX = 16 - 1;
                break;

            case KEY_RIGHT:
            case 'd':
                selecaoX++;
                if (selecaoX >= 16) selecaoX = 0;
                break;

            case KEY_UP:
            case 'w':
                selecaoY--;
                if (selecaoY < 0) selecaoY = 15 - 1;
                break;

            case KEY_DOWN:
            case 's':
                selecaoY++;
                if (selecaoY >= 16) selecaoY = 0;
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

/*#include "oo.h"

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
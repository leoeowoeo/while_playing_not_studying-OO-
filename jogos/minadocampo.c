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
    int revelado;
    char sprite;
} campo;
void geracampo(int altura, int largura, campo matriz[altura][largura], int num_bombas);
void inundamatriz(int altura, int largura, campo matriz[altura][largura], int x, int y);
int campominado()
// LEEEO ANTES DE QUALQUER COISA LE ISSO
/*Vamo add 2 coisas pra fazer o jogo na 30 por 30 não ficar estupdamente tedioso:
Peso nas bombas, vão ter bombas de niveis diferentes, e elas somam mais numeros, bomba nivel 1 soma 1, bomba nivel 2 soma 2, bomba nivel 3 soma 3, etc etc
em cima vai estar escrito quanto de cada tem, e vai poder marcar os lugares com cores diferentes pra avisar cada uma.

A segunda coisa, avisar quantas bombas tem em cada linha e em cada coluna.
na borda da linha e da coluna vai ter o numero de bombas que la tem, pra agilisar o processo de jogar o jogo.*/
{
    srand(time(NULL));    
    int i,j;
    int altura = 30;
    int largura = 30;
    int num_bombas = 100; // Ajustei para 100 pois um campo 30x30 (900 casas) com 20 bombas seria muito fácil
    
    // Calcula o tamanho da janela da ncurses dinamicamente
    // Altura = (altura do jogo) + 2 (para as bordas)
    // Largura = (largura do jogo * 3 espaços) + 2 (para as bordas)
    WINDOW *campominado = newwin(altura + 2, (largura * 3) + 2, 2, 5);
    
    keypad(campominado, TRUE); 
    nodelay(campominado, TRUE);

    // Declaração dinâmica da matriz (VLA)
    campo matriz[altura][largura];
    
    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura; j++)
        {
            matriz[i][j].bomba = 0; // pode ser 1 ou 0, mas futuramente pode ter valor atpe 3
            matriz[i][j].pertobomba = 0;// de 0 a 8, mas pode aumentar com os pesos das bombas quando tivermos
            matriz[i][j].revelado = 0;// 1 ou 0.
        }
    }
    
    geracampo(altura, largura, matriz, num_bombas);
    
    int selecaoX = 0; 
    int selecaoY = 0;
    int tecla = 0;

    flushinp();

    while (tecla != 'p')
    {
        tecla = wgetch(campominado);
        werase(campominado);
        for (int j = 1; j < altura + 1; j++)
        {

            for (int i = 1; i < (largura * 3) + 1; i += 3)
            {
                int posX = i / 3;
                int posY = j - 1;
                
                int par_de_cores;
                if ((posX + posY) % 2 == 0) {
                    par_de_cores = PAR_CINZAESCURO;
                } else {
                    par_de_cores = PAR_CINZACLARO;
                }

                if (posX == selecaoX && posY == selecaoY)
                {
                    wattron(campominado, COLOR_PAIR(par_de_cores) | A_REVERSE); 
                }
                else
                {
                    wattron(campominado, COLOR_PAIR(par_de_cores));
                }

                if (matriz[posY][posX].revelado == 0) {
                    mvwprintw(campominado, j, i, "   ");
                } else {
                    if (matriz[posY][posX].bomba == 1) {
                        mvwprintw(campominado, j, i, " @ ");
                    } else if (matriz[posY][posX].pertobomba > 0) {
                        mvwprintw(campominado, j, i, " %d ", matriz[posY][posX].pertobomba);
                    } else {
                        mvwprintw(campominado, j, i, " . ");
                    }
                }

                if (posX == selecaoX && posY == selecaoY)
                {
                    wattroff(campominado, COLOR_PAIR(par_de_cores) | A_REVERSE);    
                }
                else
                {
                    wattroff(campominado, COLOR_PAIR(par_de_cores));
                }
            }
        }
        
        box(campominado, 0, 0);
        wrefresh(campominado);

        switch (tecla)
        {
            case KEY_LEFT:
            case 'a':
                selecaoX--;
                if (selecaoX < 0) selecaoX = largura - 1;
                break;

            case KEY_RIGHT:
            case 'd':
                selecaoX++;
                if (selecaoX >= largura) selecaoX = 0;
                break;

            case KEY_UP:
            case 'w':
                selecaoY--;
                if (selecaoY < 0) selecaoY = altura - 1;
                break;

            case KEY_DOWN:
            case 's':
                selecaoY++;
                if (selecaoY >= altura) selecaoY = 0;
                break;

            case '\n': inundamatriz(altura, largura, matriz,selecaoY,selecaoX);
                break;
            case ' ':
                matriz[selecaoY][selecaoX].revelado = 1; 
                break;
        }

        napms(30);
    }

    delwin(campominado);
    return 0;
}

void geracampo(int altura, int largura, campo matriz[altura][largura], int num_bombas){
    int i, j;
    int bombaplaced = 0;

    while (bombaplaced < num_bombas) {
        i = rand() % altura;
        j = rand() % largura;

        if (matriz[i][j].bomba == 0) {
            matriz[i][j].bomba = 1;
            bombaplaced++;
            
            if(i-1 >= 0) matriz[i-1][j].pertobomba++;
            if(i+1 < altura) matriz[i+1][j].pertobomba++;
            if(j-1 >= 0) matriz[i][j-1].pertobomba++;
            if(j+1 < largura) matriz[i][j+1].pertobomba++;
            
            if(i+1 < altura && j+1 < largura) matriz[i+1][j+1].pertobomba++;
            if(i-1 >= 0 && j+1 < largura) matriz[i-1][j+1].pertobomba++;
            if(i+1 < altura && j-1 >= 0) matriz[i+1][j-1].pertobomba++;
            if(i-1 >= 0 && j-1 >= 0) matriz[i-1][j-1].pertobomba++;
        }
    }
}

void inundamatriz(int altura, int largura, campo matriz[altura][largura], int y, int x) {
    if (x < 0 || x >= altura || y < 0 || y >= largura) {
        return;
    }
    
    

    if (matriz[x][y].pertobomba >= 1&& matriz[x][y].revelado==0&&matriz[x][y].bomba==0) { // se for algo perto da bomba para
        return;
    }

    matriz[x][y].revelado = 1; // revela o quadrado que ela chegou independente
    
    inundamatriz(altura, largura, matriz, x - 1, y);
    inundamatriz(altura, largura, matriz, x + 1, y);
    inundamatriz(altura, largura, matriz, x, y + 1);
    inundamatriz(altura, largura, matriz, x, y - 1);
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
#include "oo.h"
#include <stdlib.h>
#include <time.h>

#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO     21
#define PAR_CINZAESCURO    26
#define PAR_CINZACLARO     27
#define PAR_VERMELHO       42

#define PAR_NUM1           43 
#define PAR_NUM2           44 
#define PAR_NUM3           45 
#define PAR_NUM4           46 
#define PAR_NUM5           47 
#define PAR_NUM6           48 
#define PAR_NUM7           49 
#define PAR_NUM8           50 

#define PAR_NUM9           51 
#define PAR_NUM10          52 
#define PAR_NUM11          53 
#define PAR_NUM12          54 
#define PAR_NUM13          55 
#define PAR_NUM14          56 
#define PAR_NUM15          57

typedef struct A_{
    int bomba;
    int pertobomba;
    int revelado;
    char icone;
    int marcado;
    int quadradoachado;
    int checado;
} campo;

void geracampo(int altura, int largura, campo matriz[altura][largura], int num_bombas);
void inundamatriz(int altura, int largura, campo matriz[altura][largura], int x, int y);
int campominado()

// LEEEO ANTES DE QUALQUER COISA LE ISSOclear
/*Vamo add 2 coisas pra fazer o jogo na 30 por 30 não ficar estupdamente tedioso:
Peso nas bombas, vão ter bombas de niveis diferentes, e elas somam mais numeros, bomba nivel 1 soma 1, bomba nivel 2 soma 2, bomba nivel 3 soma 3, etc etc
em cima vai estar escrito quanto de cada tem, e vai poder marcar os lugares com cores diferentes pra avisar cada uma.

A segunda coisa, avisar quantas bombas tem em cada linha e em cada coluna.
na borda da linha e da coluna vai ter o numero de bombas que la tem, pra agilizar o processo de jogar o jogo.*/




// LEEEOOO parte 2
/*vamo fazer tipo aquela questão de prova do ano passado, que inundava a matriz pra ver as queimadas e pegava a que tinha a maior e dava o resultado dela? se lembra?
vamo fazer isso, pegar a maior inundação possivel e dar um valor no meio dela como dica pra pessoa iniciar sem perder de cara

*/
{

    srand(time(NULL));    
    int i,j;
    int altura = 16;
    int largura = 16;
    int num_bombas = 10; // Ajustei para 100 pois um campo 30x30 (900 casas) com 20 bombas seria muito fácil

    // Calcula o tamanho da janela da ncurses dinamicamente
    // Altura = (altura do jogo) + 2 (para as bordas)
    // Largura = (largura do jogo * 3 espaços) + 2 (para as bordas)
    int largura_do_quadrado = 6; // largura de cada célula em caracteres (deve ser par para centralizar bem)
    int altura_do_quadrado = 3; // altura de cada célula em linhas
    char *opcoes[] = {"Facil", "Medio", "Dificil"};
    int escolha = 0;
    int dificuldade = 0;
    int tecla_menu = 0;
    int timer=0,velocidade_timer=0;
    int perdeu=0, marcadoerrado=0,acerto,ganhou=0;

    while (tecla_menu != '\n') 
    {
        erase();
        
        mvwprintw(stdscr, 2, 4, "Selecione a Dificuldade:");
        
        for (int k = 0; k < 3; k++) 
        {
            if (k == escolha) 
            {
                wattron(stdscr, A_REVERSE);
                mvwprintw(stdscr, 4 + k, 6, "> %s", opcoes[k]);
                wattroff(stdscr, A_REVERSE);
            } else 
            {
                mvwprintw(stdscr, 4 + k, 6, "  %s", opcoes[k]);
            }
        }
        wrefresh(stdscr);
        tecla_menu = wgetch(stdscr);
        switch (tecla_menu) 
        {
            case KEY_UP:
            case 'w':
                escolha--;
                if (escolha < 0) escolha = 2;
                break;
            case KEY_DOWN:
            case 's':
                escolha++;
                if (escolha > 2) escolha = 0;
                break;
        }
    }

    dificuldade = escolha;
    if(dificuldade==0)
    {
        altura = 9;
        largura = 9;
        num_bombas = 2;
    }
    else if(dificuldade==1)
    {
        altura = 16;
        largura = 16;
        num_bombas =40;
    }
    else
    {
        altura = 16;
        largura = 30;
        num_bombas = 70;
    }
    WINDOW *campominado = newwin((altura * altura_do_quadrado) + 2, (largura * largura_do_quadrado) + 2, 2, 5);
    keypad(campominado, TRUE); 
    nodelay(campominado, TRUE);

        box(campominado, 0, 0);


    // Declaração dinâmica da matriz (VLA)
    campo matriz[altura][largura];
    
    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura; j++)
        {
            matriz[i][j].bomba = 0; // pode ser 1 ou 0, mas futuramente pode ter valor atpe 3
            matriz[i][j].pertobomba = 0;// de 0 a 8, mas pode aumentar com os pesos das bombas quando tivermos
            matriz[i][j].revelado = 0;// 1 ou 0.
            matriz[i][j].marcado = 0;
            matriz[i][j].quadradoachado=0;
        }
    }
    
    geracampo(altura, largura, matriz, num_bombas);
    
    int selecaoX = 0; 
    int selecaoY = 0;
    int tecla = 0;

    flushinp();


while (tecla != 'p')
{
    
            //check de vitoria
            if(ganhou==1){
                werase(campominado);
                mvwprintw(campominado,(altura * altura_do_quadrado) / 2, 2,"hahahah parabens some daqui agora otario");
                wattron(campominado,A_BOLD);
                mvwprintw(campominado,(altura * altura_do_quadrado) / 2, 2+34,"otario");
                wattroff(campominado,A_BOLD);
                wrefresh(campominado);
                napms(2500);
                break;
            }

    acerto = 0;
    marcadoerrado = 0;

    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura; j++)
        {
            if(matriz[i][j].marcado == 1) {
                if(matriz[i][j].bomba == 1) {
                    acerto++;
                } else {
                    marcadoerrado++;
                }
            }
        }
    }


    if(acerto == num_bombas && marcadoerrado == 0){
        ganhou = 1;
    }
            //timer
            velocidade_timer++;
            if(velocidade_timer%33==0)
                timer++;
            tecla = wgetch(campominado);

            if(perdeu==1)
            {
                for(i=0;i<altura;i++)
                {
                    for(j=0;j<largura;j++)
                    {
                        if(matriz[i][j].bomba==1)
                        {
                            matriz[i][j].revelado=1;
                        }
                    }
                }
            }

            werase(campominado);
            
            for (int y = 0; y < altura; y++)
            {
                for (int x = 0; x < largura; x++)
                {
                    int posY = (y * altura_do_quadrado) + 1;
                    int posX = (x * largura_do_quadrado) + 1;
                    
                    int par_de_cores;
                    if((x + y) % 2 == 0)
                        {par_de_cores = PAR_CINZAESCURO;}
                    else
                        {par_de_cores = PAR_CINZACLARO; }
                    
                    int e_selecionado = (x == selecaoX && y == selecaoY);
                    
                    
                    int estilo_base = COLOR_PAIR(par_de_cores);
                    if (e_selecionado) estilo_base |= A_REVERSE;
                    
                    wattron(campominado, estilo_base);
                    
                    if (matriz[y][x].revelado == 1 && matriz[y][x].bomba == 0 && matriz[y][x].pertobomba == 0) {
                        wattroff(campominado, estilo_base);
                        
                        int estilo_vazio = COLOR_PAIR(31);
                        if (e_selecionado) estilo_vazio |= A_REVERSE;
                        
                        wattron(campominado, estilo_vazio);
                        for (int h = 0; h < altura_do_quadrado; h++) {
                            mvwprintw(campominado, posY + h, posX, "      "); 
                        }
                        wattroff(campominado, estilo_vazio);
                    } 
                    else 
                    {
                        for (int h = 0; h < altura_do_quadrado; h++) {
                            mvwprintw(campominado, posY + h, posX, "      "); 
                        }
                        
                        if (matriz[y][x].revelado == 0)
                        {
                            if (matriz[y][x].marcado == 1) {
                                mvwprintw(campominado, posY + 1, posX + 2, "!");
                            } else if (matriz[y][x].marcado == 2) {
                                mvwprintw(campominado, posY + 1, posX + 2, "?");
                            }
                        }
                        
                        if (matriz[y][x].revelado == 1) 
                        {
                            if (matriz[y][x].bomba == 1) 
                            {
                                wattroff(campominado, estilo_base);
                                
                                int estilo_bomba = COLOR_PAIR(PAR_VERMELHO) | A_BOLD;
                                if (e_selecionado) estilo_bomba |= A_REVERSE;
                                
                                wattron(campominado, estilo_bomba);
                                mvwprintw(campominado, posY + 1, posX + 2, "@");
                                wattroff(campominado, estilo_bomba);
                                
                                wattron(campominado, estilo_base);
                            } 
                            else if (matriz[y][x].pertobomba > 0) 
                            {
                                wattroff(campominado, estilo_base);
                                
                                int cor_do_numero = 42 + matriz[y][x].pertobomba; // 43 a 50
                                if ((x + y) % 2 != 0) cor_do_numero += 8;         // 51 a 58 para fundo claro
                                
                                // Adicionado A_BOLD e tratamento limpo com A_REVERSE quando selecionado
                                int estilo_numero = COLOR_PAIR(cor_do_numero) | A_BOLD;
                                if (e_selecionado) {
                                    estilo_numero |= A_REVERSE;
                                }
                                
                                wattron(campominado, estilo_numero);
                                mvwprintw(campominado, posY + 1, posX + 2, "%d", matriz[y][x].pertobomba);
                                wattroff(campominado, estilo_numero);
                                
                                wattron(campominado, estilo_base);
                            }
                        }
                    }

                    wattroff(campominado, estilo_base);
                }
            }

            box(campominado, 0, 0);
            mvwprintw(campominado, 0, 2, " Tempo: %d ", timer);
            wrefresh(campominado);

            if(perdeu>=1)
            {   
                perdeu++;
                napms(1000);
            }

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
                    matriz[selecaoY][selecaoX].revelado = 1;
                    if(matriz[selecaoY][selecaoX].bomba==1){
                        perdeu=1;
                    }
                    break;
                case ' ':
                    matriz[selecaoY][selecaoX].marcado++;
                    if(matriz[selecaoY][selecaoX].marcado>2)
                        matriz[selecaoY][selecaoX].marcado=0;
                    if(matriz[selecaoY][selecaoX].marcado<0)
                        matriz[selecaoY][selecaoX].marcado=2;
                    break;
            }
            napms(30);

                    
            if(perdeu==3)
            {
                werase(campominado);
                mvwprintw(campominado, (altura * altura_do_quadrado) / 2, 2, "Voce perdeu");
                wrefresh(campominado); 
                napms(2000);
                break;
            }
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

void inundamatriz(int altura, int largura, campo matriz[altura][largura], int y, int x) 
{
    if (y < 0 || y >= altura || x < 0 || x >= largura) {
        return;
    }
    if (matriz[y][x].pertobomba >= 1 && matriz[y][x].revelado == 0 && matriz[y][x].bomba == 0) { 
        matriz[y][x].revelado = 1;
        return;
    }

    if (matriz[y][x].revelado == 1) {
        return;
    }

    matriz[y][x].revelado = 1; // revela o quadrado que ela chegou independente
    
    inundamatriz(altura, largura, matriz, y - 1, x);
    inundamatriz(altura, largura, matriz, y + 1, x);
    inundamatriz(altura, largura, matriz, y, x + 1);
    inundamatriz(altura, largura, matriz, y, x - 1);
}

void achamaior(int altura, int largura, campo matriz[altura][largura], int y, int x,int quadrados)
{
    if(matriz[y][x].quadradoachado==1)
    {
        return;
    }

    if (y < 0 || y >= altura || x < 0 || x >= largura) 
    {
        return;
    }

    if (matriz[y][x].pertobomba >= 1 && matriz[y][x].bomba == 0) 
    { 
        quadrados++;
        return;
    }
    quadrados++;
    matriz[y][x].quadradoachado=1;
    achamaior(altura, largura, matriz, y - 1, x,quadrados);
    achamaior(altura, largura, matriz, y + 1, x,quadrados);
    achamaior(altura, largura, matriz, y, x + 1,quadrados);
    achamaior(altura, largura, matriz, y, x - 1,quadrados);
}
//achamaior(altura, largura, matriz, y - 1, x,quadrados);
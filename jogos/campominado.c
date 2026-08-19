#include "jogos.h"

#define NUM_COLUNAS 30  // 90 espaços de largura da janela / 3 caracteres por bloco
#define NUM_LINHAS  29  // 31 de altura da janela - 2 bordas do box

#define PAR_CINZAESCURO    26
#define PAR_CINZACLARO     27

int campominado()
{
    WINDOW *campominado = newwin(31, 91, 3, 15);
    keypad(campominado, TRUE);
    nodelay(campominado, TRUE);

    int matriz[NUM_LINHAS][NUM_COLUNAS] = {0};

    int selecaoX = 0; 
    int selecaoY = 0;
    int tecla = 0;

    flushinp();

    while (tecla != 'p')
    {
        tecla = wgetch(campominado);
        werase(campominado);

        // Desenho da Matriz
        for (int j = 0; j < NUM_LINHAS; j++)
        {
            for (int i = 0; i < NUM_COLUNAS; i++)
            {
                int pos_x = 1 + (i * 3);
                int pos_y = 1 + j;

                int par_base = ((i + j) % 2 == 0) ? PAR_CINZAESCURO : PAR_CINZACLARO;

                if (i == selecaoX && j == selecaoY)
                {
                    // A_REVERSE inverte o fundo com o COLOR_BLACK, preenchendo todo o bloco
                    wattron(campominado, COLOR_PAIR(par_base) | A_REVERSE);
                    mvwprintw(campominado, pos_y, pos_x, "   "); 
                    wattroff(campominado, COLOR_PAIR(par_base) | A_REVERSE);
                }
                else
                {
                    wattron(campominado, COLOR_PAIR(par_base));
                    mvwprintw(campominado, pos_y, pos_x, "   ");
                    wattroff(campominado, COLOR_PAIR(par_base));
                }
            }
        }

        box(campominado, 0, 0);
        wrefresh(campominado);

        // Movimentação
        switch (tecla)
        {
            case KEY_LEFT:
            case 'a':
                selecaoX--;
                if (selecaoX < 0) selecaoX = NUM_COLUNAS - 1;
                break;

            case KEY_RIGHT:
            case 'd':
                selecaoX++;
                if (selecaoX >= NUM_COLUNAS) selecaoX = 0;
                break;

            case KEY_UP:
            case 'w':
                selecaoY--;
                if (selecaoY < 0) selecaoY = NUM_LINHAS - 1;
                break;

            case KEY_DOWN:
            case 's':
                selecaoY++;
                if (selecaoY >= NUM_LINHAS) selecaoY = 0;
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

/*
initscr = iniciar screen
curs_set = setar cursor
mvwprintw = move window print window
wrefresh = window refresh
napms = nap(dormir), milissegundos
werase = window erase
nodelay = no(não) delay(atraso)
getch = get char (pegar caractere
mvwaddch = move window adicionar char
if(cor==1) wattron = window atribuir ON
wattroff = window atribuir OFF




        [ mvwprintw_cansado(..., "PROVA")]
                        │
                        ▼
        [string lenght pega o tamanho do "prova" ex(5 letras)]
                        │
                        ▼
        [Inicia um laço 'for' de 0 a 4]
                        │
        ┌───────────────┴───────────────┐
        ▼                               ▼
    [Letra 'P']                     [Letra 'R']
Sorteia o dado (%) :             Sorteia o dado (%) :
Deu 85 (Maior que 4)            Deu 2 (Menor que 4!)
        │                               │
        ▼                               ▼
    (Cai no else)                    (Cai no if)
Mantém a letra real              Sorteia um símbolo caos
        │                               │
        ▼                               ▼
Usa a função 'mvwaddch'          Usa a função 'mvwaddch'
para desenho her 'P' em X=40        para desenho her '?' em X=41



void mvwprintw_cansado(WINDOW *win, int y, int x, const char *texto) {  nisso aqui ele definiu uma função quase igual ao mvwpintw

    int tam = strlen(texto); // qui ele ta definindo o tamanho do "texto que ele quer mecher", com o string lenght.
    char carac_caos[] = "@#$?*!01X%&Z[+";
    
    for (int i = 0; i < tam; i++) {
        // 4% de chance de o caractere se corromper no frame atual
        // Protegemos as bordas estruturais '|' e os colchetes das opções para manter o HUD jogável
        if (rand() % 100 < 4 && texto[i] != '|' && texto[i] != ' ' && texto[i] != '[' && texto[i] != ']') {
            int r = rand() % 14;
            mvwaddch(win, y, x + i, carac_caos[r]);
        } else {
            mvwaddch(win, y, x + i, texto[i]);
        }
    }
}
*/



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
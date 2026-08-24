#include "oo.h"

/*

TUTORIALZINHO DAS CORES NA NCURSES

1 start_color()
não tem parametro
primeira função pra iniciar as cores ( usada de preferencia logo apos o initscr( );)

init_pair(short <id do par>, short <cor do texto> , short <cor do fundo>);

init_color(short < id da cor>, short<vermelho>,short<verde>,short<azul>);
é tipo um rgb mas vai de 0 a 1000 ao inves dos 255, tudo 1000 é branco tudo 0 é preto

use_default_color()
não tem parametro, habilita o -1 nos init pair, faz pegar a cor do terminal.

has_colors()
não tem parametro, retorna valor booleano true ou false, verifica se o terminal tem suporte pra receber cores
*/


#define TARGET_FRAME_MS 30
#define COR_MARROM         8
#define COR_JANELA         9
#define COR_FUNDO_CHUVA    10
#define COR_CHUVA          11
#define COR_CHAO           12
#define COR_ESTANTE        13
#define COR_TAPETE_OPCAO1  14
#define COR_RODAPE         15
#define COR_BANCO          16
#define COR_ESPELHO        17
#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO     20
#define COR_CINZAMTESCUROMEIOMARROM  21

void inicializar_cores(SAVE *save, int interage, int *par)
{
    if (save->cor == 1)
    {
        start_color();
        use_default_colors();
        init_color(COR_MARROM, 550, 270, 70);
        init_color(COR_JANELA, 400, 450, 500);
        init_color(COR_FUNDO_CHUVA, 30, 40, 120);
        init_color(COR_CHUVA, 400, 700, 1000);
        init_color(COR_CHAO, 760, 600, 410);
        init_color(COR_ESTANTE, 300, 150, 50);
        init_color(COR_TAPETE_OPCAO1, 500, 0, 100);
        init_color(COR_RODAPE, 750, 750, 750);
        init_color(COR_BANCO, 600, 400, 200);
        init_color(COR_ESPELHO, 700, 850, 900);
        init_color(COR_CIANO, 0, 1000, 1000);
        init_color(COR_CINZACLARO, 850, 850, 850);
        init_color(COR_CINZAESCURO, 700, 700, 700);
        init_color(COR_CINZAMTESCUROMEIOMARROM, 500, 450, 400);
        
        init_pair(1, COR_RODAPE, -1);
        init_pair(2, COR_JANELA, -1);
        init_pair(4, COLOR_RED, -1);
        init_pair(5, COR_CHUVA, -1);
        init_pair(6, COR_MARROM, -1);
        init_pair(7, COR_ESTANTE, -1);
        init_pair(8, COR_TAPETE_OPCAO1, -1);
        init_pair(9, COR_RODAPE, -1);
        init_pair(10, COLOR_WHITE, COLOR_WHITE);
        init_pair(11, COR_ESPELHO, -1);
        init_pair(31, -1, COR_JANELA);
        init_pair(59, COR_CINZAMTESCUROMEIOMARROM, -1);
        
        init_pair(26, COLOR_WHITE, COR_CINZAESCURO);
        init_pair(27, COLOR_WHITE, COR_CINZACLARO);

        init_pair(15, COR_JANELA,-1);
        init_pair(16, COLOR_WHITE, COLOR_BLUE);
        init_pair(17, COLOR_WHITE, COLOR_GREEN);
        init_pair(18, COLOR_WHITE, COLOR_RED);
        init_pair(19, COLOR_WHITE, COLOR_MAGENTA);
        init_pair(20, COLOR_WHITE, COLOR_YELLOW);

        init_pair(43, COLOR_CYAN,    COR_CINZAESCURO); // 1
        init_pair(44, COLOR_GREEN,   COR_CINZAESCURO); // 2
        init_pair(45, COLOR_YELLOW,  COR_CINZAESCURO); // 3
        init_pair(46, COLOR_RED,     COR_CINZAESCURO); // 4
        init_pair(47, COLOR_MAGENTA, COR_CINZAESCURO); // 5
        init_pair(48, COLOR_CYAN,    COR_CINZAESCURO); // 6
        init_pair(49, COLOR_YELLOW,  COR_CINZAESCURO); // 7
        init_pair(50, COLOR_WHITE,   COR_CINZAESCURO); // 8

        init_pair(51, COLOR_BLUE,    COR_CINZACLARO);  // 1
        init_pair(52, COLOR_GREEN,   COR_CINZACLARO);  // 2
        init_pair(53, COLOR_RED,     COR_CINZACLARO);  // 3
        init_pair(54, COLOR_MAGENTA, COR_CINZACLARO);  // 4
        init_pair(55, COLOR_YELLOW,  COR_CINZACLARO);  // 5
        init_pair(56, COLOR_CYAN,    COR_CINZACLARO);  // 6
        init_pair(57, COLOR_BLACK,   COR_CINZACLARO);  // 7
        init_pair(58, COLOR_RED,     COR_CINZACLARO);  // 8

        if (interage == 1)
        {
            init_pair(12, COLOR_YELLOW, -1);
            init_pair(13, COLOR_WHITE, -1);
            init_pair(14, COR_CIANO, -1);
            if (save->selecao_cor == 0) *par = 12;
            else if (save->selecao_cor == 1) *par = 13;
            else if (save->selecao_cor == 2) *par = 14;
        }
    }
}

/*#include "oo.h"
#define TARGET_FRAME_MS 30
#define COR_MARROM         8
#define COR_JANELA         9
#define COR_FUNDO_CHUVA    10
#define COR_CHUVA          11
#define COR_CHAO           12
#define COR_ESTANTE        13
#define COR_TAPETE_OPCAO1  14
#define COR_RODAPE         15
#define COR_BANCO          16
#define COR_ESPELHO        17
#define COR_CIANO          18
#define COR_CINZAESCURO    19
#define COR_CINZACLARO    21
void inicializar_cores(SAVE *save, int interage, int *par)
{
    if (save->cor == 1)
    {
        start_color();
        use_default_colors();
        init_color(COR_MARROM, 550, 270, 70);
        init_color(COR_JANELA, 400, 450, 500);
        init_color(COR_FUNDO_CHUVA, 30, 40, 120);
        init_color(COR_CHUVA, 400, 700, 1000);
        init_color(COR_CHAO, 760, 600, 410);
        init_color(COR_ESTANTE, 300, 150, 50);
        init_color(COR_TAPETE_OPCAO1, 500, 0, 100);
        init_color(COR_RODAPE, 750, 750, 750);
        init_color(COR_BANCO, 600, 400, 200);
        init_color(COR_ESPELHO, 700, 850, 900);
        init_color(COR_CIANO, 0, 1000, 1000);
        init_color(COR_CINZACLARO, 800, 800, 800);
        init_color(COR_CINZAESCURO, 700, 700, 700);
        init_pair(1, COR_RODAPE, -1);
        init_pair(2, COR_JANELA, -1);
        init_pair(4, COLOR_RED, -1);
        init_pair(5, COR_CHUVA, -1);
        init_pair(6, COR_MARROM, -1);
        init_pair(7, COR_ESTANTE, -1);
        init_pair(8, COR_TAPETE_OPCAO1, -1);
        init_pair(9, COR_RODAPE, -1);
        init_pair(10, COLOR_WHITE, COLOR_WHITE);
        init_pair(11, COR_ESPELHO, -1);
        init_pair(26, -1,COR_CINZAESCURO);
        init_pair(27, -1,COR_CINZACLARO);
        init_pair(16, COLOR_WHITE, COLOR_BLUE);
        init_pair(17, COLOR_WHITE, COLOR_GREEN);
        init_pair(18, COLOR_WHITE, COLOR_RED);
        init_pair(19, COLOR_WHITE, COLOR_MAGENTA);
        init_pair(20, COLOR_WHITE, COLOR_YELLOW);
        if (interage == 1)
        {
            init_pair(12, COLOR_YELLOW, -1);
            init_pair(13, COLOR_WHITE, -1);
            init_pair(14, COR_CIANO, -1);
            if (save->selecao_cor == 0) *par = 12;
            else if (save->selecao_cor == 1) *par = 13;
            else if (save->selecao_cor == 2) *par = 14;
        }
    }
}*/
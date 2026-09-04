#include "oo.h"

char simbolo_da_celula(int tabuleiro[3][3],int marcacoes[3][3],int linha, int coluna)
{
    if (tabuleiro[linha][coluna] == 1)
        return 'X';

    if (tabuleiro[linha][coluna] == 2)
        return 'O';

    return ' ';
}

void alternar_marcacao(int tabuleiro[3][3],int marcacoes[3][3],int linha, int coluna)
{
    if (tabuleiro[linha][coluna] != 0)
    {
        return;
    }
    marcacoes[linha][coluna]++;
}

int verificar_vencedor(int tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] != 0 &&
            tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2])
        {
            return tabuleiro[i][0];
        }

        if (tabuleiro[0][i] != 0 &&
            tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i])
        {
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] != 0 &&
        tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2])
    {
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] != 0 &&
        tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0])
    {
        return tabuleiro[0][2];
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (tabuleiro[linha][coluna] == 0)
                return 0;
        }
    }

    return 3;
}

void desenhar_tabuleiro(WINDOW *jogodavelha,int tabuleiro[3][3],int marcacoes[3][3],int selecao_linha,int selecao_coluna,int jogadorXouO)
{
    int tabuleiro_largura = (15) + ((3 - 1));
    int tabuleiro_altura = (9) + ((3 - 1));
    int inicioy = (LINES - tabuleiro_altura) / 2;
    int iniciox = (COLS - tabuleiro_largura) / 2;

    if (inicioy < 3)
        inicioy = 3;

    if (iniciox < 2)
        iniciox = 2;

    werase(jogodavelha);
    box(jogodavelha, 0, 0);
    mvwprintw(jogodavelha, 1, 2,"Jogo da velha| Jogue com Enter | p sai");
    if (jogadorXouO == 1)
    {
        mvwprintw(jogodavelha, 1+3, 2,"\\  /");
        mvwprintw(jogodavelha, 2+3, 2," \\/ ");
        mvwprintw(jogodavelha, 3+3, 2," /\\ ");
        mvwprintw(jogodavelha, 4+3, 2,"/  \\ ");
    }
    else
    {
        mvwprintw(jogodavelha, 1+3, 2," ___ ");
        mvwprintw(jogodavelha, 2+3, 2,"|   |");
        mvwprintw(jogodavelha, 3+3, 2,"|   |");
        mvwprintw(jogodavelha, 4+3, 2,"|___|");
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            int celula_y = inicioy + (linha * (3 + 1));
            int celula_x = iniciox + (coluna * (5 + 1));
            int selecionada = (linha == selecao_linha && coluna == selecao_coluna);

            if (selecionada)
                wattron(jogodavelha, A_REVERSE);

            for (int altura = 0; altura < 3; altura++)
            {
                for (int largura = 0; largura < 5; largura++)
                {
                    mvwaddch(jogodavelha, celula_y + altura, celula_x + largura, ' ');
                }
            }

            mvwprintw(jogodavelha,celula_y + (3 / 2),celula_x + (5 / 2),"%c",simbolo_da_celula(tabuleiro, marcacoes, linha, coluna));

            if (selecionada)
                wattroff(jogodavelha, A_REVERSE);
        }
    }

    for (int linha = 0; linha < 3 - 1; linha++)
    {
        int separador_y = inicioy + ((linha + 1) * 3) + linha;
        mvwhline(jogodavelha, separador_y, iniciox, ACS_HLINE, tabuleiro_largura);
    }

    for (int coluna = 0; coluna < 3 - 1; coluna++)
    {
        int separador_x = iniciox + ((coluna + 1) * 5) + coluna;
        mvwvline(jogodavelha, inicioy, separador_x, ACS_VLINE, tabuleiro_altura);
    }

    wrefresh(jogodavelha);
}

void jogodavelha()
{
    int tabuleiro[3][3] = {0};
    int marcacoes[3][3] = {0};
    int selecao_linha = 0;
    int selecao_coluna = 0;
    int jogadorXouO = 1;
    int vezdojogador = 1;
    int venceu = 0;// acho que vou deixar como 0,1 e 2;
    int tecla = 0;
    int vitorias_x = 0;
    int vitorias_o = 0;
    int rodada = 1;
    int vezdobot=0;

    curs_set(0);
    noecho();

    WINDOW *janela_jogo = newwin(LINES, COLS, 0, 0);
    keypad(janela_jogo, TRUE);
    nodelay(janela_jogo, TRUE);

    flushinp();

    while (tecla != 'p' && tecla != 'q' && vitorias_x < 2 && vitorias_o < 2)
    {
        desenhar_tabuleiro(janela_jogo, tabuleiro, marcacoes, selecao_linha, selecao_coluna, jogadorXouO);
        tecla = wgetch(janela_jogo);

        switch (tecla)
        {
            case KEY_LEFT:
            case 'a':
                selecao_coluna--;
                if (selecao_coluna < 0)
                    selecao_coluna = 2;
                break;

            case KEY_RIGHT:
            case 'd':
                selecao_coluna++;
                if (selecao_coluna >= 3)
                    selecao_coluna = 0;
                break;

            case KEY_UP:
            case 'w':
                selecao_linha--;
                if (selecao_linha < 0)
                    selecao_linha = 2;
                break;

            case KEY_DOWN:
            case 's':
                selecao_linha++;
                if (selecao_linha >= 3)
                    selecao_linha = 0;
                break;

            case '\n':
            case KEY_ENTER:
                if (tabuleiro[selecao_linha][selecao_coluna] == 0)
                {
                    tabuleiro[selecao_linha][selecao_coluna] = jogadorXouO;
                    marcacoes[selecao_linha][selecao_coluna] = 0;
                    venceu = verificar_vencedor(tabuleiro);

                    if (venceu == 0)
                    {
                        if (jogadorXouO == 1)
                            jogadorXouO = 2;
                        else
                            jogadorXouO = 1;
                    }
                    else
                    {
                        if (venceu == 1)
                            vitorias_x++;
                        else if (venceu == 2)
                            vitorias_o++;

                        if (vitorias_x < 2 && vitorias_o < 2)
                        {
                            rodada++;
                            venceu = 0;

                            for (int linha = 0; linha < 3; linha++)
                            {
                                for (int coluna = 0; coluna < 3; coluna++)
                                {
                                    tabuleiro[linha][coluna] = 0;
                                    marcacoes[linha][coluna] = 0;
                                }
                            }

                            if (vezdobot==0)// adicionei isso aqui pra testar ( esse if especificamente)
                                if (rodada % 2 == 1)
                                {
                                    jogadorXouO = 1;
                                }
                                else
                                {
                                    jogadorXouO = 2;
                                }
                            else// adicionei esse else todo tbm, se tiver dando erro tira os 2 e deixa só esse segundo if que não tem comentário
                                if (rodada % 2 == 1)
                                {
                                    jogadorXouO = 2;
                                }
                                else
                                {
                                    jogadorXouO = 1;
                                }

                                if(vezdobot==1)
                                {
                                    // Botar os if e else e cada posição responida pelo player aqui!... talvez...?s
                                    vezdobot=0;
                                }
                                else
                                {
                                    vezdobot =1;
                                }
                        }
                    }
                }
                break;
        }

        if (tecla == ERR)
            napms(20);
    }

    if (vitorias_x >= 2 || vitorias_o >= 2)
    {
        werase(janela_jogo);
        box(janela_jogo, 0, 0);

        if (vitorias_x >= 2)
        {
            mvwprintw(janela_jogo, LINES / 2, (COLS - 26) / 2, "X venceu melhor de 3.");
        }
        else
        {
            mvwprintw(janela_jogo, LINES / 2, (COLS - 26) / 2, "O venceu melhor de 3.");
        }

        wrefresh(janela_jogo);
        napms(2000);
    }

    delwin(janela_jogo);
}
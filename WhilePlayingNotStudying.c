#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "oo.h"

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
#include "oo.h"
// ==================== MAIN ====================
int main()
{
    curs_set(0);
    initscr();
    cbreak();
    noecho();
    int Xall = (COLS/2)-57, Yall = 3;
    Cenario objetos = {0};
    SAVE save;
    save.atividade_sono = 0;
    save.celularpickup = 0;
    save.livropickup = 0;
    save.revistapickup = 0;
    save.maepistola = 0;
    save.maepistoladef = 0;
    save.janelaaberta = 0;
    save.depoisprova = 0;
    save.iniciado = 0;
    save.x = 22 + Xall;
    save.y = 10 + Yall;
    save.celularpos = 2;
    save.quest = 0;
    save.estagio = 0;
    save.cor = 1; 
    save.selecao_face =0;
    save.selecao_olhos=9;
    save.selecao_pernas=0;
    save.selecao_cor=0;
    save.caixacaindo=0;
    int tecla = 0;
    int xf = 22 + Xall, yf = 10 + Yall, lado = 0;
    objetos.janela.x = 50 + Xall; objetos.janela.y = 4 + Yall;
    objetos.celular.x = 76 + Xall; objetos.celular.y = 9 + Yall;
    objetos.armario.x = 19 + Xall; objetos.armario.y = 14 + Yall;
    objetos.cama.x = 80 + Xall; objetos.cama.y = 8 + Yall;
    objetos.estante.x = 34 + Xall; objetos.estante.y = 5 + Yall;
    objetos.mesa.x = 74 + Xall; objetos.mesa.y = 8 + Yall;
    objetos.lixo.x = 84 + Xall; objetos.lixo.y = 27 + Yall;
    objetos.rodape.x = 21 + Xall; objetos.rodape.y = 9 + Yall;
    objetos.espelho.x = 63 + Xall; objetos.espelho.y = 3 + Yall;
    objetos.interruptor.x = 16 + Xall; objetos.interruptor.y = 16 + Yall;
    objetos.porta.x = 11 + Xall; objetos.porta.y = 3 + Yall;
    objetos.tapete.x = 47 + Xall; objetos.tapete.y = 18 + Yall;
    objetos.caixa.x = 34 + Xall; objetos.caixa.y = 5 + Yall;
    objetos.gato.x = objetos.armario.x + 10; objetos.gato.y = objetos.armario.y + 13;
    objetos.chuva.x = 53 + Xall; objetos.chuva.y = 5 + Yall;
    int celularY = objetos.celular.y, celularX = objetos.celular.x;
    int armarioaberto = 0, dormindo = 0;
    int revistax = celularX, revistay = celularY;
    int livroX = celularX + 17, livroY = celularY, abrindolivro = 0;
    int livro1 = 0, livro2 = 0, livro3 = 0, estudando = 0;
    int acertos = 0;
    int interruptorON = 1;
    int interagirInt = 0;
    int interagirCel = 0, interagirEst = 0, interagirArm = 0, interagirJan = 0, interagirCam = 0,interagirCaixa = 0;
    int interage = 0,par = 0;
    int jogarcelular5 = 0, encararespelho = 0, dormircama = 0, jogartodosjogos = 0, ler1jogar3 = 0, ler3dormir = 0, ler3jogatodos = 0;
    char *quests[8] = {
        "Ganhar 5 jogos no celular",
        "Encarar o espelho",
        "Dormir na cama",
        "Jogar todos os jogos uma vez",
        "Ler um livro e jogar 3 jogos",
        "Ler 3 livros e jogar todos os jogos do celular",
        "Ler 3 livros e . . .dormir?",
        "Leia 3 livros e durma bem"
    };
    int finais_alcancados;
    char *revista[9] = {"1", "2", "3", "4", "5", "6"};
    int passo = 0, vira = 0,virahoriz=0;
    int check = 0;
    int espelho = 0;
    int marcar = 0;
    int xbarra = 3, ybarra = 3;
    int maexinga = 0;
    int epilepsia = 0;
    int estudo = 0;
    int validador = 1;
    int voltar_inicio = 0;
    int jogar = 0;
    int revista_coluna = 0;
    int revista_linha = 0;
    int iniciar = 0;
    int estanoquarto = 0;
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    erase();
    move(0, 0);
    curs_set(0);
    while (1) // menu
    {
        estanoquarto = 0;
        if (save.depoisprova == 0)
        {
            inicio(&interage, &iniciar, &epilepsia, &save, &jogar, estanoquarto);
            //inicio(&save.selecao_olhos, &save.selecao_face, &save.selecao_pernas, &save.cor, &interage, &save.selecao_cor, &iniciar, &epilepsia, &save, &save.iniciado, &jogar, estanoquarto);
            noraw();
            cbreak();
        }
        if (epilepsia == 1) mvprintw(LINES-5, 5, "MODO DE EPILEPSIA");
        erase();
        refresh();
        inicializar_cores(&save, interage, &par);
        //void inicializar_cores(int cor, int interage, int selecaocor, int *par)
        napms(30);
        if ((iniciar == 0 || save.depoisprova == 0) && save.estagio == 0)
        {/*
            keypad(stdscr, FALSE);
            mvprintw(Yall, Xall, "Mova-se com \"WASD\" - saia com a tecla q");
            refresh(); napms(4000); erase();
            mvprintw(Yall, Xall, "Para uma boa gameplay, dentro dos jogos nao saia apertando todos os botoes");
            mvprintw(Yall+1, Xall, "Ou movendo a janela do terminal, pode ocasionar em bugs");
            refresh(); napms(4000);
            mvprintw(Yall+3, Xall, "Fora dos jogos aperte \"Q\" para sair*");
            refresh(); napms(5000); erase();
            mvprintw(Yall, Xall, "Esse projeto ainda esta sendo desenvolvido");
            refresh(); napms(4000); erase();
            mvprintw(Yall, Xall, "Bom jogo!");
            refresh(); napms(4000);*/
            save.estagio++;
            erase();
            transicao(&epilepsia);
            save.quest = dialogoMae(&maexinga);
            keypad(stdscr, TRUE);
        }
        int pisca = 1, vontadedepisca = 0;
        int chuvax = objetos.chuva.x, chuvay = objetos.chuva.y, pos = 0, pos2 = 1, pos3 = 2;
        while (1)
        {
            if (save.depoisprova == 1) { save.x = 22 + Xall; save.y = 10 + Yall; }
            while (1)
            {
                if (save.atividade_sono >= 0 && save.depoisprova == 1) save.atividade_sono = 3;
                dormindo = 0;
                while (1)
                {

                    estanoquarto = 1;
                    gravar_imagem_do_momento(save.x, save.y, save.imagem);
                    if (tecla == 'm') menusave(&save, &jogar,estanoquarto);
                    if (save.depoisprova == 1 && validador == 1) { save.maepistola = 0; save.maepistoladef = 0; validador = 0; }
                    clock_t frame_start = clock();
                    if (save.depoisprova == 0)
                    {
                        if (save.estagio == 0) strcpy(save.momento, "Dialogo com a mae");
                        else if (save.estagio == 1) strcpy(save.momento, "Quarto");
                        else if (save.estagio == 2) strcpy(save.momento, "Prova");
                    }
                    else
                    {
                        if (save.estagio == 3) strcpy(save.momento, "Quarto(depois da prova)");
                        else if (save.estagio == 4) strcpy(save.momento, "Dialogo final");
                    }
                    vontadedepisca++;
                    nodelay(stdscr, TRUE);
                    if (vontadedepisca <= 500) pisca = 1;
                    else if (vontadedepisca > 500 && vontadedepisca <= 505) pisca = 0;
                    else vontadedepisca = 0;
                    erase();
                    // ===== DESENHO DO QUARTO =====
                    int rodapey = objetos.rodape.y, rodapex = objetos.rodape.x;
                    int espelhoy = objetos.espelho.y, espelhox = objetos.espelho.x;
                    //==========================DESENHA O QUARTO===========================
                    desenhar_rodape(&objetos, save.cor);
                    desenhar_cama(&objetos, save.cor, interagirCam, par);
                    desenhar_estante(&objetos, save.cor, interagirEst, par, &save);
                    desenhar_caixa(&objetos, save.cor, interagirCaixa, par, &save);
                    desenhar_mesa(&objetos, save.cor);
                    espelhaogaroto(&save, espelhox, espelhoy, pisca,save.selecao_face,save.selecao_pernas,save.selecao_olhos,passo,vira,virahoriz);
                    desenhar_espelho(&objetos, save.cor, par);
                    desenhar_janela(&objetos, save.cor,save.janelaaberta, interagirJan, par,chuvax, chuvay, &pos, &pos2, &pos3,check);
                    //void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check)
                    desenhar_interruptor(&objetos, &interruptorON, &interagirInt,par,save.cor);
                    desenhar_armario(&objetos, save.cor, armarioaberto, interagirArm, par);
                    desenhar_porta(&objetos, save.cor,save.depoisprova,save.maepistoladef,maexinga, acertos);
                    //void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos)
                    desenhar_lixo(&objetos, save.cor);
                    desenhar_tapete(&objetos, save.cor);
                    desenhar_gato(&objetos, vontadedepisca, save.depoisprova);
                    desenhar_celular_mesa(&objetos, &save, interagirCel, par);
                    desenhar_jogador(&save, vira, passo, pisca,save.cor, save.selecao_face, save.selecao_olhos, save.selecao_pernas,virahoriz);
                    desenhar_hud(ybarra, xbarra,save.cor, &save, jogarcelular5, encararespelho, dormircama, jogartodosjogos, ler1jogar3, ler3jogatodos, ler3dormir, quests);
                    if(save.celularpickup==1) printar_celular(&objetos, save);
                    check++;//fazer chover
                    if(save.maepistola>150)
                        save.maepistoladef=1;
                    save.maepistola++;//mae fechar a porta
                    // ===== MOVIMENTAÇÃO =====
                    tecla = getch();
                    movimentar_jogador(tecla, &xf, &yf, &passo, &lado, &vira, Xall, Yall,&virahoriz);
                    check++;
                    if (check > 100) { check = 0; passo = 0; }
                    processar_colisoes(&objetos, &xf, &yf, &save);
                    save.x = xf; save.y = yf;
                    check++;
                    if (check > 100) { check = 0; passo = 0; }
                    // ===== INTERAÇÕES =====
                    processar_interacoes(&objetos, &save, tecla, Xall, Yall, &espelho, &dormindo, &armarioaberto, &interagirCam,
                    &interagirArm, &interagirJan, &interagirCel, &interagirEst, &marcar, &jogarcelular5,save.cor,
                    &revista_linha, &revista_coluna, &livro1, &livro2, &livro3, &abrindolivro, &estudo, &estudando,
                    &acertos, vira, &interruptorON, &interagirInt, &interagirCaixa);
                    desenhanafrente(&objetos, save.cor,  armarioaberto,  interagirArm,  par);
                    // ===== ESPELHO MINIGAME =====
                    if (espelho == 1)
                    {
                        nodelay(stdscr, FALSE);
                        pedrapapeltesoura(&encararespelho);
                        espelho = 0;
                        nodelay(stdscr, TRUE);
                        erase();
                        save.atividade_sono++;
                    }
                    // ===== LIVRO ABERTO =====
                    printar_livro(save.livropickup, &abrindolivro, livro1, livro2, livro3, livroY, livroX);
                    // ===== CELULAR MENU =====
                    if (save.celularpickup == 1)
                    {
                        char *jogar[3] = {"cobrinha", "campo minado", "jogo da velha"};
                        for (int i = 0; i < 3; i++)
                        {
                            if (i == marcar) attron(A_REVERSE);
                            mvprintw(objetos.celular.y + 4 + i, objetos.celular.x + 21, "%s", jogar[i]);
                            attroff(A_REVERSE);
                        }
                        switch (tecla)
                        {
                            case KEY_UP: marcar--; if (marcar == -1) marcar = 2; break;
                            case KEY_DOWN: marcar++; if (marcar > 2) marcar = 0; break;
                            case '\n':
                                if (marcar == 0) { cobra(&save.cor, &jogarcelular5); save.atividade_sono++; marcar = 0;flushinp(); }
                                if (marcar == 1) {printapracelular(Xall, Yall, rodapey-5, rodapex-4); campominado(); marcar = 0;flushinp(); }
                                if (marcar == 2) { printapracelular(Xall, Yall, rodapey-5, rodapex-4); jogodavelha(); save.atividade_sono++; marcar = 0; flushinp();}
                                break;
                        }
                    }
                    // ===== REVISTA MENU =====
                    if (save.revistapickup == 1)
                    {
                        attron(A_REVERSE);
                        mvprintw(revistay + 5 + revista_linha, revistax + 18 + revista_coluna + 3, "%s", revista[marcar]);
                        attroff(A_REVERSE);
                        switch (tecla)
                        {
                            case KEY_RIGHT: marcar--; revista_coluna += 2;
                                if (revista_coluna > 4 && revista_linha == 0) revista_coluna = 0;
                                else if (revista_linha == 1) { if (revista_coluna > 6) marcar = 0; if (revista_coluna > 12) revista_coluna = 0; }
                                if (marcar == -1) {marcar = 5;} break;
                            case KEY_LEFT: marcar++; if (marcar > 5) marcar = 0; break;
                            case KEY_DOWN: revista_linha++; if (revista_linha > 2) revista_linha = 0; break;
                            case KEY_UP: if (revista_coluna >= 6) revista_linha--; break;
                            case '\n': if (marcar == 0 || marcar) demo(); break;
                        }
                    }
                    // ===== ESTUDAR LIVRO =====
                    if (livro1 || livro2 || livro3) estudar(save,livro1,livro2,livro3,&estudando,&estudo,&tecla,chuvax, chuvay, &pos, &pos2, &pos3,check);
                    // ===== FRAME RATE =====

                    if (!interruptorON && save.cor)
                    {
                        for (int y = 0; y < LINES; y++)
                        {
                            mvchgat(y, 0, -1, A_DIM, 60, NULL);
                        }
                        if(!save.maepistola)
                        {
                            for (int y = 0; y < LINES; y++)
                            {
                                mvchgat(y, 0, -1, A_DIM, 60, NULL);
                            }   
                        }
                    }

                    refresh();
                    clock_t frame_end = clock();
                    double elapsed_ms = (double)(frame_end - frame_start) * 1000.0 / CLOCKS_PER_SEC;
                    int sleep_ms = (int)(TARGET_FRAME_MS - elapsed_ms);
                    if (sleep_ms > 0) napms(sleep_ms);
                    nodelay(stdscr, TRUE);
                    if (save.atividade_sono > 5) { iniciar = 0; voltar_inicio = 0; break; }
                    if (dormindo == 1) { iniciar = 0; dormindo = 0; voltar_inicio = 0; break; }
                    if (tecla == 'q') { voltar_inicio = 1; break; }
                }
                if (voltar_inicio == 1) break;
                if (save.depoisprova == 0)
                {
                    save.estagio++;
                    strcpy(save.momento, "Prova");
                    save.celularpickup = 0; save.livropickup = 0; save.revistapickup = 0;
                    save.x = COLS/2; save.y = LINES/2;
                    if (save.atividade_sono > 5 && estudo >= 3) { cair_no_sono(); dialogoprovacs(); prova_cansado_simples(&save, &acertos); }
                    if (save.atividade_sono <= 5 && estudo >= 3) { dormir(); dialogoprovas(); prova_simples(&save, &acertos); }
                    if (save.atividade_sono > 5 && estudo < 3) { cair_no_sono(); dialogoprovacc(); prova_cansado_complexa(&save, &acertos); }
                    if (save.atividade_sono <= 5 && estudo < 3) { dormir(); dialogoprovac(); prova_complexa(&save, &acertos); }
                    save.depoisprova = 1;
                    dialogodepoisprova(&acertos, &maexinga, &epilepsia);
                }
                else break;
            }
            if (voltar_inicio == 1) break;
            if (acertos < 5 && save.depoisprova == 1) save.depoisprova = 1;
            else { save.estagio++; strcpy(save.momento, "Fim"); }
            dialogofinal(&finais_alcancados, &acertos);
        }
    }
    demo();
    napms(3000);
    endwin();
    return 0;
}
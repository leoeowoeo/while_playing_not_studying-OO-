#include "oo.h"

void processar_interacoes(Cenario *objetos, SAVE *save, int tecla, int Xall, int Yall,
     int *espelho, int *dormindo, 
     int *armarioaberto, int *interagirCam, int *interagirArm, int *interagirJan, int *interagirCel, int *interagirEst,
     int *marcar, int *jogarcelular5, int cor, int *revista_linha, int *revista_coluna, int *livro1, int *livro2, 
     int *livro3, int *abrindolivro, int *estudo, int *estudando, int *acertos, int vira, int *interruptorON, int *interagirInt, int *interagirCaixa)
{
    (void)marcar;         // usado em outra parte da interface, aqui não entra na lógica desta função
    (void)jogarcelular5;   // estado de progresso do jogo do celular, mantido por compatibilidade da assinatura
    (void)cor;             // cor atual do quarto; esta função só desenha textos de interação
    (void)revista_linha;   // navegação do menu da revista, tratada em outro bloco
    (void)revista_coluna;  // navegação do menu da revista, tratada em outro bloco
    (void)estudo;          // estado do estudo do livro, controlado em outra função
    (void)estudando;       // estado do estudo do livro, controlado em outra função
    (void)acertos;         // placar da prova, usado em outro fluxo do jogo

    // ESPELHO
    int espelhox = objetos->espelho.x;
    int espelhoy = objetos->espelho.y;
    int camaX = objetos->cama.x;
    int camaY = objetos->cama.y;
    int armarioX = objetos->armario.x;
    int armarioY = objetos->armario.y;
    int janelaX = objetos->janela.x;
    int janelaY = objetos->janela.y;
    int celularX = objetos->celular.x;
    int celularY = objetos->celular.y;
    int estanteX = objetos->estante.x;
    int estanteY = objetos->estante.y;
    int interruptorX = objetos->interruptor.x;
    int interruptorY = objetos->interruptor.y;

    if (save->y > espelhoy && save->y < espelhoy + 8 && save->x > espelhox - 2 && save->x < espelhox + 9 && vira % 2 == 1)
    {
        wattron(stdscr, A_BOLD);
        mvprintw(Yall+33, Xall+27, "Encarar o espelho: E");
        wattroff(stdscr, A_BOLD);
        if (tecla == 'e' || tecla == 'E') *espelho = 1;
    }

    // CAMA
    if (save->y > camaY && save->y < camaY + 5 && save->x > camaX - 4 && save->x < camaX + 9)
    {
        *interagirCam = 1;
        mvprintw(camaY-2, camaX, "Dormir: F");
        if (tecla == 'f' || tecla == 'F') *dormindo = 1;
    }
    else *interagirCam = 0;

    // ARMARIO
    int pertodearmario = (save->x >= armarioX - 2 && save->x <= armarioX + 8) && (save->y >= armarioY + 2 && save->y <= armarioY + 9);
    if (pertodearmario)
    {
        if (*armarioaberto) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+26, "Fechar armario: E"); wattroff(stdscr, A_BOLD); *interagirArm = 1; }
        else { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, "Abrir armario: E"); wattroff(stdscr, A_BOLD); *interagirArm = 1; }
        if (tecla == 'e' || tecla == 'E') *armarioaberto = !(*armarioaberto);
    }
    else *interagirArm = 0;

    // JANELA
    int pertoJanela = (save->x >= janelaX - 2 && save->x <= janelaX + 8) && (save->y >= janelaY - 1 && save->y <= janelaY + 5);
    if (pertoJanela)
    {
        if (save->janelaaberta) { *interagirJan = 1; wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, " Abrir janela: E"); wattroff(stdscr, A_BOLD); }
        else { *interagirJan = 1; wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, " Fechar janela: E"); wattroff(stdscr, A_BOLD); }
        if (tecla == 'e' || tecla == 'E') save->janelaaberta = !save->janelaaberta;
    }
    else *interagirJan = 0;

    // CELULAR
    if (save->celularpickup == 0 && save->y > celularY - 3 && save->y < celularY + 3 && save->x >= celularX - 4 && save->x <= celularX + 4 && save->revistapickup == 0 && save->livropickup == 0)
    {
        *interagirCel = 1;
        if (save->depoisprova == 0) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, "Pegar celular: E"); wattroff(stdscr, A_BOLD); }
        else mvprintw(Yall+33, Xall+27, "Caramba, ela tirou o celular daqui...");
        if ((tecla == 'e' || tecla == 'E') && save->depoisprova == 0) save->celularpickup = 1;
    }
    else if (save->celularpickup == 1 && save->y > celularY - 3 && save->y < celularY + 3 && save->x >= celularX - 4 && save->x <= celularX + 4)
    {

        wattron(stdscr, A_BOLD);
        mvprintw(Yall+33, Xall+27, "Soltar celular: E");
        wattroff(stdscr, A_BOLD);
        if (tecla == 'e' || tecla == 'E') { save->celularpickup = 0; }
        save->celularpos++;
        if (save->celularpos > 3) save->celularpos = 1;
    }
    else *interagirCel = 0;
    
    // REVISTA
    int pertoRevista = ((save->x >= armarioX - 3 && save->x <= armarioX + 7) && (save->y >= armarioY && save->y <= armarioY + 7));
    if (*armarioaberto)
    {
        if (pertoRevista && save->celularpickup == 0 && save->livropickup == 0 && save->revistapickup == 0)
        {
            *interagirArm = 1;
            if (save->depoisprova == 0) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+47, " Pegar revista: R"); wattroff(stdscr, A_BOLD); }
            else mvprintw(Yall+33, Xall+47, "Caramba, ela tirou o revista daqui...");
            if ((tecla == 'r' || tecla == 'R') && save->depoisprova == 0) save->revistapickup = !save->revistapickup;
        }
        else if (save->revistapickup && pertoRevista && save->celularpickup == 0 && save->livropickup == 0)
        {
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+47, "Soltar revista: R");
            wattroff(stdscr, A_BOLD);
            if (tecla == 'r' || tecla == 'R') save->revistapickup = !save->revistapickup;
        }
        else if ((save->celularpickup == 1 || save->livropickup == 1) && pertoRevista)
        {
            *interagirArm = 0;
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+65, "Mao ocupada");
            mvprintw(Yall+34, Xall+65, "Devolva o item da mao");
            wattroff(stdscr, A_BOLD);
        }
    }

    // ESTANTE / LIVROS
    int pertoestante = ((save->x >= estanteX - 2 && save->x <= estanteX + 14) && (save->y >= estanteY - 1 && save->y <= estanteY + 7));
    if (pertoestante)
    {
        *interagirEst = 1;
        if (save->livropickup == 0 && save->celularpickup == 0 && save->revistapickup == 0)
        {
            if (save->x >= estanteX - 2 && save->x <= estanteX + 2)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 1: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 1; *livro2 = 0; *livro3 = 0; *abrindolivro = 1; }
            }
            else if (save->x >= estanteX + 3 && save->x <= estanteX + 8)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 2: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 0; *livro2 = 1; *livro3 = 0; *abrindolivro = 1; }
            }
            else if (save->x >= estanteX + 9 && save->x <= estanteX + 14)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 3: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 0; *livro2 = 0; *livro3 = 1; *abrindolivro = 1; }
            }
        }
        else if (save->livropickup == 1)
        {
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+27, "Soltar livro: E");
            wattroff(stdscr, A_BOLD);
            if (tecla == 'e' || tecla == 'E') { save->livropickup = 0; *livro1 = 0; *livro2 = 0; *livro3 = 0; *abrindolivro = 0; }
        }
    }
    else *interagirEst = 0;

    // CAIXA
    int pertoCaixa = (save->x >= estanteX + 5 && save->x <= estanteX + 15) && (save->y >= estanteY - 1 && save->y <= estanteY + 2);
    if (pertoCaixa && save->y <= estanteY + 2)
    {
        *interagirCaixa = 1;
        if (save->caixacaindo == 0)
        {
            wattron(stdscr, A_BOLD);
            mvprintw(Yall + 33, Xall + 27, "Olhar caixa: E");
            wattroff(stdscr, A_BOLD);
            if (tecla == 'e' || tecla == 'E') save->caixacaindo = 1;
        }
    }
    else *interagirCaixa = 0;

    if (save->caixacaindo > 0 && save->caixacaindo < 500)
    {
        save->caixacaindo++;
        if (save->caixacaindo >= 500) 
            save->caixacaindo = 501;
    }
    else if (save->caixacaindo >= 500)
    {
        save->caixacaindo = 501;
    }

    int pertoInterruptor = (save->x >= interruptorX - 2 && save->x <= interruptorX + 4) && (save->y >= interruptorY - 1 && save->y <= interruptorY + 3);
    if (pertoInterruptor)
    {
        *interagirInt = 1;
        if (*interruptorON) 
        { 
            wattron(stdscr, A_BOLD); 
            mvprintw(Yall+33, Xall+27, "Desligar luz: E"); 
            wattroff(stdscr, A_BOLD); 
        }
        else 
        { 
            wattron(stdscr, A_BOLD); 
            mvprintw(Yall+33, Xall+27, "Ligar luz: E"); 
            wattroff(stdscr, A_BOLD); 
        }
        
        if (tecla == 'e' || tecla == 'E') 
        {
            *interruptorON = !(*interruptorON);
        }
    }
    else *interagirInt = 0;
}
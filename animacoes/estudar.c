#include "oo.h"
void estudar(SAVE save,int livro1, int livro2,int livro3,int *estudando,int *estudo,int *tecla,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check){
    nodelay(stdscr,TRUE);    
    int Xall = (COLS/2)-57, Yall = 3;
        wattron(stdscr, A_BOLD);
        mvprintw(Yall+33, Xall+47, "Estudar livro?:R");
        wattroff(stdscr, A_BOLD);
        
        if (*tecla == 'r' || *tecla == 'R')
        {
                *estudando = 1;
                        int cont = 0;
                        nodelay(stdscr, TRUE);
                            while (*tecla != 'p' && *tecla != 'P')
                            {
                                *tecla = getch();
                                wattron(stdscr, A_BOLD);
                                mvprintw(LINES-10, COLS-25, "Parar de estudar?: P");
                                wattroff(stdscr, A_BOLD);
                                if (cont > 13000)
                                {
                                    wattron(stdscr, A_BOLD);
                                    mvprintw(LINES-10, COLS-30, "Liberta-lo do sofrimento?: P");
                                    wattroff(stdscr, A_BOLD);
                                }
                                if ((cont / 300) % 6 == 0) mvprintw(save.y-2, save.x-8, "estudando... ");
                                else if ((cont / 300) % 6 == 1) mvprintw(save.y-2, save.x-8, "estudando.. .");
                                else if ((cont / 300) % 6 == 2) mvprintw(save.y-2, save.x-8, "estudando. ..");
                                else if ((cont / 300) % 6 == 3) mvprintw(save.y-2, save.x-8, "estudando ...");
                                else if ((cont / 300) % 6 == 4) mvprintw(save.y-2, save.x-8, "estudando. ..");
                                else mvprintw(save.y-2, save.x-8, "estudando.. .");

                                if (livro1)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- isso vai demorar...                              ");
                                        mvprintw(9, 7, "eu poderia estar jogando agora                           ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- quantas paginas tem isso aqui?                   ");
                                        mvprintw(8, 7, "nossa, ainda estou em um 1/3...                          ");
                                        mvprintw(9, 7, "Eu poderia jogar agora...                                ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Aperta \"P\", por favor, isso aqui...            ");
                                        mvprintw(8, 7, "isso aqui e um saco, silogismo... to so na metade        ");
                                        mvprintw(9, 7, "Eu nao quero fazer diagrama de Venn...                   ");
                                        refresh(); 
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    {
                                        mvprintw(7, 7, "Garoto- Nao vou falar mais nada nao, seu...              ");
                                        mvprintw(8, 7, "SEU BOBOCA!!! EH, BOBOCA, voce nao me deixa              ");
                                        mvprintw(9, 7, "saiiiiir, eu quero jogar =(, nao ver equacoes            ");
                                    }
                                }
                                else if (livro2)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Geometria? Serio mesmo?                          ");
                                        mvprintw(8, 7, "Pra que eu quero saber o tamanho de um poligono?         ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- 'Calcule a area da figura hachurada...'          ");
                                        mvprintw(8, 7, "Isso aqui parece um labirinto bizarro!                   ");
                                        mvprintw(9, 7, "Minha cabeca ta comecando a doer...                      ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Ei, voce ai controlando o teclado...              "); 
                                        mvprintw(8, 7, "Se eu ver mais um triangulo retangulo na minha frente    ");
                                        mvprintw(9, 7, "eu vou quebrar esse terminal, juro por Deus!             ");
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Cateto oposto, hipotenusa, blablabla...          ");
                                        mvprintw(8, 7, "Corta essa! Me deixa voltar pro celular!                 ");
                                        mvprintw(9, 7, "Voce gosta de me ver sofrer, e isso?                     ");
                                    }
                                }
                                else if (livro3)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Ah nao, algebra linear...                        ");
                                        mvprintw(8, 7, "Matrizes 5x5 cheias de zeros e uns. Que tedio.           ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- 'Um algoritmo deterministico...'                 ");
                                        mvprintw(8, 7, "Eu sou um personagem de um jogo em C, sabia?             ");
                                        mvprintw(9, 7, "Estudar programacao dentro de um programa e meta demais. ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Querido jogador introspectivo...                 ");
                                        mvprintw(8, 7, "A essa altura, a cobrinha do celular parece              ");
                                        mvprintw(9, 7, "a oitava maravilha do mundo. APERTA \"R\" POR FAVOR!       ");
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Se eu nao passar nessa prova amanha...           ");
                                        mvprintw(8, 7, "A culpa vai ser inteiramente sua e desse loop...         ");
                                        mvprintw(9, 7, "Aperta 'P' e finge que a gente leu tudo! Vai!            ");
                                    }
                                }
                                if (cont > 60000 && cont <= 75000)
                                { 
                                    mvprintw(7, 7, "Garoto- ...                                              "); 
                                    mvprintw(8, 7, "                                                         ");
                                    mvprintw(9, 7, "                                                         "); 
                                }
                                else if (cont > 75000) 
                                { 
                                    mvprintw(7, 7, "Garoto- FINALMENTE!!!                                    ");
                                    refresh(); napms(1500); estudo++; save.atividade_sono++; break; 
                                }
                                check++;
                                desenhar_chuva(save.cor,chuvax,chuvay, pos, pos2, pos3,check);
                                refresh(); napms(30); cont += 70;
                            }
                            mvprintw(5, 10, "                                                         ");
                            mvprintw(6, 10, "                                                         ");
                            mvprintw(7, 10, "                                                         ");
                            mvprintw(save.y-2, save.x-8, "              ");
                            refresh();

        }
}
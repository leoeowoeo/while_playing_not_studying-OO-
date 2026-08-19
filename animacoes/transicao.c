#include <ncurses.h>

void transicao(int *epilepsia)
{
    nodelay(stdscr, TRUE);
    int tecla, skipa = 0;
    
    tecla = getch();
    if (tecla == '\n') skipa = 1;
    
    if (tecla != '\n') {
        if (*epilepsia == 0) {
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return; 
                    
                    wattron(stdscr, COLOR_PAIR(10));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(10));
                    refresh();
                }
            }
            napms(60);
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return;
                    
                    wattron(stdscr, COLOR_PAIR(16));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(16));
                    refresh();
                }
            }
            napms(60);
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return;
                    
                    wattron(stdscr, COLOR_PAIR(17));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(17));
                    refresh();
                }
            }
            napms(60);
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return;
                    
                    wattron(stdscr, COLOR_PAIR(18));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(18));
                    refresh();
                }
            }
            napms(60);
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return;
                    
                    wattron(stdscr, COLOR_PAIR(19));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(19));
                    refresh();
                }
            }
            napms(60);
            
            for (int i = 0; i < LINES; i++) {
                for (int j = 0; j < COLS; j++) {
                    tecla = getch();
                    if (tecla == '\n') skipa = 1;
                    if (skipa) return;
                    
                    wattron(stdscr, COLOR_PAIR(20));
                    mvprintw(i, j, "   ");
                    wattroff(stdscr, COLOR_PAIR(20));
                    refresh();
                }
            }
            napms(200);
        }
    }
}
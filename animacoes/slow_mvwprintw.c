#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int slow_mvwprintw(WINDOW *win, const char *str, int y, int x, int delay_ms,int *skipado)
{
    
    *skipado=0;
    flushinp();
    int len = (int)strlen(str);
    int i;
    int ch;
    int linhatemp=LINES;
    nodelay(win, TRUE);

    for (i = 0; i < len; i++)
    {
        mvwaddch(win, y, x + i, str[i]);
        //comentário pra avisar sobre poder pular
        mvwprintw(win,LINES-2,1,"Pule dialogos com enter, acelere com a barra de espaço");
        // isso aqui sou eu tentando tratar o usuário mover o tamanho da tela enquanto os dialogos acontecem, funciona, mas pouco, n quero me apegar a isso não, vou dexar assim
                if(linhatemp!=LINES)
        {
            mvwprintw(win,linhatemp-2,1,"                                                      ");
        }
        wrefresh(win);
        linhatemp=LINES;

        wrefresh(win);        
        if (str[i]==','||str[i]==';'||str[i]==':')
        {
            napms(400);
        }

        if(str[i]=='-'&&(str[i+1]!=' '||str[i+1]!='\0'))
        {
            napms(300);
        }
        if(str[i]=='.')
        {
            napms(1000);
        }


        ch = wgetch(win);
        if (ch != ERR && (ch == '\n' || ch == 'k' || ch == 'K'))
        {
            *skipado=1;
            if (i + 1 < len)
            {
                mvwprintw(win, y, x + i + 1, "%s", str + i + 1);
                wrefresh(win);
            }
            flushinp();
            nodelay(win, FALSE);
            return *skipado;
        }
        if(ch=='2')
        {
            napms(1);
        }
        else
        {
            napms(delay_ms);
        }


    }

    flushinp();
    nodelay(win, FALSE);
    return 0;
}
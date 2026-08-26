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

    nodelay(win, TRUE);

    for (i = 0; i < len; i++)
    {
        mvwaddch(win, y, x + i, str[i]);
        wrefresh(win);

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

        napms(delay_ms);
    }

    flushinp();
    nodelay(win, FALSE);
    return 0;
}
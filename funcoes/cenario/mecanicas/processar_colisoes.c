#include "oo.h"
void processar_colisoes(int *xf, int *yf, SAVE *save, int camaX, int camaY, int estanteX, int estanteY, int armarioX, int armarioY, int mesaX, int mesaY, int lixoX, int lixoY)
{   
      int Xall = (COLS/2)-57;
      int Yall = 3;  
    for (int i = camaX - 2; i <= camaX + 8; i++)
        for (int j = camaY; j <= camaY + 3; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = estanteX - 2; i <= estanteX + 13; i++)
        for (int j = estanteY; j <= estanteY + 4; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    /*for (int i = armarioX - 2; i <= armarioX + 5; i++)
        for (int j = armarioY + 5; j <= armarioY + 7; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }*/
        



        /*for (int i = armarioX - 2; i <= armarioX + 5; i++)
        for (int j = armarioY + 5; j <= armarioY + 7; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }*/


        
    for (int i = mesaX - 1; i <= mesaX + 5; i++)
        for (int j = mesaY; j <= mesaY + 1; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = lixoX - 2; i <= lixoX + 3; i++)
        for (int j = lixoY + 1; j <= lixoY + 1; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }

    for (int rx = 21+Xall-2, ry = 10+Yall-2; ry < 31+3; ry++, rx--)
    {
        if (*xf == rx && *yf == ry && (*xf - save->x) != 0) *xf = save->x;
        else if (*xf == rx && *yf == ry && (*yf - save->y) != 0) *yf = save->y;
    }
    for (int rx = 21+Xall-2+72, ry = 10+Yall-2; ry < 31+3; ry++, rx--)
    {
        if (*xf == rx && *yf == ry && (*xf - save->x) != 0) *xf = save->x;
        else if (*xf == rx && *yf == ry && (*yf - save->y) != 0) *yf = save->y;
    }

    for (int rx = 21+Xall-2+2, ry = 12+Yall; ry <12+Yall; ry++, rx--)
    {
        if (*xf == rx && *yf == ry && (*xf - save->x) != 0) *xf = save->x;
        else if (*xf == rx && *yf == ry && (*yf - save->y) != 0) *yf = save->y;
    }
    //armarioY+8
    //int armarioY = 12 + Yall
    
}
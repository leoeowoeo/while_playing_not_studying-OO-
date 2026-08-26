#include "oo.h"
void processar_colisoes(int *xf, int *yf, SAVE *save, int camaX, int camaY, int estanteX, int estanteY, int armarioX, int armarioY, int mesaX, int mesaY, int lixoX, int lixoY)
{   
      int Xall = (COLS/2)-57;
      int Yall = 3;  
    
    //colisao cama
    for (int i = camaX - 1, j = camaY-1; j < camaY + 5; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }

    for (int i = camaX -1+9, j = camaY-1; j < camaY + 5; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
        


      /*mvprintw(camaY, camaX,          "._______.");
        mvprintw(camaY+1, camaX-1,     "/~~     /|");
        mvprintw(camaY+2, camaX-2,    "/       //");
        mvprintw(camaY+3, camaX-3,   "/    ~~ //");
        mvprintw(camaY+4, camaX-4,  "/_______//");
        mvprintw(camaY+5, camaX-5, "|_______|/");*/
    
// Estante - lado esquerdo (diagonal)
for (int i = estanteX + 2, j = estanteY -1+ 1-2; j < estanteY +1+ 5-2; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Estante - lado direito (diagonal)
for (int i = estanteX + 2 + 15, j = estanteY -1+ 1-2; j < estanteY +1+ 5-2; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
//linhas

for (int i = estanteX + 2 + 15, j = estanteY -1+ 1; j < estanteY +1+ 5; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
    



// Armário - lado esquerdo (diagonal)
for (int i = armarioX - 1, j = armarioY + 5; j < armarioY + 9; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Armário - lado direito (diagonal)
for (int i = armarioX - 1 + 8, j = armarioY + 5; j < armarioY + 9; i--, j++)
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


    //colisao mesa        
    for (int i = mesaX+1,j=mesaY; i <= mesaX; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    /*   mvprintw(mesaY, mesaX+1,     "_____");
         mvprintw(mesaY+1, mesaX,    "/    /");
         mvprintw(mesaY+2, mesaX-1, "/____/|");
         mvprintw(mesaY+3, mesaX-1, "|   | ");*/
    //colisao lixo
    for (int i = lixoX - 2; i <= lixoX + 3; i++)
        for (int j = lixoY + 1; j <= lixoY + 1; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    
    
    //colisao rodape 
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

 /*      
        int armarioY = 12 + Yall, armarioX = 6 + Xall;
         mvprintw(armarioY+8, armarioX+2, "|    |  | /");
         mvprintw(armarioY+9, armarioX+2, "|    |  |/ ");
         mvprintw(armarioY+10,armarioX+2, "|    | / ");
         mvprintw(armarioY+11,armarioX+2, "|____|/");*/   
}
/*
poderia reformular as colisões? eu deixei os sprites em perspectiva,  então muitas coisas foram deslocadas, e as matrises de colisões do processar colisões que eram retangulares, agora devem alem de ser reposicionadas nos lugares certos de onde estão os sprites na imagem, serem deslocadas a cada linha que descem pra condizer com o deslocamento no monitor, pra fazer o efeito de 3d


// Estante - lado esquerdo (diagonal)
for (int i = estanteX - 1, j = estanteY - 1; j < estanteY + 5; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Estante - lado direito (diagonal)
for (int i = estanteX - 1 + 15, j = estanteY - 1; j < estanteY + 5; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
    



// Armário - lado esquerdo (diagonal)
for (int i = armarioX - 1, j = armarioY + 5; j < armarioY + 9; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Armário - lado direito (diagonal)
for (int i = armarioX - 1 + 8, j = armarioY + 5; j < armarioY + 9; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}*/
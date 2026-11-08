#include "oo.h"
void processar_colisoes(Cenario *objetos, int *xf, int *yf, SAVE *save)
{   
    int Xall = objetos->rodape.x - 21;
    int Yall = objetos->rodape.y - 9;  
    int camaX = objetos->cama.x, camaY = objetos->cama.y;
    int estanteX = objetos->estante.x, estanteY = objetos->estante.y;
    int armarioX = objetos->armario.x, armarioY = objetos->armario.y;
    int mesaX = objetos->mesa.x, mesaY = objetos->mesa.y;
    int lixoX = objetos->lixo.x, lixoY = objetos->lixo.y;
    
    //colisao cama
    for (int i = camaX-2, j = camaY; j < camaY + 5; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }

    for (int i = camaX -2+9, j = camaY; j < camaY + 5; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = camaX -2+5, j = camaY+4; i>camaX-6; i--)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
        


      /*mvprintw(camaY(linha), camaX(coluna),          "._______.");
        mvprintw(camaY+1, camaX-1,     "/~~     /|");
        mvprintw(camaY+2, camaX-2,    "/       //");
        mvprintw(camaY+3, camaX-3,   "/    ~~ //");
        mvprintw(camaY+4, camaX-4,  "/_______//");
        mvprintw(camaY+5, camaX-5, "|_______|/");*/
    
// Estante - lado esquerdo (diagonal)
for (int i = estanteX + 13, j = estanteY +3; i> estanteY -1; i--)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) {*xf = save->x;mvprintw(0,0,"SOU EU");}
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Estante - lado direito (diagonal)
for (int i = estanteX + 14, j = estanteY +3; j < estanteY +5; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) {*xf = save->x;mvprintw(0,0,"SOU EU");}
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
/*  mvprintw(estanteY-2, estanteX+2,   "_____________.");
    mvprintw(estanteY-1, estanteX+1,  "/            /|");
    mvprintw(estanteY, estanteX,     "/____________/ |");
    mvprintw(estanteY+1, estanteX,   "|_[]_!!__||[]| |");
    mvprintw(estanteY+2, estanteX,   "|!!_[]_!!_!!_| |");
    mvprintw(estanteY+3, estanteX,   "|!!_!!__||[]_| |");
    mvprintw(estanteY+4, estanteX,   "|__!!_!!___!!| |");
    mvprintw(estanteY+5, estanteX,   "|_||!![]_!![]| /");
    mvprintw(estanteY+6, estanteX,   "|_!!_!!_[]_|||/");*/
//linhas






for (int i = estanteX + 13, j = estanteY +4; i>estanteX-1; i--)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) {*xf = save->x;}
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
    


//Armario------- EM TESTE

for (int i = armarioX-2, j = armarioY+5; j < armarioY +9; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) {*xf = save->x;mvprintw(0,0,"SOU EU ENTAO");}
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}
for (int i = armarioX-8, j = armarioY+9; i>armarioX-10; i--)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) {*xf = save->x;mvprintw(0,0,"SOU EU ENTAO");}
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}

// Armário - lado direito (diagonal)
/*for (int i = armarioX +12, j = armarioY + 7; j < armarioY + 12; i--, j++)
{
    if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
}*/
/*      mvprintw(armarioY+1, armarioX+3+3,  "/\"\"\"\"/|");
        mvprintw(armarioY+2, armarioX+3+2, "/    / |");
        mvprintw(armarioY+3, armarioX+3+1,"/    /| |");
        mvprintw(armarioY+4, armarioX+3, "/    / | |");
        mvprintw(armarioY+5, armarioX+2, "|\"\"\"\"|  | |");
        mvprintw(armarioY+6, armarioX+2, "|    |  |)|");
        mvprintw(armarioY+7, armarioX+2, "|    | )| |");
        mvprintw(armarioY+8, armarioX+2, "|    |  | /");
        mvprintw(armarioY+9, armarioX+2, "|    |  |/ ");
        mvprintw(armarioY+10,armarioX+2, "|    | / ");
        mvprintw(armarioY+11,armarioX+2, "|____|/");*/
        



        /*for (int i = armarioX - 2; i <= armarioX + 5; i++)
        for (int j = armarioY + 5; j <= armarioY + 7; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }*/


    //colisao mesa        
    for (int i = mesaX-2,j=mesaY; j<mesaY+2; i--,j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = mesaX-1+3,j=mesaY+1; i>mesaX-3; i--)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    /*   mvprintw(mesaY(linha), mesaX+1(coluna),     "_____");
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
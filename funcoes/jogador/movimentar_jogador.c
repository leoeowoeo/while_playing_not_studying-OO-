#include "oo.h"
void movimentar_jogador(int tecla, int *xf, int *yf, int *passo, int *lado, int *vira, int Xall, int Yall,int *virahoriz)
{
    switch (tecla)
    {
        case 'a': (*xf)--; /*if (*xf < 20 + Xall) *xf = 20 + Xall;*/ (*passo)++; *lado = 2; *virahoriz = 1; break;
        case 'd': (*xf)++; /*if (*xf > 87 + Xall) *xf = 87 + Xall;*/ (*passo)++; *lado = 1; *virahoriz = 0; break;
        case 's': (*yf)++; if (*yf > 29 + Yall) *yf = 29 + Yall; (*passo)++; *vira = 2; break;
        case 'w': (*yf)--; if (*yf < 8 + Yall) *yf = 8 + Yall; (*passo)++; *vira = 1; break;
        default: break;
    }
}
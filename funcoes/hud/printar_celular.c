#include "oo.h"
void printar_celular(Cenario *objetos,SAVE save)
{   

    if(save.celularpickup==1&&save.depoisprova==0)
    {
        
                        mvprintw(objetos->celular.y,      objetos->celular.x+18, "  _______________ ");
                        mvprintw(objetos->celular.y+1,    objetos->celular.x+18, " | _____________ |");        
                        mvprintw(objetos->celular.y+2,    objetos->celular.x+18, " ||      O      ||");
                        mvprintw(objetos->celular.y+3,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+4,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+5,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+6,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+7,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+8,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+9,    objetos->celular.x+18, " ||             ||");
                        mvprintw(objetos->celular.y+10,   objetos->celular.x+18, " ||_____________||");
                        mvprintw(objetos->celular.y+11,   objetos->celular.x+18, " | ===  [ ]  <-- |");
                        mvprintw(objetos->celular.y+12,   objetos->celular.x+18, " \\===============/");
    }
}

#include "oo.h"
void desenhar_armario(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par)
{
    int armarioY = 12 + Yall, armarioX = 6 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (armarioaberto == 1)
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        armarioY = 11+Yall;
        mvprintw(armarioY+1, armarioX+2+11,      ",-'|");
        mvprintw(armarioY+2, armarioX+2+4,      "/\"\"\"\"/|   |");
        mvprintw(armarioY+3, armarioX+2+3,     "/    / |   |");
        mvprintw(armarioY+4, armarioX+2+2,    "/    /  |   |");
        mvprintw(armarioY+5, armarioX+2+1,   "/    /   |   |");
        mvprintw(armarioY+6, armarioX+2,    "|\"\"\"\"|   /|   |");
        mvprintw(armarioY+7, armarioX+2,   "|    |'-',|   |");
        mvprintw(armarioY+8, armarioX+2,   "|    |   \";,-'\"");
        mvprintw(armarioY+9, armarioX+2,   "|    |    |");
        mvprintw(armarioY+10, armarioX+2,  "|    |   (| ");
        mvprintw(armarioY+11, armarioX+2,  "|    |    |");
        mvprintw(armarioY+12, armarioX+2,  "|____|    |");
        mvprintw(armarioY+13, armarioX+2+6,      "'.._|");

        if (cor == 1) wattron(stdscr, COLOR_PAIR(59));
        mvprintw(armarioY+6, armarioX+11,    "/");
        mvprintw(armarioY+7, armarioX+10,   "'");

        mvprintw(armarioY+2+2, armarioX+5+2+4,      "/");
        mvprintw(armarioY+2+3, armarioX+5+2+3,     "/");
        mvprintw(armarioY+2+4, armarioX+5+2+2,    "/");

        if (cor == 1) wattroff(stdscr, COLOR_PAIR(59));
    }
    else
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        armarioY = 12+Yall;
        mvprintw(armarioY+1, armarioX+3+3, "/\"\"\"\"/|");
        mvprintw(armarioY+2, armarioX+3+2, "/    / |");
        mvprintw(armarioY+3, armarioX+3+1, "/    /| |");
        mvprintw(armarioY+4, armarioX+3, "/    / | |");
        mvprintw(armarioY+5, armarioX+2, "|\"\"\"\"|  | |");
        mvprintw(armarioY+6, armarioX+2, "|    |  |)|");
        mvprintw(armarioY+7, armarioX+2, "|    | )| |");
        mvprintw(armarioY+8, armarioX+2, "|    |  | /");
        mvprintw(armarioY+9, armarioX+2, "|    |  |/ ");
         mvprintw(armarioY+10,armarioX+2,"|    | / ");
         mvprintw(armarioY+11,armarioX+2,"|____|/");
    }
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(6));
}

/*
            /""""/|
           /    / |
          /    /| |
         /    / | |
        |""""|  | |    
        |    |  |)| 
        |    | )| |   
        |    |  | / ...........
        |    |  |/  
        |    | /    
        |____|/
        
mvprintw(armarioY + 0, armarioX+4,   "/\"\"\"\"/|");
mvprintw(armarioY + 1, armarioX+3,  "/    / |");
mvprintw(armarioY + 2, armarioX+2, "/    /| |");
mvprintw(armarioY + 3, armarioX+1,"/    / | |");
mvprintw(armarioY + 4, armarioX,  "|\"\"\"\"|  | |");
mvprintw(armarioY + 5, armarioX,  "|    |  |)|");
mvprintw(armarioY + 6, armarioX,  "|    | )| |");
mvprintw(armarioY + 7, armarioX,  "|    |  | /");
mvprintw(armarioY + 8, armarioX,  "|    |  |/");
mvprintw(armarioY + 9, armarioX,  "|    | ./");
mvprintw(armarioY + 10, armarioX, "|____|/");

mvprintw(armarioY + 0,  armarioX+5,      ",-'\"|");
mvprintw(armarioY + 1,  armarioX+4,     "/\"\"\"\"/|    |");
mvprintw(armarioY + 2,  armarioX+3,    "/    / |    |");
mvprintw(armarioY + 3,  armarioX+2,   "/    /  |    |");
mvprintw(armarioY + 4,  armarioX+1,  "/    /   |    |");
mvprintw(armarioY + 5,  armarioX,   "|\"\"\"\"|'-, |    |");
mvprintw(armarioY + 6,  armarioX,   "|    |   \";    |");
mvprintw(armarioY + 7,  armarioX,   "|    |    |,-'\"");
mvprintw(armarioY + 8,  armarioX,   "|    |    | ");
mvprintw(armarioY + 9,  armarioX,   "|    |   (|  ");
mvprintw(armarioY + 10, armarioX,   "|    |    |   ");
mvprintw(armarioY + 11, armarioX,   "|____|    |");
mvprintw(armarioY + 12, armarioX+6,        "'.._|  ");














                                             
                   ,-'"|
            /""""/|    |
           /    / |    |
          /    /  |    |
         /    /   |    |
        |""""|'-, |    |
        |    |   ";    |
        |    |    |,-'"    
        |    |    | 
        |    |   (|  ................
        |    |    |   
        |____|    |
              '.._|  
                 
               
            
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"     ______ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    /     /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"   /     / |");
            mvwprintw(stdscr, livroY++,     livroX-20,"  /     /  |"); 
            mvwprintw(stdscr, livroY++,     livroX-20," /_____/   |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fund.|  _ |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da   | / '|"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat. |'  ||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|elem-| .' |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|entar| | /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  2  | |/ | ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |   /" );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |  /"  );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     | /"   );
            mvwprintw(stdscr, livroY++,     livroX-20,"|_____|/"    );
            wrefresh(stdscr);
            napms(60);



            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,                  "____");
                    mvwprintw(stdscr, livroY++,     livroX-20,"       ,-'  ,-|  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"   _,-'_,--'  |");
                    mvwprintw(stdscr, livroY++,     livroX-20,",-'_,-'       |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|fun|  ,--,   |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|da | '    |  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|mat|     ,/  |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ele|    /    |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ent|   /   , |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"| 2 |  /,--'  |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |       ,-'   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |    ,-'      ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|___| ,-'         ");


            livroY = 8+Yall;
            napms(105);
            mvwprintw(stdscr, livroY++,     livroX-20,"              __,,  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___,--'''__,|");
            mvwprintw(stdscr, livroY++,     livroX-20,"_,--'___---'''   |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |       ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|            |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |   ,--,     |       ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|  '    |     |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|      ,/    |           ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|     /      |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 1 |    /   ,      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |   /,--'     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |          ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |           _|   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    __,--''          ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___|,--'           ");
            wrefresh(stdscr);
            napms(105); // Espera 2 segundos



                    
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|       ,-'''-.      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      '       |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ,-'     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|          ,-'       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|        ,-          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|       /_______     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|");
            wrefresh(stdscr);
            napms(105);
            

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ''---..,_,.-=:;|    ");   
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   .,       ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /   \     ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      ,     ||||||||    ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ,'      ||||||||    ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  .'___     ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___         ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"    ''---..,|;:-=\"' ");
            wrefresh(stdscr);
            napms(55);




            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|''-=::;;_'','.\"',:| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  ,.-,   || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| '    |  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      /  || |||  ||| ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|   ,-'   || |||  ||| ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /____  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|_        ||,|||,_||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"''-=:..,_'' ;:'  ''   ");
            wrefresh(stdscr);
            napms(55);
            
            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,'-,'-, '--,,'-, |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   '-,'-,'-,  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,-. || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |    ||| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   ,'|| | ||  | || |  ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,'  || | ||  | || |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |',,._|| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||._|_||_|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,.,.||_|_||'-,:'' '  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,; -',;'             ");
            wrefresh(stdscr);
            napms(105);

            livroY = 8+Yall;
            werase(stdscr);

            mvwprintw(stdscr, livroY++,     livroX-20,"          ___,____________________");
            mvwprintw(stdscr, livroY++,     livroX-20," ___---'''__,|                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|_,,--''''   |                    |     "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |     ");     
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |     ");         
            mvwprintw(stdscr, livroY++,     livroX-20,"|||         _|____________________|     ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||  __,--''                              ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|,--'                                    ");
            wrefresh(stdscr);
            napms(105);  

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ____________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");      
        mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |   
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|____________________|   ");
            wrefresh(stdscr);
            livroY = 8+Yall;
            napms(100);
            
            */
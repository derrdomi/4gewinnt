#ifndef viergewinnt_h
#define viergewinnt_h


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>//ist eine library für pausen z.b Sleep
#include "viergewinnt.h"
#include "interface2.h"

#define rot "\x1b[31m"
#define green "\x1b[32m"
#define gelb "\x1b[33m"
#define blau "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan "\x1b[36m"
#define weis "\x1b[37m"
#define schwarzh "\x1b[40m"
#define roth "\x1b[41m"
#define greenh "\x1b[42m"
#define gelbh "\x1b[43m"
#define blauh "\x1b[44m"
#define magentah "\x1b[45m"
#define cyanh "\x1b[46m"
#define reset "\x1b[0m"

int animation(char *Felder[6][7], int Eingabe, char *Farbe, int Player){
    int reihe;
    for(int i = 0; i < 6; i++){
        Sleep(250);//Hält das System für eine viertel Sekunde an
        if(Felder[i][Eingabe-1] != schwarzh){
            system("cls");
            gameinterface(Felder, Player);
            break;
        }else{
            reihe = i;//zum merken auf welcher zeile dieser block steht für später winncheck
        }
        if(i == 0){
            Felder[i][Eingabe-1] = Farbe;//am anfang ganz oben
        }else{
            Felder[i-1][Eingabe-1] = schwarzh; //macht es wieder schwarz
            Felder[i][Eingabe-1] = Farbe;//macht zur farbe
        }
        system("cls");
        gameinterface(Felder, Player);
    }
    return reihe;
}







#endif
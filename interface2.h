#ifndef interface2_h
#define interface2_h

//Die StandartFarben
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

#include <stdio.h>

void gameinterface(char *Felder[6][7], int Player){

    printf("\t\t\t\t\t\t\t\tPlayer : %d\n", Player+1);
    //erste Forschleife zählt die reihen
    for(int i = 0; i < 6; i++){
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");//so das man es von dem terminalrand wegbekommt
            }
            if(i == 0){
                printf("%s       %d       %s", blauh, j+1, reset); //für die Zahlen ganz oben
            }else{            
                printf("%s               %s", blauh, reset);//das ist sonst der standart
            }
        }
        printf("\n");//das man eine spalte runter geht
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");
            }
            printf("%s    %s       %s    %s", blauh, Felder[i][j], blauh, reset);//macht weiter mit dem kreis
        }
        printf("\n");//das man eine spalte runter geht
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");
            }
            printf("%s   %s         %s   %s", blauh, Felder[i][j], blauh, reset);
        }
        printf("\n");//das man eine spalte runter geht
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");
            }
            printf("%s   %s         %s   %s", blauh, Felder[i][j], blauh, reset);
        }
        printf("\n");//das man eine spalte runter geht
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");
            }
            printf("%s    %s       %s    %s", blauh, Felder[i][j], blauh, reset);
        }
        printf("\n");//das man eine spalte runter geht
        //diese zählt die spalten
        for(int j = 0; j < 7; j++){
            if(j == 0){
                printf("\t\t\t");
            }
            printf("%s               %s", blauh, reset);
        }
        
        printf("\n");//das man eine spalte runter geht

    }
}

#endif
/**
* @brief Vier gewinnt Projekt
* @author Dominic Dersch (dominic.dersch11@htl-salzburg.ac.at) und elias.putzhammer01@htl-salzburg.at für das spielinterface idee
* @date 15.4.2026
*/
#include "viergewinnt.h"
#include "winncheck.h"
#include "interface2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>//ist eine library für pausen z.b Sleep


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

typedef struct figures figures;

int main(){
    int start;
    int Player = 0;
    int Eingabe;
    char *Felder[6][7];
    int reihe;
    int bwinn = 0;
    int rwinn = 0;
    int decider = 0;
    system("chcp 65001");
    system("cls");
    
    //Zum starten des spiels
    printf("Do you want to begin? 0 to reject\n");
    scanf("%d", &start);
    system("cls");

    if(start != 0){
        
        //das das spielfeld als schwarze farbe beginnt
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 6; j++){
                Felder[j][i] = schwarzh;
            }
        }

        //Zum randomisen das ein zufälliger spieler anfängt
        srand(time(NULL));
        Player = rand() % 2;

        for(int i = 0; i < 42; i++){
            //zum asuwählen des spielers
            if(Player == 0){
                char *Farbe = gelbh;
               for(;;){
                    system("cls");
                    gameinterface(Felder, Player);

                    printf("\t\t\t\t\t\t\t\tWähle die Setzspalte\n");

                    if(scanf(" %d", &Eingabe) == 1){

                    // überprüft ob die Spalte gültig und nicht voll ist
                        if(Eingabe > 0 && Eingabe < 8){
                            if(Felder[0][Eingabe-1] == schwarzh){
                                break;
                            }           
                        }
                    }else{
                        scanf("%*s");
                    }

                printf("Ungültige Eingabe!\n");
                }
                
                //animation zum runterfallen
                reihe = animation(Felder, Eingabe, Farbe, Player);
                //checkt ob gewonnen
                bwinn = winncheck(reihe, Eingabe, Farbe, Felder);
                
                if(bwinn == 1){
                    break;
                }

                Player = 1;

            }else if(Player == 1){
                char *Farbe = roth;
                
               for(;;){
                    system("cls");
                    gameinterface(Felder, Player);

                    printf("\t\t\t\t\t\t\t\tWähle die Setzspalte\n");

                    if(scanf(" %d", &Eingabe) == 1){

                    // überprüft ob die Spalte gültig und nicht voll ist
                        if(Eingabe > 0 && Eingabe < 8){
                            if(Felder[0][Eingabe-1] == schwarzh){
                                break;
                            }           
                        }
                    }else{
                        scanf("%*s");
                    }

                printf("Ungültige Eingabe!\n");
                }

                reihe = animation(Felder, Eingabe, Farbe, Player);

                rwinn = winncheck(reihe, Eingabe, Farbe, Felder);
                
                if(rwinn == 1){
                    break;
                }

                Player = 0;

            }
        }
        //schaut ob bwinn true ist
        switch(bwinn) {

            case 1 :
                printf("\t\t\t\t\t\t\t\tGelb hat Gewonnen!\n");
                decider = 1;
                break;

        }
        //wenn bewinn nicht true ist dann schaut er ob rot gewonnen hat oder unentschieden ist 
        if(decider == 0){
        switch(rwinn) {

            case 1 :
                printf("\t\t\t\t\t\t\t\tRot hat Gewonnen!\n");
                break;

            case 0 :
                printf("\t\t\t\t\t\t\t\tEs ist ein Unentschieden\n");
                break;
        }
    }
        

    }else{
        //nothing because it was rejected
        printf("System aus\n");
    }

    return 0;
}






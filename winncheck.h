#ifndef winncheck_h
#define winncheck_h

int winncheck(int reihe, int Eingabe, char *Farbe, char *Felder[6][7]){

    int infolge = 0;
    for(int i = 0; i < 7; i++){ //schaut ob gewinn in der reihe
        if(Felder[reihe][i] == Farbe){
            infolge++;
        }else{
            infolge = 0;
        }

        if(infolge == 4){
            return 1;
            break;
        }
    }
    infolge = 1;
    for(int i = 1; i < 4; i++){//schaut für einen gewinn in der spalte
        if(reihe+3 <= 5){
            if(Felder[reihe+1][Eingabe-1] == Farbe && Felder[reihe+2][Eingabe-1] == Farbe && Felder[reihe+3][Eingabe-1] == Farbe){
                return 1;
            }
        }else{
            break;
        }
    }
    infolge = 1;
    //schaut für einen diagonalen winn
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
        if(i == 3){break;}
        if(Felder[i][j] == Farbe){
            if(i-3 <= 5 && j-3 >= 0){
                for(int k = 1; k < 4; k++){
                    if(Felder[i-k][j-k] == Farbe){
                        infolge++;
                    }else{
                        infolge = 1;
                        break;
                    }
                }
            }else if(i-3 < 5 && j+3 < 7){
                for(int k = 1; k < 4; k++){
                    if(Felder[i-k][j+k] == Farbe){
                        infolge++;
                    }else{
                        infolge = 1;
                        break;
                    }
                }
            }

            if(infolge == 4){
                return 1;
                break;
            }

        }
    }
}   
}

#endif
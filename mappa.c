#include "mappa.h"

char mappa[RIGHE][COLONNE];

void inizializzaMappa() {

    for(int i = 0; i < RIGHE; i++) {

        for(int j = 0; j < COLONNE; j++) {

            if(i == 0 || i == RIGHE - 1 || j == 0 || j == COLONNE - 1) {

                mappa[i][j] = '#';

            } else {

                mappa[i][j] = '.';
            }
        }
    }
}
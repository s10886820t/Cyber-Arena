#include <stdlib.h>
#include "robot.h"
#include "mappa.h"

int rX[MAX_ROBOT];
int rY[MAX_ROBOT];
int rHP[MAX_ROBOT];
int rStato[MAX_ROBOT];
char rSimbolo[MAX_ROBOT];
int rInvincibile[MAX_ROBOT];

void inizializzaRobot() {

    for(int i = 0; i < MAX_ROBOT; i++) {

        int x;
        int y;

        do {

            x = 1 + rand() % (RIGHE - 2);
            y = 1 + rand() % (COLONNE - 2);

        } while(mappa[x][y] != '.');

        rX[i] = x;
        rY[i] = y;

        rHP[i] = 100;

        rStato[i] = 1;

        rSimbolo[i] = 'A' + i;

        rInvincibile[i] = 0;

        mappa[x][y] = rSimbolo[i];
    }
}

int contaRobotVivi() {

    int cont = 0;

    for(int i = 0; i < MAX_ROBOT; i++) {

        if(rStato[i] == 1) {
            cont++;
        }
    }

    return cont;
}
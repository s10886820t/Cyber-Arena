#include <stdlib.h>
#include <math.h>

#include "ia.h"
#include "robot.h"
#include "mappa.h"

int distanza(int x1, int y1, int x2, int y2) {

    return abs(x1 - x2) + abs(y1 - y2);
}

int trovaNemico(int i) {

    int min = 9999;
    int indice = -1;

    for(int j = 0; j < MAX_ROBOT; j++) {

        if(j != i && rStato[j] == 1) {

            int d = distanza(
                rX[i],
                rY[i],
                rX[j],
                rY[j]
            );

            if(d < min) {

                min = d;
                indice = j;
            }
        }
    }

    return indice;
}

void turnoRobot(int i) {

    int nemico = trovaNemico(i);

    if(nemico == -1) {
        return;
    }

    int d = distanza(
        rX[i],
        rY[i],
        rX[nemico],
        rY[nemico]
    );

    if(d == 1) {

        rHP[nemico] -= 10;

        if(rHP[nemico] <= 0) {

            rHP[nemico] = 0;

            rStato[nemico] = 0;

            mappa[rX[nemico]][rY[nemico]] = '.';
        }

        return;
    }

    int nx = rX[i];
    int ny = rY[i];

    if(rX[nemico] < rX[i]) {
        nx--;
    }
    else if(rX[nemico] > rX[i]) {
        nx++;
    }
    else if(rY[nemico] < rY[i]) {
        ny--;
    }
    else if(rY[nemico] > rY[i]) {
        ny++;
    }

    if(mappa[nx][ny] == '.') {

        mappa[rX[i]][rY[i]] = '.';

        rX[i] = nx;
        rY[i] = ny;

        mappa[nx][ny] = rSimbolo[i];
    }
}
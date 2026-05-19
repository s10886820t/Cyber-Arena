#include <ncurses.h>

#include "rendering.h"
#include "mappa.h"
#include "robot.h"

void disegna() {

    clear();

    for(int i = 0; i < RIGHE; i++) {

        for(int j = 0; j < COLONNE; j++) {

            mvaddch(i, j, mappa[i][j]);
        }
    }

    mvprintw(2, COLONNE + 3, "HP Robot");

    for(int i = 0; i < MAX_ROBOT; i++) {

        mvprintw(
            4 + i,
            COLONNE + 3,
            "%c -> %d HP",
            rSimbolo[i],
            rHP[i]
        );
    }

    refresh();
}
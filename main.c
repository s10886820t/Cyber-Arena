#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "mappa.h"
#include "robot.h"
#include "rendering.h"
#include "ia.h"

int main() {

    srand(time(NULL));

    initscr();

    noecho();

    curs_set(0);

    inizializzaMappa();

    inizializzaRobot();

    while(contaRobotVivi() > 1) {

        for(int i = 0; i < MAX_ROBOT; i++) {

            if(rStato[i] == 1) {

                turnoRobot(i);

                disegna();

                usleep(150000);
            }
        }
    }

    mvprintw(22, 0, "Fine simulazione");

    refresh();

    getch();

    endwin();

    return 0;
}
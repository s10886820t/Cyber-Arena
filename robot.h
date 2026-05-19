#ifndef ROBOT_H
#define ROBOT_H

#define MAX_ROBOT 5

extern int rX[MAX_ROBOT];
extern int rY[MAX_ROBOT];
extern int rHP[MAX_ROBOT];
extern int rStato[MAX_ROBOT];
extern char rSimbolo[MAX_ROBOT];
extern int rInvincibile[MAX_ROBOT];

void inizializzaRobot();
int contaRobotVivi();

#endif
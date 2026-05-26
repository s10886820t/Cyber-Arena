# Cyber-Arena

Progetto sviluppato in C usando la libreria ncurses.

Il programma simula una battaglia tra robot autonomi dentro una mappa 2D.
Ogni robot si muove automaticamente, cerca il nemico più vicino e lo attacca.

## Funzionalità

- movimento automatico dei robot
- attacco tra robot
- gestione HP
- ricerca del nemico più vicino
- mappa con bordi
- visualizzazione grafica nel terminale
- aggiornamento in tempo reale con ncurses

## Struttura del progetto

- main.c -> gestione principale del programma
- mappa.c -> gestione arena
- robot.c -> gestione robot
- ia.c -> logica dei robot
- rendering.c -> visualizzazione nel terminale

## Compilazione

Per compilare il progetto:

```bash
make
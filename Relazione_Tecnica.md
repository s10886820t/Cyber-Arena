# Relazione Tecnica — Progetto “Cyber-Arena”

## Introduzione

Il progetto **Cyber-Arena** è una simulazione sviluppata in linguaggio C che utilizza la libreria ncurses per realizzare un’arena 2D interattiva nel terminale.

L’applicazione simula una battaglia tra robot autonomi che si muovono all’interno di una mappa, cercano automaticamente il nemico più vicino e lo attaccano fino alla distruzione di tutti gli avversari.

Il programma è stato progettato con una struttura modulare, suddividendo le varie funzionalità in file separati per migliorare leggibilità, manutenzione e organizzazione del codice.

---

# Obiettivi del progetto

Gli obiettivi principali del progetto sono:

- simulare il comportamento autonomo dei robot
- implementare una semplice intelligenza artificiale
- gestire una mappa bidimensionale
- utilizzare la libreria ncurses per il rendering grafico
- applicare la programmazione modulare in C
- gestire collisioni, movimento e combattimento

---

# Tecnologie utilizzate

| Tecnologia | Utilizzo |
|---|---|
| Linguaggio C | sviluppo logica applicativa |
| ncurses | interfaccia grafica nel terminale |
| Makefile | compilazione automatica |
| GCC | compilatore C |

---

# Architettura del progetto

Il progetto è suddiviso in più moduli:

| File | Funzione |
|---|---|
| `main.c` | gestione principale della simulazione |
| `mappa.c` | creazione e gestione arena |
| `robot.c` | gestione dati robot |
| `ia.c` | logica decisionale dei robot |
| `rendering.c` | visualizzazione grafica |

---

# Struttura generale del programma

Il flusso principale del programma è il seguente:

1. inizializzazione della libreria ncurses
2. creazione della mappa
3. generazione casuale dei robot
4. ciclo principale della simulazione
5. movimento e attacco automatico
6. rendering aggiornato in tempo reale
7. terminazione quando rimane un solo robot vivo

---

# Modulo `main.c`

Il file `main.c` rappresenta il punto di ingresso del programma.

## Funzioni principali utilizzate

| Funzione | Descrizione |
|---|---|
| `srand(time(NULL))` | inizializza il generatore casuale |
| `initscr()` | avvia ncurses |
| `noecho()` | evita la stampa dei tasti premuti |
| `curs_set(0)` | nasconde il cursore |
| `inizializzaMappa()` | crea la mappa |
| `inizializzaRobot()` | genera i robot |
| `turnoRobot()` | esegue il turno del robot |
| `disegna()` | aggiorna la schermata |

## Ciclo principale

Il ciclo:

```c
while(contaRobotVivi() > 1)
```

mantiene la simulazione attiva finché rimangono almeno due robot vivi.

Ogni robot vivo:
- esegue un turno
- si muove o attacca
- aggiorna la grafica

---

# Modulo `mappa.c`

Questo modulo gestisce la creazione della mappa 2D.

## Struttura della mappa

La mappa è rappresentata da una matrice bidimensionale:

```c
char mappa[RIGHE][COLONNE];
```

## Simboli utilizzati

| Simbolo | Significato |
|---|---|
| `#` | muro/bordo |
| `.` | spazio libero |
| `A-B-C...` | robot |

## Inizializzazione

La funzione `inizializzaMappa()`:
- crea i bordi della mappa
- riempie l’interno con celle vuote

---

# Modulo `robot.c`

Gestisce tutti i dati relativi ai robot.

## Variabili globali

| Variabile | Descrizione |
|---|---|
| `rX[]` | coordinate X |
| `rY[]` | coordinate Y |
| `rHP[]` | punti vita |
| `rStato[]` | stato del robot |
| `rSimbolo[]` | carattere identificativo |
| `rInvincibile[]` | stato invincibilità |

## Inizializzazione robot

I robot vengono posizionati casualmente:

```c
x = 1 + rand() % (RIGHE - 2);
y = 1 + rand() % (COLONNE - 2);
```

Il ciclo `do-while` impedisce sovrapposizioni tra robot.

## Conta robot vivi

La funzione:

```c
int contaRobotVivi()
```

restituisce il numero di robot ancora attivi.

---

# Modulo `ia.c`

È il modulo più importante del progetto perché implementa la logica dell’intelligenza artificiale.

---

# Calcolo distanza

La funzione:

```c
int distanza(int x1, int y1, int x2, int y2)
```

calcola la distanza Manhattan tra due robot.

Formula utilizzata:

```text
d = |x1 - x2| + |y1 - y2|
```

Questa distanza è adatta ai movimenti su griglia.

---

# Ricerca del nemico

La funzione:

```c
trovaNemico(int i)
```

scorre tutti i robot vivi e seleziona il più vicino.

## Algoritmo utilizzato

1. inizializza distanza minima
2. controlla ogni robot
3. calcola la distanza
4. salva il robot più vicino

Complessità:

```text
O(n)
```

dove `n` rappresenta il numero di robot.

---

# Movimento dei robot

Il robot si muove verso il nemico riducendo progressivamente la distanza.

Esempio:

```c
if(rX[nemico] < rX[i]) {
    nx--;
}
```

Il movimento avviene:
- solo su celle libere
- senza attraversare muri
- senza sovrapporsi ad altri robot

---

# Sistema di combattimento

Quando due robot sono adiacenti:

```c
if(d == 1)
```

il robot attacca il nemico.

## Danno

```c
rHP[nemico] -= 10;
```

Ogni attacco infligge 10 HP di danno.

## Eliminazione

Quando gli HP raggiungono 0:
- il robot viene disattivato
- la cella torna libera
- il simbolo viene rimosso dalla mappa

---

# Modulo `rendering.c`

Gestisce la visualizzazione tramite ncurses.

## Rendering della mappa

Ogni cella viene stampata usando:

```c
mvaddch(i, j, mappa[i][j]);
```

## Visualizzazione HP

La schermata laterale mostra:
- simbolo del robot
- punti vita residui

---

# Aspetti di programmazione utilizzati

## Programmazione modulare

Il progetto utilizza:
- file `.c`
- file `.h`
- dichiarazioni `extern`

Questo approccio migliora:
- organizzazione
- riutilizzo
- manutenzione

---

# Utilizzo delle librerie

## Libreria standard C

| Libreria | Utilizzo |
|---|---|
| `stdlib.h` | numeri casuali |
| `time.h` | seed random |
| `math.h` | valore assoluto |
| `unistd.h` | delay simulazione |

## Libreria ncurses

Permette:
- aggiornamento dinamico del terminale
- controllo cursore
- rendering grafico testuale

---

# Gestione della memoria

Il progetto utilizza memoria statica tramite array globali.

### Vantaggi
- semplicità
- velocità
- assenza di malloc/free

### Svantaggi
- dimensione fissa
- minore scalabilità

---

# Possibili miglioramenti

## Miglioramenti IA

- pathfinding avanzato
- algoritmi A*
- comportamenti differenti

## Gameplay

- ostacoli
- proiettili
- squadre
- armi diverse
- power-up

## Ottimizzazione

- eliminazione variabili globali
- utilizzo di `struct Robot`
- threading
- gestione eventi

---

# Diagramma logico del programma

```text
+----------------+
|   main.c          |
+----------------+
        |
        v
+----------------+
|    inizializza()   |
+----------------+
        |
        v
+----------------+
|   ciclo partita   |
+----------------+
        |
   +----+----+
   |         |
   v         v
+------+  +--------+
|   IA  |  |    Render  |
+------+  +--------+
   |
   v
+--------+
|   Combat  |
+--------+
```

---

# Compilazione

Per compilare il progetto:

```bash
make
```

Oppure manualmente:

```bash
gcc *.c -lncurses -o cyberarena
```

---

# Esecuzione

```bash
./cyberarena
```

---

# Conclusioni

Il progetto Cyber-Arena dimostra l’utilizzo combinato di:
- programmazione modulare in C
- gestione matrici bidimensionali
- algoritmi base di intelligenza artificiale
- rendering grafico tramite ncurses

La simulazione risulta dinamica, scalabile e facilmente estendibile con nuove funzionalità.

Il progetto rappresenta un ottimo esempio pratico di:
- gestione di entità autonome
- simulazione real-time
- organizzazione software multi-file
- sviluppo terminal-based in linguaggio C
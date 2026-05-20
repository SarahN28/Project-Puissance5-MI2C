#ifndef P5FUNCTION_H
#define P5FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p5types.h"

/* selection des joueurs */
int constructPlayer (Player pl[3]);

/* initialisation grill */
void createGrid(int tab[NBLIN][NBCOL], int nbl, int nbc);

/* affichage grille */
void printGame(Game nwGame, int nbl, int nbc);

/* sauvegarde grille */
void saveGrid (int gridIn[NBLIN][NBCOL], int gridOut[NBLIN][NBCOL]) ;
 
/* calcul nombre de cases pour le coté du pivot */
int sizePiv();

/* saisie de la colonne pour insertion du jeton */
int selectCol();

/* gravite du jeton insérer */
int fall(int tab[NBLIN][NBCOL], int nbJ, int numcol);

/* selection pivot */
pivot selectPiv(int n, int line, int col);

/* selection type de rotation */
int askRotation();

/* rotation horaire */
void Clockwise(int tab[NBLIN][NBCOL], int n, pivot p);

/* rotation anti-horaire */
void counterClock(int tab[NBLIN][NBCOL], int n, pivot p) ;

/* gravite sur carré pivoté */
void gravityPivot(int tab[NBLIN][NBCOL], pivot pi, int nbc);

/* verif si gagnant */
int endGame(int tab[NBLIN][NBCOL], Player resP[3]);

/* sauvegarde du jeu */
int saveGame(Game sgame, FILE *fic);

#endif

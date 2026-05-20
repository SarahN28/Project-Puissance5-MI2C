#ifndef P5TYPES_H
#define P5TYPES_H

#define NBLIN 6
#define NBCOL 8

typedef struct {
  int line;
  int col;
} pivot;

typedef struct {
  int numPlayer;
  char namePlayer[11];
  int Win;
} Player;

// les données du jeu : sont mises dans une structure pour pourvoir sauvegarder dans un fichier binaire, et les récupérer facilement
typedef struct {
  int nbPlayer;
  int noPlayer;                           //prochain joueur à jouer
  Player pl[3];
  int grid[NBLIN][NBCOL];
} Game;

#endif

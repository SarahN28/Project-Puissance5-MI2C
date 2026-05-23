# CY-CONNECT

### ***Projet-semestre2 - PréIng1***
## **Bienvenue dans notre programme**

## Sommaire
1. [Description du projet](#description-du-projet)
2. [Règles du jeu](#règles-du-jeu)
3. [Structure](#structure)
4. [Installation](#installation)
5. [Utilisation](#utilisation)
6. [Auteurs](#auteurs)

## Description du projet 
Ce projet consiste à créer un jeu en langage C inspiré du Puissance 4, nommé **CY Connect**. 
Le jeu se joue sur une grille de **6 lignes et 8 colonnes** et peut accueillir **2 ou 3 joueurs**. L’objectif est d’aligner **5 jetons identiques** horizontalement, verticalement ou en diagonale afin de remporter la partie.

## Règles du jeu
Le jeu se déroule sur une grille de **6 lignes et 8 colonnes**.  
Chaque joueur joue à tour de rôle.

### Conditions de victoire
Un joueur gagne lorsqu’il aligne **5 jetons identiques** :
- horizontalement ;
- verticalement ;
- diagonalement.

Il est possible que plusieurs joueurs gagnent en même temps.

### Cases spéciales
Au début de la partie, quatre blocs sont placés au coin de la grille. Ces cases sont indestructibles et sont représentés par ###. De plus : 

- Elles ne sont pas soumises à la gravité ; 
- Elles empêchent les pièces d’accéder aux cases inférieures ; 
- Elles peuvent cependant être déplacées lors des rotations. 

### Mécanisme spécial : 
Tout au long du jeu, après que le joueur a placé sa pièce, un mécanisme de rotation est activé. 

- La taille de la zone a tourné est annoncé avant le tour d’un joueur. Elle varie entre un carré de 3x3 cases et un carré de 5x5 cases. 
- Après avoir posé sa pièce, le joueur choisi un pivot qui agira comme centre du carré de rotation ainsi qu’un sens de rotation (horaire ou anti-horaire). 
ATTENTION : La pièce qui vient d’être posé doit faire partie du carré. 
- Par la suite, la zone choisie subit la rotation et les pièces concernées retombent par la gravité. 

### Déroulement d’un tour
1. La taille de la zone de rotation est annoncée. 
2. Le joueur choisit une colonne pour insérer son jeton. 
3. Le jeton tombe automatiquement sous l’effet de la gravité jusqu’à atteindre une position libre. 
4. Le joueur choisi ensuite un pivot et un sens de rotation. 
5. La zone sélectionnée pivote de 90° dans le sens choisi. 
6. Après cela, la gravité est appliquée une nouvelle fois aux jetons présents dans la zone pivotée. 
7. Fin de tour : 
   - S'il y a un gagnant, la fin de jeu est annoncée. 
   - Sinon, c’est au tour du joueur suivant. 

### Fin de partie

La partie se termine : 
   - Lorsqu’un joueur réussit un alignement de 5 jetons ; 
   - Ou, lorsqu’il n’est plus possible de jouer : 
      - La grille est entièrement remplie. 

## Structure
 - **`p5types.h`** : définit les constantes et structures ( Player, Game , pivot)
 - **`p5main.c`** : contient la fonction main()
 - **`p5function.c`** : contient toutes les fonctions du jeu
 - **`p5function.h`** : contient les prototypes des fonctions
 - **`Makefile`** : permet de compiler automatiquement


## Installation

### Prérequis

Pour compiler et exécuter le projet, il faut :
- un compilateur C (GCC) ;
- Make ;

### Compilation

Ouvrir un terminal dans le dossier du projet puis exécuter :
```bash
make
```
Nettoyage : 
```bash
make clean
```
Supprimer l’exécutable du projet :
```bash
make fclean
```
Nettoyer puis recompiler entièrement le projet :
```bash
make re
```

## Utilisation
### Lancer le jeu

Après la compilation, exécuter le programme avec :

```bash
./Puissance5
```
### Au lancement, le joueur peut :

- commencer une nouvelle partie ;
- reprendre une sauvegarde existante.

### Commandes disponibles

- 2 : partie à 2 joueurs ;
- 3 : partie à 3 joueurs ;
- Q : quitter le programme ;
- 99 : quitter la partie avec sauvegarde possible.

## Auteurs   
- **Sarah NGO** - SarahN28  
- **Jenshika JEKUMAR** - jenshij05  
- **Yukie YOSHIOKA** - yukie06

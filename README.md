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
### Déroulement d’un tour
1. Une taille de zone de rotation est choisie aléatoirement :
   - soit **3×3** ;
   - soit **5×5**.

2. Le joueur choisit une colonne pour insérer son jeton.

3. Le jeton tombe automatiquement sous l’effet de la gravité jusqu’à atteindre une position libre.

4. Le joueur doit ensuite choisir un pivot situé dans une zone contenant le jeton qu’il vient d’insérer.

5. Le joueur choisit le sens de rotation :
   - horaire ;
   - anti-horaire.

6. La zone sélectionnée pivote de **90°**.

7. Après la rotation, la gravité est appliquée une nouvelle fois aux jetons présents dans la zone pivotée.

### Conditions de victoire
Un joueur gagne lorsqu’il aligne **5 jetons identiques** :
- horizontalement ;
- verticalement ;
- diagonalement.

Il est possible que plusieurs joueurs gagnent en même temps.

### Cases spéciales

Les quatre coins de la grille contiennent des blocs indestructibles représentés par `###` :
- ils ne tombent pas ;
- ils bloquent les jetons ;
- ils peuvent être déplacés lors des rotations.

### Fin de partie

La partie se termine :
- lorsqu’un joueur réussit un alignement de 5 jetons ;
- ou lorsque la grille est entièrement remplie.

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

### Pendant la partie :

- les joueurs jouent chacun leur tour ;
- un jeton est inséré dans une colonne ;
- une zone du plateau est pivotée ;
- le programme vérifie les conditions de victoire.

### Commandes disponibles

- 2 : partie à 2 joueurs ;
- 3 : partie à 3 joueurs ;
- Q : quitter le programme ;
- 99 : quitter la partie avec sauvegarde possible.

## Auteurs   
- **Sarah NGO** - SarahN28  
- **Jenshika JEKUMAR** - jenshij05  
- **Yukie YOSHIOKA** - yukie06

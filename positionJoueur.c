void placement(int k, Pivot place){  //numéro du joueur, penser à changer les cases qui bougent pas de 1 à 4!!!
  int col = 87;
  int vide = 56;
  while (vide!=0){
    printf ("Choisir un numéro de colonne.");  //demander à joueur colonne pour placer jeton
    scanf ("%d", &col);
    col--;
    place.colonne = col;
    if (tab[0][col])!=0){  //vérifier que tab [0][j] vide
     printf ("Cette case n'est pas disponible. Choisir une autre case.");  //si non afficher erreur et recommencer
     vide = 1;
    }
    else{
     tab[0][col] = k;  //si oui placer jeton
     vide = 0;
     }
  }
}
void deplacement_bas(int tab[][8], int j, int nbJ){
  int k, tmp, i;             //k c'est la première case avec un espace disponible
  k=-1;                      //on initialise k à -1 pour éviter les erreurs
  i=5;
  while(i>=0){                     //i s'arrête quand i=-1, le parcours de la colonne est terminé
    if (tab[i][j]==0 && i>k){       //si case vide et i supérieur à l'indice de la case vide (n'arrive que au départ ou si il y a un block)
      k = i;                       //k prend la valeur de la dernière case
     }
    else if (tab[i][j]==4){         //si il y a un block
      k = -1;                      //réinitialisation de la case dispo
    }
    else if (k>-1 && tab[i][j]>0 && tab[i][j]<nbJ+1){             //si il y a une case dispo et si c'est un joueur
      tmp = tab[i][j];                                            //échange des cases
      tab[i][j] = tab[k][j];
      tab[k][j] = tmp;
      i=k;                                                        //on repart de la case changée
      k=-1;                                                       //réinitialisation de la case dispo
    }
    i=i-1;                                                        //passage à la case du dessus
 }

void gravite(int tab[][8], int nbJ){
  for (int j=0; j<8; j++){                                        //répéter la fonction pour chaque colonne
    deplacement_bas(tab[][8], i, nbJ);
   }
 }
Pivot placePiece(int tab[][8], Pivot place){
  place.ligne = 99;
  for (int i=0; i<6; i++){
    if (tab[i][place.colonne]!=0 && tab[i][place.colonne]!=4){
      place.ligne=i;
      return place;
    }
  }
  if (place.ligne==99){
    printf("erreur 44\n");
    exit();
  }
}

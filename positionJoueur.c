void placement(int k, Pivot place){  //numéro du joueur, penser à changer les cases qui bougent pas de 1 à 4!!!
  int col = 87;
  int vide = 56;
  while (vide!=0){
    printf ("Choisir un numéro de colonne.");  //demander à joueur colonne pour placer jeton
    scanf ("%d", &col);
    col--;
    place.colonne = colonne;
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

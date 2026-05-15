 // insertion  pion d un joueur nbJ en colonne c numcol
int deplacement_bas(int tab[][numCol], int nbJ, int numcol){
  int i;
  i=0;
  while(tab[i][numcol]==0 && i<6){
    i = i+1;
  }
  // i contient la première ligne non vide (arrêt car !=0)
  if (i==0) { return(-1);} // la colonne est pleine : insertion du jeton impossible
  tab[i-1][numcol] = nbJ;
  return(i-1);
 }

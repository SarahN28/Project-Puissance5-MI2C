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

int constructPlayer (Player pl[3]){
  int n = 0;
  int j;
  char carlu, c1;
  do{
     printf("Veuillez choisir le mode du jeu ! \n");
     printf("  2 : 2 joueurs | 3 : 3 joueurs |  Q : pour sortir \n");
     scanf("%c", &c1);
     carlu = c1;
     while (carlu !='\n') {
      carlu = getchar();                                      //verif que l'utilisateur n'a mis qu'un nombre
     }
     if (c1!='2' && c1!='3' && c1!='q' && c1!='Q') {
       printf("Erreur : Le nombre de joueur est incorrect\n");                   //verif que le nombre donne est prenable
     }
  } while (c1!='2' && c1!='3' && c1!='q' && c1!='Q');
  if (c1=='q' || c1=='Q') {
    return 99;
   }
  n = c1-'0';
  for(int i=0; i<n; i++) {
   pl[i].numPlayer = i+1;
   pl[i].Win = 0;
   carlu = ' ';
   j=0;
   do {
     if (carlu=='\n'){
       printf("erreur de saisie\n");
     }
     printf("Entrez le nom du joueur %d et tapez sur la touche Entrée \n", i+1);
     scanf("%c", &carlu);
   } while (carlu=='\n');
   pl[i].namePlayer[j] = carlu;
   j++;
   while (carlu !='\n') {
     scanf("%c", &carlu);
     if (j < 10 && carlu != '\n') {
       pl[i].namePlayer[j] = carlu;
       j++;
     }
   }
   while (j<10) {
     pl[i].namePlayer[j] = ' ';
     j++;
   }
   pl[i].namePlayer[10] = '\0';
  }
  return n;
 }

 void createGrid(int tab[NBLIN][NBCOL], int nbl, int nbc){
  for (int i=0; i<nbl; i++){
    for(int j=0; j<nbc; j++) {
      tab[i][j] = 0;
    }
  }
  tab[0][0]=1;                //carré sur L1 C1
  tab[0][nbc-1]=1;                //carré sur L1 C8
  tab[nbl-1][0]=1;                //carré sur L6 C1
  tab[nbl-1][nbc-1]=1;                //carré sur L6 C8
}

void printGame(Game nwGame, int nbl, int nbc){
  int k;
  printf("-\n");
  printf("    1   2   3   4   5   6   7   8\n");
  for (int i=0; i<nbl; i++){ 
    printf ("%d ", i+1);
    for (int j=0; j<nbc; j++){
      if(nwGame.grid[i][j]==0){
        printf("|   ");
       }
      else if(nwGame.grid[i][j]==1){
        printf("|###");
       }
      else if(nwGame.grid[i][j]==2){
        printf("| ");
        printf("\033[94m¤ \033[00m");
       }
      else if(nwGame.grid[i][j]==3){
        printf("| ");
        printf("\033[95m& \033[00m");
       }
      else if(nwGame.grid[i][j]==4){
        printf("| ");
        printf("\033[92m¥ \033[00m");
       }
     }
    printf("| \n");
    printf("  ");
    for (k = 0; k<nbc; k++) {
    printf("----");
    }  
    printf("-\n");
   }
 }

void saveGrid (int gridIn[NBLIN][NBCOL], int gridOut[NBLIN][NBCOL]) {
for(int i=0; i< NBLIN; i++) {
  for(int j=0; j<NBCOL; j++) {
    gridOut[i][j]=gridIn[i][j];
  }
 }
}

int sizePiv(){
  int piv;
  piv = rand()%2;
  if(piv==0){
    piv = 3;
  }
  else {
    piv = 5;
  }
printf("Le carré pivotant a une largeur de %d cases \n", piv);
return piv;
}

// saisie de la colonne ou 99 pour sortir du jeu
 int selectCol() {
   int n=0;
   char carlu;
    do{
     printf("Entrez le numéro de colonne pour insérer votre jeton, ou 99 pour sortir : \n");
     scanf("%d", &n);
     carlu = getchar();
     while (carlu != '\n') {
       carlu = getchar();
     }
     if (n<1 || (n>8 && n!=99)) {
       printf("Erreur :  le numéro de colonne est incorrecte\n");
     }
  } while (n<1 || (n>8 && n!=99));
  if (n!=99) {
    return (n-1);
  }
  else {
    return n;
  } 
 }

int fall(int tab[NBLIN][NBCOL], int nbJ, int numcol){                          // insert piece in column 'numcol'
  int i = 0;
  while (tab[i][numcol]==0 && i<6){
    i = i+1;                                                                // 2 if first player, 3 if second player, etc...
   }
  if (i==0) {
    printf(" ERREUR ! Insertion impossible\n");
    return (-1);          // insertion impossible, column full
  } 
  tab[i-1][numcol] = nbJ;               //nbJ : number of player
  return (i-1);
 }

pivot selectPiv(int n, int line, int col) {               // line = i-1 de deplacement et col = numcol = n de selectCol
  int i=0, j=0;
  int lineMin, lineMax, colMin, colMax;
  pivot c;
  char carlu;
  printf("Votre nouveau jeton est en l%d, c%d \n", line+1, col+1);
  lineMin = line-n;
  lineMax = line+n;
  colMin = col-n;
  colMax = col+n;  
  if ((lineMin-n) < 0) {
    lineMin = n;
   }
  if ((lineMax+n) > (NBLIN-1) ) {
    lineMax = (NBLIN-1) - n;
   }
  if ((colMin-n) < 0) {
    colMin = n;
   }
  if ((colMax + n) > (NBCOL-1) ) {
    colMax = (NBCOL-1) - n;
  }
  while (j<(colMin+1) || (j>(colMax+1) && j!=99)){                                         // la ligne affichée est à +1 de l'indice
    if((j<(colMin+1) && j!=0) || (j>(colMax+1) && j!=99)) {
      printf("erreur de saisie : \n");
    }
    printf("Choisir la colonne du pivot : comprise entre %d et %d ou 99 pour sortir du jeu\n", colMin+1, colMax+1);
    scanf("%d", &j);
    carlu = getchar();
    while (carlu != '\n') {
      carlu = getchar();
    }
  }   
  if (j!=99) {
    while (i<(lineMin+1) || i>(lineMax+1)) {
      if((i<(lineMin+1) && i!=0) || (i>(lineMax+1))) {
        printf("erreur de saisie : \n");
      }
      printf("Choisir la ligne du pivot : comprise entre %d et %d \n", lineMin+1, lineMax+1);
      scanf("%d", &i);
      carlu = getchar();
      while (carlu != '\n') {
        carlu = getchar();
      }
    }
    printf("Votre pivot est en l%d, c%d \n", i, j);
    i--;
    j--;
  }
  else {
    i = 99;
   } 
  c.line = i;
  c.col = j;
  return c;
 }

int askRotation(){
  int select = 0;
  char carlu;
  carlu = ' ';
  while(select!=1 && select!=2) {
    if(select!=1 && select!=2 && select!=0){
      printf("erreur de saisie : \n");
    }
    printf("Choisir un sens de rotation :\n");
    printf("   1 : Horaire  |  2 : Anti-Horaire\n");
    scanf("%d", &select);
    carlu = getchar();                                      // pour supprimer les caractères restants au cas où...
    while (carlu != '\n') {
      carlu = getchar();
     }
   }
  if(select == 1){
    printf(" Activation de la rotation Horaire\n");
   }
  else {
    printf(" Activation de la rotation Anti-Horaire\n");
   }
  return select;
 }

void Clockwise(int tab[NBLIN][NBCOL], int n, pivot p) {
  int i, j, k, k2;
  int t[5][5];                                                                                             //definir en constante
  k2 = 0;
  for (i=0; i<5; i++) {                                                                      // initialisation table intermédiaire
    for (j=0; j<5; j++) {
      t[i][j] = 0;
    }
   }
  for(i=(p.line+n); i>=(p.line-n); i--) {                          // remplissage table intermédiaire avec nouvelle valeur suite à rotation
    k = 0;
    for(j=(p.col-n); j<=(p.col+n); j++) {
      t[k][k2] = tab[i][j];
      k++;
     }
    k2++;
   }
  k = 0; 
  for(i=(p.line-n); i<=(p.line+n); i++) {
    k2 = 0;
    for(j=(p.col-n); j<=(p.col+n); j++) {
      tab[i][j] = t[k][k2];
      k2++;
     }
    k++;
   }
}

void counterClock(int tab[NBLIN][NBCOL], int n, pivot p) {
  int i,j,k, k2;
  int t[5][5];
  for (i=0; i<5; i++) {
    for (j=0; j<5; j++) {
      t[i][j] = 0;
     }
   }
  k2 = 2*n;                                                         // remplissage table intermédiaire avec nouvelle valeur
  for(i=(p.line+n); i>=(p.line-n); i--) {
    k = 2*n;
    for(j=(p.col-n); j<=(p.col+n); j++) {
      t[k][k2] = tab[i][j];
      k--;
     }
    k2--;
   }
  k = 0;                                            // nouvelles valeur à mettre dans la grid : substitution par celle de t renseignée
  for(i=(p.line-n); i<=(p.line+n); i++) {
    k2 = 0;
    for(j=(p.col-n); j<=(p.col+n); j++) {
      tab[i][j] = t[k][k2];
      k2++;
     }
    k++;
   }
}

void gravityPivot(int tab[NBLIN][NBCOL], pivot pi, int nbc) {
  int t[NBLIN];
  int k;
  int i, j ;
  for(j=(pi.col-nbc); j<=(pi.col+nbc); j++){
    for(k=0; k<NBLIN; k++) {
      t[k] = 0;
     }
    k = 5;
    for(i=(NBLIN-1); i>=0; i--) {
      if (tab[i][j] != 0 && tab[i][j] != 1) {
        t[k] = tab[i][j];
        k--;
       }
      else if (tab[i][j] == 1) {
        t[i] = tab[i][j];
        k = i-1;
       }
     }
    for(i=0; i<NBLIN; i++) {
      tab[i][j]=t[i];
     }
   }
}

// fin = 1 : non terminée, fin = 0 : joueur(s) gagnant(s), fin = 2 : Partie Nulle
int endGame(int tab[NBLIN][NBCOL], Player resP[3]) {
  int i, j, k;
  int end = 1;
  for (i=0; i<NBLIN; i++) {                                                                         // verif gagnant en ligne
    for(j=0; j<=NBCOL-5; j++) {
      if (tab[i][j]==tab[i][j+1] && tab[i][j]==tab[i][j+2] && tab[i][j]==tab[i][j+3] && tab[i][j]==tab[i][j+4] && tab[i][j] != 0) {
        k = tab[i][j] - 2;
        resP[k].Win = 1;
        printf("Gagnant en ligne %d \n", i+1);
        end = 0;
       }
     }
   }
  for (j=0; j<NBCOL; j++) {                                                                        // vérif gagnant en colonne : NON Testée
    for(i=0; i<=NBLIN-5; i++) {
      if (tab[i][j]==tab[i+1][j] && tab[i][j]==tab[i+2][j] && tab[i][j]==tab[i+3][j] && tab[i][j]==tab[i+4][j]  && tab[i][j] != 0) {
        k = tab[i][j] - 2;
        resP[k].Win = 1;
        printf("Gagnant en colonne %d \n", j+1);
        end = 0;
       }
     }
   }
  for(i=0; i<=(NBLIN-5); i++) {                                                                            // verif gagnant en diagonale /
    for(j=(NBCOL-1); j>=(NBCOL-5); j--) {
      if (tab[i][j]==tab[i+1][j-1] && tab[i][j]==tab[i+2][j-2] && tab[i][j]==tab[i+3][j-3] && tab[i][j]==tab[i+4][j-4] && tab[i][j]!=0){
        k = tab[i][j] - 2;
        resP[k].Win = 1;
        printf("Gagnant en diagnonale %d \n", i+1);
        end = 0;
       }
     }
   }
  for(i=0; i<=(NBLIN-5); i++) {                                                                    // verif gagnant en diagonale inversée
    for(j=0; j<=NBCOL-5; j++) {
      if (tab[i][j]==tab[i+1][j+1] && tab[i][j]==tab[i+2][j+2] && tab[i][j]==tab[i+3][j+3] && tab[i][j]==tab[i+4][j+4] && tab[i][j]!=0){
        k = tab[i][j] - 2;
        resP[k].Win = 1;
        printf("Gagnant en diagonale inversée %d \n", i+1);
        end = 0;
       }
     }
   }
  if (end==1) {                                                                         // verif si partie NULLE
    end = 2;
    for(j=0; j<NBCOL; j++) {
      if(tab[0][j]==0) {
        end = 1;
       }
     }
   }
  return end;
}

int saveGame(Game sgame, FILE *fic){
  int save = 0;
  fic = fopen("SauvP5.txt", "wb+") ;
  if (fic!=NULL) {
    save = fwrite(&sgame, sizeof(Game), 1, fic);
    save = fclose(fic);
   }
   return save;
 }


// programme principal
int main () {
 int nwline, nbpivot, nbcase, ret;
 int numerocol = 0;
 int endMatch = 1;
 int retF = 0;
 int sGrid[NBLIN][NBCOL];
 char carlu;
 char reprise = ' ';
 char topinit = '0';
 pivot piv;
 Game nwGame;
 FILE *f = NULL;
 srand(time(NULL));
   
 f = fopen("SauvP5.txt", "rb") ;
 if(f!= NULL) {                                                                                                      // verification si sauvegarde du jeu existe
  while(reprise != 'o' && reprise != 'O' && reprise != 'n' && reprise != 'N') {
    do {
      if (reprise == '\n'){
        printf("erreur de saisie 2\n");
      }
      printf("Voulez vous reprendre l'ancienne partie ? O pour Oui, N pour Non \n");
      scanf("%c", &reprise);
    } while (reprise == '\n');
    carlu = getchar();
    while (carlu != '\n') {
      carlu = getchar();
     }
   }
  if (reprise=='o' || reprise == 'O') {                                                                    // initialisation jeu avec sauvegarde
    retF = fread(&nwGame, sizeof(Game), 1, f);
    if (retF!=1) {
      printf("Dernier jeu introuvable, vous allez commencer une nouvelle partie \n");
     }
    else{
      topinit = '1';
     }
   }
  retF = fclose(f);
  retF = remove("SauvP5.txt");
 }
if (topinit != '1') {
  nwGame.nbPlayer=constructPlayer(nwGame.pl);
  if (nwGame.nbPlayer == 99) {
    return 0;
  }                                                               //endMatch
  createGrid(nwGame.grid, NBLIN, NBCOL);
  nwGame.noPlayer = 0; 
}

printGame(nwGame, NBLIN, NBCOL);
while(endMatch == 1) {                                                                                  // a faire tant que partie non terminée
  saveGrid(nwGame.grid, sGrid);
  printf("Au tour du joueur %s \n", nwGame.pl[nwGame.noPlayer].namePlayer);
  nwline = -1;
   // calcul largeur carré à pivoter
  nbpivot = sizePiv();
  nbcase = nbpivot/2;
  while(nwline==-1) {                                                                                       //insertion du jeton du nv joueur
    // demander la colonne où insérer le jeton ou 99 pour sortir
    numerocol = selectCol(nwGame.noPlayer); 
    if (numerocol == 99) {
      endMatch = 2;
      reprise = ' ';
      do {
        printf("Voulez vous sauvegarder la partie ? O pour Oui, N pour Non \n");
        scanf("%c", &reprise);
        if(reprise == 'o' || reprise == 'O') { 
          saveGrid(sGrid, nwGame.grid);
          ret=saveGame(nwGame, f);
          return 0;
        }
        else if (reprise == 'n' || reprise == 'N'){
          return 0;
         }
      } while ((reprise!='o' && reprise!='O' && reprise!='n' && reprise!='N') || (reprise == '\n'));
      carlu = getchar();
      while (carlu != '\n') {
        carlu = getchar();
       }
    }
    nwline= fall(nwGame.grid, nwGame.noPlayer+2, numerocol);                  // insertion du jeton : valeur jeton = indice  du joueur + 2
   }                                                                                        // fin insertion du jeton : le nouveau pion sera en nwline, numerocol
  printGame(nwGame, NBLIN, NBCOL);
  piv = selectPiv(nbcase, nwline, numerocol);                                               // demande position du pivot
  if (piv.line==99) {
    endMatch = 2;
    reprise = ' ';
    while(reprise != 'o' && reprise != 'O' && reprise != 'n' && reprise != 'N') {
        printf("Voulez vous sauvegarder la partie ? O pour Oui, N pour Non \n");
        scanf("%c", &reprise);
        carlu = reprise;
        while (carlu != '\n') {
         scanf("%c", &carlu);
        }
    }
    if(reprise == 'o' || reprise == 'O') { 
        saveGrid(sGrid, nwGame.grid);
        ret=saveGame(nwGame, f);
    }
    return 0;
   }
  if (askRotation()==1 ) {                                                            // demande du type de rotation
   Clockwise(nwGame.grid, nbcase, piv);
   }
  else {
    counterClock(nwGame.grid, nbcase, piv);
   }
  printGame(nwGame, NBLIN, NBCOL);
  gravityPivot(nwGame.grid, piv, nbcase);                                                 // gravity suite à la rotation
  printGame(nwGame, NBLIN, NBCOL);
  endMatch = endGame(nwGame.grid, nwGame.pl);                                              // si endMatch = 2 => Terminée pas de gagnant, si = 0 : gagnant
  if (nwGame.noPlayer >= nwGame.nbPlayer-1) {                                            // calcul du nouveau joueur qui doit jouer
    nwGame.noPlayer = 0;
   }
   else {
     nwGame.noPlayer =  nwGame.noPlayer+1;
    }
}                                                                                         //fin de partie
if (endMatch == 2) {                                                                      // affichage résultat 
  printf("La partie est terminée, SANS gagnant \n");
 }
 else {
   for (int i=0; i<3; i++) {
     if (nwGame.pl[i].Win == 1) {
       printf("BRAVO au joueur %s, vous avez gagné\n", nwGame.pl[i].namePlayer);
      }
    }
  }
return 0;
}

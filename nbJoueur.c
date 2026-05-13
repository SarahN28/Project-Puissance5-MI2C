int nbJoueur(){
  int n = 0;
  printf("Nombre de joueurs:\n");
  printf("2 : 2joueurs       3 : 3joueurs\n");
  scanf("%d", &n);
  if (n==2 || n==3){
    printf("Mode : %d joueurs\n", n);
   }
  else {
    printf("Erreur 0\n");
    constructJoueur();
  }
  return n; 
 }

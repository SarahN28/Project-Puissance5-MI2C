void printGame(int tab[6][8]){
  for (int j=0; j<6; j++){
    for (int i=0; i<8; i++){
      if(tab[i][j]==0){
        printf("|  ");
       }
      else if(tab[i][j]==4){
        printf("|##");
       }
      else if(tab[i][j]==1){
        printf("|()");
       }
      else if(tab[i][j]==2){
        printf("|><");
       }
      else if(tab[i][j]==3){
        printf("|¤¤");
       }
     }
    printf("| \n");
   }
 }

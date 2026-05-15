 int verification(int tab[6][8]){
   int i;
   int j;
   int valeur;

 // horizontale
   for(i = 0; i < 6; i++){
     for(j = 0; j < 8 ; j++){
     valeur = tab[i][j];
//on verifie que la case contient un pion
       if(valeur>1){
//on verifie qu'il reste 4 cases à droite
         if(j+4 < 8){
//on compare les 5 cases
           if(tab[i][j+1] == valeur && tab[i][j+2] == valeur && tab[i][j+3] == valeur && tab[i][j+4] == valeur){
             return valeur;    //le joueur gagne
           }
         }
      
//verticale 
//on verifie qu'il reste 4 cases en bas
          if(j+4 < 6){
            if(tab[i+1][j] == valeur && tab[i+2][j] == valeur && tab[i+3][j] == valeur && tab[i+4][j] == valeur){
             return valeur;   //le joueur gagne
            }
         }
  
//diagonale droite
//on verifie qu'il reste 4 cases en bas à droite
         if(i+4 < 6 && j+4 < 8){
           if(tab[i+1][j+1] == valeur && tab[i+2][j+2] == valeur && tab[i+3][j+3] == valeur && tab[i+4][j+4] == valeur){
            return valeur;   //le joueur gagne
           }
         }

//diagonale gauche
//on verifie qu'il reste 4 cases en bas à gauche
         if(i+4 < 6 && j-4 >= 0){
           if(tab[i+1][j-1] == valeur && tab[i+2][j-2] == valeur && tab[i+3][j-3] == valeur && tab[i+4][j-4] == valeur){
             return valeur;
           }
         }
       }
     }
   }
   return 0  //aucun victoire
}

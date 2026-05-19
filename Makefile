EXEC = CYFighter

#Sources à compiler
SRC = 

#Règle par défaut : compile et execute
all: $(EXEC)
     ./$(EXEC)

#Compilation du programme
$(EXEC): $(SRC) fichier.h affichage.h couleurs.h
  gcc -Wall -o $(EXEC) $(SRC)

#Nettoyage des fichiers compilés
clean:
  rm -f $(EXEC)

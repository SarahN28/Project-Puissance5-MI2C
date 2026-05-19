EXEC = CYConnect

#Sources à compiler
SRC = Main.c

#Règle par défaut : compile et execute
all: $(EXEC)

#Compilation du programme
$(EXEC): $(SRC) Fonctions.h bibli.h const.h struct.h
  gcc -Wall -o $(EXEC) $(SRC)

#Nettoyage des fichiers compilés
clean:
  rm -f $(EXEC)

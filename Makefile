# ============================================================
#  Makefile — CY-Puissance5
# ============================================================

# --- Compilateur et options ---
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -pedantic -std=c99 -g
LDFLAGS =

# --- Répertoires ---
SRCDIR  = src
OBJDIR  = obj
BINDIR  = .

# --- Cible finale ---
TARGET  = $(BINDIR)/cy_puissance5

# --- Sources et objets ---
SRCS    = $(wildcard $(SRCDIR)/*.c)
OBJS    = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# ============================================================
#  Règles
# ============================================================

.PHONY: all clean fclean re run valgrind help

## Compilation complète (cible par défaut)
all: $(OBJDIR) $(TARGET)

## Création du répertoire obj si absent
$(OBJDIR):
	mkdir -p $(OBJDIR)

## Édition des liens
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo ""
	@echo "  ✔  Compilation réussie → $(TARGET)"
	@echo ""

## Compilation de chaque fichier source
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/game.h
	$(CC) $(CFLAGS) -c $< -o $@

## Supprime les fichiers objets
clean:
	rm -rf $(OBJDIR)
	@echo "  ✔  Objets supprimés."

## Supprime les objets ET le binaire
fclean: clean
	rm -f $(TARGET)
	@echo "  ✔  Binaire supprimé."

## Recompilation complète
re: fclean all

## Lance le jeu directement
run: all
	./$(TARGET)

## Lance le jeu sous Valgrind (détection de fuites mémoire)
valgrind: all
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

## Affiche l'aide
help:
	@echo ""
	@echo "  Cibles disponibles :"
	@echo "    make          — compile le projet"
	@echo "    make run      — compile et lance le jeu"
	@echo "    make clean    — supprime les objets"
	@echo "    make fclean   — supprime objets + binaire"
	@echo "    make re       — recompilation complète"
	@echo "    make valgrind — lance sous Valgrind"
	@echo ""

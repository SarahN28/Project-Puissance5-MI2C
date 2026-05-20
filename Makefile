# ============================================================
#  Makefile — Puissance5
#  Compilation de tous les modules du projet
# ============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude
TARGET  = Puissance5

# Fichiers sources et objets
SRCS    = p5main.c \
          p5function.c 

OBJS    = $(SRCS:.c=.o)

# ---- Règle principale ----------------------------------------
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# ---- Compilation de chaque .c en .o --------------------------
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---- Nettoyage -----------------------------------------------
clean:
	rm -f src/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -g

# Archivos de código fuente y de encabezado
SRC = main.c datos.c auth.c logIn.c menu.c
OBJ = $(SRC:.c=.o)
TARGET = main

# Regla principal para compilar el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lm

# Compilar archivos .c en archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos de compilación
clean:
	rm -f $(OBJ) $(TARGET)

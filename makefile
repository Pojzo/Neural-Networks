CC=gcc
CLAGS=-Wall -std=c99
DEPS=layer.h functions.h
OBJ=main.o layer.o functions.o matrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

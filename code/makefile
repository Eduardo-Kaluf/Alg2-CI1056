# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -Wextra -g -std=c99 # flags de compilacao
CC = gcc

all: main.o utils.o menu.o algorithms.o statistics.o
	$(CC) -o main main.o utils.o menu.o algorithms.o statistics.o -lm

algorithms.o: algorithms.c algorithms.h
	$(CC) -c $(CFLAGS) algorithms.c

menu.o: menu.c menu.h
	$(CC) -c $(CFLAGS) menu.c

utils.o: utils.c utils.h
	$(CC) -c $(CFLAGS) utils.c

statistics.o: statistics.c statistics.h
	$(CC) -c $(CFLAGS) statistics.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c


clean:
	rm -f *.o *~ main
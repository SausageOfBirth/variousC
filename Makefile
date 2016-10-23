CC=gcc
CFLAGS=-std=c99 -I.
DOCS=main.c room.c inventory.c utils.c

all: main.c numString.c
	$(CC) -o main $(DOCS) $(CFLAGS)

clean:
	rm -f *.o *.out main

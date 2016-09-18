CC=gcc
CFLAGS=-I.
DOCS=main.c numString.c inventory.c

all: main.c numString.c
	$(CC) -o main $(DOCS) $(CFLAGS)

clean:
	rm -f *.o *.out main
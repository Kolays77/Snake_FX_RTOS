CC=gcc
CFLAGS= -Wall

all:
	$(CC) $(CFLAGS) table.c main.c game.c ascii_gui.c -o snake 
clean:
	rm -rf *.o snake	
CC=gcc
CFLAGS= -Wall

all:
	$(CC) $(CFLAGS) snake.c main.c game.c -o snake 
clean:
	rm -rf *.o snake	
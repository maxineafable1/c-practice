CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11

output: main.o
	$(CC) main.o -o output

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o output
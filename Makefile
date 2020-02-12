CC = gcc
CFlags = -Wall -g

main: main.o

main.o: main.c

clean:
	rm -f main *.o

CC = gcc
CFLAGS = -lncurses

run: presentation.o
	./presentation.o

%.o: %.c
	$(CC) $< $(CFLAGS) -o$@

clean:
	rm *.o

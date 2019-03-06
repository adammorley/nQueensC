CC=clang
CFLAGS=-I. -g
DEPS=../log/log.c ../stack/stack.c

all: test

clean:
	rm -f test *.o

test: test.c nQueens.c
	$(CC) -o test test.c nQueens.c $(DEPS) $(CFLAGS)

# Makefile for CS152 lab8 Winter 2020

.PHONY : clean

htbl: htbl.[hc] bucket.c main.c
	clang -lm -g -Wall -o htbl bucket.c htbl.c main.c

clean:
	rm -rf htbl *.dSYM

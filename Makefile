
all: TreeDr

TreeDr: TreeDr.o
	g++ -Wall -g -o TreeDr TreeDr.o

TreeDr.o: TreeDr.cpp TreeType.h QueType.h
	g++ -Wall -std=c++14 -c -O0 -pedantic-errors TreeDr.cpp



clean:
	rm -f TreeDr
	rm -f TreeDr.o
	rm -f TreeType.o
	rm -f QueType.o

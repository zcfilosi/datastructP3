all: TreeDr

TreeDr: TreeDr.o TreeType.o QueType.o
	g++ -Wall -g -o TreeDr TreeDr.o

TreeDr.o: TreeDr.cpp TreeType.h
	g++ -Wall -std=c++14 -c -O0 -pedantic-errors TreeDr.cpp

TreeType.o: TreeType.cpp TreeType.h
	g++ -Wall -std=c++14 -c -O0 -pedantic-errors TreeType.cpp

QueType.o: QueType.cpp QueType.h
	g++ -Wall -std=c++14 -c -O0 -pedantic-errors QueType.cpp

clean:
	rm -f TreeDr
	rm -f TreeDr.o
	rm -f TreeType.o
	rm -f QueType.o
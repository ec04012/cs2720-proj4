
link: QueType TreeType TreeDr.cpp
	g++ -Wall -g -pedantic-errors -o p4 QueType.o TreeType.o TreeDr.cpp

TreeType: TreeDr.cpp TreeType.h
	g++ -c -Wall -g -pedantic-errors TreeType.cpp

QueType: QueType.cpp QueType.h
	g++ -c -Wall -g -pedantic-errors QueType.cpp

run:
	./p4

clean:
	/bin/rm *.o p4
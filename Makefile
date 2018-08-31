CFLAGS=-std=c++11 -ggdb

OBJECTS=main.o dfa.o

union.x: $(OBJECTS)
	g++ $(CLAGS) $(OBJECTS) -o union.x

dfa.o: dfa.hpp dfa.cpp
	g++ $(CFLAGS) -c dfa.cpp -o dfa.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o
clean:
	rm -fr *~ $(OBJECTS) make.x

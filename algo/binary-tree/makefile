all: main

CXXFLAGS = -std=c++11

main: main.o 
	g++ -o main main.o

main.o: main.cpp
	g++ ${CXXFLAGS} -c main.cpp

clean:
	rm -f *.o main

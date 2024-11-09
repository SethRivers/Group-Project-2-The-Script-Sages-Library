CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o Library.o
	$(CXX) $(CXXFLAGS) -o main main.o Library.o

main.o: main.cpp Library.h Book.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Library.o: Library.cpp Library.h Book.h
	$(CXX) $(CXXFLAGS) -c Library.cpp

clean:
	rm -f *.o main

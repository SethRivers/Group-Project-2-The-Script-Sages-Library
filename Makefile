 # /
 # @file Makefile
 # @author Script Sages
 # @date 2024-10-23
 # @brief Description: The Makefile for the Simple Steganography assignment. Compiles the main, book, and
 # Library files together so that they can be used.
 #
 #
 #
 #
 # /

CXX = g++
CXXFLAGS = -Wall -std=c++11

LIBRARY_SRC = Library.cpp
BOOK_SRC = Book.cpp
MAIN_SRC = main.cpp

OBJECTS = Library.o Book.o main.o
EXECUTABLE = card

# Build executable from object files
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compile library source files to object files
Library.o: Library.cpp Library.h
	$(CXX) $(CXXFLAGS) -c Library.cpp

# Compile book source files to object files
Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c Book.cpp

# Compile main source files to object files
main.o: main.cpp Library.h Book.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) *~

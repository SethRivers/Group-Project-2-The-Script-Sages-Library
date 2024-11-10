CXX = g++
CXXFLAGS = -Wall -std=c++11

LIBRARY_SRC = library.cpp
BOOK_SRC = book.cpp
MAIN_SRC = main.cpp

OBJECTS = library.o book.o main.o
EXECUTABLE = library_app

# Build executable from object files
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compile library source files to object files
library.o: library.cpp library.h
	$(CXX) $(CXXFLAGS) -c library.cpp

# Compile book source files to object files
book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c book.cpp

# Compile main source files to object files
main.o: main.cpp library.h book.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)



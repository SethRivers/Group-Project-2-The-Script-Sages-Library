 # /
 # @file Makefile
 # @author Script Sages
 # @date 2024-10-23
 # @brief Description: The Makefile for the Simple Steganography assignment. Compiles the main and
 # steganography files together so that they can be used.
 #
 #
 #
 #
 # /

#Defines the compiler
CC = g++

#Compile with all errors and warnings
CFLAGS = -g -Wall -Wextra -c

#Links the .o files together and creates an executable
TARGET = steg

#Readies $(TARGET) for use in the following code
all: $(TARGET)

#Marks all the files that will be compiled
$(TARGET):	main.o library.o
		$(CC) main.o library.o -o $(TARGET)

#Compiles the main.cpp file with the .h file
main.o: 	main.cpp library.h
		$(CC) $(CFLAGS) main.cpp

#Compiles the Steganography.cpp/.h files
library.o: 	library.h library.cpp
		$(CC) $(CFLAGS) library.cpp

#Cleans out any unnecaary items post compiling.
clean:
		$(RM) *.o *~ LibraryCard

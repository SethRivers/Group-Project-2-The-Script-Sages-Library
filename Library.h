/**
 * @file library.h
 * @author Script Sages
 * @date 2024-10-23
 * @brief This is the .h file for the library. Essentially the library's library that initializes the functions and objects used to run the system. 
 * 
 * 
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <list>
#include <string>
using namespace std;

// Library class declaration
// Manages a collection of Book objects stored in a list
class Library {
private:
  list<Book> books; // A list of Book objects to store the library's books

public:
  // Method declarations
  void insertSorted(const Book& book);
  void findAuthor(const string& author) const;
  void findAlbum(const string& title) const;
  void deleteBook(const string& author, const string& title);
  void pushFront(const Book& book);  // Declare pushFront here
  void pushBack(const Book& book);   // Declare pushBack here
  void loadFromFile(const string& filename);
  void saveToFile(const string& filename) const;
  void displayAllBooks() const;
};

#endif

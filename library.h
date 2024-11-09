/**
 * @file library.h
 * @author Script Sages
 * @date 2024-10-23
 * @brief This is the .h file for the library. Essentially the library's library that initializes the functions and objects used to run the system. 
 * 
 * 
 */

#ifndef LIBRARY_h
#DEFINE LIBRARY.H

#include "Book.h"
#include <list>
#include <string>

class Library {
 public:
  //loads books from a file
  void loadFromFile(const std::string& filename);

  //Saves books to a file
  void saveToFile(const std::string& filename);

  //Adds a book in sorted order by author name
  void insertSorted(const Book& book);

  //Finds books by author
  void findAuthor(const std::string& author) const;

  //Finds books by title
  void findBook(const std::string& author, const std::string& title);

  //Displays all books
  void displayBooks() const;

private:
  std::List<Books> books;
};

#endif

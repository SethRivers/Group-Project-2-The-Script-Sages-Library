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

/**
 * The library class manages a collection of books stored within a list. 
 *
 * @class Library Library.h "Group-Project-2-The-Script-Sages-Library/Library.h"
 * @brief 
 *
 */
class Library {
private:
  list<Book> books; // A list of Book objects to store the library's books

public:
  // Method declarations

/**
 * The insert sorted function sorts incoming data and places it within the list as necesary
 *
 * @param const Book& book the book list it will be interacting with
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void insertSorted(const Book& book);


/**
 * The find author function locates all the books within the list that were written by a specific individual.
 *
 * @param const string& author the item holding their name
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void findAuthor(const string& author) const;


/**
 * locates a book and displays its data when prompted its name by a user
 *
 * @param const string& title the book's title
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void findAlbum(const string& title) const;

/**
 * removes a book from the list 
 *
 * @param const string& author the author's name
 * @param const string& title the book's name
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void deleteBook(const string& author, const string& title);

/**
 * creates and pushes a new book's data to the front of the list
 *
 * @param const Book& book the book list
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pushFront(const Book& book);  // Declare pushFront here

/**
 * creates and pushes a new book's data to the back of the list
 *
 * @param const Book& book the book list
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pushBack(const Book& book);   // Declare pushBack here

/**
 * Loads booklist data in from a txt file
 *
 * @param const string& filename the name of the file that will be read
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void loadFromFile(const string& filename);

/**
 * saves data from the book list onto a file; whether existing or created by this member
 *
 * @param const string& filename the name of the file to save to
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void saveToFile(const string& filename) const;

/**
 * displays all of the boosk within the book list
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void displayAllBooks() const;
};

#endif

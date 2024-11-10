#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;


/**
 * This is the primary class where the book data is initialized and constructed, allowing for a smoother display of data
 *
 * @class Book Book.h "Group-Project-2-The-Script-Sages-Library/Book.h"
 * @brief 
 *
 */
class Book {
private:
  string title;
  string authorName;
  int pages;
  string isbn;
  float coverPrice;
  int year;

public:
  // Constructor

/**
 * main constructor of the Book class; readying its data for use within the program. 
 */
  Book(string t, string a, int p, string i, float cp, int y);

  

/**
 * a set of getter members, with an additional purpose of exiistence for access of the above private parameters
 * 
 */
  string getTitle() const;
  string getAuthorName() const;
  int getPages() const;
  string getIsbn() const;
  float getCoverPrice() const;
  int getYear() const;

  // Display function

/**
 * the print function for the book class. Displays the data of whatever book requested of it
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void displayBook() const;
};

#endif

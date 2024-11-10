/**
 * @file Book.h
 * @author Seth Rivers
 * @date 2024-11-09
 * @brief this is the seperated .h file for the Book struct. 
 * 
 * 
 */

#ifndef BOOK_H
#define BOOK_H

#include <string>


/**
 * This struct readies the necesary data for storing a book's title, its author's name, the number of pages it has, its isbn-10, its cover price, and finally its publishing year. 
 *
 * @class Book Book.h "Group-Project-2-The-Script-Sages-Library/Book.h"
 * @brief 
 *
 */
struct Book {
  std::string title;
  std::string authorName;
  int pages;
  std::string isbn;
  float coverPrice;
  short year;

  // Constructor to initialize the Book
  Book(std::string t, std::string a, int p, std::string i, float c, short y)
//  : title(t), authorName(a), pages(p), isbn(i), coverPrice(c), year(y) {}*/
};

#endif // BOOK_H

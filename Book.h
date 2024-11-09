#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
  std::string title;
  std::string authorName;
  int pages;
  std::string isbn;
  float coverPrice;
  short year;
  Book* next; 

  // Constructor to initialize the Book
  Book(std::string t, std::string a, int p, std::string i, float c, short y);
  // : title(t), authorName(a), pages(p), isbn(i), coverPrice(c), year(y) {}
};

#endif // BOOK_H

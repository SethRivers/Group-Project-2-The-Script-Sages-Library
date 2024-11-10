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
#include <string>
#include <list>
#include "Book.h"
class Library
{
private: 
  std::list<Book> Book_List; //Declares the Linked list.
  Book * midpoint;
  int number_of_books;
  std::list<Book>::iterator it;

public:
  Library();

  void push_back(std::string New_Title, std::string New_Author_Name, int New_Pages, std::string New_isbn, float New_Price, int New_Year);

  void push_front(std::string New_Title, std::string New_Author_Name, int New_Pages, std::string New_isbn, float New_Price, int New_Year);

  void load_from_file(std::string filename);

  void store_to_file(const std::string filename);
  
  void insert_sorted(std::string Sort_Title, std::string Sort_Author_Name, int Sort_Pages, std::string Sort_isbn, float Sort_Price, int Sort_Year);

  void Insert_Sort();

  void findBook(const std::string &title);

  void findAuthor(const std::string &author);

  void deleteBook(const std::string &author, const std::string &title);

  void print(const Book &book);

  void print_all(); 
  ~Library();

};


#endif //LIBRARY_H

/**
 * @file library.cpp
 * @author Script Sages
 * @date 2024-10-23
 * @brief The cpp file for the library. Acts as the guts and what happens behind the scenes
 * 
 * 
 */


#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Book.h"
#include "Library.h"


using namespace std;



Library::Library()
{
  midpoint = NULL;
  number_of_books = 0;
  Book_List = {}; //creates our list which should be empty of Nodes/Movies.
}
Library::~Library()
{
  midpoint = NULL;
  number_of_books = 0;
}

void Library::load_from_file(string filename)
{
  Book temp;
  ifstream File(filename);

  while(getline(File, temp.title))
    {
      getline(File, temp.authorName);
      File >> temp.pages >> temp.isbn >> temp.coverPrice >> temp.year;
      Book_List.push_back(temp);
      File.ignore();
      File.ignore();
      number_of_books++;
    }

}
void Library::print_all(){
  if(Book_List.empty())
  {
    cout << "No books in the library.\n";
    return;
  }
  for (const Book &book : Book_List) {
      print(book);
    }
}

void Library::print(const Book &book){ 
      std::cout << "Title: " << book.title << "\n"
		<< "Author: " << book.authorName << "\n"
		<< "Pages: " << book.pages << "\n"
		<< "ISBN: " << book.isbn << "\n"
		<< "Price: $" << std::fixed << std::setprecision(2) << book.coverPrice << "\n"
		<< "Year: " << book.year << "\n"
		<< "--------------------------\n";
    
  }
void Library::insert_sorted(const std::string &book)
{
  auto it = Book_List.begin();
  while (it != Book_List.end() && it->authorName < book.authorName) {
    ++it;
  }
  Book_List.insert(it, book);
}

void Library::deleteBook(const std::string &author, const std::string &title){ 
  auto it = Book_List.begin();
  while (it != Book_List.end()) {
    if (it->authorName == author && it->title == title) {
      Book_List.erase(it);
      cout << "Book deleted: " << title << " by " << author << "\n";
      return;
    }
    ++it;
  }
  cout << "No matching book found for deletion.\n";
}

  void Library::push_back(std::string New_title, std::string New_authorName, int New_pages, std::string New_isbn, float New_coverPrice, int New_year)
  {
    Book temp;
    temp.title = New_title;
    temp.authorName = New_authorName;
    temp.pages = New_pages;
    temp.isbn = New_isbn;
    temp.coverPrice = New_coverPrice;
    temp.year = New_year;
    Book_List.push_back(temp);
    number_of_books++;
  }
  void Library::push_front(std::string New_title, std::string New_authorName, int New_pages, std::string New_isbn, float New_coverPrice, int New_year)
  {
    Book temp;
    temp.title = New_title;
    temp.authorName = New_authorName;
    temp.pages = New_pages;
    temp.isbn = New_isbn;
    temp.coverPrice = New_coverPrice;
    temp.year = New_year;
    Book_List.push_front(temp);
    number_of_books++;
  }

void Library::findBook(const std::string &title)
  {
    bool found = false;
    for (const Book &book : Book_List) {
      if (book.title == title) {
	print(book);
	found = true;
      }
    }
    if (!found) {
      cout << "No book found with title: " << title << "\n";
    }

  }

  void Library::findAuthor(const std::string &author)
  {
    bool found = false;
    for (const Book &book : Book_List) {
      if (book.authorName == author) {
	print(book);
	found = true;
      }
    }
    if (!found) {
      std::cout << "No books found by author: " << author << "\n";
    }
  }

void Library::store_to_file(const std::string filename)
    {
      if(filename == "")
	{
	  cout << "Please enter a file name to write to: " << endl;
	  return;
	}
      ofstream File(filename);
      it = Book_List.begin();
      while(it != Book_List.end())
	{
	  File << (it -> title) << '\n' << (it -> authorName) << '\n' << (it -> isbn) << '\n' << (it -> pages) << '\n' << (it -> year) << '\n' << (it -> coverPrice) << '\n' << '\n';
	  it++;
	}
    }

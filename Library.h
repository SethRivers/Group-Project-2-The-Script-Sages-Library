// Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <list>
#include <fstream>
#include <iostream>

class Library {
private:
    std::list<Book> books;  // A list to store books

public:
    // Method to load books from a file
    void loadBooksFromFile(const std::string &filename);

    // Method to save books to a file
    void saveBooksToFile(const std::string &filename);

    // Insert a book into the list in sorted order (by author's name)
    void insertSorted(const Book &book);

    // Find and display all books by a specific author
    void findAuthor(const std::string &author);

    // Find and display a book by its title
    void findTitle(const std::string &title);

    // Delete a book by author and title
    void deleteBook(const std::string &author, const std::string &title);

    // Display all books in the library
    void displayAllBooks();

    // Method to display a book
    void displayBook(const Book &book);
};

#endif // LIBRARY_H



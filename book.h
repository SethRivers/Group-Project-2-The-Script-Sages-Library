/**
 * @file book.h
 * @author Bodey Lassiter
 * @date 2024-11-09
 * @This file defines the Book class, which represents a book in the library. It contains attributes like title, author, pages, ISBN, cover price, and year, along with methods for accessing these attributes and displaying the book's details. 
 * 
 * 
 */





#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

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
    Book(string t, string a, int p, string i, float cp, int y);

    // Getters and Setters
    string getTitle() const;
    string getAuthorName() const;
    int getPages() const;
    string getIsbn() const;
    float getCoverPrice() const;
    int getYear() const;

    // Display function
    void displayBook() const;
};

#endif




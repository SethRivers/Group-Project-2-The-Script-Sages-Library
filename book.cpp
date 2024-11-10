/**
 * @file book.cpp
 * @author Bodey Lassiter
 * @date 2024-11-09
 * @This file defines the Book class with a constructor to initialize a book's attributes and getter methods to access details like the title, author, pages, ISBN, cover price, and year. The displayBook() method prints all these details to the console. 
 * 
 * 
 */


#include "book.h"
#include <iostream>
using namespace std;

//Constructor for the Book class
Book::Book(string t, string a, int p, string i, float cp, int y)
    : title(t), authorName(a), pages(p), isbn(i), coverPrice(cp), year(y) {}

//Returns title of the book.
string Book::getTitle() const { return title; }
//Returns the name of the author of the book
string Book::getAuthorName() const { return authorName; }
//Returns the number of pages in the book
int Book::getPages() const { return pages; }
//Returns the ISBN number of the book
string Book::getIsbn() const { return isbn; }
//Returns the cover price of the book
float Book::getCoverPrice() const { return coverPrice; }
//Returns the year the book was published
int Book::getYear() const { return year; }

//Outputs the book's details to the console, including title, author, page count, ISBN, cover price, and year
void Book::displayBook() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << authorName << endl;
    cout << "Pages: " << pages << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Cover Price: $" << coverPrice << endl;
    cout << "Year: " << year << endl;
}

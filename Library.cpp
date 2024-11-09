// Library.cpp
#include "Library.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

// Method to load books from a file
void Library::loadBooksFromFile(const std::string& filename) {
     std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        std::istringstream stream(line);
        std::string title, author, isbn;
        int pages, year;
        float price;

        // Read title (remove quotes)
        std::getline(stream, title, '"');  // Skip first quote
        std::getline(stream, title, '"');  // Get title inside quotes

        // Read author (remove quotes)
        std::getline(stream, author, '"');  // Skip first quote
        std::getline(stream, author, '"');  // Get author inside quotes

        // Read remaining fields
        stream >> pages >> isbn >> price >> year;

        // If any fields are missing, continue to the next line (skip invalid entries)
        if (title.empty() || author.empty() || pages <= 0 || isbn.empty() || price <= 0 || year <= 0) {
            continue;
        }

        // Add the book to the list
        books.push_back(Book(title, author, pages, isbn, price, year));
    }
}
// Method to save books to a file
void Library::saveBooksToFile(const std::string &filename) {
    std::ofstream outfile(filename);
    for (const Book &book : books) {
        outfile << book.title << "\n" << book.authorName << "\n"
                << book.pages << "\n" << book.isbn << "\n"
                << std::fixed << std::setprecision(2) << book.coverPrice << "\n"
                << book.year << "\n";
    }
    outfile.close();
}

// Insert a book into the list in sorted order by author's name
void Library::insertSorted(const Book &book) {
    auto it = books.begin();
    while (it != books.end() && it->authorName < book.authorName) {
        ++it;
    }
    books.insert(it, book);
}

// Find and display all books by a specific author
void Library::findAuthor(const std::string &author) {
    bool found = false;
    for (const Book &book : books) {
        if (book.authorName == author) {
            displayBook(book);
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found by author: " << author << "\n";
    }
}

// Find and display a book by its title
void Library::findTitle(const std::string &title) {
    bool found = false;
    for (const Book &book : books) {
        if (book.title == title) {
            displayBook(book);
            found = true;
        }
    }
    if (!found) {
        std::cout << "No book found with title: " << title << "\n";
    }
}

// Delete a book by author and title
void Library::deleteBook(const std::string &author, const std::string &title) {
    auto it = books.begin();
    while (it != books.end()) {
        if (it->authorName == author && it->title == title) {
            books.erase(it);
            std::cout << "Book deleted: " << title << " by " << author << "\n";
            return;
        }
        ++it;
    }
    std::cout << "No matching book found for deletion.\n";
}

// Display all books in the library
void Library::displayAllBooks() {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    for (const Book &book : books) {
        displayBook(book);
    }
}

// Display a single book
void Library::displayBook(const Book &book) {
    std::cout << "Title: " << book.title << "\n"
              << "Author: " << book.authorName << "\n"
              << "Pages: " << book.pages << "\n"
              << "ISBN: " << book.isbn << "\n"
              << "Price: $" << std::fixed << std::setprecision(2) << book.coverPrice << "\n"
              << "Year: " << book.year << "\n"
              << "--------------------------\n";
}











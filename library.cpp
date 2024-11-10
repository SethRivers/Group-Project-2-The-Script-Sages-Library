#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

// Inserts a book into the library in alphabetical order by author's name
void Library::insertSorted(const Book& book) {
    // Finds the correct position to insert the book to keep list sorted by author name
    auto it = books.begin();
    while (it != books.end() && it->getAuthorName() < book.getAuthorName()) {
        ++it;
    }
    books.insert(it, book);  // Inserts the book at the found position
}

// Searches for books by a specific author and displays them
void Library::findAuthor(const string& author) const {
    bool found = false;  // Tracks if any books are found
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getAuthorName() == author) {  // Checks if book's author matches
            it->displayBook();  // Displays the book details if there's a match
            found = true;
        }
    }
    if (!found) {  // If no books are found, display a message
        cout << "No books found by author: " << author << endl;
    }
}

// Searches for a book by its title and displays it
void Library::findAlbum(const string& title) const {
    bool found = false;  // Tracks if the book is found
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {  // Checks if book's title matches
            it->displayBook();  // Displays book details if there's a match
            found = true;
        }
    }
    if (!found) {  // If no book is found, display a message
        cout << "No books found with title: " << title << endl;
    }
}

// Deletes a book by matching both author and title
void Library::deleteBook(const string& author, const string& title) {
    auto it = books.begin();
    while (it != books.end()) {
        if (it->getAuthorName() == author && it->getTitle() == title) {
            it = books.erase(it);  // Erases the book and updates the iterator
        } else {
            ++it;  // Move to the next book if no match
        }
    }
}

// Adds a book to the front of the library list
void Library::pushFront(const Book& book) {
    books.push_front(book);
}

// Adds a book to the back of the library list
void Library::pushBack(const Book& book) {
    books.push_back(book);
}

// Loads books from a file, creating Book objects and inserting them in sorted order
void Library::loadFromFile(const string& filename) {
    ifstream file(filename);  // Opens the file for reading
    if (!file.is_open()) {    // Checks if file was opened successfully
        cout << "Error opening file." << endl;
        return;
    }

    string title, author, isbn;
    int pages, year;
    float price;

    // Reads each book's data from the file line by line and constructs Book objects
    while (getline(file, title)) {
        getline(file, author);
        file >> pages >> isbn >> price >> year;
        file.ignore(); // Skips the newline after reading the year

        Book book(title, author, pages, isbn, price, year);  // Constructs a Book object
        insertSorted(book);  // Inserts the book in sorted order
    }

    file.close();  // Closes the file after reading all books
}

// Saves all books in the library to a file
void Library::saveToFile(const string& filename) const {
    ofstream file(filename);  // Opens the file for writing
    for (auto it = books.begin(); it != books.end(); ++it) {
        // Writes each book's data to the file line by line
        file << it->getTitle() << endl;
        file << it->getAuthorName() << endl;
        file << it->getPages() << endl;
        file << it->getIsbn() << endl;
        file << it->getCoverPrice() << endl;
        file << it->getYear() << endl;
    }
}

// Displays all books in the library
void Library::displayAllBooks() const {
    if (books.empty()) {  // Checks if there are any books in the library
        cout << "No books available in the library." << endl;
        return;
    }
    for (auto it = books.begin(); it != books.end(); ++it) {
        it->displayBook();  // Displays each book
        cout << "------------------------" << endl;  // Separator for readability
    }
}



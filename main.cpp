/**
 * @file main.cpp
 * @author Script Sagesxc
 * @date 2024-10-23
 * @brief The main driver of the library assignment. Allowing access to the contents and creating a UI interface for users
 * 
 * 
 */


#include <iostream>
#include <fstream>
#include "Library.h"
using namespace std;


int main() {
  Library library;  // Creates a Library object to manage books
  string filename;

  // Prompts the user to enter a filename to load an existing library
  cout << "Enter the filename to load the library from: ";
  getline(cin, filename);
  library.loadFromFile(filename);  // Loads books from the specified file

  int choice;  // Variable to store user's menu choice
  do {
    // Display menu options to the user
    cout << "Library Menu:" << endl;
    cout << "1. Display all books" << endl;
    cout << "2. Find books by author" << endl;
    cout << "3. Find books by title" << endl;
    cout << "4. Add a book (sorted)" << endl;
    cout << "5. Delete a book" << endl;
    cout << "6. Add and Push book to front" << endl;
    cout << "7. Add and Push book to back" << endl;
    cout << "8. Save and exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // Clears newline character from input
    cout << "------------------------" << endl; 
    switch (choice) {
    case 1:
      // Displays all books in the library
      library.displayAllBooks();
      break;

    case 2: {
      // Finds and displays books by a specific author
      string author;
      cout << "Enter author name: ";
      getline(cin, author);
      library.findAuthor(author);
      break;
    }

    case 3: {
      // Finds and displays a book by title
      string title;
      cout << "Enter book title: ";
      getline(cin, title);
      library.findAlbum(title);
      cout << "------------------------" << endl;
      break;
    }

    case 4: {
      // Adds a new book to the library, sorting it by author
      string title, author, isbn;
      int pages, year;
      float price;
      cout << "Enter book title: ";
      getline(cin, title);
      cout << "Enter author name: ";
      getline(cin, author);
      cout << "Enter number of pages: ";
      cin >> pages;
      cin.ignore();
      cout << "Enter ISBN: ";
      getline(cin, isbn);
      cout << "Enter cover price: ";
      cin >> price;
      cout << "Enter year: ";
      cin >> year;
      cin.ignore();

      // Creates a Book object and inserts it in sorted order
      Book book(title, author, pages, isbn, price, year);
      library.insertSorted(book);
      cout << "------------------------" << endl;
      break;
    }

    case 5: {
      // Deletes a book by matching the author and title
      string author, title;
      cout << "Enter author name: ";
      getline(cin, author);
      cout << "Enter book title: ";
      getline(cin, title);
      library.deleteBook(author, title);
      cout << "------------------------" << endl;
      break;
    }

    case 6: {
      // Adds a new book to the front of the library's list
      string title, author, isbn;
      int pages, year;
      float price;
      cout << "Enter book title: ";
      getline(cin, title);
      cout << "Enter author name: ";
      getline(cin, author);
      cout << "Enter number of pages: ";
      cin >> pages;
      cin.ignore();
      cout << "Enter ISBN: ";
      getline(cin, isbn);
      cout << "Enter cover price: ";
      cin >> price;
      cout << "Enter year: ";
      cin >> year;
      cin.ignore();

      // Creates a Book object and pushes it to the front of the list
      Book book(title, author, pages, isbn, price, year);
      library.pushFront(book);
      cout << "------------------------" << endl;
      break;
    }

    case 7: {
      // Adds a new book to the back of the library's list
      string title, author, isbn;
      int pages, year;
      float price;
      cout << "Enter book title: ";
      getline(cin, title);
      cout << "Enter author name: ";
      getline(cin, author);
      cout << "Enter number of pages: ";
      cin >> pages;
      cin.ignore();
      cout << "Enter ISBN: ";
      getline(cin, isbn);
      cout << "Enter cover price: ";
      cin >> price;
      cout << "Enter year: ";
      cin >> year;
      cin.ignore();

      // Creates a Book object and pushes it to the back of the list
      Book book(title, author, pages, isbn, price, year);
      library.pushBack(book);
      cout << "------------------------" << endl;
      break;
    }

    case 8: {
      // Prompts the user to save the library to a file, with overwrite check
      bool fileSaved = false;
      while (!fileSaved) {
	cout << "Enter the filename to save the library to (e.g., books.txt): ";
	getline(cin, filename);

	// Check if the file already exists
	ifstream fileCheck(filename);
	if (fileCheck) {
	  // If file exists, ask for permission to overwrite
	  cout << "File already exists. Overwrite? (y/n): ";
	  char overwrite;
	  cin >> overwrite;
	  cin.ignore();
	  if (tolower(overwrite) == 'y') {
	    library.saveToFile(filename);  // Saves the library
	    cout << "Library saved to " << filename << "!" << endl;
	    fileSaved = true;
	  }
	} else {
	  // File does not exist, save directly
	  library.saveToFile(filename);
	  cout << "Library saved to " << filename << "!" << endl;
	  fileSaved = true;
	}
      }
      break;
    }

    default:
      // Displays a message for an invalid menu choice
      cout << "Invalid choice." << endl;
    }
  } while (choice != 8);  // Loops until the user chooses to save and exit

  return 0;  // End of program
}

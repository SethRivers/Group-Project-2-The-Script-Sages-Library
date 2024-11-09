/**
 * @file main.cpp
 * @author Script Sagesxc
 * @date 2024-10-23
 * @brief The main driver of the library assignment. Allowing access to the contents and creating a UI interface for users
 * 
 * 
 */


#include "Library.h"
#include <iostream>

using namespace std;

void displayMenu() {
  cout << "\nLibrary Menu:\n"
	    << "1. Add Book\n"
	    << "2. Find Books by Author\n"
	    << "3. Find Book by Title\n"
	    << "4. Delete Book\n"
	    << "5. Display All Books\n"
	    << "6. Save Books to File\n"
	    << "7. Load Books from File\n"
	    << "8. Exit\n"
	    << "Enter your choice: ";
}

int main() {
  Library library;

  int choice;
  do {
    // Ask the user if they want to load data from a file initially
    cout << "Do you want to load data from a file? (y/n): ";
    char loadChoice;
    cin >> loadChoice;
    cin.ignore(); // Clear the newline character from the buffer

    if (loadChoice == 'y' || loadChoice == 'Y') {
      library.loadBooksFromFile("database.txt");
      cout << "Books loaded from file.\n";
    } else {
      cout << "Starting with an empty library.\n";
    }

    // Main loop for menu options
    do {
      displayMenu();
      cin >> choice;
      cin.clear();
      while (cin.get() != '\n') ;  // Clear the input buffer

      switch (choice) {
      case 1: {
	string title, author, isbn;
	int pages;
	float price;
	short year;

	cout << "Enter title: ";
	cin.ignore();
	getline(cin, title);
        cout << "Enter author: ";
	getline(cin, author);
	cout << "Enter number of pages: ";
	cin >> pages;
	cin.ignore(); // Clear newline
	cout << "Enter ISBN: ";
	getline(cin, isbn);
	cout << "Enter cover price: ";
	cin >> price;
	cin.ignore(); // Clear newline
	cout << "Enter year: ";
	cin >> year;
	cin.ignore(); // Clear newline

	library.insertSorted(Book(title, author, pages, isbn, price, year));
	break;
      }
      case 2: {
	string author;
	cout << "Enter author name: ";
	getline(cin, author);
	library.findAuthor(author);
	break;
      }
      case 3: {
	string title;
	cout << "Enter title: ";
	getline(cin, title);
	library.findTitle(title);
	break;
      }
      case 4: {
	string author, title;
	cout << "Enter author name: ";
	getline(cin, author);
	cout << "Enter title: ";
	getline(cin, title);
	library.deleteBook(author, title);
	break;
      }
      case 5:
	library.displayAllBooks();
	break;
      case 6:
	library.saveBooksToFile("database.txt");
	cout << "Books saved to file.\n";
	break;
      case 7:
	library.loadBooksFromFile("database.txt");
        cout << "Books loaded from file.\n";
	break;
      case 8:
	cout << "Exiting...\n";
	break;
      default:
	cout << "Invalid choice. Try again.\n";
      }
    } while (choice != 8);  // Exit when option 8 is chosen

  } while (choice != 8);

  return 0;
}

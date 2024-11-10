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
    int pages;
    float price;
    short year;
    string author, isbn, title, filename;

    // Ask the user if they want to load data from a file initially
    cout << "Do you want to load data from a file? (y/n): ";
    char loadChoice;
    cin >> loadChoice;
    cin.ignore(); // Clear the newline character from the buffer


    if (loadChoice == 'y' || loadChoice == 'Y') {
      cout << "What file would you like to load?(txt file please): ";
      cin >> filename;
      library.load_from_file(filename);
      cout << "\nBooks loaded from file.\n"
	   << "If you don't see anything when viewing books, there was likely a typo, the file was invalid, or the file was empty." << endl;
    } else {
      cout << "Starting with an empty library.\n";
    }


    // Main loop for menu options
    do {
      displayMenu();
      cin >> choice;
      cin.clear();
      while (cin.get() != '\n');  // Clear the input buffer
      // switch case for options
      switch (choice) {
	//
      case 1: {

	cout << "Enter title: ";
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

	cout << "--------------------------" << endl;
	library.insert_sorted(Book(title, author, pages, isbn, price, year));
	break;
      }
	//
      case 2: {
	cout << "Enter author name: ";
	getline(cin, author);
	cout << "--------------------------" << endl;
	library.findAuthor(author);
	break;
      }
	//
      case 3: {
	cout << "Enter title: ";
	getline(cin, title);
	cout << "--------------------------" << endl;
	library.findBook(title);
	break;
      }
      case 4: {
	cout << "Enter author name: ";
	getline(cin, author);
	cout << "Enter title: ";
	getline(cin, title);
	cout << "--------------------------" << endl;
	library.deleteBook(author, title);
	break;
      }
	//
      case 5:
	cout << "--------------------------" << endl;
	library.print_all();
	break;
	//
      case 6:
	cout << "--------------------------" << endl;
	cout << "What file would you like to save to?";
	cin >> filename;
	cout << "--------------------------" << endl;
	library.store_to_file(filename);
	cout << "Books saved to file.\n";
	break;
	//
      case 7:
	cout << "--------------------------" << endl;
	cout << "What file would you like to load?(txt file please): ";
	cin >> filename;
	cout << "--------------------------" << endl;
	library.load_from_file(filename);
	cout << "Books loaded from file.\n";
	break;
	//
      case 8:
	cout << "Exiting...\n";
	break;
      default:
	cout << "Invalid choice. Try again.\n";

      }

    } while (choice != 8);
  
  return 0;
}

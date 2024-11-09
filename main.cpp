// main.cpp
#include "Library.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nLibrary Menu:\n"
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
        std::cout << "Do you want to load data from a file? (y/n): ";
        char loadChoice;
        std::cin >> loadChoice;
        std::cin.ignore(); // Clear the newline character from the buffer

        if (loadChoice == 'y' || loadChoice == 'Y') {
            library.loadBooksFromFile("database.txt");
            std::cout << "Books loaded from file.\n";
        } else {
            std::cout << "Starting with an empty library.\n";
        }

        // Main loop for menu options
        do {
            displayMenu();
            std::cin >> choice;
            std::cin.clear();
            while (std::cin.get() != '\n') ;  // Clear the input buffer

            switch (choice) {
                case 1: {
                    std::string title, author, isbn;
                    int pages;
                    float price;
                    short year;

                    std::cout << "Enter title: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Enter author: ";
                    std::getline(std::cin, author);
                    std::cout << "Enter number of pages: ";
                    std::cin >> pages;
                    std::cin.ignore(); // Clear newline
                    std::cout << "Enter ISBN: ";
                    std::getline(std::cin, isbn);
                    std::cout << "Enter cover price: ";
                    std::cin >> price;
                    std::cin.ignore(); // Clear newline
                    std::cout << "Enter year: ";
                    std::cin >> year;
                    std::cin.ignore(); // Clear newline

                    library.insertSorted(Book(title, author, pages, isbn, price, year));
                    break;
                }
                case 2: {
                    std::string author;
                    std::cout << "Enter author name: ";
                    std::getline(std::cin, author);
                    library.findAuthor(author);
                    break;
                }
                case 3: {
                    std::string title;
                    std::cout << "Enter title: ";
                    std::getline(std::cin, title);
                    library.findTitle(title);
                    break;
                }
                case 4: {
                    std::string author, title;
                    std::cout << "Enter author name: ";
                    std::getline(std::cin, author);
                    std::cout << "Enter title: ";
                    std::getline(std::cin, title);
                    library.deleteBook(author, title);
                    break;
                }
                case 5:
                    library.displayAllBooks();
                    break;
                case 6:
                    library.saveBooksToFile("database.txt");
                    std::cout << "Books saved to file.\n";
                    break;
                case 7:
                    library.loadBooksFromFile("database.txt");
                    std::cout << "Books loaded from file.\n";
                    break;
                case 8:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 8);  // Exit when option 8 is chosen

    } while (choice != 8);

    return 0;
}



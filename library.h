/**
 * @file library.h
 * @author Script Sages
 * @date 2024-10-23
 * @brief This is the .h file for the library. Essentially the library's library that initializes the functions and objects used to run the system. 
 * 
 * 
 */

class Library {
 private:
  struct Book {
    std::string Title;
    std::string Author_Name;
    int Pages;
    std::string isbn;
    float Cover_Price;
    int Year;
  };
 

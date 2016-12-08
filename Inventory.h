//
// Created by Jack Banta on 11/8/2016.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "Book.h"
#include "LinkedList.h"
#include <fstream>


class Inventory {
private:

    //total number of books in stock
    int bookStock;

    //sorted linkedList of all books
    LinkedList* itemsInStock;


public:

    //constructor
    Inventory();

    //copy constructor needed because inventory holds onto array memory outside of the object
    Inventory(const Inventory& other);

    //Destructor
    ~Inventory();

    // assignment operator overload
    Inventory& operator=(const Inventory& inventoryToCopy);

    //searches through allBooksInStock and if the given book is found, returns all information associated with that book
    // findType is either "ISBN", "AUTHOR", "Title"
    // value is the associated search term for the chosen findType
    Book* findBook(std::string title);

    //returns the size of the object
    long calcSizeOf();

    // takes a pointer to a book object
    // adds the book to the inventory
    // links book being pointed to into inventory list
    void addNewBook(Book* bookToAdd);

    // takes parameters for creating a new book
    // adds the book to the inventory
    void addNewBook(std::string author, std::string title, std::string ISBN, double price, int haveValue, int wantValue);

    // takes a pointer to a book object
    // removes the book from the inventory
    void removeBook(Book* bookToRemove);

    // removes the book from the inventory by title
    void removeBook(std::string title);

    // returns the index of the book, returns -1 if book is not in inventory
    int findTitle(std::string title);

    // Lists the entire inventory alphabetically
    void list();

    // Prints out all the information on the specified book
    void inquire(std::string title);

    // Modify want value for title, display current want and have values
    void modify(std::string title);

    // Sets want value for specific title
    void setWant(std::string title, int newWant);

    // Sets have value for specific title
    void setHave(std::string title, int newHave);

    // Decreases the have value by 1, if doesn't exist, create book and add them to waitlist
    void sell(std::string title);

    // Gets current want value for book
    int currWant(std::string title);

    // Gets current have value for book
    int currHave(std::string title);

    // Create purchase order for books if want value is greater than have value
    void order(std::string file_name);

    // Books returned if have value is greater than want value
    void returnBooks(std::string file_name);

    // Reads in file and updates have/want values
    void delivery(std::string file_name);

};



#endif //INVENTORY_H
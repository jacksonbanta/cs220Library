//
// Created by Jack Banta on 11/8/2016.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "Book.h"
#include <fstream>


class Inventory {
private:

    //total number of books in stock
    int bookStock;

    //sorted linkedList of all books
    List* itemsInStock;


public:

    //constructor
    Inventory();

    //copy constructor needed because inventory holds onto array memory outside of the object
    Inventory(Inventory& other);

    //Destructor
    ~Inventory();

    // assignment operator overload
    Inventory& operator=(const Inventory& inventoryToCopy);

    //searches through allBooksInStock and if the given book is found, returns all information associated with that book
    // findType is either "ISBN", "AUTHOR", "Title"
    // value is the associated search term for the chosen findType
    Book findBook(std::string value, std::string findType);

    //returns the size of the object
    long calcSizeOf();

    // takes a pointer to a book object
    // adds the book to the inventory
    void addNewBook(Book* bookToAdd);

    // takes parameters for creating a new book
    // adds the book to the inventory
    void addNewBook(std::string author, std::string title, std::string ISBN, double price, int haveValue, int wantValue);

    // takes a pointer to a book object
    // removes the book from the inventory
    void removeBook(Book* bookToAdd);

};



#endif //INVENTORY_H

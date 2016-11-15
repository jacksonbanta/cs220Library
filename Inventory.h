//
// Created by Jack Banta on 11/8/2016.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdexcept>
#include <string>
#include "List.h"
template<class ItemType>

class Inventory {
private:

    //total number of books in stock
    int bookStock;

    //sorted linkedList of all books
    Book* allBooksInStock;


public:

    //constructor
    Inventory();

    //copy constructor needed because inventory holds onto array memory outside of the object
    Inventory(Inventory& other);

    //Destructor
    ~Inventory();

    //searches through allBooksInStock and if the given book is found, returns all information asscioated with that book
    itemType findBook(ItemType bookToFind);

    //returns the size of the object
    itemType calcSizeOf();

    void addNewBook(ItemType bookToAdd);

};




#endif //INVENTORY_H

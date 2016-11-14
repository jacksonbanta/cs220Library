//
// Created by Jack Banta on 11/8/2016.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdexcept>
#include <string>
#include "List.h"

class Inventory {
private:

    //total number of books in stock
    int bookStock;

    //sorted array of all books
    Book* allBooksInStock;


public:

    //constructor
    Inventory();

    //copy constructor needed because inventory holds onto array memory outside of the object
    Inventory();

    //Destructor
    ~Inventory();

    //returns title of book
    std::string getTitle();
    //returns author of book
    std::string getAuthor();

    //returns price of book
    int getPrice();
    //sets price of book
    void setPrice();

    //returns ISBN of book
    int getISBN();



    //returns the haveValue
    int getHaveValue();
    //sets the haveValue
    void setHaveValue();

    //gets the wantValue
    int getWantValue();
    //sets the wantValue
    void setWantValue();

    //returns the waitList
    std::string waitListToString();
    //clears the waitList
    void clearWaitList();
    //adds to the end of the waitList
    void addToWaitList(std::string personToAdd);
    //removes & returns first person on waitList
    std::string popOffWaitList();

    //returns the size of the object
    int calcSizeOf();

};




#endif //INVENTORY_H

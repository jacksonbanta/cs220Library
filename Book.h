//
// Created by Jack Banta on 11/8/2016.
//

#ifndef BOOK_H
#define BOOK_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "ArrayList.h"

class Book {
private:

    //title of the book
    std::string title;

    //author of the book
    std::string author;

    //price set by seller
    double price;

    //ISBN number used for categorizing
    std::string ISBN;

    //number of copies currently in stock
    int haveValue;

    //number of copies the seller would like
    int wantValue;

    //pointer to start of waitList array - this must be a queue //TODO: should we be using pointer syntax here and everywhere else?
    ArrayList<std::string> waitList; //TODO: should this be a pointer? If so is it deleted in destructor?


public:

    //constructor
    Book(std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue);

    //copy constructor - waitList is outside of our object
    Book(const Book& other);

    //Destructor
    ~Book();

    //overloading assignment operator
    Book& operator=(const Book &other);

    //returns title of book
    std::string getTitle();
    //returns author of book
    std::string getAuthor();

    //returns price of book
    double getPrice();
    //sets price of book
    void setPrice(double newPrice);

    //returns ISBN of book
    std::string getISBN();



    //returns the haveValue
    int getHaveValue();
    //sets the haveValue
    void setHaveValue(int newHaveValue);

    //gets the wantValue
    int getWantValue();
    //sets the wantValue
    void setWantValue(int newWantValue);

    //returns the waitList
    std::string waitListToString();

    //clears the waitList
    void clearWaitList();

    //adds to the end of the waitList
    void addToWaitList(std::string personToAdd);

    //removes & returns first person on waitList
    std::string popOffWaitList();

    //TODO: I think we may need a get waitlist function that returns
    //TODO: A copy of the waitlist (necessary for Inventory functions)

    //returns the size of the object
    int calcSizeOf();

};




#endif //BOOK_H

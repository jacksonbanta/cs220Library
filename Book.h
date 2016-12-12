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

    //pointer to start of waitList array - this must be a queue
    ArrayList<std::string> *waitList;


public:

    // @param: std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue
    // ----------
    // Book Constructor which creates a book that owns ArrayList on the heap
    // ----------
    Book(std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue);

    // @param: Book
    // ----------
    // Book Overloaded Equals Operator
    // ----------
    Book& operator=(const Book &other);

    // @param: Book
    // ----------
    // Book Copy Constructor
    // ----------
    Book(const Book& other);

    // @param: None
    // ----------
    // Book Destructor (handles ArrayList memory on the heap)
    // ----------
    ~Book();

    // @param: None
    // ----------
    // getAuthor returns a book's author as a string
    // ----------
    std::string getAuthor();

    // @param: None
    // ----------
    // getTitle returns a book's title as a string
    // ----------
    std::string getTitle();

    // @param: None
    // ----------
    // getPrice returns a book's price as a double
    // ----------
    double getPrice();

    // @param: double newPrice
    // ----------
    // setPrice takes in a price and sets the book's current price to the newPrice value
    // ----------
    void setPrice(double newPrice);


    // @param: None
    // ----------
    // getISBN returns the book's ISBN as a string
    // ----------
    std::string getISBN();

    // @param: None
    // ----------
    // getHaveValue returns the book's haveValue as an int
    // ----------
    int getHaveValue();

    // @param: int newHaveValue
    // ----------
    // setHaveValue returns the book's ISBN as a string
    // ----------
    void setHaveValue(int newHaveValue);

    // @param: None
    // ----------
    // getWantValue returns the book's ISBN as a string
    // ----------
    int getWantValue();

    // @param: int newWantValue
    // ----------
    // setWantValue takes in a new want value and sets the book's current wantValue to the newWantValue value
    // ----------
    void setWantValue(int newWantValue);

    // @param: None
    // ----------
    // waitListToString returns a string containing all names on a book's waitList. Prints out in {1,2,3,4...n} format.
    // ----------
    std::string waitListToString();

    // @param: None
    // ----------
    // clearWaitList removes all names on a book's waitList
    // ----------
    void clearWaitList();

    // @param: string personToAdd
    // ----------
    // addToWaitList takes in a personToAdd and adds them to the end of the book's waitList
    // ----------
    void addToWaitList(std::string personToAdd);

    // @param: None
    // ----------
    // popOffWaitList returns the first person on a book's waitList as a string, removes the person from the waitList, and checks to see if the waitList's capacity can be shrunk
    // ----------
    std::string popOffWaitList();

    // @param: None
    // ----------
    // calcSizeOf returns an integer that is the memory size in bytes of a book
    // ----------
    int calcSizeOf();

    // @param: None
    // ----------
    // numOnWaitList returns an integer that is the number of people on the waitList currently
    // ----------
    int numOnWaitList();

    // @param: None
    // ----------
    // capacityOfWaitList returns an integer that is the number of people the waitList can hold
    // ----------
    int capacityOfWaitList();

    // @param: None
    // ----------
    // bookToString returns a string containing all information associated with a book seperated by commas.
    // ----------
    std::string bookToString();

};
#endif //BOOK_H

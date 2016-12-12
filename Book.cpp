//
// Created by Jack Banta on 11/8/2016.
//

#include <iostream>
#include "Book.h"


// @param: std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue
// ----------
// Book Constructor which creates a book that owns ArrayList on the heap
// ----------
Book::Book(std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue){
    this->title = title;
    this->author = author;
    this->price = price;
    this->ISBN = ISBN;
    this->haveValue = haveValue;
    this->wantValue = wantValue;
    this->waitList = new ArrayList<std::string>(1);
}



// @param: Book
// ----------
// Book Overloaded Equals Operator
// ----------
Book& Book::operator=(const Book &other){
    if (this == &other){
        return *this;
    } else {
        this->title = other.title;
        this->author = other.author;
        this->price = other.price;
        this->ISBN = other.ISBN;
        this->haveValue = other.haveValue;
        this->wantValue = other.wantValue;
        this->waitList = other.waitList;
        return *this;
    }

}


// @param: Book
// ----------
// Book Copy Constructor
// ----------
Book::Book(const Book& other){
    this->title = other.title;
    this->author = other.author;
    this->price = other.price;
    this->ISBN = other.ISBN;
    this->haveValue = other.haveValue;
    this->wantValue = other.wantValue;
    this->waitList = other.waitList;
}

// @param: None
// ----------
// Book Destructor (handles ArrayList memory on the heap)
// ----------
Book::~Book(){
    std::cout << "Deleting Book: " << this->getTitle() << " By: " << this->getAuthor() << std::endl;
    delete waitList;

}

// @param: None
// ----------
// getAuthor returns a book's author as a string
// ----------
std::string Book::getAuthor() {
    return this->author;
}

// @param: None
// ----------
// getTitle returns a book's title as a string
// ----------
std::string Book::getTitle() {
    return this->title;
}

// @param: None
// ----------
// getPrice returns a book's price as a double
// ----------
double Book::getPrice() {
    return this->price;
}

// @param: double newPrice
// ----------
// setPrice takes in a price and sets the book's current price to the newPrice value
// ----------
void Book::setPrice(double newPrice) {
   this->price = newPrice;
}

// @param: None
// ----------
// getISBN returns the book's ISBN as a string
// ----------
std::string Book::getISBN(){
    return this->ISBN;
}

// @param: None
// ----------
// getHaveValue returns the book's haveValue as an int
// ----------
int Book::getHaveValue() {
    return this->haveValue;
}

// @param: int newHaveValue
// ----------
// setHaveValue returns the book's ISBN as a string
// ----------
void Book::setHaveValue(int newHaveValue) {
    this->haveValue = newHaveValue;
}

// @param: None
// ----------
// getWantValue returns the book's ISBN as a string
// ----------
int Book::getWantValue() {
    return this->wantValue;
}

// @param: int newWantValue
// ----------
// setWantValue takes in a new want value and sets the book's current wantValue to the newWantValue value
// ----------
void Book::setWantValue(int newWantValue) {
    this->wantValue = newWantValue;
}

// @param: None
// ----------
// waitListToString returns a string containing all names on a book's waitList. Prints out in {1,2,3,4...n} format.
// ----------
std::string Book::waitListToString(){
    std::string toReturn = "{";
    for(int iii=0; iii < this->waitList->getCurrItemCount() ;iii++){
        toReturn += waitList->get(iii);
        if (iii==waitList->getCurrItemCount()-1) {
            toReturn += "";
        } else {
            toReturn += ", ";
        }
    }
    toReturn += "}";
    return toReturn;
}


// @param: None
// ----------
// clearWaitList removes all names on a book's waitList
// ----------
void Book::clearWaitList(){
    waitList->clearList();
}

// @param: string personToAdd
// ----------
// addToWaitList takes in a personToAdd and adds them to the end of the book's waitList
// ----------
void Book::addToWaitList(std::string personToAdd){
    this->waitList->addToEnd(personToAdd);
}

// @param: None
// ----------
// popOffWaitList returns the first person on a book's waitList as a string, removes the person from the waitList, and checks to see if the waitList's capacity can be shrunk
// ----------
std::string Book::popOffWaitList(){
    std::string toBePopped = waitList->pop();
    return toBePopped;
}

// @param: None
// ----------
// calcSizeOf returns an integer that is the memory size in bytes of a book
// ----------
int Book::calcSizeOf(){
    int currentSize = 0;
    currentSize += sizeof(std::string) * 2;
    currentSize += sizeof(int) * 3;
    currentSize += sizeof(double);
    currentSize += this->waitList->calcSizeOf();
    return currentSize;
}

// @param: None
// ----------
// numOnWaitList returns an integer that is the number of people on the waitList currently
// ----------
int Book::numOnWaitList() {
    return waitList->getCurrItemCount();
}

// @param: None
// ----------
// capacityOfWaitList returns an integer that is the number of people the waitList can hold
// ----------
int Book::capacityOfWaitList() {
    return waitList->getCurrCapacity();
}

// @param: None
// ----------
// bookToString returns a string containing all information associated with a book seperated by commas.
// ----------
std::string Book::bookToString() {
    std::string bookString = "";
    bookString += this->getTitle();
    bookString += ", ";
    bookString += this->getAuthor();
    bookString += ", ";
    bookString += std::to_string(this->getPrice());
    bookString += ", ";
    bookString += this->getISBN();
    bookString += ", ";
    bookString += std::to_string(this->getHaveValue());
    bookString += ", ";
    bookString += std::to_string(this->getWantValue());
    bookString += ", ";
    bookString += std::to_string(this->numOnWaitList());
    return bookString;
}


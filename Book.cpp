//
// Created by Jack Banta on 11/8/2016.
//

#include <iostream>
#include "Book.h"
#include "ArrayList.h"


Book::Book(std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue){
    std::cout << "CONSTRUCTING BOOK" << std::endl;
    this->title = title;
    this->author = author;
    this->price = price;
    this->ISBN = ISBN;
    this->haveValue = haveValue;
    this->wantValue = wantValue;
    this->waitList = new ArrayList<std::string>(1);
}

Book::Book(const Book& other){
    this->title = other.title;
    this->author = other.author;
    this->price = other.price;
    this->ISBN = other.ISBN;
    this->haveValue = other.haveValue;
    this->wantValue = other.wantValue;
    this->waitList = other.waitList;
}

Book::~Book(){
    std::cout << "Deleting Book: " << this->getTitle() << " By: " << this->getAuthor() << std::endl;
    delete waitList;

}


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

std::string Book::getAuthor() {
    return this->author;
}

std::string Book::getTitle() {
    return this->title;
}

double Book::getPrice() {
    return this->price;
}
void Book::setPrice(double newPrice) {
   this->price = newPrice;
}

std::string Book::getISBN(){
    return this->ISBN;
}

int Book::getHaveValue() {
    return this->haveValue;
}
void Book::setHaveValue(int newHaveValue) {
    this->haveValue = newHaveValue;
}

int Book::getWantValue() {
    return this->wantValue;
}
void Book::setWantValue(int newWantValue) {
    this->wantValue = newWantValue;
}

std::string Book::waitListToString(){
    std::string toReturn = "{";
    for(int iii=0; iii < this->waitList->getCurrItemCount() ;iii++){
        std::cout << waitList->get(iii) << std::endl;
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


void Book::clearWaitList(){
    waitList->clearList();
}


void Book::addToWaitList(std::string personToAdd){
    this->waitList->addToEnd(personToAdd);
}

std::string Book::popOffWaitList(){
    std::string toBePopped = this->waitList->pop();
    return toBePopped;
}

int Book::calcSizeOf(){
    int currentSize = 0;
    currentSize += sizeof(std::string) * 2;
    currentSize += sizeof(int) * 3;
    currentSize += sizeof(double);
    currentSize += this->waitList->calcSizeOf();
    return currentSize;
}

int Book::numOnWaitList() {
    return waitList->getCurrItemCount();
}

int main(){
    Book myBook = Book("Test","Jack Banta",19.99,"1234",10,10);
    myBook.addToWaitList("test_Person1");
    myBook.addToWaitList("test_Person2");
    std::cout << myBook.waitListToString() << std::endl;

    Book myBookTwo = Book("Test2","Jack Banta2",20.00,"5678",10,10);
    myBookTwo.addToWaitList("TP1");
    myBookTwo.addToWaitList("TP2");
    std::cout << myBookTwo.waitListToString() << std::endl;
    myBookTwo.clearWaitList();
    std::cout << "BEFORE myBookTwo wantValue: " << myBookTwo.getWantValue() << std::endl;
    std::cout << "BEFORE myBookTwo haveValue: " << myBookTwo.getHaveValue() << std::endl;
    std::cout << "BEFORE myBookTwo price: " << myBookTwo.getPrice() << std::endl;
    std::cout << "BEFORE myBookTwo ISBN: " << myBookTwo.getISBN() << std::endl;
    myBookTwo.setHaveValue(9999);
    myBookTwo.setWantValue(9999);
    myBookTwo.setPrice(99.99);
    std::cout << "AFTER myBookTwo wantValue: " << myBookTwo.getWantValue() << std::endl;
    std::cout << "AFTER myBookTwo haveValue: " << myBookTwo.getHaveValue() << std::endl;
    std::cout << "AFTER myBookTwo price: " << myBookTwo.getPrice() << std::endl;




    std::cout << std::endl;
    std::cout << "END MAIN" << std::endl;
    return 0;
}
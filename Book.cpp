//
// Created by Jack Banta on 11/8/2016.
//

#include <iostream>
#include "Book.h"
#include "ArrayList.h"


Book::Book(std::string title, std::string author, double price, std::string ISBN, int haveValue, int wantValue){
    this->title = title;
    this->author = author;
    this->price = price;
    this->ISBN = ISBN;
    this->haveValue = haveValue;
    this->wantValue = wantValue;
    this->waitList = ArrayList<std::string>(1);
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
    for(int iii;iii<this->waitList.getCurrItemCount();iii++){
        toReturn += waitList.get(iii);
        if (iii<waitList.getCurrItemCount()) {
            toReturn += ", ";
        } else {
            toReturn += "}";
        }
    }
    return toReturn;
}


void Book::clearWaitList(){
    this->waitList = ArrayList<std::string>(1); //TODO: what happens to the old arraylist?
}


void Book::addToWaitList(std::string personToAdd){
    this->waitList.addToEnd(personToAdd);
}

std::string Book::popOffWaitList(){
    std::string toBePopped = this->waitList.pop();
    return toBePopped;
}

int Book::calcSizeOf(){
    int currentSize = 0;
    currentSize += sizeof(std::string) * 2;
    currentSize += sizeof(int) * 3;
    currentSize += sizeof(double);
    currentSize += this->waitList.calcSizeOf();
    return currentSize;
}

int main(){
    return -1;
}
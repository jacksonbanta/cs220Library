#include <iostream>
#include "Book.h"
#include "LinkedList.h"
#include "LinkedNode.h"
#include "ArrayList.h"


Book::Book(std::string title, std::string author, double price, int ISBN, int haveValue, int wantValue){
    this->title = title;
    this->author = author;
    this->price = price;
    this->ISBN = ISBN;
    this->haveValue = haveValue;
    this->wantValue = wantValue;
    this->waitList = std::string[5];
}

Book::Book(Book& other){
    this->title = other.title;
    this->author = other.author;
    this->price = other.price;
    this->ISBN = other.ISBN;
    this->haveValue = other.haveValue;
    this->wantValue = other.wantValue;
    this->waitList = std::string[5];
    for (int iii = 0;other.waitList->currItemCount;iii++){
        this->waitList[iii] = other.waitList[iii];
        //if we can't add another item without going over capacity, double capacity
        if (this->waitList.currItemCount+1 > this->waitList.currCapacity){
            this->waitList.doubleCapacity();
        }
    }
}

std::string Book::getTitle(Book* book) {
    return book->title;
}

std::sting Book::getAuthor(Book* book) {
    return book->author;
}

int Book::getPrice(Book* book) {
    return book->price;
}

void Book::setPrice(Book* book, int newPrice) {
    book->price = newPrice;
}

int Book::getISBN(Book* book) {
    return book->ISBN;
}

int Book::getHaveValue(Book* book) {
    return book->haveValue;
}

void Book::setHaveValue(Book *book, int newHaveVal) {
    book->haveValue = newHaveVal;
}

int Book::getWantValue(Book *book) {
    return book->wantValue;
}

void Book::setWantValue(Book *book, int newWantVal) {
    book->wantValue = newWantVal;
}




Book::~Book(){
    std::cout << "Deleteing Book: " << this->getTitle() << " By: " << this->getAuthor() << std::endl;
    delete[] waitList;
    waitList = nullptr;
}







int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
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

Book::~Book(){
    std::cout << "Deleteing Book: " << this->getTitle() << " By: " << this->getAuthor() << std::endl;
    delete[] waitList;
    waitList = nullptr;
}







int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
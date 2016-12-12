//
// Created by Kenny Potts on 11/3/16.
// Implements LinkedList That holds pointers to Book Objects
//

#include "LinkedList.h"
#include <iostream>
#include "Book.h"



// @param: none
// ----------
// Creates an empty Linked List
// ----------
LinkedList::LinkedList() {
    this->start = nullptr;
    this->end = nullptr;
    this->currItemCount = 0;
    this->totalLinesRun = 3;
}

// @param: const LinkedList &other - Another Linked list by reference
// ----------
// Creates a copy of the other linked list passed by reference
// ----------
LinkedList::LinkedList(const LinkedList &other) {
    this->start = nullptr;
    this->end = nullptr;
    this->currItemCount = 0;
    this->totalLinesRun = 3;

    for (int i = 0; i < other.currItemCount; ++i) {
        Book *currBook = other.get(i);
        Book *newBook = new Book(*currBook); // make new copy of other book
        this->addToEnd(newBook); // add new book to end through pointer
    }
}

// @param: const LinkedList &other - Another Linked list by reference
// ----------
// Overrides the assignment operator, Creates a copy of the other linked list
// ----------
LinkedList& LinkedList::operator=(const LinkedList &other) {
    if (this != &other) {
        this->start = nullptr;
        this->end = nullptr;
        this->currItemCount = 0;
        this->totalLinesRun = 3;

        for (int i = 0; i < other.currItemCount; ++i) {
            Book *currBook = other.get(i);
            Book *newBook = new Book(*currBook); // make new copy of other book
            this->addToEnd(newBook); // add new book to end through pointer
        }
    }
    return *this;
}

// @param: none
// ----------
// Deletes all the nodes in the linked list
// ----------
LinkedList::~LinkedList() {
    LinkedNode* currNode = this->start;
    while (currNode != nullptr) {
        LinkedNode* toDel = currNode;
        currNode = currNode->getNext();
        delete toDel;
    }
    this->start = nullptr;
    this->end = nullptr;
    this->totalLinesRun = 0;
}

// @param: std::string title - The title of a book as a std::string
// ----------
// finds a book with the input title, returns the index of the book
// ----------
int LinkedList::findTitle(std::string title) {
    const char* charCompareTitle = title.c_str();
    LinkedNode* currNode = start;
    int count = 0;
    while (currNode != nullptr){
        Book* currBook = currNode->getItem();
        const char* charTitle = currBook->getTitle().c_str();
        if (std::strcmp(charCompareTitle, charTitle) == 0){
            return count;
        }else{
            count++;
            currNode = currNode->getNext();
        }
    }
    return -1;
}

// @param: std::string ISBN - The ISBN of a book as a std::string
// ----------
// finds a book with the input ISBN, returns the index of the book
// ----------
int LinkedList::findISBN(std::string ISBN) {
    const char* charCompareISBN = ISBN.c_str();
    LinkedNode* currNode = start;
    int count = 0;
    while (currNode != nullptr){
        Book* currBook = currNode->getItem();
        const char* charTitle = currBook->getISBN().c_str();
        if (std::strcmp(charCompareISBN, charTitle) == 0){
            return count;
        }else{
            count++;
            currNode = currNode->getNext();
        }
    }
    return -1;
}

// @param: Book* bookToAdd - Book pointer
// ----------
// Adds a book by pointer to the end of the linked list
// Book becomes property of the LinkedList
// and will be deleted by the LinkedList in destructor
// ----------
void LinkedList::addToEnd(Book* bookToAdd) {
    this->totalLinesRun += 6;
    LinkedNode* n = new LinkedNode(bookToAdd);
    if (this->currItemCount) {
        this->end->setNext(n);
        this->end = n;
    } else {
        this->start = n;
        this->end = n;
    }
    this->currItemCount++;

}

// @param: Book* bookToAdd - Book pointer
// ----------
// Adds a book by pointer to the front of the linked list
// Book becomes property of the LinkedList
// and will be deleted by the LinkedList in destructor
// ----------
void LinkedList::addToFront(Book* bookToAdd) {
    this->totalLinesRun += 7;
    LinkedNode* n = new LinkedNode(bookToAdd);
    n->setNext(this->start);
    this->start = n;
    if (!this->currItemCount) {
        this->end = n;
    }
    this->currItemCount++;
}

// @param: Book* bookToAdd - Book pointer, int index - location of insertion
// ----------
// Adds a book by pointer to the specified index of the linked list
// Book becomes property of the LinkedList
// and will be deleted by the LinkedList in destructor
// if the index is invalid, returns an out_of_range exception
// ----------
void LinkedList::add(Book* itemToAdd, int index) {
    this->totalLinesRun += 2;
    if ((index>=0)&&(index <= currItemCount)) {

        if (!this->currItemCount || !index) {
            this->addToFront(itemToAdd);
        } else if (index == this->currItemCount) {
            this->addToEnd(itemToAdd);
        } else {
            this->totalLinesRun += 5;
            LinkedNode *n = new LinkedNode(itemToAdd);
            LinkedNode *pointNode = this->start;
            for (int i = 1; i < index; ++i) {
                this->totalLinesRun += 4;
                pointNode = pointNode->getNext();
            }
            this->totalLinesRun += 4;
            n->setNext(pointNode->getNext());
            pointNode->setNext(n);
            this->currItemCount++;
        }

    } else {
        this->totalLinesRun += 1;
        throw std::out_of_range("Index out of range"); // throws out of range exception
    }
}

// @param: int index - location of book to get
// ----------
// gets and returns book at the specified index
// ----------
Book* LinkedList::get(int index) const{
    if ((index>=0)&&(index < currItemCount)) {
        LinkedNode *currNode = this->start;
        for (int i = 0; i < index; ++i) {
            currNode = currNode->getNext();
        }
        return currNode->getItem();
    } else {
        std::cout << "Book not in inventory..." << std::endl; // throws out of range exception
        return nullptr;
    }
}


// @param: int index - location of book to remove
// ----------
// removes and deletes the node at the specified index
// gets and returns a copy of the book at the specified index
// LinkedList loses responsibility of deleting book
// function caller is responsible for deleting the book.
// if the index is invalid, returns an out_of_range exception
// ----------
Book* LinkedList::remove(int index) {
    this->totalLinesRun += 2;
    if ((index>0)&&(index < currItemCount)) {
        this->totalLinesRun += 2;
        LinkedNode *pointNode = this->start;
        for (int i = 1; i < index; ++i) {
            this->totalLinesRun += 4;
            pointNode = pointNode->getNext();
        }
        this->totalLinesRun += 10;
        LinkedNode *toDel = pointNode->getNext();
        Book* val = new Book(toDel->getItem());
        pointNode->setNext(toDel->getNext());
        delete toDel;
        toDel = nullptr;
        this->currItemCount--;
        return val;
    } else if (!index && (index < currItemCount)) {
        LinkedNode* toDel = this->start;
        Book* val = new Book(toDel->getItem());
        this->start = toDel->getNext();
        delete toDel;
        toDel = nullptr;
        this->currItemCount--;
        return val;
    } else {
        this->totalLinesRun += 1;
        throw std::out_of_range("Index out of range"); // throws out of range exception
    }
}

// @param: none
// ----------
// check to see if there are any valid items in the linked list
// returns True if empty, False if there are valid items
// ----------
bool LinkedList::isEmpty() {
    this->totalLinesRun++;
    return !this->currItemCount;
}

// @param: none
// ----------
// returns the number of valid items in the LinkedList
// ----------
int LinkedList::size() {
    this->totalLinesRun++;
    return this->currItemCount;
}

// @param: none
// ----------
// clears the list by deleting the nodes
// and setting the item count to 0
// ----------
void LinkedList::clearList() {
    LinkedNode* currNode = this->start;
    while (currNode != nullptr) {
        LinkedNode* toDel = currNode;
        currNode = currNode->getNext();
        delete toDel;
    }
    this->start = nullptr;
    this->end = nullptr;
    this->currItemCount = 0;
}


// @param: Book* itemToFind - book to find
// ----------
// finds and returns the index of the book to find
// ----------
int LinkedList::find(Book* itemToFind) {
    int idx = -1;
    this->totalLinesRun += 3;
    LinkedNode *currNode = this->start;
    for (int i = 0; i < this->currItemCount; ++i) {
        this->totalLinesRun += 4;
        if (currNode->getItem() == itemToFind) {
            this->totalLinesRun ++;
            return i;
        }
        currNode = currNode->getNext();
    }
    this->totalLinesRun += 1;
    return idx;
}


// @param: none
// ----------
// prints out all the books in the LinkedList
// ----------
std::string LinkedList::toString() {
    this->totalLinesRun +=3;
    std::string newStr = "{"; // starts string with {
    LinkedNode* currNode = this->start;
    for (int i = 0; i < this->currItemCount; ++i) {
        this->totalLinesRun +=3;
        if (i > 0) {
            this->totalLinesRun++;
            newStr += " "; //ensures proper space formatting
        }
        this->totalLinesRun +=3;
        newStr += (currNode->getItem()->bookToString()); // convert int to string
        if (i != this->currItemCount - 1) {
            this->totalLinesRun++;
            newStr += ";";
        }
        currNode = currNode->getNext();
    }
    this->totalLinesRun +=2;
    newStr += "}"; // end string with }
    return newStr;
}

// @param: none
// ----------
// returns the number of lines run by the LinkedList
// ----------
long LinkedList::getTotalLinesRun() {
    return this->totalLinesRun;
}

// @param: none
// ----------
// resets the number of lines run to 0
// ----------
void LinkedList::resetTotalLinesRun() {
    this->totalLinesRun = 0;
}

// @param: none
// ----------
// calculates and returns the memory size of the Linked List
// ----------
int LinkedList::calcSizeOf() {
    int totalSize = sizeof(start) + sizeof(end) //start and end
                    + sizeof(this->currItemCount) + sizeof(this->totalLinesRun);
    LinkedNode* currNode = this->start;
    while (currNode != nullptr) {
        totalSize += sizeof(currNode);
        currNode = currNode->getNext();
    }
    return totalSize;
}
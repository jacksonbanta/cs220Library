//
// Created by Kenny Potts on 11/3/16.
// Implements LinkedList
//

#include "LinkedList.h"
#include <iostream>
#include "Book.h"




LinkedList::LinkedList() {
    this->start = nullptr;
    this->end = nullptr;
    this->currItemCount = 0;
    this->totalLinesRun = 3;
}

LinkedList::LinkedList(const LinkedList &other) {
    this->start = nullptr;
    this->end = nullptr;
    this->currItemCount = 0;
    this->totalLinesRun = 3;

    for (int i = 0; i < other.currItemCount; ++i) {
        Book *currBook = other.get(i);
        Book *newBook = new Book(currBook); // make new copy of other book
        this->addToEnd(newBook); // add new book to end through pointer
    }
}

LinkedList& LinkedList::operator=(const LinkedList &other) {
    if (this != &other) {
        this->start = nullptr;
        this->end = nullptr;
        this->currItemCount = 0;
        this->totalLinesRun = 3;

        for (int i = 0; i < other.currItemCount; ++i) {
            Book *currBook = other.get(i);
            Book *newBook = new Book(currBook); // make new copy of other book
            this->addToEnd(newBook); // add new book to end through pointer
        }
    }
    return *this;
}


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

int LinkedList::findTitle(std::string title) {
    LinkedNode* currNode = start;
    int count = 0;
    while (currNode != nullptr){
        Book* currBook = currNode->getItem();
        if (currBook->getTitle() == title){
            return count;
        }else{
            count++;
            currNode = currNode->getNext();
        }
    }
    return -1;
}

int LinkedList::findISBN(std::string ISBN) {
    LinkedNode* currNode = start;
    int count = 0;
    while (currNode != nullptr){
        Book* currBook = currNode->getItem();
        if (currBook->getISBN() == ISBN){
            return count;
        }else{
            count++;
            currNode = currNode->getNext();
        }
    }
    return -1;
}

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


Book* LinkedList::get(int index) const{
    if ((index>=0)&&(index < currItemCount)) {
        LinkedNode *currNode = this->start;
        for (int i = 0; i < index; ++i) {
            currNode = currNode->getNext();
        }
        return currNode->getItem();
    } else {
        throw std::out_of_range("Index out of range"); // throws out of range exception
    }
}


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
        Book* val = toDel->getItem();
        pointNode->setNext(toDel->getNext());
        delete toDel;
        toDel = nullptr;
        this->currItemCount--;
        return val;
    } else if (!index && (index < currItemCount)) {
        LinkedNode* toDel = this->start;
        Book* val = toDel->getItem();
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

bool LinkedList::isEmpty() {
    this->totalLinesRun++;
    return !this->currItemCount;
}


int LinkedList::size() {
    this->totalLinesRun++;
    return this->currItemCount;
}


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
        newStr += std::to_string(currNode->getItem()); // convert int to string
        if (i != this->currItemCount - 1) {
            this->totalLinesRun++;
            newStr += ",";
        }
        currNode = currNode->getNext();
    }
    this->totalLinesRun +=2;
    newStr += "}"; // end string with }
    return newStr;
}


long LinkedList::getTotalLinesRun() {
    return this->totalLinesRun;
}


void LinkedList::resetTotalLinesRun() {
    this->totalLinesRun = 0;
}


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
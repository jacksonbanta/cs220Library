//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Book.h"


class LinkedNode {

private:
    Book* item;
    LinkedNode* next;

public:

    LinkedNode(Book* item){
        this->item = item;
        next = nullptr;
    }

    ~LinkedNode(){
        delete item;
        next = nullptr;
    }

    LinkedNode(const LinkedNode& other){
        this->item = new Book(*other.item);
        this->next = other.next;
    }

    LinkedNode operator=(const LinkedNode &other) {
        if (this == &other) {
            return *this;
        } else {
            this->item = new Book(*other.item);
            this->next = other.next;
            return *this;
        }
    }

    Book* getItem(){
        return item;
    }

    LinkedNode* getNext(){
        return next;
    }

    void setItem(Book* newItem){
        item = newItem;
    }

    void setNext(LinkedNode* newNext){
        next = newNext;
    }
};


#endif //LINKEDNODE_H
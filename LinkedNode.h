//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H


template <class ItemType>
class LinkedNode {

private:
    ItemType item;
    LinkedNode* next;

public:

    LinkedNode(ItemType item){
        this->item = item;
        next = nullptr;
    }

    ItemType getItem(){
        return item;
    }

    LinkedNode* getNext(){
        return next;
    }

    void setItem(ItemType newItem){
        item = newItem;
    }

    void setNext(LinkedNode* newNext){
        next = newNext;
    }
};


#endif //LINKEDNODE_H

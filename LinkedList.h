//
// Created by Toby Dragon on 9/30/16.
//

#ifndef LAB7SOLN_LINKEDLIST_H
#define LAB7SOLN_LINKEDLIST_H

#include <stdexcept>
#include<string>


#include "LinkedNode.h"
#include "Book.h"


class LinkedList{
private:
    LinkedNode* start;
    LinkedNode* end;
    int currItemCount;
    long totalLinesRun;

public:
    //creates an empty LinkedList
    LinkedList();

    //Destructor
    ~LinkedList();

    //copy constructor
    LinkedList(const LinkedList &other);

    //assignment overload
    LinkedList &operator=(const LinkedList &other);

    //appends the new item to the end of the list
    void addToEnd(Book* bookToAdd);

    //inserts the item at the front of the list
    void addToFront(Book* bookToAdd);

    //inserts the new item into the list at the specified index
    //if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
    void add(Book* bookToAdd, int index);

    //returns a copy of the item at index
    //if the index is invalid, throws an out_of_range exception
    Book* get(int index);

    //removes the item at index from the list, then returns a copy of that item
    //if the index is invalid, throws an out_of_range exception
    Book* remove(int index);
    
    //returns true if there are no valid items in the list, false otherwise
    bool isEmpty();

    //returns the number of valid items in the list
    int size();

    //makes the list entirely empty of valid items (does not change totalLinesRun)
    void clearList();

    //returns the index of the first occurrence of a book with the title in the list, or -1 if not present
    int findTitle(std::string title);

    //returns the index of the first occurrence of a book with the ISBN in the list, or -1 if not present
    int findISBN(std::string ISBN);

    //returns the index of the last occurrence of a book with the title in the list, or -1 if not present
    int findLastTitle(std::string title);

    //returns the index of the last occurrence of a book with the ISBN in the list, or -1 if not present
    int findLastISBN(std::string title);

    //returns the total number of lines run by this object
    long getTotalLinesRun();

    //resets the value of totalLinesRun to 0
    void resetTotalLinesRun();

    //returns the minimum size of the object in bytes
    int calcSizeOf();
};


#endif //LAB7SOLN_LINKEDLIST_H

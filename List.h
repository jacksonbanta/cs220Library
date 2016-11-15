//
// Created by Toby Dragon on 9/30/16.
//

#ifndef LAB7SOLN_LIST_H
#define LAB7SOLN_LIST_H

#include <stdexcept>
#include<string>

template <class ItemType>
class List {

public:
    virtual ~List(){}

    //appends the new item to the end of the list
    virtual void addToEnd(ItemType itemToAdd)=0;

    //inserts the item at the front of the list
    virtual void addToFront(ItemType itemToAdd)=0;

    //inserts the new item into the list at the specified index
    //if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
    virtual void add(ItemType itemToAdd, int index)=0;

    //returns a copy of the item at index
    //if the index is invalid, throws an out_of_range exception
    virtual ItemType get(int index)=0;

    //removes the item at index from the list, then returns a copy of that item
    //if the index is invalid, throws an out_of_range exception
    virtual ItemType remove(int index)=0;
    
    //returns true if there are no valid items in the list, false otherwise
    virtual bool isEmpty()=0;

    //returns the number of valid items in the list
    virtual int size()=0;

    //makes the list entirely empty of valid items (does not reset totalLinesRun)
    virtual void clearList()=0;

    //returns the index of the first occurrence of itemToFind in the list, or -1 if not present
    virtual int find(ItemType itemToFind)=0;

    //returns the index of the last occurrence of itemToFind in the list, or -1 if not present
    virtual int findLast(ItemType itemToFind)=0;

    //returns the index of first instance of the maximum item in the list
    //throws an out_of_range exception if list is empty
    virtual int findMax()=0;

    //returns a string representing the given list in the exact format shown below
    // {1, 2, 3, 4, 5}
    virtual std::string toString()=0;

    //returns the total number of lines run by this object
    virtual long getTotalLinesRun()=0;

    //resets the value of totalLinesRun to 0
    virtual void resetTotalLinesRun()=0;

    //returns the minimum size of the object in bytes
    virtual int calcSizeOf()=0;
};


#endif //LAB7SOLN_LIST_H

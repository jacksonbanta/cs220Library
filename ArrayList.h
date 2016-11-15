//
// Created by Toby Dragon on 9/30/16.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "List.h"
template<class ItemType>

class ArrayList: public List<ItemType> {
private:
    //pointer to the start of the array
    ItemType* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;
    //tracks the lines run by this object
    long totalLinesRun;

    //creates a new array with twice the capacity and shifts the old data to the new array
    //deletes the old array
    void doubleCapacity();

public:
    //creates an arrayList with a specific initial capacity (defaults to size 5)
    ArrayList(ItemType initialCapacity=5);



    //Destructor
    ~ArrayList();

    //appends the new item to the end of the arrayList
    void addToEnd(ItemType itemToAdd);

    //inserts the item at the front of the arrayList
    void addToFront(ItemType itemToAdd);

    //inserts the new item into the array at the specified index
    //if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
    void add(ItemType itemToAdd, int index);

    //returns a copy of the item at index
    //if the index is invalid, throws an out_of_range exception
    int get(int index);

    //removes the item at index from the list, then returns a copy of that item
    //if the index is invalid, throws an out_of_range exception
    int remove(int index);
    
    //returns true if there are no valid items in the list, false otherwise
    bool isEmpty();

    //returns the number of valid items in the list
    int size();

    //makes the list entirely empty of valid items (does not change totalLinesRun)
    void clearList();

    //returns the index of the first occurrence of itemToFind in the list, or -1 if not present
    int find(int itemToFind);

    //returns the index of the last occurrence of itemToFind in the list, or -1 if not present
    int findLast(int itemToFind);

    //returns the index of the maximum item in the list
    //throws an out_of_range exception if list is empty
    int findMax();

    //returns a string representing the given list in the exact format shown below
    // {1, 2, 3, 4, 5}
    std::string toString();

    //returns the total number of lines run by this object
    long getTotalLinesRun();

    //resets the value of totalLinesRun to 0
    void resetTotalLinesRun();

    //returns the minimum size of the object in bytes
    int calcSizeOf();
};




#endif //ARRAYLIST_H

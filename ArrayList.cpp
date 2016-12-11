//
//Created by Jack Banta on 10/5/2016
//


#include <iostream>
#include "ArrayList.h"

// @param: int initialCapacity
// ----------
// Constructor
// ----------
template <class ItemType>
ArrayList<ItemType>::ArrayList (int initialCapacity){
    this->array = new ItemType[initialCapacity];
    this->currItemCount = 0;
    this->currCapacity = initialCapacity;
    this->totalLinesRun = 0;

}

// @param: None
// ----------
// Destructor
// ----------
template <class ItemType>
ArrayList<ItemType>::~ArrayList() {
    delete[] array;
    array = nullptr;
}

// @param: ArrayList other
// ----------
// copy constructor
// ----------
template <class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType> &other){
    this->array = other.array;
    this->currItemCount = other.currItemCount;
    this->currCapacity = other.currCapacity;
    this->totalLinesRun = 0;
    for (int iii; iii < other.currItemCount; iii++) {
        this->array[iii] = other.array[iii];
    }
}

// @param: ArrayList other
// ----------
// assignment operator
// ----------
template <class ItemType>
ArrayList<ItemType>& ArrayList<ItemType>::operator=(const ArrayList<ItemType> &other){
    if (this == &other){

        return *this;
    } else {
        this->array = other.array;
        this->currItemCount = other.currItemCount;
        this->currCapacity = other.currCapacity;
        this->totalLinesRun = 0;
        for (int iii; iii < other.currItemCount; iii++) {
            this->array[iii] = other.array[iii];
        }
    }
    return *this;

}
// @param: ItemType itemToAdd
// ----------
// adds the specific item to the end of the arrayList
// ----------
template <class ItemType>
void ArrayList<ItemType>::addToEnd(ItemType itemToAdd){
    if (currItemCount+1<=currCapacity) {
        array[currItemCount] = itemToAdd;

        currItemCount++;
        totalLinesRun += 3;
    } else {
        doubleCapacity();
        addToEnd(itemToAdd);
        totalLinesRun += 5;
    }
}

// @param: ItemType itemToAdd
// ----------
// Adds the specific item to the front of the arrayList
// ----------
template <class ItemType>
void ArrayList<ItemType>::addToFront(ItemType itemToAdd){
    //if the array can hold another item
    if (currItemCount+1<=currCapacity){
        //from the end of the array, move all the elements up one space
        for (int iii=currItemCount;iii>=0;iii--){
            array[iii+1] = array[iii];
            totalLinesRun += 4;
        }
        //add in the new item in the now "black" first space of the array
        array[0] = itemToAdd;
        currItemCount++;
        totalLinesRun += 4;
    } else {

        doubleCapacity();
        addToFront(itemToAdd);
        totalLinesRun += 5;
    }

}

// @param: ItemType itemToAdd, int index
// ----------
// inserts the new item into the array at the specified index
// if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
// ----------
template <class ItemType>
void ArrayList<ItemType>::add(ItemType itemToAdd, int index){
    if (index <0 || index>currCapacity){
        totalLinesRun += 2;
        throw std::out_of_range("ERROR: invalid index given");
    } else if (currItemCount+1<=currCapacity) {
        //from the end of the array to the given index, move all the elements up one space to make room at the index
        totalLinesRun += 1;
        for (int iii=currItemCount;iii>=index;iii--){
            array[iii+1] = array[iii];
            totalLinesRun += 3;
        }
        array[index] = itemToAdd;
        currItemCount++;
        totalLinesRun += 2;
    } else{
        doubleCapacity();
        add(itemToAdd,index);
        totalLinesRun += 6;
    }
}

// @param: int index
// ----------
// returns a copy of the item at index
// if the index is invalid, throws an out_of_range exception
// ----------
template <class ItemType>
ItemType ArrayList<ItemType>::get(int index){
    if (index <0 || index>currCapacity){
        totalLinesRun += 2;
        throw std::out_of_range("ERROR: invalid index given");
    } else {
        ItemType temp;
        temp = array[index];
        totalLinesRun += 5;
        return temp;
    }
}



template <class ItemType>
int ArrayList<ItemType>::getCurrItemCount() {
    return currItemCount;
}

template <class ItemType>
int ArrayList<ItemType>::getCurrCapacity() {
    return currCapacity;
}


//returns true if there are no valid items in the list, false otherwise
template <class ItemType>
bool ArrayList<ItemType>::isEmpty(){
    if (currItemCount==0){
        totalLinesRun += 1;
        return true;
    } else {
        totalLinesRun += 2;
        return false;
    }
}
// @param: None
// ----------
// returns the number of valid items in the list
// ----------
template <class ItemType>
int ArrayList<ItemType>::size(){
    totalLinesRun += 1;
    return currItemCount;
}

// @param: None
// ----------
// makes the list entirely empty of valid items (does not change totalLinesRun)
// ----------
template <class ItemType>
void ArrayList<ItemType>::clearList(){
    totalLinesRun += 1;
    currItemCount = 0;
}

// @param: ItemType itemToFind
// ----------
//returns the index of the first occurrence of itemToFind in the list, or -1 if not present
// ----------
template <class ItemType>
int ArrayList<ItemType>::find(ItemType itemToFind){
    for (int iii=0;iii<currItemCount;iii++){
        totalLinesRun += 2;
        //if the value at position iii in arrayPtr is the number we want to find, return that position
        if (array[iii]==itemToFind){
            totalLinesRun += 1;
            return iii;
        }
    }
    totalLinesRun += 1;
    return -1;
}

// @param: ItemType itemToFind
// ----------
//returns the index of the last occurrence of itemToFind in the list, or -1 if not present
// ----------
template <class ItemType>
int ArrayList<ItemType>::findLast(ItemType itemToFind){
    //int to briefly hold the itemToFind if it is found in the array BEFORE the array has finished iterating through
    //this is essentially just to save the last known position of a number in the array
    int currentFound = 0;
    totalLinesRun += 1;
    for (int iii=0;iii<currItemCount;iii++){
        totalLinesRun += 2;
        //if value at array[iii] is equal to the value we wish to find, then:
        if (array[iii]==itemToFind){
            totalLinesRun += 1;
            if (iii<currItemCount-1){
                totalLinesRun += 2;
                currentFound = iii;
            } else if (iii==currItemCount-1){
                totalLinesRun += 2;
                //however, if position iii is at the end of the array, simply return that position
                return iii;
            }
        }
    }
    //if the end of the array is reached, check that the value in arrayPtr at position currentFound is the number we want to find, and if so return it
    if (array[currentFound]==itemToFind){
        totalLinesRun += 2;
        return currentFound;
    }
    totalLinesRun += 1;
    return -1;
}

// @param: None
// ----------
//returns the total number of lines run by this object
// ----------
template <class ItemType>
long ArrayList<ItemType>::getTotalLinesRun(){
    totalLinesRun += 1;
    return totalLinesRun;
}

// @param: None
// ----------
//resets the value of totalLinesRun to 0
// ----------
template <class ItemType>
void ArrayList<ItemType>::resetTotalLinesRun(){
    totalLinesRun = 0;
}

// @param: None
// ----------
// returns the size of ArrayList
// ----------
template <class ItemType>
int ArrayList<ItemType>::calcSizeOf(){
    totalLinesRun += 1;
    return currCapacity * sizeof(ItemType);
}

// @param: None
// ----------
// doubles the capacity of the arrayList
// ----------
template <class ItemType>
void ArrayList<ItemType>::doubleCapacity(){
    int makeCurrCapacity = currCapacity*2;
    ItemType* newArray = new ItemType[makeCurrCapacity];
    currCapacity = makeCurrCapacity;

    totalLinesRun += 1;
    for (int iii=0;iii<currItemCount;iii++){
        totalLinesRun += 3;
        newArray[iii] = array[iii];
    }
    totalLinesRun += 2;
    delete[] array;
    array = newArray;
}

// @param: int index
// ----------
// shrinks the capacity of the arraylist half the size unless its greater than 1
// ----------
template <class ItemType>
void ArrayList<ItemType>::shrinkCapacity() {
    if (currCapacity>1) {
        if (this->currItemCount < this->currCapacity) {
            if (this->currCapacity % this->currItemCount == 0) {
                this->currCapacity = this->currItemCount;
                ItemType *newArray = new ItemType[currCapacity];
                for (int iii = 0; iii < currItemCount; iii++) {
                    totalLinesRun += 3;
                    newArray[iii] = array[iii];
                }
                delete[] array;
                array = newArray;
            }
        }
    }
}

// @param: None
// ----------
// Pops off the first person at the waitlist
// ----------
template <class ItemType>
ItemType ArrayList<ItemType>::pop(){
    std::string toBePopped = "";
    if (currItemCount>0) {
        toBePopped = array[0];
        currItemCount = currItemCount - 1;
        if (currItemCount >= 0) {
            for (int iii = 0; iii < currItemCount; iii++) {
                array[iii] = array[iii + 1];
            }
            shrinkCapacity();
            return toBePopped;
        }
    }
    toBePopped = "No names left on wait list";
    return toBePopped;
}


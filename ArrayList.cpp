//
//Created by Jack Banta on 10/5/2016
//


#include <iostream>
#include "ArrayList.h"


template <class ItemType>
ArrayList<ItemType>::ArrayList (int initialCapacity){
    this->array = new int[initialCapacity];
    this->currItemCount = 0;
    this->currCapacity = initialCapacity;
    this->totalLinesRun = 0;

}

template <class ItemType>
ArrayList<ItemType>::~ArrayList() {
    std::cout << std::endl;
    //std::cout << "in destructor" << std::endl;

    //std::cout << "Deleting array: " << toString() << std::endl;
    delete[] array;
    array = nullptr;
    //std::cout << std::endl;
}

template <class ItemType>
ArrayList& ArrayList::operator=(const ArrayList &other){
    this->array = other.array;
    this->currItemCount = other.currItemCount;
    this->currCapacity = other.currCapacity;
    this->totalLinesRun = 0;
    for (int iii; iii<other.currItemCount; iii++){
        this->array[iii] = other.array[iii];
    }

}

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

//inserts the new item into the array at the specified index
//if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
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
        std::cout << "Doubling array size to: " << currCapacity*2 << std::endl;
        doubleCapacity();
        add(itemToAdd,index);
        totalLinesRun += 6;
    }
}

//returns a string representing the given list in the exact format shown below
// {1, 2, 3, 4, 5}
template <class ItemType>
std::string ArrayList<ItemType>::toString(){

    //THIS RETURNS A STD::STRING OBJECT
    std::string tempArray;
    tempArray= "{";
    totalLinesRun += 2;
    for (int iii=0;iii<currItemCount;iii++) {
        if (iii==0 || iii==currItemCount){
            tempArray= tempArray + std::to_string(array[iii]);
            totalLinesRun += 4;
        } else{
            tempArray= tempArray + (", " + std::to_string(array[iii]));
            totalLinesRun += 5;
        }
    }
    tempArray= tempArray + "}";
    totalLinesRun += 2;
    return tempArray;



}

//returns a copy of the item at index
//if the index is invalid, throws an out_of_range exception
template <class ItemType>
ItemType ArrayList<ItemType>::get(int index){
    if (index <0 || index>currCapacity){
        totalLinesRun += 2;
        throw std::out_of_range("ERROR: invalid index given");
    } else {
        int temp;
        temp = array[index];
        totalLinesRun += 5;
        return temp;
    }
}



template <class ItemType>
ItemType ArrayList<ItemType>::getCurrItemCount() {
    return currItemCount;
}

template <class ItemType>
ItemType ArrayList<ItemType>::getCurrCapacity() {
    return currCapacity;
}


//removes the item at index from the list, then returns a copy of that item
//if the index is invalid, throws an out_of_range exception
template <class ItemType>
ItemType ArrayList<ItemType>::remove(int index){
    if (index <0 || index>currCapacity){
        totalLinesRun += 2;
        throw std::out_of_range("ERROR: invalid index given");
    } else {
        int temp;
        temp = array[index];
        totalLinesRun += 4;
        for (int iii=index;iii<currItemCount;iii++){
            array[iii] = array[iii+1];
            totalLinesRun += 3;
        }
        currItemCount--;
        totalLinesRun += 2;
        return temp;
    }
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

//returns the number of valid items in the list
template <class ItemType>
int ArrayList<ItemType>::size(){
    totalLinesRun += 1;
    return currItemCount;
}

//makes the list entirely empty of valid items (does not change totalLinesRun)
template <class ItemType>
void ArrayList<ItemType>::clearList(){
    for (int iii=0;iii<currItemCount;iii++){
        totalLinesRun += 2;
        array[iii] = 0;
    }
    totalLinesRun += 1;
    currItemCount = 0;
}

//returns the index of the first occurrence of itemToFind in the list, or -1 if not present
template <class ItemType>
ItemType ArrayList<ItemType>::find(int itemToFind){
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

//returns the index of the last occurrence of itemToFind in the list, or -1 if not present
template <class ItemType>
ItemType ArrayList<ItemType>::findLast(int itemToFind){
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

//returns the index of the maximum item in the list
//throws an out_of_range exception if list is empty
template <class ItemType>
int ArrayList<ItemType>::findMax(){
    if (currItemCount<=0){
        totalLinesRun += 2;
        throw std::out_of_range("ERROR: invalid array given - size is less than or equal to 0");
    } else {
        int largestNum = -99999;
        int largestNumPos = 0;
        totalLinesRun += 4;
        for (int iii=0;iii<currItemCount;iii++){
            totalLinesRun += 2;
            //if the number we are currently at is bigger than a previously found largestNum:
            if (array[iii]>=largestNum){
                totalLinesRun += 1;
                //not at the end of the array
                if (iii < (currItemCount-1) ){
                    totalLinesRun += 3;
                    largestNum = array[iii];
                    largestNumPos = iii;
                }
                    //at the end of the array
                else if (iii==(currItemCount-1)){
                    totalLinesRun += 2;
                    return iii;
                }
                //if we get through the array without finding anything bigger
            } else if (iii==(currItemCount-1)){
                totalLinesRun += 2;
                return largestNumPos;
            }
        }
    }
}

//returns the total number of lines run by this object
template <class ItemType>
long ArrayList<ItemType>::getTotalLinesRun(){
    totalLinesRun += 1;
    return totalLinesRun;
}

//resets the value of totalLinesRun to 0
template <class ItemType>
void ArrayList<ItemType>::resetTotalLinesRun(){
    totalLinesRun = 0;
}

template <class ItemType>
int ArrayList<ItemType>::calcSizeOf(){
    totalLinesRun += 1;
    return currCapacity * sizeof(int);
}

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

<ItemType>
void ArrayList<ItemType>::shrinkCapacity() {
    if (this->currItemCount < this->currCapacity){
        if (this->currCapacity%this->currItemCount=0){
            this->currCapacity = this->currItemCount;
        }
    }
}

template <class ItemType>
std::string ArrayList<ItemType>::pop(){
    std::string toBePopped = array[0];
    for (int iii;iii<this->getCurrItemCount();iii++){
        array[iii] = array[iii+1];
    }
    this->currItemCount = this->currItemCount-1;
    shrinkCapacity();
    return toBePopped;
}



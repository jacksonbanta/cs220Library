//
// Created by Toby Dragon on 9/30/16.
//

#ifndef LAB7SOLN_LINKEDLIST_H
#define LAB7SOLN_LINKEDLIST_H

#include <stdexcept>
#include<string>

#include "List.h"
#include "LinkedNode.h"
#include "Book.h"


class LinkedList{
private:
    LinkedNode* start;
    LinkedNode* end;
    int currItemCount;
    long totalLinesRun;

public:
    // @param: none
    // ----------
    // Creates an empty Linked List
    // ----------
    LinkedList();

    // @param: none
    // ----------
    // Deletes all the nodes in the linked list
    // ----------
    ~LinkedList();

    // @param: const LinkedList &other - Another Linked list by reference
    // ----------
    // Overrides the assignment operator, Creates a copy of the other linked list
    // ----------
    LinkedList& operator=(const LinkedList &other);


    // @param: const LinkedList &other - Another Linked list by reference
    // ----------
    // Creates a copy of the other linked list passed by reference
    // ----------
    LinkedList(const LinkedList &other);

    // @param: Book* bookToAdd - Book pointer
    // ----------
    // Adds a book by pointer to the end of the linked list
    // Book becomes property of the LinkedList
    // and will be deleted by the LinkedList in destructor
    // ----------
    void addToEnd(Book* itemToAdd);

    // @param: Book* bookToAdd - Book pointer
    // ----------
    // Adds a book by pointer to the front of the linked list
    // Book becomes property of the LinkedList
    // and will be deleted by the LinkedList in destructor
    // ----------
    void addToFront(Book* itemToAdd);


    // @param: Book* bookToAdd - Book pointer, int index - location of insertion
    // ----------
    // Adds a book by pointer to the specified index of the linked list
    // Book becomes property of the LinkedList
    // and will be deleted by the LinkedList in destructor
    // if the index is invalid, returns an out_of_range exception
    // ----------
    void add(Book* itemToAdd, int index);

    // @param: int index - location of book to get
    // ----------
    // gets and returns book at the specified index
    // ----------
    Book* get(int index) const;

    // @param: int index - location of book to remove
    // ----------
    // removes and deletes the node at the specified index
    // gets and returns a copy of the book at the specified index
    // LinkedList loses responsibility of deleting book
    // function caller is responsible for deleting the book.
    // if the index is invalid, returns an out_of_range exception
    // ----------
    Book* remove(int index);

    // @param: none
    // ----------
    // check to see if there are any valid items in the linked list
    // returns True if empty, False if there are valid items
    // ----------
    bool isEmpty();


    // @param: none
    // ----------
    // returns the number of valid items in the LinkedList
    // ----------
    int size();


    // @param: none
    // ----------
    // clears the list by deleting the nodes
    // and setting the item count to 0
    // ----------
    void clearList();


    // @param: std::string title - The title of a book as a std::string
    // ----------
    // finds a book with the input title, returns the index of the book
    // ----------
    int findTitle(std::string title);


    // @param: std::string ISBN - The ISBN of a book as a std::string
    // ----------
    // finds a book with the input ISBN, returns the index of the book
    // ----------
    int findISBN(std::string ISBN);


    // @param: Book* itemToFind - book to find
    // ----------
    // finds and returns the index of the book to find
    // ----------
    int find(Book* itemToFind);


    // @param: none
    // ----------
    // returns the number of lines run by the LinkedList
    // ----------
    long getTotalLinesRun();


    // @param: none
    // ----------
    // resets the number of lines run to 0
    // ----------
    void resetTotalLinesRun();


    // @param: none
    // ----------
    // calculates and returns the memory size of the Linked List
    // ----------
    int calcSizeOf();


    // @param: none
    // ----------
    // prints out all the books in the LinkedList
    // ----------
    std::string toString();


};


#endif //LAB7SOLN_LINKEDLIST_H

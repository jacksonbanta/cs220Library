//
// Created by Kenny Potts on 11/29/16.
//

#include "Inventory.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

Inventory::Inventory() {

    string author;
    string title;
    string ISBN;
    string price;
    string haveValue;
    string wantValue;
    string waitListString;

    this->itemsInStock = new LinkedList<Book*>;
    this->bookStock = 0;

    ifstream infile;
    infile.open("inventoryData.txt");

    if (infile) {
        while (infile) {
            string line;
            getline(infile, line); // get the line
            stringstream splitter(line); // create line string stream splitter
            getline(splitter, author, ',');
            getline(splitter, title, ',');
            getline(splitter, ISBN, ',');
            getline(splitter, price, ',');
            getline(splitter, haveValue, ',');
            getline(splitter, wantValue, ',');
            splitter.ignore('{');
            getline(splitter, waitListString, '}');

            Book *currBook = new Book(title,author,atof( price.c_str() ),
                                      ISBN, stoi(haveValue), stoi(wantValue));

            waitListString += ","; // add delimiter to end for parsing
            std::string tempPerson;
            if (waitListString.length() != 0) { // check not empty
                stringstream persons(waitListString); //create persons string stream
                while (persons) { // check for more data
                    getline(persons, tempPerson, ','); // get
                    currBook->addToWaitList(tempPerson);
                    persons.ignore(' ');
                }
            }

            while (splitter) {
                getline(splitter, tempPerson);
                currBook->addToWaitList(tempPerson);
            }
            this->addNewBook(currBook); //TODO: address pbv vs pbp and consequences
            //TODO: is there book copy constructor, how are they deleted when linked list is deleted, templating issue?
            this->bookStock ++;

        }
    } else {
        throw runtime_error("File Not Found");
    }
    infile.close();
}

Inventory::Inventory(Inventory &other) {
    this->itemsInStock = new LinkedList<Book*>;
    this->bookStock = 0;

    for (int i = 0; i < other.bookStock; ++i) {
        Book* otherCurrBook = other.itemsInStock->get(i);
        Book newBookCopy = Book(*otherCurrBook);
        Book* newBookPtr = &newBookCopy; // grab pointer to new book
        this->itemsInStock->addToEnd(newBookPtr); //  add book to end because books are already in order
        this->bookStock++; // increment book stock
    }
}

Inventory& Inventory::operator=(const Inventory &inventoryToCopy) {

}

Inventory::~Inventory() {

    ofstream outfile;
    outfile.open("inventoryData.txt");

    for (int i = 0; i < this->bookStock; ++i) { //loop through books in linked list
        Book *currBook = this->itemsInStock->get(i);

        // write book data to outfile
        outfile << currBook->getAuthor() << ",";
        outfile << currBook->getTitle() << ",";
        outfile << currBook->getISBN() << ",";
        outfile << currBook->getPrice() << ",";
        outfile << currBook->getHaveValue() << ",";
        outfile << currBook->getWantValue() << ",";
        outfile << currBook->waitListToString() << endl;
    }

    outfile.close(); // close file output stream

    delete this->itemsInStock; // delete linked list (linked list destrustor is called)
    this->itemsInStock = nullptr;

}

//TODO: .cpp implementation




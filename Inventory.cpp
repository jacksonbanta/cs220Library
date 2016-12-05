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

            Book *currBook = new Book(title,author,atof( price.c_str() ),
                                      ISBN, stoi(haveValue), stoi(wantValue));
            std::string tempPerson = "";

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

Inventory::~Inventory() {
    //TODO: Output to file

    ofstream outfile;
    outfile.open("inventoryData.txt");

    for (int i = 0; i < this->bookStock; ++i) {
        Book *currBook = this->itemsInStock->get(i);
        outfile << currBook->getAuthor() << ",";
        outfile << currBook->getTitle() << ",";
        outfile << currBook->getISBN() << ",";
        outfile << currBook->getPrice() << ",";
        outfile << currBook->getHaveValue() << ",";
        outfile << currBook->getWantValue() << ",";
        //TODO: output waitlist here
    }


    outfile.close();

    delete this->itemsInStock;
    this->itemsInStock = nullptr;

}

//TODO: .cpp implementation




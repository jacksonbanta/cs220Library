//
// Created by Kenny Potts on 11/29/16.
//

#include "Inventory.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>


Inventory::Inventory() {

    std::string author;
    std::string title;
    std::string ISBN;
    std::string price;
    std::string haveValue;
    std::string wantValue;
    std::string waitListString;

    this->itemsInStock = new LinkedList();
    this->bookStock = 0;

    std::ifstream infile;
    infile.open("inventoryData.txt");

    if (infile) {
        while (infile.good()) {        //TODO: i read online that .good() updates the infile for the loop -- kevin
            std::string line;
            getline(infile, line); // get the line
            std::stringstream splitter(line); // create line string stream splitter
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
                std::stringstream persons(waitListString); //create persons string stream
                while (persons.good()) { // check for more data     //TODO: i read online that .good() updates the infile for the loop -- kevin
                    getline(persons, tempPerson, ','); // get
                    currBook->addToWaitList(tempPerson);
                    if (persons) {
                        persons.ignore(' ');
                    }
                }
            }

            while (splitter.good()) {           //TODO: i read online that .good() updates the infile for the loop -- kevin
                getline(splitter, tempPerson);
                currBook->addToWaitList(tempPerson);
            }
            this->addNewBook(currBook); //TODO: address pbv vs pbp and consequences
            //TODO: is there book copy constructor, how are they deleted when linked list is deleted, templating issue?
            this->bookStock ++;

        }
    } else {
        throw std::runtime_error("File Not Found");
    }
    infile.close();
}

Inventory::Inventory(const Inventory &other) {
    this->itemsInStock = new LinkedList();
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
    if (this != &inventoryToCopy) { // check for self
        this->itemsInStock = new LinkedList();
        this->bookStock = 0;

        for (int i = 0; i < inventoryToCopy.bookStock; ++i) {
            Book* otherCurrBook = inventoryToCopy.itemsInStock->get(i);
            Book newBookCopy = Book(*otherCurrBook);
            Book* newBookPtr = &newBookCopy; // grab pointer to new book
            this->itemsInStock->addToEnd(newBookPtr); //  add book to end because books are already in order
            this->bookStock++; // increment book stock
        }
    }
    return *this;
}

Inventory::~Inventory() {

    std::ofstream outfile;
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
        outfile << currBook->waitListToString() << std::endl;
    }
    delete this->itemsInStock;
    this->itemsInStock = nullptr;
}

long Inventory::calcSizeOf() {
    //TODO
}

void Inventory::addNewBook(Book *bookToAdd) {
    int count = 0;
    const char* newTitle = bookToAdd->getTitle().c_str();
    for (int i = 0; i < bookStock; ++i) {
        Book* iter = itemsInStock->get(i);
        const char* titleChar = iter->getTitle().c_str();
        if (titleChar[0] > newTitle[0]){
            itemsInStock->add(bookToAdd, i);
            break;
        }else if(titleChar[0] == newTitle[0]){
            if (titleChar[1] > newTitle[1]){
                itemsInStock->add(bookToAdd, i);
                break;
            }else if(titleChar[1] == newTitle[1]){
                if (titleChar[2] > newTitle[2]){
                    itemsInStock->add(bookToAdd, i);
                    break;
                }else{
                    itemsInStock->add(bookToAdd, i);
                }
            }else{
                continue;
            }
        }else{
            count++;
            continue;
        }
    }
    if (count == bookStock) {
        //std::cout << "Adding to end of list" << std::endl;  //TODO: Check if this code gets run
        itemsInStock->addToEnd(bookToAdd);  // Adds to end if it doesn't break out of loop
    }
}

void Inventory::addNewBook(std::string author, std::string title, std::string ISBN, double price, int haveValue,
                           int wantValue) {
    Book* bookToAdd = new Book(title, author, price, ISBN, haveValue, wantValue);
    const char* newTitle = title.c_str();
    int count = 0;
    for (int i = 0; i < bookStock; ++i) {
        Book* iter = itemsInStock->get(i);
        const char* titleChar = iter->getTitle().c_str();
        if (titleChar[0] > newTitle[0]){
            itemsInStock->add(bookToAdd, i);
            bookStock++;
            break;
        }else if(titleChar[0] == newTitle[0]){
            if (titleChar[1] > newTitle[1]){
                itemsInStock->add(bookToAdd, i);
                bookStock++;
                break;
            }else if(titleChar[1] == newTitle[1]){
                if (titleChar[2] > newTitle[2]){
                    itemsInStock->add(bookToAdd, i);
                    bookStock++;
                    break;
                }else{
                    itemsInStock->add(bookToAdd, i);
                    bookStock++;
                    break;
                }
            }else{
                continue;
            }
        }else{
            count++;
            continue;
        }
    }
    if (count == bookStock) {
        std::cout << "Adding to end of list" << std::endl;  //TODO: Check if this code gets run
        itemsInStock->addToEnd(bookToAdd);  // Adds to end if it doesn't break out of loop
        bookStock++;
    }
}

Book* Inventory::findBook(std::string title) {
    int index = itemsInStock->findTitle(title);
    if (index != -1){
        Book* copiedBook = itemsInStock->get(index);
        return copiedBook;
    }else{
        return nullptr;
    }
}

void Inventory::removeBook(Book *bookToRemove) {
    if (itemsInStock->findTitle(bookToRemove->getTitle()) == -1){
        std::cout << "Book not in inventory" << std::endl;
    }else{
        int index = itemsInStock->findTitle(bookToRemove->getTitle());
        Book* tempBook = itemsInStock->get(index);
        if (tempBook->getHaveValue() > 1){
            tempBook->setHaveValue(tempBook->getHaveValue() - 1);
            itemsInStock->remove(index);
        }else{
            itemsInStock->remove(index);
        }
    }
}

int Inventory::findTitle(std::string title) {
    return itemsInStock->findTitle(title);
}

void Inventory::inquire(std::string title){
    Book* tempBook = this->itemsInStock->get(this->itemsInStock->findTitle(title));
    std::cout << "Title: " << tempBook->getTitle() << std::endl;
    std::cout << "Author: " << tempBook->getAuthor() << std::endl;
    std::cout << "ISBN: " << tempBook->getISBN() << std::endl;
    std::cout << "Price: " << tempBook->getPrice() << std::endl;
    std::cout << "Have Value: " << tempBook->getHaveValue() << std::endl;
    std::cout << "Want Value: " << tempBook->getWantValue() << std::endl;
}

void Inventory::delivery(std::string file_name){
    std::string author;
    std::string title;
    std::string ISBN;
    std::string price;
    std::string haveValue;
    std::string wantValue;

    std::ifstream infile;
    infile.open(file_name);
    if (infile) {
        while (infile.good()) {      //TODO: i read online that .good() updates the infile for the loop -- kevin
            std::string line;
            getline(infile, line); // get the line
            std::stringstream splitter(line); // create line string stream splitter
            getline(splitter, author, ',');
            getline(splitter, title, ',');
            getline(splitter, ISBN, ',');
            getline(splitter, price, ',');
            getline(splitter, haveValue, ',');
            getline(splitter, wantValue, ',');

            Book *currBook = new Book(title,author,atof( price.c_str() ),
                                      ISBN, stoi(haveValue), stoi(wantValue));
            std::string tempPerson = "";

            while (splitter.good()) {       //TODO: i read online that .good() updates the infile for the loop -- kevin
                getline(splitter, tempPerson);
                currBook->addToWaitList(tempPerson);
            }
            this->addNewBook(currBook); //TODO: address pbv vs pbp and consequences
            //TODO: is there book copy constructor, how are they deleted when linked list is deleted, templating issue?
            this->bookStock ++;

        }
    } else {
        throw std::runtime_error("File Not Found");
    }

    infile.close();

}

void Inventory::returnBooks(std::string file_name) {
    std::ofstream outfile;
    outfile.open(file_name);
    for (int i = 0; i < bookStock; ++i) {
        Book* temp = itemsInStock->get(i);
        if (temp->getHaveValue() > temp->getWantValue()){
            outfile << temp->getAuthor() << ",";
            outfile << temp->getTitle() << ",";
            outfile << temp->getISBN() << ",";
            outfile << temp->getPrice() << ",";
            outfile << temp->getHaveValue() << ",";
            outfile << temp->getWantValue() << ",";
            itemsInStock->remove(i);
        }
    }
}

void Inventory::removeBook(std::string title) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory" << std::endl;
    }else{
        int index = itemsInStock->findTitle(title);
        Book* tempBook = itemsInStock->get(index);
        if (tempBook->getHaveValue() > 1){
            tempBook->setHaveValue(tempBook->getHaveValue() - 1);
            itemsInStock->remove(index);
        }else{
            itemsInStock->remove(index);
        }
    }
}

void Inventory::setWant(std::string title, int newWant) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else {
        int index = itemsInStock->findTitle(title);
        Book* temp = itemsInStock->get(index);
        temp->setWantValue(newWant);
    }
}

void Inventory::setHave(std::string title, int newHave) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else {
        int index = itemsInStock->findTitle(title);
        Book* temp = itemsInStock->get(index);
        temp->setHaveValue(newHave);
    }
}

int Inventory::currHave(std::string title) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
        return -1;
    }else{
        int index = itemsInStock->findTitle(title);
        Book* temp  = itemsInStock->get(index);
        return temp->getHaveValue();
    }

}

int Inventory::currWant(std::string title) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
        return -1;
    }else{
        int index = itemsInStock->findTitle(title);
        Book* temp = itemsInStock->get(index);
        return temp->getWantValue();
    }
}

void Inventory::list() {
    std::cout << "\n----------------------" << std::endl;
    std::cout << "-----  Inventory -----" << std::endl;
    int count = 1;
    for (int i = 1; i <= bookStock; ++i) {
        Book* temp = itemsInStock->get(i-1);
        if (temp->getHaveValue() > 0) {
            std::cout << count << ") " << " " << temp->getTitle() << "  By: " << temp->getAuthor() << std::endl;
            count++;
        }
    }

}

void Inventory::order(std::string file_name) {
    std::ofstream outfile;
    outfile.open(file_name);
    for (int i = 0; i < bookStock; ++i) {
        Book* temp = itemsInStock->get(i);
        if (temp->getWantValue() > temp->getHaveValue()){
            outfile << temp->getAuthor() << ",";
            outfile << temp->getTitle() << ",";
            outfile << temp->getISBN() << ",";
            outfile << temp->getPrice() << ",";
            outfile << temp->getHaveValue() << ",";
            outfile << temp->getWantValue() << ",";
        }
    }
}

void Inventory::modify(std::string title) {
    if (itemsInStock->findTitle(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else{
        int index = itemsInStock->findTitle(title);
        Book* temp = itemsInStock->get(index);
        std::cout << "Have Value: " << temp->getHaveValue() << std::endl;
        std::cout << "Want Value: " << temp->getWantValue() << std::endl;
        bool tempBool = true;
        while (tempBool) {
            int newWant;
            std::cin.clear();
            std::cout << "Enter new want value: " << std::endl;
            if (!(std::cin >> newWant)){
                std::cin.clear();
                std::cout << "Invalid input.. enter number" << std::endl;
            }else{
                tempBool = false;
            }
        }
    }
}

void Inventory::sell(std::string title) {
    int index = itemsInStock->findTitle(title);
    Book* temp = itemsInStock->get(index);
    temp->setHaveValue(temp->getHaveValue()-1);
}
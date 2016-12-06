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

    this->itemsInStock = new LinkedList<Book*>;
    this->bookStock = 0;

    std::ifstream infile;
    infile.open("inventoryData.txt");

    if (infile) {
        while (infile) {
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

            while (splitter) {
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

Inventory::~Inventory() {
    //TODO: Output to file

    std::ofstream outfile;
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
}

Inventory& Inventory::Inventory(Inventory &other) {
    //TODO
}

Inventory& Inventory::operator=(const Inventory &inventoryToCopy) {
    //TODO
}

void Inventory::addNewBook(Book *bookToAdd) {
    //TODO
}

void Inventory::addNewBook(std::string author, std::string title, std::string ISBN, double price, int haveValue,
                           int wantValue) {
    //TODO
}

Book Inventory::findBook(std::string value, std::string findType) {
    //TODO
}

long Inventory::calcSizeOf() {
    //TODO
}

void Inventory::returnBooks(std::string file_name) {
    //TODO
}

void Inventory::removeBook(Book *bookToAdd) {
    //TODO
}

void Inventory::delivery(std::string file_name){
    //TODO
}

void Inventory::setWant(std::string title, int newWant) {
    if (itemsInStock->find(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else {
        int index = itemsInStock->find(title);
        Book* temp = itemsInStock->get(index);
        temp->setWantValue(newWant);
    }
}

void Inventory::setHave(std::string title, int newHave) {
    if (itemsInStock->find(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else {
        int index = itemsInStock->find(title);
        Book* temp = itemsInStock->get(index);
        temp->setHaveValue(newHave);
    }
}

int Inventory::currHave(std::string title) {
    if (itemsInStock->find(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
        return -1;
    }else{
        int index = itemsInStock->find(title);
        Book* temp  = itemsInStock->get(index);
        return temp->getHaveValue();
    }

}

int Inventory::currWant(std::string title) {
    if (itemsInStock->find(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
        return -1;
    }else{
        int index = itemsInStock->find(title);
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
    for (int i = 0; i < bookStock; ++i) {
        Book* temp = itemsInStock->get(i);
        if (temp->getWantValue() > temp->getHaveValue()){
            //TODO: add book to order
        }
    }
}

void Inventory::modify(std::string title) {
    if (itemsInStock->find(title) == -1){
        std::cout << "Book not in inventory.." << std::endl;
    }else{
        int index = itemsInStock->find(title);
        Book* temp = itemsInStock->get(index);
        std::cout << "Have Value: " << temp->getHaveValue() << std::endl;
        std::cout << "Want Value: " << temp->getWantValue() << std::endl;
        bool tempBool = true;
        while (tempBool) {
            int newWant;
            std::cin.clear();
            std::cout << "Enter new want value: " << std::endl;
            std::cin >> newWant;
            if (std::cin.fail()){
                std::cin.clear();
                std::cout << "Invalid input.. enter number" << std::endl;
            }else{
                tempBool = false;
            }
        }
    }
}

void Inventory::sell(std::string title) {
    if (itemsInStock->find(title) == -1){
        //TODO: book not in stock, add book (haveValue = 0, wantValue = 1)
    }else{
        int index = itemsInStock->find(title);
        Book* temp = itemsInStock->get(index);
        temp->setHaveValue(temp->getWantValue()-1);
    }

}




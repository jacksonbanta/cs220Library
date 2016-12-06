//
// Created by Kevin Short on 11/29/16.
//

#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface() {
    this->myInventory = new Inventory();
}

void UserInterface::help(){
    std::cout << "\n------------------------------------------------" << std::endl;
    std::cout << "--------------- List Of Commands ---------------" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "|   H              Help menu                   |" << std::endl;
    std::cout << "|   I <title>      Inquire                     |" << std::endl;
    std::cout << "|   L              List Inventory              |" << std::endl;
    std::cout << "|   A <title>      Add to Inventory            |" << std::endl;
    std::cout << "|   M <title>      Modify want value           |" << std::endl;
    std::cout << "|   S <title>      Sell Book                   |" << std::endl;
    std::cout << "|   O <file_name>  Order Books                 |" << std::endl;
    std::cout << "|   D <file_name>  Delivery (Read-in file)     |" << std::endl;
    std::cout << "|   R <file_name>  Return Book                 |" << std::endl;
    std::cout << "|   Q              Quit (writes out to file)   |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

}


void UserInterface::inquire(std::string title){
    myInventory->inquire(title);
}

void UserInterface::list(){
    myInventory->list();
}

void UserInterface::setUserIn(std::string user_in) {
    this->userIn = user_in;
}

void UserInterface::add(std::string title){
    std::string userTitle;
    std::string userAuthor;
    std::string userISBN;
    std::string price;
    std::string haveVal;
    std::string wantVal;

    bool tempBool = true;
    int count = 0;
    while (tempBool) {
        std::string tempUserIn;
        if (count == 0) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book Title: " << std::endl;
                std::getline(std::cin, userTitle);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                }
            }
        }else if (count == 1) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book Author: " << std::endl;
                std::getline(std::cin, userAuthor);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                }
            }
        }else if (count == 2) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book ISBN: " << std::endl;
                std::getline(std::cin, userISBN);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                }
            }
        }else if (count == 3) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book Price: " << std::endl;
                std::getline(std::cin, price);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                }
            }
        }else if (count == 4) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book Have Value: " << std::endl;
                std::getline(std::cin, haveVal);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                }
            }
        }else if (count == 5) {
            bool innerBool = true;
            while (innerBool) {
                std::cout << "\tNew Book Title: " << std::endl;
                std::getline(std::cin, wantVal);
                if (tempUserIn == ""){
                    continue;
                }else{
                    innerBool = false;
                    count++;
                    tempBool = false;
                    myInventory->addNewBook(userAuthor, userTitle, userISBN, std::atof( price.c_str() ), std::stoi(haveVal), std::stoi(wantVal));
                }
            }
        }
    }
}

void UserInterface::modify(std::string title){
    myInventory->modify(title);
}


void UserInterface::sell(std::string title){
    myInventory->sell(title);
}

void UserInterface::order(std::string file_name){
    myInventory->order(file_name);
}

void UserInterface::delivery(std::string file_name){
    myInventory->delivery(file_name);
}

void UserInterface::returnBooks(std::string file_name) {
    myInventory->returnBooks(file_name);
}

void UserInterface::quit(){
    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "----------- Goodbye.. -----------" << std::endl;
    myInventory->~Inventory();
}


int main(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Welcome to the Book Store Inventory Program" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    bool temp = true;
    UserInterface* myUserInterface = new UserInterface();
    while (temp) {

        // User input
        std::string userIn;
        std::cout << "\tEnter a command: " << std::endl;
        std::getline(std::cin, userIn);
        myUserInterface->setUserIn(userIn);
        const char* charInput = userIn.c_str();

        if (charInput[0] == 'H' && std::strlen(charInput) == 1){
            myUserInterface->help();
            std::cin.clear();
        }else if(charInput[0] == 'I' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->inquire(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'L' && std::strlen(charInput) == 1){
            myUserInterface->list();
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'A' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->add(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'M' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->modify(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'S' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->sell(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'O' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->order(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'D' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->delivery(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'R' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->returnBooks(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'Q' && std::strlen(charInput) == 1){
            myUserInterface->quit();
            std::cin.clear(); // reset failbit
            temp = false;
        }else{
            // user didn't input a string
            std::cin.clear(); // reset failbit
            std::cout << "\t\tInvalid input.. " << std::endl;
        }
    }
}
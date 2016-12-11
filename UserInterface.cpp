//
// Created by Kevin Short on 11/29/16.
//

#include "UserInterface.h"
#include <iostream>

// @param: None
// ----------
// UserInterface Constructor
// ----------
UserInterface::UserInterface() {
    this->myInventory = new Inventory();
}

// @param: None
// ----------
// help prints out all of the commands that the user can enter
// ----------
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

// @param: string title
// ----------
// inquire is a stub function to call the inquire function within the inventory class
// ----------
void UserInterface::inquire(std::string title){
    myInventory->inquire(title);
}

// @param: None
// ----------
// list is a stub function to call the list function within the inventory class
// ----------
void UserInterface::list(){
    myInventory->list();
}

// @param: string userIn
// ----------
// setUserIn sets the user input within the class
// ----------
void UserInterface::setUserIn(std::string user_in) {
    this->userIn = user_in;
}

// @param: string title
// ----------
// add takes in a title and checks to make sure its not in the inventory and if its not
// it prompts the user for an Author, Price, ISBN, haveValue, and wantValue
// ----------
void UserInterface::add(std::string title){
    if (myInventory->findTitle(title) != -1){
        std::cout << "Book already in inventory..." << std::endl;
    }else {
        std::string userTitle;
        std::string userAuthor;
        std::string userISBN;
        std::string price;
        std::string haveVal;
        std::string wantVal;

        bool tempBool = true;
        int count = 0;
        while (tempBool) {
            if (count == 0) {
                bool innerBool = true;                              // while loop for valid input
                while (innerBool) {
                    std::cout << "\tNew Book Author: " << std::endl;
                    std::getline(std::cin, userAuthor);
                    if (userAuthor == "") {
                        std::cout << "Invalid entry..." << std::endl;
                        continue;
                    } else {
                        innerBool = false;
                        count++;
                    }
                }
            } else if (count == 1) {
                bool innerBool = true;
                while (innerBool) {                                     // while loop for valid input
                    std::cout << "\tNew Book ISBN: " << std::endl;
                    std::getline(std::cin, userISBN);
                    if (userISBN == "") {
                        std::cout << "Invalid entry..." << std::endl;
                        continue;
                    } else {
                        innerBool = false;
                        count++;
                    }
                }
            } else if (count == 2) {
                bool innerBool = true;
                while (innerBool) {                                     // while loop for valid input
                    std::cout << "\tNew Book Price: " << std::endl;
                    std::getline(std::cin, price);
                    if (price == "") {
                        std::cout << "Invalid entry..." << std::endl;
                        continue;
                    } else {
                        innerBool = false;
                        count++;
                    }
                }
            } else if (count == 3) {
                bool innerBool = true;
                while (innerBool) {                                     // while loop for valid input
                    std::cout << "\tNew Book Have Value: " << std::endl;
                    std::getline(std::cin, haveVal);
                    if (haveVal == "") {
                        std::cout << "Invalid entry..." << std::endl;
                        continue;
                    } else {
                        innerBool = false;
                        count++;
                    }
                }
            } else if (count == 4) {
                bool innerBool = true;
                while (innerBool) {                                     // while loop for valid input
                    std::cout << "\tNew Book Want Value: " << std::endl;
                    std::getline(std::cin, wantVal);
                    if (wantVal == "") {
                        std::cout << "Invalid entry..." << std::endl;
                        continue;
                    } else {
                        innerBool = false;
                        count++;
                        tempBool = false;
                        myInventory->addNewBook(userAuthor, title, userISBN, std::atof(price.c_str()),
                                                std::stoi(haveVal), std::stoi(wantVal));
                    }
                }
            }
        }
    }
}

// @param: string title
// ----------
// modify is a stub function to call the modify function within the inventory class
// ----------
void UserInterface::modify(std::string title){
    myInventory->modify(title);
}


// @param: string title
// ----------
// sell makes sure the book is in the inventory, and if its not it calls the add() function within this class
// if the book is out of stock it will prompt the user for their name to add to the waitlist
// ----------
void UserInterface::sell(std::string title){
    if (myInventory->findTitle(title) == -1){
        std::cout << "Book not in inventory..." << std::endl;
        add(title);
    }else if(myInventory->findBook(title)->getHaveValue() == 0){
        bool tempBool = true;
        while (tempBool) {
            std::string userName;
            std::cout << "None in stock, enter your name, we'll add you to the waitlist: " << std::endl;
            std::getline(std::cin, userName);
            if (userName == "" || std::cin.fail()){
                std::cout << "Invalid input.." << std::endl;
                continue;
            }else{
                tempBool = false;
                myInventory->findBook(title)->addToWaitList(userName);
                myInventory->findBook(title)->setWantValue(myInventory->currWant(title) + 1);

            }
        }
    } else{
        Book* userBook = myInventory->findBook(title);
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "-- Thank you for purchasing " << title << "--" << std::endl;
        myInventory->sell(title);
    }
}

// @param: string file_name
// ----------
// order is a stub function to call the order function within the inventory class
// ----------
void UserInterface::order(std::string file_name){
    myInventory->order(file_name);
}

// @param: string file_name
// ----------
// delivery is a stub function to call the delivery function within the inventory class
// ----------
void UserInterface::delivery(std::string file_name){
    myInventory->delivery(file_name);
}

// @param: string file_name
// ----------
// return is a stub function to call the return function within the inventory class
// ----------
void UserInterface::returnBooks(std::string file_name) {
    myInventory->returnBooks(file_name);
}

// @param: None
// ----------
// quit is a stub function to call the destructor within the inventory class
// ----------
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

        if (charInput[0] == 'H' && std::strlen(charInput) == 1){    // Help Menu
            myUserInterface->help();
            std::cin.clear();
        }else if(charInput[0] == 'I' && std::strlen(charInput) != 1){   // Inquire command
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->inquire(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'L' && std::strlen(charInput) == 1){   // List command
            myUserInterface->list();
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'A' && std::strlen(charInput) != 1){   // Add command
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->add(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'M' && std::strlen(charInput) != 1){   // Modify command
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->modify(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'S' && std::strlen(charInput) != 1){   // Sell command
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            myUserInterface->sell(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'O' && std::strlen(charInput) != 1){   // Order command
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->order(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'D' && std::strlen(charInput) != 1){   // Delivery command
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->delivery(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'R' && std::strlen(charInput) != 1){   // Return command
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            myUserInterface->returnBooks(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'Q' && std::strlen(charInput) == 1){   // Quit command
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
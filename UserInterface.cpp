//
// Created by Kevin Short on 11/29/16.
//

#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface() {

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

}

void UserInterface::list(){

}

void UserInterface::setUserIn(std::string user_in) {
    this->userIn = user_in;
}

void UserInterface::add(std::string title){
    //TODO: Request author, and sell price (generate random ISBN)
}

void UserInterface::modify(std::string title){

}


void UserInterface::sell(std::string title){

}

void UserInterface::order(std::string file_name){

}

void UserInterface::delivery(std::string file_name){

}

void UserInterface::returnBooks(std::string file_name) {

}

void UserInterface::quit(){

}


int main(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Welcome to the Book Store Inventory Program" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    bool temp = true;
    UserInterface* userInterface = new UserInterface();
    while (temp) {
        std::string userIn;
        std::cout << "\tEnter a command: " << std::endl;
        std::getline(std::cin, userIn);
        userInterface->setUserIn(userIn);
        const char* charInput = userIn.c_str();
        if (charInput[0] == 'H' && std::strlen(charInput) == 1){
            userInterface->help();
            std::cin.clear();
        }else if(charInput[0] == 'I' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->inquire(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'L' && std::strlen(charInput) == 1){
            userInterface->list();
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'A' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->add(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'M' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->modify(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'S' && std::strlen(charInput) != 1){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->sell(title);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'O' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->order(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'D' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->delivery(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'R' && std::strlen(charInput) != 1){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->returnBooks(fileName);
            std::cin.clear(); // reset failbit
        }else if(charInput[0] == 'Q' && std::strlen(charInput) == 1){
            userInterface->quit();
            std::cin.clear(); // reset failbit
            temp = false;
        }else{
            // user didn't input a string
            std::cin.clear(); // reset failbit
            std::cout << "\t\tInvalid input.. " << std::endl;
        }
    }
}
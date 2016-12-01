//
// Created by Kevin Short on 11/29/16.
//

#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface() {

}

void UserInterface::help(){

}


void UserInterface::inquire(std::string title){

}

void UserInterface::list(){

}

void UserInterface::setUserIn(std::string user_in) {
    this->userIn = user_in;
}

void UserInterface::add(std::string title){

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
    std::string userIn;
    bool temp = true;
    std::cout << "\tEnter a command: " << std::endl;
    UserInterface* userInterface = new UserInterface();
    while (temp) {
        std::getline(std::cin, userIn);
        userInterface->setUserIn(userIn);
        const char* charInput = userIn.c_str();
        if (charInput[0] == 'H'){
            userInterface->help();
        }else if(charInput[0] == 'I'){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->inquire(title);
            //std::cout << title << std::endl;
        }else if(charInput[0] == 'L'){
            userInterface->list();
        }else if(charInput[0] == 'A'){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->add(title);
        }else if(charInput[0] == 'M'){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->modify(title);
        }else if(charInput[0] == 'S'){
            std::string title = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                title+=charInput[i];
            }
            userInterface->sell(title);
        }else if(charInput[0] == 'O'){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->order(fileName);
        }else if(charInput[0] == 'D'){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->delivery(fileName);
        }else if(charInput[0] == 'R'){
            std::string fileName = "";
            for (int i = 2; i < strlen(charInput); ++i) {
                fileName+=charInput[i];
            }
            userInterface->returnBooks(fileName);
        }else if(charInput[0] == 'Q'){
            userInterface->quit();
            temp = false;
        }else{
            // user didn't input a string
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            std::cout << "Invalid input.. Try Again: " << std::endl;
        }
    }
}
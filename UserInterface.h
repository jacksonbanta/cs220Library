//
// Created by Kevin Short on 11/15/16.
//

#ifndef CS220LIBRARY_USERINTERFACE_H
#define CS220LIBRARY_USERINTERFACE_H

class UserInterface {


public:

    //constructor
    UserInterface();

    //destructor
    ~UserInterface();

    //help
    void help();

    //inquire
    void inquire(std::string title);

    //list of inventory (alphabetical order by title)
    void list();

    //add book to inventory
    void add(std::string title);

    //modify want value (displays have/want values)
    void modify(std::string title);

    //decreases count by 1, if sold out or doesn't exist: prompt user for buyer's name then put on waitlist
    void sell(std::string title);

    //purchase additional books based on a comparison of the have and want values in the inventory (have and want values should be equal)
    void order(std::string filename);

    //update have values for books coming in, add any new titles to inventory
    void delivery(std::string filename);

    //writes a return invoice to a file for the books that contain a higher have value than want value
    void returnBooks(std::string filename);

    //Saves the inventory and wait-lists in a file and terminate execution
    void quit();

};

#endif //CS220LIBRARY_USERINTERFACE_H

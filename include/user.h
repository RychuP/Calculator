#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id_;
    std::string name_;

public:
    User(std::string _name);
    int getId() const;
    std::string getName() const;

    // prints a welcome message
    void printGreeting();

private:
    int getRandomInt(); 
};

#endif

#include "user.h"
#include <ctime>
#include <iostream>

User::User(std::string _name) : name_(_name) {
    id_ = getRandomInt();
}

int User::getId() const { 
    return  id_; 
}

std::string User::getName() const {
    return name_;
}

void User::printGreeting() {
    std::cout << "Hi, " << name_ << "." << std::endl;
    std::cout << "Your user ID is: " << id_ << std::endl;
}

int User::getRandomInt() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return std::rand();
}

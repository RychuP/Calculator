#include "../include/user.h"
#include "../include/calculation.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector> 

void printSeparator();

int main() {
    std::vector<std::unique_ptr<Calculation>> history; 

    // get user name
    std::string name;
    std::cout << "Enter user name: ";
    std::getline(std::cin, name);

    // create a user and show greeting
    auto user = std::make_unique<User>(name);
    user->printGreeting();
    printSeparator();

    // calculation loop
    char choice = 'y';
    while (choice == 'y') {
        double x, y;
        char o;

        // get user input to calculate
        std::cout << "Enter calculation: ";
        if (!(std::cin >> x >> o >> y)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // create a ptr for a calculation
        std::unique_ptr<Calculation> calc;
       
        try {
            // create a calculation based on the user input  
            if (o == '^' || o == 's')
                calc = std::make_unique<ScientificCalculation>(x, o, y);
            else if (o == '+' || o == '-' || o == '*' || o == '/')
                calc = std::make_unique<BasicCalculation>(x, o, y);
            else
                throw std::invalid_argument("Unsupported calculation operator.");

            // print result
            calc->printRes();

            // save calculation to history
            history.push_back(std::move(calc));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        printSeparator();
    }

    // print calculation history
    std::cout << "-- History ( " << history.size() << " ): --" << std::endl;
    
    for (const std::unique_ptr<Calculation> &calc_ptr : history) {
        calc_ptr->printRes();
    }

    return 0;
}

void printSeparator() {
    std::cout << "--------------------" << std::endl;
}

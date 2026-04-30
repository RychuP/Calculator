#include "../include/user.h"
#include "../include/calculation.h"
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

        std::unique_ptr<Calculation> calc;
       
        // establish the type of calculation
        if (o == '^' || o == 's')
            calc = std::make_unique<ScientificCalculation>(x, o, y);
        else
            calc = std::make_unique<BasicCalculation>(x, o, y);

        // print result
        calc->printRes();

        // save to history if valid
        if (calc->isValid()) {
            history.push_back(std::move(calc));
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

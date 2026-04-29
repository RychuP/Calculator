#include "user.h"
#include "calculation.h"
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

        std::cout << "Enter calculation: ";
        if (!(std::cin >> x >> o >> y)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        auto calc_ptr = std::make_unique<Calculation>(x, o, y);
        calc_ptr->printRes();

        if (calc_ptr->isValid()) {
            history.push_back(std::move(calc_ptr));
        }
        
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;

        if (choice == 'y')
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
    std::cout << "-x-+-----xx-----+-x-" << std::endl;
}

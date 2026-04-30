#include "../include/user.h"
#include "../include/calculation.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector> 
#include <sstream>

void printSeparator();
void printError(const std::string& message);

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
    while (true) {
        std::string input;
        std::cout << "Enter calculation (or 'exit'): ";

        // read user input
        if (!std::getline(std::cin >> std::ws, input)) {
            break; // If input completely fails, exit
        }

        // handle exit command
        if (input == "exit") {
            break;
        }

        // handle "ans" keyword for using the last result
        size_t ans_pos = input.find("ans");
        if (ans_pos != std::string::npos) {
            if (history.empty()) {
                printError("No previous calculation to use.");
                continue;
            }
            
            // get the last result
            double last_result = history.back()->getRes();
            
            // replace "ans" with the last result if it exists
            input.replace(ans_pos, 3, std::to_string(last_result));
        }

        // extract the math from our modified string
        std::stringstream ss(input);
        double x, y;
        char o;

        if (!(ss >> x >> o >> y)) {
            printError("Invalid format. Please use 'Number Operator Number'.");
            continue;
        }

        // create a calculation pointer
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
            
            printSeparator();
        }
        catch (const std::exception& e) {
            printError(e.what());
        }
    }

    // print calculation history
    std::cout << "-- History ( " << history.size() << " ): --" << std::endl;
    
    for (const std::unique_ptr<Calculation> &calc : history) {
        calc->printRes();
    }

    return 0;
}

void printSeparator() {
    std::cout << "--------------------" << std::endl;
}

void printError(const std::string &message){
    std::cerr << "Error: " << message << std::endl;
    printSeparator();
}

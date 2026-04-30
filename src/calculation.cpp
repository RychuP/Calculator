#include "../include/calculation.h"
#include <cmath>
#include <stdexcept>

void Calculation::printRes() const {
    std::cout << a_ << " " << op_ << " " << b_ << " = " << res_ << std::endl;
}

void ScientificCalculation::printRes() const {
    if (op_ == 's')
        std::cout << "sqrt(" << a_ << ") = " << res_ << std::endl; 
    else if (op_ == '^')
        std::cout << a_ << " to the power of " << b_ << " = " << res_ << std::endl;  
}

void BasicCalculation::calculate() {
    res_ = op_ == '+' ? a_ + b_ :
           op_ == '-' ? a_ - b_ : 
           op_ == '*' ? a_ * b_ :
           op_ == '/' ? a_ / b_ : 
           throw std::invalid_argument(getOpWarning());
}


void ScientificCalculation::calculate() {
    res_ = op_ == '^' ? std::pow(a_, b_) :
           op_ == 's' ? std::sqrt(a_) :
           throw std::invalid_argument(getOpWarning());
}

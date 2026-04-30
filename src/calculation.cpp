#include "../include/calculation.h"

void Calculation::printRes() const {
    std::cout << a_ << " " << op_ << " " << b_;
    if (valid_) {
        std::cout << " = " << res_ << std::endl;
    }
    else {
        std::cout << " is not a valid operation" << std::endl;
    }
}

void BasicCalculation::calculate() {
    switch (op_) {
        case '+':
            res_ = a_ + b_;
            break;
        case '-':
            res_ = a_ - b_;
            break;
        case '*':
            res_ = a_ * b_;
            break;
        case '/':
            if (b_ != 0) {
                res_ = a_ / b_;
            }
            else {
                valid_ = false;
            }
            break;
        default:
            valid_ = false;
            break;
    };
}


void ScientificCalculation::calculate() {
    switch (op_) {
        case '^':
            res_ = std::pow(a_, b_);
            break;
        case 's':
            if (a_ >= 0) res_ = std::sqrt(a_);
            else valid_ = false;
            break;
        default:
            valid_ = false;
            break;
    };
}

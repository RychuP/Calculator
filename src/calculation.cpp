#include "calculation.h"

Calculation::Calculation(double _a, char _op, double _b) 
    : a_(_a), b_(_b), res_(0), valid_(false), op_(_op) {
    calculate();
}

bool Calculation::isValid() const { return valid_; }

void Calculation::printRes() const {
    std::cout << a_ << " " << op_ << " " << b_;
    if (valid_) {
        std::cout << " = " << res_ << std::endl;
    }
    else {
        std::cout << " is not a valid operation" << std::endl;
    }
}

void Calculation::calculate() {
    valid_ = true;

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

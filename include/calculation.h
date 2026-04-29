#ifndef CALCULATION_H
#define CALCULATION_H

#include <cmath>
#include <memory>
#include <cstdlib> 
#include <iostream>

class Calculation {
private:
    double a_, b_, res_;
    bool valid_;
    char op_;
    
public:
    Calculation(double _a, char _op, double _b);

    // checks if the operator is supported by the calculation
    bool isValid() const;

    // prints the result of the calculation
    void printRes() const;

private:
    void calculate();
};

#endif

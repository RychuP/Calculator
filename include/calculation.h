#ifndef CALCULATION_H
#define CALCULATION_H

#include <cmath>
#include <memory>
#include <cstdlib> 
#include <iostream>

class Calculation {
protected:
    double a_, b_, res_ = 0.0;
    bool valid_ = true;
    char op_;
    
public:
    Calculation(double a, char op, double b) : a_(a), b_(b), op_(op) {}

    virtual ~Calculation() = default; 

    virtual void calculate() = 0; 
    
    bool isValid() const { return valid_; }
    void printRes() const;
};

class BasicCalculation : public Calculation {
public:
    BasicCalculation(double a, char op, double b) : Calculation(a, op, b) {
        calculate();
    }

    void calculate() override; 
};

class ScientificCalculation : public Calculation {
public:
    ScientificCalculation(double a, char op, double b) : Calculation(a, op, b) {
        calculate();
    }

    void calculate() override;
};

#endif

#ifndef CALCULATION_H
#define CALCULATION_H

#include <cmath>
#include <memory>
#include <cstdlib> 
#include <iostream>
#include <stdexcept>

// base class for calculations
class Calculation {
protected:
    double a_, b_, res_ = 0.0;
    char op_;
    
public:
    // base constructor
    Calculation(double a, char op, double b) : a_(a), b_(b), op_(op) {}

    // virtual destructor
    virtual ~Calculation() = default;

    // returns a (left operand)
    double getA() const { return a_; }

    // returns b (right operand)
    double getB() const { return b_; }

    // returns op (operator of the calculation)
    char getOp() const { return op_; }

    // prints result of the calculation
    virtual void printRes() const;

protected:
    virtual void calculate() = 0;

    std::string getOpWarning() { return "Given operator is not supported."; }
};

// performs basic calculations with +, -, * and /
class BasicCalculation : public Calculation {
public:
    BasicCalculation(double a, char op, double b) : Calculation(a, op, b) {
        if (op_ == '/' && b_ == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        calculate();
    }

protected:
    void calculate() override;
};

// performs scientific calculations with ^ (power) and s (sqr root)
class ScientificCalculation : public Calculation {
public:
    ScientificCalculation(double a, char op, double b) : Calculation(a, op, b) {
        if (a < 0) {
            throw std::runtime_error("Square root of a negative number is not a real number");
        }
        calculate();
    }

public:
    void printRes() const override;

protected:
    void calculate() override;
};

#endif

// calculator.cpp
#include <cmath>
#include <limits>
#include "calculator.h"

double Calculator::suma(double a, double b){ return a + b; }
double Calculator::resta(double a, double b){ return a - b; }
double Calculator::mult(double a, double b){ return a * b; }
double Calculator::div(double a, double b){ return b==0.0? std::numeric_limits<double>::quiet_NaN() : a/b; }
double Calculator::pot(double base, double expn){ return std::pow(base, expn); }
double Calculator::raiz(double x){ return (x<0.0)? std::numeric_limits<double>::quiet_NaN() : std::sqrt(x); }

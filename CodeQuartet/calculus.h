// calculus.h
#ifndef CALCULUS_H
#define CALCULUS_H

class Calculus {
public:
    static double limit_numeric(int k, double a, int side);
    static double deriv_central(int k, double x0, double h);
    static double integral_simpson(int k, double a, double b, int n);
};

#endif

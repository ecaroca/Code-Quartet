// equations.h
#ifndef EQUATIONS_H
#define EQUATIONS_H

struct Root2D {
    double x;
    double y;
    bool   ok;
    int    iters;
};

class Equations {
public:
    static double root_bisection(int k, double a, double b, double tol, int itmax);
    static double root_newton(int k, double x0, double tol, int itmax);
    static Root2D system2_newton(int s, double x0, double y0, double tol, int itmax);
};

#endif

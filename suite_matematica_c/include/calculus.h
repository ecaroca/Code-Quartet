// calculus.h
#ifndef CALCULUS_H
#define CALCULUS_H

double limit_numeric(int k, double a, int side /*-1 izq, +1 der*/);
double deriv_central(int k, double x0, double h);
double integral_simpson(int k, double a, double b, int n);

#endif
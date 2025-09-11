// equations.h
#ifndef EQUATIONS_H
#define EQUATIONS_H

double root_bisection(int k, double a, double b, double tol, int itmax);
double root_newton(int k, double x0, double tol, int itmax);

int  system2_newton(int s, double x0, double y0, double tol, int itmax);
void system2_result(double* xr, double* yr);

#endif
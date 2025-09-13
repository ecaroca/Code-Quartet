// calculator.c
#include <math.h>
#include "calculator.h"

double calc_suma(double a, double b){ return a+b; }
double calc_resta(double a, double b){ return a-b; }
double calc_mult(double a, double b){ return a*b; }
double calc_div(double a, double b){ return a/b; }
double calc_pot(double base, double expn){ return pow(base,expn); }
double calc_raiz(double x){ return sqrt(x); }
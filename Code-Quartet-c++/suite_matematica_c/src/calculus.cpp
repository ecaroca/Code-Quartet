// calculus.c
#include <cmath>
#include <limits>
#include <cstdio>
#include "calculus.h"
#include "functions.h"

double limit_numeric(int k, double a, int side){
    // Aproxima con pasos decrecientes h -> 0+
    double h = 1e-1;
    double prev = std::numeric_limits<double>::quiet_NaN();
    for (int i=0;i<12;i++){
        double x = (side>0)? (a + h) : (a - h);
        double fx = f_eval(k, x);
        if (std::isnan(fx) || std::isinf(fx)) return fx;
        if (i>0 && std::isfinite(prev) && std::fabs(fx-prev) < 1e-8) return fx;
        prev = fx;
        h *= 0.1;
    }
    return prev;
}

double deriv_central(int k, double x0, double h){
    if (h<=0) h=1e-5;
    double f1 = f_eval(k, x0+h);
    double f2 = f_eval(k, x0-h);
    return (f1 - f2)/(2.0*h);
}

double integral_simpson(int k, double a, double b, int n){
    if (n<2) n=2;
    if (n%2) n++; // par
    double h = (b-a)/n;
    double s = f_eval(k,a) + f_eval(k,b);
    for (int i=1;i<n;i++){
        double x = a + i*h;
        double fx = f_eval(k,x);
        s += (i%2? 4.0:2.0)*fx;
    }
    return s*(h/3.0);
}
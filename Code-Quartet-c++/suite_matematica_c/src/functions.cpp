// functions.c
#include <cmath>
#include <limits>
#include "functions.h"

double f_eval(int k, double x){
    switch(k){
        case 1: return std::sin(x);
        case 2: return std::cos(x);
        case 3: return std::exp(x);
        case 4: return (x>0)? std::log(x) : std::numeric_limits<double>::quiet_NaN();
        case 5: return x*x;
        case 6: return x*x*x - x - 2.0;
        default: return std::numeric_limits<double>::quiet_NaN();
    }
}
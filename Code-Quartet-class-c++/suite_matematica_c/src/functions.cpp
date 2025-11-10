// functions.cpp
#include <cmath>
#include <limits>
#include "functions.h"

double Functions::f_eval(int k, double x){
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

double Functions::df_eval(int k, double x){
    switch(k){
        case 1: return std::cos(x);
        case 2: return -std::sin(x);
        case 3: return std::exp(x);
        case 4: return (x>0)? 1.0/x : std::numeric_limits<double>::quiet_NaN();
        case 5: return 2.0*x;
        case 6: return 3.0*x*x - 1.0;
        default: return std::numeric_limits<double>::quiet_NaN();
    }
}

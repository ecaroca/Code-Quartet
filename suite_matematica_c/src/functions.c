// functions.c
#include <math.h>
#include "functions.h"

double f_eval(int k, double x){
    switch(k){
        case 1: return sin(x);
        case 2: return cos(x);
        case 3: return exp(x);
        case 4: return (x>0)? log(x) : NAN;
        case 5: return x*x;
        case 6: return x*x*x - x - 2.0;
        default: return NAN;
    }
}
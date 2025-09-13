// equations.c
#include <math.h>
#include <stdio.h>
#include "equations.h"
#include "functions.h"

double root_bisection(int k, double a, double b, double tol, int itmax){
    double fa=f_eval(k,a), fb=f_eval(k,b);
    if (!(fa*fb<0)){ printf("Advertencia: f(a)*f(b)>=0\n"); }
    for (int i=0;i<itmax;i++){
        double c=0.5*(a+b), fc=f_eval(k,c);
        if (fabs(fc)<tol || fabs(b-a)<tol) return c;
        if (fa*fc<0){ b=c; fb=fc; } else { a=c; fa=fc; }
    }
    return 0.5*(a+b);
}

static double deriv_num(int k, double x){
    double h=1e-6;
    return (f_eval(k,x+h)-f_eval(k,x-h))/(2*h);
}

double root_newton(int k, double x0, double tol, int itmax){
    double x=x0;
    for (int i=0;i<itmax;i++){
        double fx=f_eval(k,x);
        double d = deriv_num(k,x);
        if (fabs(d)<1e-14) break;
        double xn = x - fx/d;
        if (fabs(xn-x)<tol) return xn;
        x=xn;
    }
    return x;
}

// ----- Sistemas 2x2 predefinidos -----
// s=1: F1 = x^2 + y^2 - 4,   F2 = exp(x) + y - 1
// s=2: F1 = sin(x) + y - 1,  F2 = x + cos(y) - 1
static void F(int s, double x, double y, double* F1, double* F2){
    switch(s){
        case 1: *F1 = x*x + y*y - 4.0; *F2 = exp(x) + y - 1.0; break;
        case 2: *F1 = sin(x) + y - 1.0; *F2 = x + cos(y) - 1.0; break;
        default: *F1 = *F2 = NAN;
    }
}
static void J(int s, double x, double y, double* a11,double* a12,double* a21,double* a22){
    switch(s){
        case 1: *a11 = 2*x; *a12 = 2*y; *a21 = exp(x); *a22 = 1.0; break;
        case 2: *a11 = cos(x); *a12 = 1.0; *a21 = 1.0; *a22 = -sin(y); break;
        default: *a11=*a12=*a21=*a22=NAN;
    }
}
static double SX, SY; // para devolver resultado

int system2_newton(int s, double x0, double y0, double tol, int itmax){
    double x=x0,y=y0;
    for (int it=0; it<itmax; ++it){
        double F1,F2,a11,a12,a21,a22;
        F(s,x,y,&F1,&F2);
        J(s,x,y,&a11,&a12,&a21,&a22);
        double det = a11*a22 - a12*a21;
        if (fabs(det)<1e-14) return 0;
        // delta = J^{-1} * F
        double dx = ( + a22*F1 - a12*F2)/det;
        double dy = ( - a21*F1 + a11*F2)/det;
        x -= dx; y -= dy;
        if (sqrt(dx*dx+dy*dy) < tol){ SX=x; SY=y; return 1; }
    }
    SX=x; SY=y; return 0;
}
void system2_result(double* xr, double* yr){ if (xr) *xr=SX; if (yr) *yr=SY; }
// equations.cpp
#include <cmath>
#include <limits>
#include "equations.h"
#include "functions.h"

double Equations::root_bisection(int k, double a, double b, double tol, int itmax){
    double fa = Functions::f_eval(k,a);
    double fb = Functions::f_eval(k,b);
    if (std::isnan(fa) || std::isnan(fb) || fa*fb>0) return std::numeric_limits<double>::quiet_NaN();
    double lo=a, hi=b;
    for(int it=0; it<itmax; ++it){
        double mid = 0.5*(lo+hi);
        double fm = Functions::f_eval(k, mid);
        if (std::fabs(fm) < tol || 0.5*(hi-lo) < tol) return mid;
        if (fa*fm<=0){ hi=mid; fb=fm; } else { lo=mid; fa=fm; }
    }
    return 0.5*(lo+hi);
}

double Equations::root_newton(int k, double x0, double tol, int itmax){
    double x = x0;
    for(int it=0; it<itmax; ++it){
        double fx = Functions::f_eval(k, x);
        double d  = Functions::df_eval(k, x);
        if (!std::isfinite(fx) || !std::isfinite(d) || std::fabs(d)<1e-14)
            return std::numeric_limits<double>::quiet_NaN();
        double xn = x - fx/d;
        if (std::fabs(xn-x) < tol) return xn;
        x = xn;
    }
    return x;
}

static inline void sys_eval(int s, double x, double y, double& f, double& g){
    if (s==1){
        f = x*x + y*y - 4.0;
        g = x - y;
    } else {
        f = x*x + y*y - 4.0;
        g = x - y;
    }
}
static inline void sys_jac(int s, double x, double y, double& fx, double& fy, double& gx, double& gy){
    if (s==1){
        fx = 2.0*x; fy = 2.0*y;
        gx = 1.0;   gy = -1.0;
    } else {
        fx = 2.0*x; fy = 2.0*y;
        gx = 1.0;   gy = -1.0;
    }
}

Root2D Equations::system2_newton(int s, double x0, double y0, double tol, int itmax){
    double x=x0, y=y0;
    for(int it=1; it<=itmax; ++it){
        double f,g,fx,fy,gx,gy;
        sys_eval(s,x,y,f,g);
        sys_jac(s,x,y,fx,fy,gx,gy);
        double det = fx*gy - fy*gx;
        if (std::fabs(det) < 1e-14) return {x,y,false,it};
        double dx = (-f*gy + g*fy)/det;
        double dy = (-g*fx + f*gx)/det;
        x += dx; y += dy;
        if (std::sqrt(dx*dx + dy*dy) < tol) return {x,y,true,it};
    }
    return {x,y,false,itmax};
}

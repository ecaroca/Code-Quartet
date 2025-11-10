// plot.cpp
#include <cstdio>
#include <cmath>
#include <vector>
#include <limits>
#include "plot.h"
#include "functions.h"

void Plot::ascii_plot_function(int k, double xmin, double xmax, int width, int height){
    if (width<20) width=80;
    if (height<10) height=25;
    std::vector<double> ys(width);
    double ymin= std::numeric_limits<double>::infinity();
    double ymax=-std::numeric_limits<double>::infinity();
    for(int c=0;c<width;++c){
        double x = xmin + (xmax-xmin)*c/(width-1);
        double y = Functions::f_eval(k, x);
        ys[c]=y;
        if (std::isfinite(y)){
            ymin = std::min(ymin,y);
            ymax = std::max(ymax,y);
        }
    }
    if (!std::isfinite(ymin) || !std::isfinite(ymax)) { std::puts("No se puede graficar."); return; }
    if (std::fabs(ymax-ymin)<1e-12){ ymax+=1.0; ymin-=1.0; }
    int x0 = (int)std::round((0.0 - xmin)/(xmax-xmin)*(width-1));
    int y0 = (int)std::round((ymax - 0.0)/(ymax-ymin)*(height-1));
    for(int r=0;r<height;++r){
        double yline = ymax - (ymax-ymin)*r/(height-1);
        double yline_next = ymax - (ymax-ymin)*(r+1)/(height-1);
        for(int c=0;c<width;++c){
            double yv = ys[c];
            bool mark=false;
            if (std::isfinite(yv)){
                double pix_top=yline_next, pix_bot=yline;
                if (r==0) pix_top = ymax + (ymax-ymin)/height;
                if (yv<=pix_bot && yv>=pix_top) mark=true;
            }
            if (mark) std::putchar('*');
            else if (r==y0 && c==x0) std::putchar('+');
            else if (r==y0) std::putchar('-');
            else if (c==x0) std::putchar('|');
            else std::putchar(' ');
        }
        std::putchar('\n');
    }
}

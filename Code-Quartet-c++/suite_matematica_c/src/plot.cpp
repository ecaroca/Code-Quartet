// plot.c - Gráfico ASCII simple de f(x) en un rectángulo width x height
#include <cstdio>
#include <cmath>
#include <limits>
#include "plot.h"
#include "functions.h"

void ascii_plot_function(int k, double xmin, double xmax, int width, int height){
    if (width<20) width=80;
    if (height<10) height=25;
    double* ys = (double*)malloc(sizeof(double)*width);
    for (int i=0;i<width;i++){
        double x = xmin + (xmax-xmin)*i/(width-1);
        ys[i] = f_eval(k,x);
    }
    // rango y
    double ymin=1e300, ymax=-1e300;
    for (int i=0;i<width;i++){
        if (std::isfinite(ys[i])){
            if (ys[i]<ymin) ymin=ys[i];
            if (ys[i]>ymax) ymax=ys[i];
        }
    }
    if (!(ymax>ymin)){ ymin=-1; ymax=1; }
    // ejes
    int y0 = (0>=ymin && 0<=ymax)? (int)llround((0 - ymin)/(ymax-ymin)*(height-1)) : -1;
    int x0 = (0>=xmin && 0<=xmax)? (int)llround((0 - xmin)/(xmax-xmin)*(width-1)) : -1;
    // render
    for (int r=height-1;r>=0;r--){
        for (int c=0;c<width;c++){
            double yline = ymin + (ymax-ymin)*r/(height-1);
            double yline_next = ymin + (ymax-ymin)*(r-1)/(height-1);
            // marcar función cerca de esta fila
            double yv = ys[c];
            int mark = 0;
            if (std::isfinite(yv)){
                double pix_top = yline_next, pix_bot = yline;
                if (r==0) pix_top = ymax + (ymax-ymin)/height;
                if (yv<=pix_bot && yv>=pix_top) mark = 1;
            }
            if (mark) putchar('*');
            else if (r==y0 && c==x0) putchar('+');
            else if (r==y0) putchar('-');
            else if (c==x0) putchar('|');
            else putchar(' ');
        }
        putchar('\n');
    }
    free(ys);
}
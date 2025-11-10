// main.cpp — Menú interactivo tipo calculadora (C++17)
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

#include "calculator.h"
#include "matrix.h"
#include "calculus.h"
#include "equations.h"
#include "plot.h"
#include "functions.h"

// Utilidades de entrada segura
static void clear_stdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
static double in_double(const char* msg){
    double x;
    for(;;){
        std::cout << msg;
        if (std::cin >> x) return x;
        std::cout << "Entrada inválida. Intenta nuevamente.\n";
        clear_stdin();
    }
}
static int in_int(const char* msg, int lo, int hi){
    int x;
    for(;;){
        std::cout << msg;
        if (std::cin >> x && x>=lo && x<=hi) return x;
        std::cout << "Entrada inválida. Debe estar entre " << lo << " y " << hi << ".\n";
        clear_stdin();
    }
}

// Pequeñas funciones de apoyo para matrices
static Matrix leer_matriz(int n, int m){
    Matrix A(n,m);
    std::cout << "Ingresa " << n*m << " valores (fila por fila):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            double v = in_double("");
            A(i,j)=v;
        }
    }
    return A;
}
static Vector leer_vector(int n){
    Vector b(n);
    std::cout << "Ingresa " << n << " valores del vector:\n";
    for(int i=0;i<n;++i){
        double v = in_double("");
        b(i)=v;
    }
    return b;
}

// Menú de operaciones básicas
static void menu_calculadora(){
    for(;;){
        std::cout <<
        "\n== CALCULADORA BASICA ==\n"
        "1) Suma a+b\n"
        "2) Resta a-b\n"
        "3) Multiplicacion a*b\n"
        "4) Division a/b\n"
        "5) Potencia base^exp\n"
        "6) Raiz sqrt(x)\n"
        "0) Volver\n";
        int op = in_int("Opción: ", 0, 6);
        if (op==0) return;

        if (op>=1 && op<=5){
            double a = in_double("a: ");
            double b = in_double("b: ");
            double r = std::numeric_limits<double>::quiet_NaN();
            if (op==1) r = Calculator::suma(a,b);
            else if (op==2) r = Calculator::resta(a,b);
            else if (op==3) r = Calculator::mult(a,b);
            else if (op==4) r = Calculator::div(a,b);
            else if (op==5) r = Calculator::pot(a,b);
            std::cout << "Resultado: " << r << "\n";
        } else if (op==6){
            double x = in_double("x: ");
            std::cout << "Resultado: " << Calculator::raiz(x) << "\n";
        }
    }
}

// Menú de cálculo (límites, derivadas, integrales)
static void menu_calculus(){
    for(;;){
        std::cout <<
        "\n== CALCULO ==\n"
        "1) Limite numerico de f_k(x) en a (lado izq/der)\n"
        "2) Derivada central de f_k(x) en x0\n"
        "3) Integral (Simpson) de f_k(x) en [a,b]\n"
        "0) Volver\n";
        int op = in_int("Opción: ", 0, 3);
        if (op==0) return;

        int k = in_int("Elige k de f_k (1:sin,2:cos,3:exp,4:log(x>0),5:x^2,6:x^3-x-2): ",1,6);
        if (op==1){
            double a = in_double("a: ");
            int side = in_int("lado (-1 izq, +1 der): ", -1, 1);
            if (side==0) side = 1;
            std::cout << "Limite ~ " << Calculus::limit_numeric(k,a,side) << "\n";
        } else if (op==2){
            double x0 = in_double("x0: ");
            double h  = in_double("h (ej 1e-5): ");
            std::cout << "f'(x0) ~ " << Calculus::deriv_central(k,x0,h) << "\n";
        } else if (op==3){
            double a = in_double("a: ");
            double b = in_double("b: ");
            int n    = in_int("n (par, ej 200): ", 2, 1000000);
            if (n%2) ++n;
            std::cout << "∫ f_k dx ~ " << Calculus::integral_simpson(k,a,b,n) << "\n";
        }
    }
}

// Menú de ecuaciones y sistemas
static void menu_ecuaciones(){
    for(;;){
        std::cout <<
        "\n== ECUACIONES ==\n"
        "1) Raiz (biseccion) de f_k en [a,b]\n"
        "2) Raiz (Newton) de f_k desde x0\n"
        "3) Sistema 2D (Newton) (s=1)\n"
        "0) Volver\n";
        int op = in_int("Opción: ", 0, 3);
        if (op==0) return;
        if (op==1){
            int k = in_int("k (1..6): ",1,6);
            double a = in_double("a: ");
            double b = in_double("b: ");
            double tol = in_double("tol (ej 1e-8): ");
            int itmax  = in_int("itmax: ",1,1000000000);
            std::cout << "raiz ~ " << Equations::root_bisection(k,a,b,tol,itmax) << "\n";
        } else if (op==2){
            int k = in_int("k (1..6): ",1,6);
            double x0 = in_double("x0: ");
            double tol = in_double("tol: ");
            int itmax  = in_int("itmax: ",1,1000000000);
            std::cout << "raiz ~ " << Equations::root_newton(k,x0,tol,itmax) << "\n";
        } else if (op==3){
            int s = 1;
            double x0 = in_double("x0: ");
            double y0 = in_double("y0: ");
            double tol = in_double("tol: ");
            int itmax  = in_int("itmax: ",1,1000000000);
            Root2D r = Equations::system2_newton(s,x0,y0,tol,itmax);
            std::cout << (r.ok? "Convergió":"No convergió")
                      << " en " << r.iters << " iters. (x,y)=("
                      << r.x << ", " << r.y << ")\n";
        }
    }
}

// Menú de matrices
static void menu_matrices(){
    for(;;){
        std::cout <<
        "\n== MATRICES ==\n"
        "1) Resolver Ax=b\n"
        "2) Determinante det(A)\n"
        "3) Inversa A^{-1}\n"
        "0) Volver\n";
        int op = in_int("Opción: ", 0, 3);
        if (op==0) return;

        int n = in_int("n (size de A cuadrada, 1..20): ", 1, 20);
        if (op==1){
            Matrix A = leer_matriz(n,n);
            Vector b = leer_vector(n);
            Vector x = Matrix::solve(A,b);
            std::cout << "x = \n"; x.print();
        } else if (op==2){
            Matrix A = leer_matriz(n,n);
            std::cout << "det(A) = " << Matrix::det(A) << "\n";
        } else if (op==3){
            Matrix A = leer_matriz(n,n);
            Matrix Ai = Matrix::inv(A);
            std::cout << "A^{-1} = \n"; Ai.print();
        }
    }
}

// Menú de funciones/plot
static void menu_funciones_plot(){
    for(;;){
        std::cout <<
        "\n== FUNCIONES Y GRAFICO ASCII ==\n"
        "1) Evaluar f_k(x)\n"
        "2) Graficar f_k(x) en [xmin, xmax]\n"
        "0) Volver\n";
        int op = in_int("Opción: ", 0, 2);
        if (op==0) return;
        int k = in_int("k (1:sin,2:cos,3:exp,4:log(x>0),5:x^2,6:x^3-x-2): ",1,6);
        if (op==1){
            double x = in_double("x: ");
            std::cout << "f_k(x) = " << Functions::f_eval(k,x) << "\n";
        } else if (op==2){
            double xmin = in_double("xmin: ");
            double xmax = in_double("xmax: ");
            int w = in_int("ancho (>=20): ", 20, 500);
            int h = in_int("alto (>=10): ", 10, 200);
            Plot::ascii_plot_function(k,xmin,xmax,w,h);
        }
    }
}

int main(){
    std::cout << "==============================\n";
    std::cout << "  SUITE MATEMATICA (C++ / CLASES)\n";
    std::cout << "==============================\n";

    for(;;){
        std::cout <<
        "\n== MENU PRINCIPAL ==\n"
        "1) Calculadora basica\n"
        "2) Calculo (limite/derivada/integral)\n"
        "3) Ecuaciones (raices y sistema 2D)\n"
        "4) Matrices (Ax=b, det, inversa)\n"
        "5) Funciones y grafico ASCII\n"
        "0) Salir\n";
        int op = in_int("Opción: ", 0, 5);
        if (op==0) break;
        if (op==1) menu_calculadora();
        else if (op==2) menu_calculus();
        else if (op==3) menu_ecuaciones();
        else if (op==4) menu_matrices();
        else if (op==5) menu_funciones_plot();
    }
    std::cout << "Hasta luego!\n";
    return 0;
}

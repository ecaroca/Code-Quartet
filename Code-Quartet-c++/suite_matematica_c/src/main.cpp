// Proyecto: Herramienta educativa para métodos y conceptos matemáticos
// Licencia: MIT
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>

#include "calculator.h"
#include "matrix.h"
#include "calculus.h"
#include "equations.h"
#include "plot.h"
#include "functions.h"

static void pausa() {
    printf("\nPresione ENTER para continuar...");
    int c; while ((c=getchar())!='\n' && c!=EOF) {}
    getchar();
}

static void menu_calculadora() {
    int op;
    do {
        printf("\n=== CALCULADORA ===\n");
        printf("1) Suma\n2) Resta\n3) Multiplicación\n4) División\n5) Potencia\n6) Raíz cuadrada\n0) Volver\n> ");
        if (scanf("%d",&op)!=1) { while(getchar()!='\n'); continue; }
        double a,b;
        switch(op){
            case 1: printf("a b: "); scanf("%lf %lf",&a,&b); printf("Resultado: %.10g\n", calc_suma(a,b)); break;
            case 2: printf("a b: "); scanf("%lf %lf",&a,&b); printf("Resultado: %.10g\n", calc_resta(a,b)); break;
            case 3: printf("a b: "); scanf("%lf %lf",&a,&b); printf("Resultado: %.10g\n", calc_mult(a,b)); break;
            case 4: printf("a b: "); scanf("%lf %lf",&a,&b); if (b==0){printf("Error: división por cero.\n");} else printf("Resultado: %.10g\n", calc_div(a,b)); break;
            case 5: printf("base exp: "); scanf("%lf %lf",&a,&b); printf("Resultado: %.10g\n", calc_pot(a,b)); break;
            case 6: printf("x: "); scanf("%lf",&a); if (a<0){printf("Error: x<0.\n");} else printf("Resultado: %.10g\n", calc_raiz(a)); break;
        }
    } while(op!=0);
    while(getchar()!='\n');
}

static void menu_matriz() {
    int op;
    do {
        printf("\n=== MATRICES ===\n");
        printf("1) Suma A+B\n2) Multiplicación A*B\n3) Determinante(A)\n4) Inversa(A)\n5) Resolver Ax=b\n0) Volver\n> ");
        if (scanf("%d",&op)!=1) { while(getchar()!='\n'); continue; }
        int n,m,p;
        Matrix A,B,C; Vector b,x;
        switch(op){
            case 1:
                printf("Dimensiones n m: "); scanf("%d %d",&n,&m);
                A = mat_leer(n,m,"A"); B = mat_leer(n,m,"B");
                C = mat_add(A,B);
                printf("A+B =\n"); mat_print(C);
                mat_free(&A); mat_free(&B); mat_free(&C);
                break;
            case 2:
                printf("Dimensiones A (n x m): "); scanf("%d %d",&n,&m);
                printf("Dimensiones B (m x p): "); scanf("%d %d",&m,&p);
                A = mat_leer(n,m,"A"); B = mat_leer(m,p,"B");
                C = mat_mul(A,B);
                printf("A*B =\n"); mat_print(C);
                mat_free(&A); mat_free(&B); mat_free(&C);
                break;
            case 3:
                printf("Orden n (cuadrada): "); scanf("%d",&n);
                A = mat_leer(n,n,"A");
                printf("det(A) = %.10g\n", mat_det(A));
                mat_free(&A);
                break;
            case 4:
                printf("Orden n (cuadrada): "); scanf("%d",&n);
                A = mat_leer(n,n,"A");
                C = mat_inv(A);
                printf("A^{-1} =\n"); mat_print(C);
                mat_free(&A); mat_free(&C);
                break;
            case 5:
                printf("Orden n (cuadrada): "); scanf("%d",&n);
                A = mat_leer(n,n,"A");
                b = vec_leer(n,"b");
                x = mat_solve(A,b);
                printf("Solución x =\n"); vec_print(x);
                mat_free(&A); vec_free(&b); vec_free(&x);
                break;
        }
    } while(op!=0);
    while(getchar()!='\n');
}

static int elegir_funcion() {
    printf("\nFunciones disponibles (f(x)):\n");
    printf("1) std::sin(x)\n2) std::cos(x)\n3) std::exp(x)\n4) ln(x) (x>0)\n5) x^2\n6) x^3 - x - 2\n> ");
    int k; scanf("%d",&k);
    while(getchar()!='\n');
    return k;
}

static void menu_limites() {
    printf("\n=== LÍMITES (aprox. numérica) ===\n");
    int k = elegir_funcion();
    double a; printf("Punto a donde x->a: "); scanf("%lf",&a);
    while(getchar()!='\n');
    double Lr = limit_numeric(k,a,+1);
    double Ll = limit_numeric(k,a,-1);
    printf("Límite por la derecha: %.10g\n", Lr);
    printf("Límite por la izquierda: %.10g\n", Ll);
    if (std::isfinite(Lr) && std::isfinite(Ll) && std::fabs(Lr-Ll) < 1e-6) {
        printf("≈ Límite bilateral: %.10g\n", 0.5*(Lr+Ll));
    } else {
        printf("El límite bilateral podría no existir o ser distinto por cada lado.\n");
    }
}

static void menu_derivadas() {
    printf("\n=== DERIVADAS (numéricas) ===\n");
    int k = elegir_funcion();
    double x,h; printf("Punto x0: "); scanf("%lf",&x);
    printf("Paso h (sug. 1e-5): "); scanf("%lf",&h);
    while(getchar()!='\n');
    double d = deriv_central(k,x,h);
    printf("f'(x0) ≈ %.10g\n", d);
}

static void menu_integrales() {
    printf("\n=== INTEGRALES (Simpson compuesto) ===\n");
    int k = elegir_funcion();
    double a,b; int n;
    printf("Intervalo [a,b]: "); scanf("%lf %lf",&a,&b);
    printf("Subintervalos pares n (sug. 200): "); scanf("%d",&n);
    while(getchar()!='\n');
    double I = integral_simpson(k,a,b,n);
    printf("∫_a^b f(x) dx ≈ %.10g\n", I);
}

static void menu_graficos() {
    printf("\n=== GRÁFICOS ASCII ===\n");
    int k = elegir_funcion();
    double xmin,xmax; printf("Rango x_min x_max (p.ej. -10 10): "); scanf("%lf %lf",&xmin,&xmax);
    while(getchar()!='\n');
    ascii_plot_function(k, xmin, xmax, 80, 25);
}

static void menu_ecuaciones() {
    int op;
    do {
        printf("\n=== ECUACIONES (f(x)=0) ===\n");
        printf("1) Bisección\n2) Newton-Raphson\n0) Volver\n> ");
        if (scanf("%d",&op)!=1) { while(getchar()!='\n'); continue; }
        int k; double a,b,x0;
        switch(op){
            case 1:
                k = elegir_funcion();
                printf("Intervalo [a,b] (f(a)*f(b)<0): "); scanf("%lf %lf",&a,&b);
                while(getchar()!='\n');
                printf("Raíz ≈ %.10g\n", root_bisection(k,a,b,1e-10,1000));
                break;
            case 2:
                k = elegir_funcion();
                printf("x0 (inicial): "); scanf("%lf",&x0);
                while(getchar()!='\n');
                printf("Raíz ≈ %.10g\n", root_newton(k,x0,1e-10,1000));
                break;
        }
    } while(op!=0);
    while(getchar()!='\n');
}

static void menu_sistemas() {
    printf("\n=== SISTEMAS NO LINEALES (2x2) ===\n");
    printf("Sistemas disponibles F(x,y)=(0,0):\n");
    printf("1) { x^2 + y^2 - 4 = 0 ;  std::exp(x) + y - 1 = 0 }\n");
    printf("2) { std::sin(x) + y - 1 = 0 ;  x + std::cos(y) - 1 = 0 }\n");
    int s; printf("> "); scanf("%d",&s);
    double x0,y0; printf("x0 y0 (inicial): "); scanf("%lf %lf",&x0,&y0);
    while(getchar()!='\n');
    double xr, yr;
    int ok = system2_newton(s, x0, y0, 1e-10, 100);
    system2_result(&xr,&yr);
    if (ok) printf("Solución ≈ (x,y) = (%.12g, %.12g)\n", xr, yr);
    else    printf("No convergió. Pruebe otros x0,y0.\n");
}

int main(void){
    int op;
    do {
        printf("\n==============================\n");
        printf("  SUITE MATEMÁTICA EN C++\n");
        printf("==============================\n");
        printf("1) Calculadora\n");
        printf("2) Matrices\n");
        printf("3) Límites\n");
        printf("4) Derivadas\n");
        printf("5) Integrales\n");
        printf("6) Ecuaciones (f(x)=0)\n");
        printf("7) Sistemas no lineales (2x2)\n");
        printf("8) Gráficos ASCII de f(x)\n");
        printf("0) Salir\n> ");
        if (scanf("%d",&op)!=1) { while(getchar()!='\n'); continue; }
        switch(op){
            case 1: menu_calculadora(); break;
            case 2: menu_matriz(); break;
            case 3: menu_limites(); break;
            case 4: menu_derivadas(); break;
            case 5: menu_integrales(); break;
            case 6: menu_ecuaciones(); break;
            case 7: menu_sistemas(); break;
            case 8: menu_graficos(); break;
            case 0: printf("Hasta luego!\n"); break;
            default: printf("Opción inválida.\n"); break;
        }
    } while(op!=0);
    return 0;
}

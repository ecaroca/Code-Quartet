// matrix.c - Operaciones básicas de matrices con pivot parcial
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

Matrix mat_new(int n, int m){
    Matrix A; A.n=n; A.m=m; A.a = (double*)calloc((size_t)n*m,sizeof(double)); return A;
}
Matrix mat_identity(int n){
    Matrix I = mat_new(n,n);
    for (int i=0;i<n;i++) I.a[i*n+i]=1.0;
    return I;
}
void mat_free(Matrix* A){ if (A && A->a){ free(A->a); A->a=NULL; A->n=A->m=0; } }
void mat_set(Matrix A, int i, int j, double x){ A.a[i*A.m+j]=x; }
double mat_get(Matrix A, int i, int j){ return A.a[i*A.m+j]; }
void mat_print(Matrix A){
    for (int i=0;i<A.n;i++){
        for (int j=0;j<A.m;j++) printf("%12.6g ", mat_get(A,i,j));
        printf("\n");
    }
}
Vector vec_new(int n){ Vector x; x.n=n; x.v=(double*)calloc((size_t)n,sizeof(double)); return x; }
void vec_free(Vector* x){ if (x && x->v){ free(x->v); x->v=NULL; x->n=0; } }
void vec_set(Vector x, int i, double val){ x.v[i]=val; }
double vec_get(Vector x, int i){ return x.v[i]; }
void vec_print(Vector x){ for (int i=0;i<x.n;i++) printf("%12.6g\n", x.v[i]); }

Matrix mat_leer(int n, int m, const char* nombre){
    Matrix A = mat_new(n,m);
    printf("Ingrese matriz %s (%d x %d):\n", nombre, n,m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            double x; scanf("%lf",&x); mat_set(A,i,j,x);
        }
    return A;
}
Vector vec_leer(int n, const char* nombre){
    Vector b = vec_new(n);
    printf("Ingrese vector %s (%d):\n", nombre, n);
    for (int i=0;i<n;i++){ double x; scanf("%lf",&x); vec_set(b,i,x); }
    return b;
}

Matrix mat_add(Matrix A, Matrix B){
    if (A.n!=B.n || A.m!=B.m){ printf("Dimensiones incompatibles\n"); return mat_new(0,0); }
    Matrix C = mat_new(A.n,A.m);
    for (int i=0;i<A.n;i++)
        for (int j=0;j<A.m;j++)
            mat_set(C,i,j, mat_get(A,i,j)+mat_get(B,i,j));
    return C;
}

Matrix mat_mul(Matrix A, Matrix B){
    if (A.m!=B.n){ printf("Dimensiones incompatibles\n"); return mat_new(0,0); }
    Matrix C = mat_new(A.n,B.m);
    for (int i=0;i<A.n;i++)
        for (int k=0;k<A.m;k++){
            double aik = mat_get(A,i,k);
            for (int j=0;j<B.m;j++)
                C.a[i*C.m+j] += aik * mat_get(B,k,j);
        }
    return C;
}

// Eliminación Gaussiana con pivot parcial - retorna |A|
static double gauss_elim(Matrix A, int* piv){
    int n=A.n;
    double det=1.0;
    for (int i=0;i<n;i++) piv[i]=i;
    for (int k=0;k<n;k++){
        // pivot
        int p=k; double maxv=fabs(mat_get(A,p,k));
        for (int i=k+1;i<n;i++){
            double v=fabs(mat_get(A,i,k));
            if (v>maxv){ maxv=v; p=i; }
        }
        if (maxv<1e-15) return 0.0;
        if (p!=k){
            for (int j=k;j<n;j++){
                double tmp = mat_get(A,k,j);
                mat_set(A,k,j, mat_get(A,p,j));
                mat_set(A,p,j, tmp);
            }
            int tp=piv[k]; piv[k]=piv[p]; piv[p]=tp;
            det = -det;
        }
        double akk = mat_get(A,k,k);
        det *= akk;
        for (int i=k+1;i<n;i++){
            double factor = mat_get(A,i,k)/akk;
            mat_set(A,i,k,0.0);
            for (int j=k+1;j<n;j++)
                mat_set(A,i,j, mat_get(A,i,j) - factor*mat_get(A,k,j));
        }
    }
    return det;
}

double mat_det(Matrix A){
    if (A.n!=A.m){ printf("No cuadrada.\n"); return NAN; }
    Matrix C = mat_new(A.n,A.n);
    for (int i=0;i<A.n;i++) for (int j=0;j<A.n;j++) mat_set(C,i,j, mat_get(A,i,j));
    int* piv = (int*)malloc(sizeof(int)*A.n);
    double det = gauss_elim(C,piv);
    free(piv); mat_free(&C);
    return det;
}

Matrix mat_inv(Matrix A){
    if (A.n!=A.m){ printf("No cuadrada.\n"); return mat_new(0,0); }
    int n=A.n;
    Matrix AI = mat_new(n,2*n);
    // Construir [A | I]
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) mat_set(AI,i,j, mat_get(A,i,j));
        for (int j=0;j<n;j++) mat_set(AI,i,n+j, (i==j)?1.0:0.0);
    }
    // Gauss-Jordan con pivoteo parcial
    for (int k=0;k<n;k++){
        int p=k; double maxv=fabs(mat_get(AI,p,k));
        for (int i=k+1;i<n;i++){
            double v=fabs(mat_get(AI,i,k));
            if (v>maxv){maxv=v;p=i;}
        }
        if (maxv<1e-15){ printf("Singular.\n"); mat_free(&AI); return mat_new(0,0); }
        if (p!=k){
            for (int j=0;j<2*n;j++){
                double tmp=mat_get(AI,k,j);
                mat_set(AI,k,j, mat_get(AI,p,j));
                mat_set(AI,p,j, tmp);
            }
        }
        double piv = mat_get(AI,k,k);
        for (int j=0;j<2*n;j++) mat_set(AI,k,j, mat_get(AI,k,j)/piv);
        for (int i=0;i<n;i++) if (i!=k){
            double f = mat_get(AI,i,k);
            for (int j=0;j<2*n;j++)
                mat_set(AI,i,j, mat_get(AI,i,j) - f*mat_get(AI,k,j));
        }
    }
    Matrix Inv = mat_new(n,n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            mat_set(Inv,i,j, mat_get(AI,i,n+j));
    mat_free(&AI);
    return Inv;
}

Vector mat_solve(Matrix A, Vector b){
    if (A.n!=A.m || A.n!=b.n){ printf("Dimensiones incompatibles.\n"); return vec_new(0); }
    int n=A.n;
    Matrix Aug = mat_new(n,n+1);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) mat_set(Aug,i,j, mat_get(A,i,j));
        mat_set(Aug,i,n, b.v[i]);
    }
    // Eliminación + pivoteo
    for (int k=0;k<n;k++){
        int p=k; double maxv=fabs(mat_get(Aug,p,k));
        for (int i=k+1;i<n;i++){
            double v=fabs(mat_get(Aug,i,k));
            if (v>maxv){maxv=v;p=i;}
        }
        if (maxv<1e-15){ printf("Sistema singular.\n"); vec_new(0); }
        if (p!=k){
            for (int j=0;j<=n;j++){
                double tmp=mat_get(Aug,k,j);
                mat_set(Aug,k,j, mat_get(Aug,p,j));
                mat_set(Aug,p,j, tmp);
            }
        }
        for (int i=k+1;i<n;i++){
            double f = mat_get(Aug,i,k)/mat_get(Aug,k,k);
            mat_set(Aug,i,k,0.0);
            for (int j=k+1;j<=n;j++)
                mat_set(Aug,i,j, mat_get(Aug,i,j) - f*mat_get(Aug,k,j));
        }
    }
    Vector x = vec_new(n);
    for (int i=n-1;i>=0;i--){
        double s = mat_get(Aug,i,n);
        for (int j=i+1;j<n;j++) s -= mat_get(Aug,i,j)*x.v[j];
        x.v[i] = s/mat_get(Aug,i,i);
    }
    mat_free(&Aug);
    return x;
}
// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

typedef struct { int n,m; double* a; } Matrix;
typedef struct { int n;   double* v; } Vector;

Matrix mat_new(int n, int m);
Matrix mat_identity(int n);
void   mat_free(Matrix* A);
void   mat_set(Matrix A, int i, int j, double x);
double mat_get(Matrix A, int i, int j);
void   mat_print(Matrix A);

Vector vec_new(int n);
void   vec_free(Vector* x);
void   vec_set(Vector x, int i, double val);
double vec_get(Vector x, int i);
void   vec_print(Vector x);

Matrix mat_leer(int n, int m, const char* nombre);
Vector vec_leer(int n, const char* nombre);

Matrix mat_add(Matrix A, Matrix B);
Matrix mat_mul(Matrix A, Matrix B);

double mat_det(Matrix A);
Matrix mat_inv(Matrix A);

Vector mat_solve(Matrix A, Vector b);

#endif
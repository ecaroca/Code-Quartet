// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Vector {
public:
    Vector() = default;
    explicit Vector(int n);
    int size() const { return n_; }
    double& operator()(int i);
    double  operator()(int i) const;
    void print() const;
private:
    int n_ = 0;
    std::vector<double> v_;
};

class Matrix {
public:
    Matrix() = default;
    Matrix(int n, int m);
    static Matrix identity(int n);
    int rows() const { return n_; }
    int cols() const { return m_; }
    double& operator()(int i, int j);
    double  operator()(int i, int j) const;
    void print() const;
    static Matrix add(const Matrix& A, const Matrix& B);
    static Matrix mul(const Matrix& A, const Matrix& B);
    static double det(Matrix A);
    static Matrix inv(Matrix A);
    static Vector solve(Matrix A, Vector b);
private:
    int n_ = 0, m_ = 0;
    std::vector<double> a_;
};

#endif

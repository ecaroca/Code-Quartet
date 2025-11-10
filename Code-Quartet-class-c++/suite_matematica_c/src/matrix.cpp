// matrix.cpp
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <limits>
#include "matrix.h"

Vector::Vector(int n): n_(n), v_(n, 0.0) {}
double& Vector::operator()(int i){ return v_.at(i); }
double  Vector::operator()(int i) const{ return v_.at(i); }
void Vector::print() const{
    for(int i=0;i<n_;++i) std::printf("%g\n", v_[i]);
}

Matrix::Matrix(int n, int m): n_(n), m_(m), a_(n*m, 0.0) {}
Matrix Matrix::identity(int n){
    Matrix I(n,n);
    for(int i=0;i<n;++i) I(i,i)=1.0;
    return I;
}
double& Matrix::operator()(int i, int j){ return a_.at(i*m_ + j); }
double  Matrix::operator()(int i, int j) const{ return a_.at(i*m_ + j); }
void Matrix::print() const{
    for(int i=0;i<n_;++i){
        for(int j=0;j<m_;++j) std::printf("%10.6f ", (*this)(i,j));
        std::printf("\n");
    }
}

Matrix Matrix::add(const Matrix& A, const Matrix& B){
    Matrix C(A.n_, A.m_);
    for(int i=0;i<A.n_;++i) for(int j=0;j<A.m_;++j) C(i,j)=A(i,j)+B(i,j);
    return C;
}
Matrix Matrix::mul(const Matrix& A, const Matrix& B){
    Matrix C(A.n_, B.m_);
    for(int i=0;i<A.n_;++i){
        for(int k=0;k<A.m_;++k){
            double aik = A(i,k);
            for(int j=0;j<B.m_;++j) C(i,j) += aik*B(k,j);
        }
    }
    return C;
}

double Matrix::det(Matrix A){
    if (A.n_!=A.m_) return std::numeric_limits<double>::quiet_NaN();
    int n=A.n_;
    double d=1.0;
    for(int k=0;k<n;++k){
        int p=k;
        double mx=std::fabs(A(k,k));
        for(int i=k+1;i<n;++i){
            if (std::fabs(A(i,k))>mx){ mx=std::fabs(A(i,k)); p=i; }
        }
        if (mx<1e-15) return 0.0;
        if (p!=k){
            for(int j=k;j<n;++j) std::swap(A(k,j),A(p,j));
            d = -d;
        }
        d *= A(k,k);
        for(int i=k+1;i<n;++i){
            double f = A(i,k)/A(k,k);
            for(int j=k;j<n;++j) A(i,j) -= f*A(k,j);
        }
    }
    return d;
}

Matrix Matrix::inv(Matrix A){
    if (A.n_!=A.m_) return Matrix();
    int n=A.n_;
    Matrix I = identity(n);
    for(int k=0;k<n;++k){
        int p=k; double mx=std::fabs(A(k,k));
        for(int i=k+1;i<n;++i){
            if (std::fabs(A(i,k))>mx){ mx=std::fabs(A(i,k)); p=i; }
        }
        if (mx<1e-15) return Matrix();
        if (p!=k){
            for(int j=0;j<n;++j){ std::swap(A(k,j),A(p,j)); std::swap(I(k,j),I(p,j)); }
        }
        double piv=A(k,k);
        for(int j=0;j<n;++j){ A(k,j)/=piv; I(k,j)/=piv; }
        for(int i=0;i<n;++i){
            if (i==k) continue;
            double f=A(i,k);
            for(int j=0;j<n;++j){ A(i,j)-=f*A(k,j); I(i,j)-=f*I(k,j); }
        }
    }
    return I;
}

Vector Matrix::solve(Matrix A, Vector b){
    int n=A.n_, m=A.m_;
    (void)m;
    for(int k=0;k<n;++k){
        int p=k; double mx=std::fabs(A(k,k));
        for(int i=k+1;i<n;++i){
            if (std::fabs(A(i,k))>mx){ mx=std::fabs(A(i,k)); p=i; }
        }
        if (mx<1e-15) return Vector();
        if (p!=k){
            for(int j=k;j<n;++j) std::swap(A(k,j),A(p,j));
            std::swap(b(k), b(p));
        }
        for(int i=k+1;i<n;++i){
            double f=A(i,k)/A(k,k);
            for(int j=k;j<n;++j) A(i,j)-=f*A(k,j);
            b(i)-=f*b(k);
        }
    }
    Vector x(n);
    for(int i=n-1;i>=0;--i){
        double s=b(i);
        for(int j=i+1;j<n;++j) s-=A(i,j)*x(j);
        x(i)=s/A(i,i);
    }
    return x;
}

#ifndef JACOBI_METHOD_H
#define JACOBI_METHOD_H

#include "dense_matrix.h"

class JacobiMethod {
public:
    JacobiMethod(const DenseMatrix& matrix, const std::vector<double>& b);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
};

#endif
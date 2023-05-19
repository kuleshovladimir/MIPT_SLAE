#ifndef GAUSS_SEIDEL_METHOD_H
#define GAUSS_SEIDEL_METHOD_H

#include "dense_matrix.h"

class GaussSeidelMethod {
public:
    GaussSeidelMethod(const DenseMatrix& matrix, const std::vector<double>& b);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
};

#endif
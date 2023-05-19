#ifndef FASTEST_GRADIENT_DESCENT_METHOD_H
#define FASTEST_GRADIENT_DESCENT_METHOD_H

#include "dense_matrix.h"

class FastestGradientDescentMethod {
public:
    FastestGradientDescentMethod(const DenseMatrix& matrix, const std::vector<double>& b, int maxIterations);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
    int maxIterations_;
};

#endif
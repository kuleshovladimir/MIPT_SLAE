#ifndef FASTEST_GRADIENT_DESCENT_H
#define FASTEST_GRADIENT_DESCENT_H

#include "dense_matrix.h"

class FastestGradientDescent {
public:
    FastestGradientDescent(const DenseMatrix& matrix, const std::vector<double>& b);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
};

#endif
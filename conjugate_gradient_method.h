#ifndef CONJUGATE_GRADIENT_METHOD_H
#define CONJUGATE_GRADIENT_METHOD_H

#include "dense_matrix.h"

class ConjugateGradientMethod {
public:
    ConjugateGradientMethod(const DenseMatrix& matrix, const std::vector<double>& b, int maxIterations);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
    int maxIterations_;
};

#endif
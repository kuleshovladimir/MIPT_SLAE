#ifndef CHEBYSHEV_ACCELERATION_H
#define CHEBYSHEV_ACCELERATION_H

#include "dense_matrix.h"

class ChebyshevAcceleration {
public:
    ChebyshevAcceleration(const DenseMatrix& matrix, const std::vector<double>& b, double omega, int maxIterations);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
    double omega_;
    int maxIterations_;
};

#endif
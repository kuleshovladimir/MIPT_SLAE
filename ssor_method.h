#ifndef SSOR_METHOD_H
#define SSOR_METHOD_H

#include "dense_matrix.h"

class SSORMethod {
public:
    SSORMethod(const DenseMatrix& matrix, const std::vector<double>& b, double omega);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
    double omega_;
};

#endif
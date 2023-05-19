#ifndef SOR_METHOD_H
#define SOR_METHOD_H

#include "dense_matrix.h"

class SORMethod {
public:
    SORMethod(const DenseMatrix& matrix, const std::vector<double>& b, double omega);
    std::vector<double> solve();

private:
    DenseMatrix matrix_;
    std::vector<double> b_;
    double omega_;
};

#endif
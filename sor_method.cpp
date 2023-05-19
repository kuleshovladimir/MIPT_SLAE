#include "sor_method.h"

SORMethod::SORMethod(const DenseMatrix& matrix, const std::vector<double>& b, double omega)
        : matrix_(matrix), b_(b), omega_(omega) {}

std::vector<double> SORMethod::solve() {
    std::vector<double> solution;
    // Implementation details - SOR method solution
    return solution;
}
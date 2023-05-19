#include "ssor_method.h"

SSORMethod::SSORMethod(const DenseMatrix& matrix, const std::vector<double>& b, double omega)
        : matrix_(matrix), b_(b), omega_(omega) {}

std::vector<double> SSORMethod::solve() {
    std::vector<double> solution;
    // Implementation details - SSOR method solution
    return solution;
}
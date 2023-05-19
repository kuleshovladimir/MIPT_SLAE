#include "gauss_seidel_method.h"

GaussSeidelMethod::GaussSeidelMethod(const DenseMatrix& matrix, const std::vector<double>& b)
        : matrix_(matrix), b_(b) {}

std::vector<double> GaussSeidelMethod::solve() {
    int n = matrix_.getRows()*matrix_.getRows();
    std::vector<double> solution(n, 0.0);

    double tolerance = 1e-6;  // Tolerance for convergence
    int maxIterations = 1000; // Maximum number of iterations

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        // Perform one Gauss-Seidel iteration
        for (int i = 0; i < n; i++) {
            double sum = b_[i];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum -= matrix_(i, j) * solution[j];
                }
            }
            solution[i] = sum / matrix_(i, i);
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(matrix_.getRows(i).dot(solution) - b_[i]);
        }

        if (error < tolerance) {
            break;  // Convergence reached
        }
    }

    return solution;
}
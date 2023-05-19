#include "chebyshev_acceleration.h"

#include "cmath"

ChebyshevAcceleration::ChebyshevAcceleration(const DenseMatrix& matrix, const std::vector<double>& b, double omega, int maxIterations)
        : matrix_(matrix), b_(b), omega_(omega), maxIterations_(maxIterations) {}

std::vector<double> ChebyshevAcceleration::solve() {
    int n = matrix_.getRows()*matrix_.getRows();
    std::vector<double> solution(n, 0.0);
    std::vector<double> prevSolution(n, 0.0);
    std::vector<double> residual(n, 0.0);

    double tolerance = 1e-6;  // Tolerance for convergence

    for (int iteration = 0; iteration < maxIterations_; iteration++) {
        // Compute the residual
        residual = matrix_ * solution - b_;

        // Compute the Chebyshev acceleration factor
        double alpha = 2.0 / (matrix_.getMaxEigenvalue() + matrix_.getMinEigenvalue());

        // Perform one iteration with acceleration
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += matrix_(i, j) * solution[j];
                }
            }
            solution[i] = prevSolution[i] + alpha * (b_[i] - sum - matrix_(i, i) * prevSolution[i]);
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(residual[i]);
        }

        if (error < tolerance) {
            break;  // Convergence reached
        }

        prevSolution = solution;
    }

    return solution;
}
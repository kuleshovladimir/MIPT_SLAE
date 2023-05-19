#include "sor_method.h"

#include "cmath"

SORMethod::SORMethod(const DenseMatrix& matrix, const std::vector<double>& b, double omega, int maxIterations)
        : matrix_(matrix), b_(b), omega_(omega), maxIterations_(maxIterations) {}

std::vector<double> SORMethod::solve() {
    int n = matrix_.getSize();
    std::vector<double> solution(n, 0.0);
    std::vector<double> prevSolution(n, 0.0);

    double tolerance = 1e-6;  // Tolerance for convergence

    for (int iteration = 0; iteration < maxIterations_; iteration++) {
        // Perform one SOR iteration
        for (int i = 0; i < n; i++) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; j++) {
                sum1 += matrix_(i, j) * solution[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum2 += matrix_(i, j) * prevSolution[j];
            }
            solution[i] = (1.0 - omega_) * prevSolution[i] + (omega_ / matrix_(i, i)) * (b_[i] - sum1 - sum2);
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(solution[i] - prevSolution[i]);
        }

        if (error < tolerance) {
            break;  // Convergence reached
        }

        prevSolution = solution;
    }

    return solution;
}
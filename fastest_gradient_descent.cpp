#include "fastest_gradient_descent.h"

FastestGradientDescentMethod::FastestGradientDescentMethod(const DenseMatrix& matrix, const std::vector<double>& b, int maxIterations)
        : matrix_(matrix), b_(b), maxIterations_(maxIterations) {}

std::vector<double> FastestGradientDescentMethod::solve() {
    int n = matrix_.getSize();
    std::vector<double> solution(n, 0.0);
    std::vector<double> prevSolution(n, 0.0);
    std::vector<double> gradient(n, 0.0);

    double tolerance = 1e-6;  // Tolerance for convergence

    for (int iteration = 0; iteration < maxIterations_; iteration++) {
        // Compute the gradient
        gradient = matrix_ * solution - b_;

        // Compute the optimal step size
        double alpha = (gradient * gradient) / ((matrix_ * gradient) * gradient);

        // Update the solution
        for (int i = 0; i < n; i++) {
            solution[i] = prevSolution[i] - alpha * gradient[i];
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
#include "conjugate_gradient_method.h"

#include "cmath"

ConjugateGradientMethod::ConjugateGradientMethod(const DenseMatrix& matrix, const std::vector<double>& b, int maxIterations)
        : matrix_(matrix), b_(b), maxIterations_(maxIterations) {}

std::vector<double> ConjugateGradientMethod::solve() {
    int n = matrix_.getSize();
    std::vector<double> solution(n, 0.0);
    std::vector<double> prevSolution(n, 0.0);
    std::vector<double> gradient(n, 0.0);
    std::vector<double> conjugateDirection(n, 0.0);
    std::vector<double> prevGradient(n, 0.0);  // Declare prevGradient

    double tolerance = 1e-6;  // Tolerance for convergence

    for (int iteration = 0; iteration < maxIterations_; iteration++) {
        // Compute the gradient
        gradient = matrix_ * solution - b_;

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(gradient[i]);
        }

        if (error < tolerance) {
            break;  // Convergence reached
        }

        if (iteration == 0) {
            conjugateDirection = gradient;
        } else {
            double beta = (gradient * gradient) / (prevGradient * prevGradient);
            for (int i = 0; i < n; i++) {
                conjugateDirection[i] = gradient[i] + beta * conjugateDirection[i];
            }
        }

        // Compute the optimal step size
        double alpha = (gradient * gradient) / ((matrix_ * conjugateDirection) * conjugateDirection);

        // Update the solution
        for (int i = 0; i < n; i++) {
            prevSolution[i] = solution[i];
            solution[i] = prevSolution[i] - alpha * conjugateDirection[i];
        }

        prevGradient = gradient;
    }

    return solution;
}
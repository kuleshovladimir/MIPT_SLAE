#include "qr_decomposition.h"

#include "math.h"

QRDecomposition::QRDecomposition(const TridiagonalMatrix& matrix)
        : Q_(matrix.getSize()), R_(matrix.getSize()) {
    int n = matrix.getSize();

    TridiagonalMatrix A = matrix;  // Copy the input matrix

    for (int i = 0; i < n; i++) {
        // Compute the norm of the i-th column
        double norm = 0.0;
        for (int j = i; j < n; j++) {
            norm += A(j, i) * A(j, i);
        }
        norm = sqrt(norm);

        // Compute the sign of the first element in the i-th column
        double sign = (A(i, i) >= 0.0) ? 1.0 : -1.0;

        // Compute the scaling factor
        double alpha = sign * norm;

        // Update the first element of the i-th column
        A(i, i) -= alpha;

        // Compute the norm of the i-th column again
        norm = 0.0;
        for (int j = i; j < n; j++) {
            norm += A(j, i) * A(j, i);
        }
        norm = sqrt(norm);

        // Check if the norm is too small to proceed
        if (norm < 1e-8) {
            continue;
        }

        // Compute the Householder vector
        for (int j = i; j < n; j++) {
            A(j, i) /= norm;
        }

        // Update the remaining part of the matrix
        for (int j = i + 1; j < n; j++) {
            double dotProduct = 0.0;
            for (int k = i; k < n; k++) {
                dotProduct += A(k, i) * A(k, j);
            }
            for (int k = i; k < n; k++) {
                A(k, j) -= 2.0 * A(k, i) * dotProduct;
            }
        }
    }

    // Set the Q and R matrices
    for (int i = 0; i < n; i++) {
        Q_(i, i) = 1.0;
        for (int j = i + 1; j < n; j++) {
            Q_(j, i) = A(j, i);
        }
        for (int j = i; j < n; j++) {
            R_(j, i) = A(j, i);
        }
    }
}

const TridiagonalMatrix& QRDecomposition::getQ() const {
    return Q_;
}

const TridiagonalMatrix& QRDecomposition::getR() const {
    return R_;
}
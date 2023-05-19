#include "dense_matrix.h"

DenseMatrix::DenseMatrix(int size) : matrix_(size, std::vector<double>(size, 0.0)) {}

int DenseMatrix::getSize() const {
    return matrix_.size();
}

double DenseMatrix::getMaxEigenvalue() const {
    double maxEigenvalue = std::numeric_limits<double>::min();

    for (const auto& row : matrix_) {
        for (const double& element : row) {
            maxEigenvalue = std::max(maxEigenvalue, element);
        }
    }

    return maxEigenvalue;
}

double DenseMatrix::getMinEigenvalue() const {
    double minEigenvalue = std::numeric_limits<double>::max();

    for (const auto& row : matrix_) {
        for (const double& element : row) {
            minEigenvalue = std::min(minEigenvalue, element);
        }
    }

    return minEigenvalue;
}

double& DenseMatrix::operator()(int row, int col) {
    return matrix_[row][col];
}

const double& DenseMatrix::operator()(int row, int col) const {
    return matrix_[row][col];
}

std::vector<double>& DenseMatrix::getRow(int row) {
    return matrix_[row];
}

const std::vector<double>& DenseMatrix::getRow(int row) const {
    return matrix_[row];
}

std::vector<double> DenseMatrix::operator*(const std::vector<double>& vec) const {
    int n = matrix_.size();
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += matrix_[i][j] * vec[j];
        }
    }

    return result;
}
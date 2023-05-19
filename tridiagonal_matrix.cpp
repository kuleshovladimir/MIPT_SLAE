#include "tridiagonal_matrix.h"

TridiagonalMatrix::TridiagonalMatrix(int size)
        : size_(size),
          mainDiagonal_(size),
          upperDiagonal_(size - 1),
          lowerDiagonal_(size - 1) {}

double& TridiagonalMatrix::operator()(int row, int column) {
    if (row == column) {
        return mainDiagonal_[row];
    } else if (row == column - 1) {
        return lowerDiagonal_[row];
    } else if (row == column + 1) {
        return upperDiagonal_[row];
    } else {
        throw std::out_of_range("Invalid row/column indices for TridiagonalMatrix.");
    }
}

double TridiagonalMatrix::operator()(int row, int column) const {
    if (row == column) {
        return mainDiagonal_[row];
    } else if (row == column - 1) {
        return lowerDiagonal_[row];
    } else if (row == column + 1) {
        return upperDiagonal_[row];
    } else {
        return 0.0; // Default value for non-existing entries
    }
}

int TridiagonalMatrix::getSize() const {
    return size_;
}
#include "tridiagonal_matrix.h"

TridiagonalMatrix::TridiagonalMatrix(int size)
        : size_(size),
          diagonals_(3 * size - 2) {}  // The total number of elements required to store the three diagonals

double& TridiagonalMatrix::operator()(int row, int column) {
    int index = getIndex(row, column);
    return diagonals_[index];
}

double TridiagonalMatrix::operator()(int row, int column) const {
    int index = getIndex(row, column);
    return diagonals_[index];
}

int TridiagonalMatrix::getSize() const {
    return size_;
}

int TridiagonalMatrix::getIndex(int row, int column) const {
    int offset = row - column;
    int index = column + offset;
    return index;
}
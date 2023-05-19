#include "dense_matrix.h"

DenseMatrix::DenseMatrix(int rows, int columns)
        : rows_(rows), columns_(columns), data_(rows * columns) {}

double& DenseMatrix::operator()(int row, int column) {
    return data_[row * columns_ + column];
}

double DenseMatrix::operator()(int row, int column) const {
    return data_[row * columns_ + column];
}

int DenseMatrix::getRows() const {
    return rows_;
}

int DenseMatrix::getColumns() const {
    return columns_;
}

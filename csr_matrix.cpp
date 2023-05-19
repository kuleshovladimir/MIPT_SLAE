#include "csr_matrix.h"

CSRMatrix::CSRMatrix(int rows, int columns, const std::vector<double>& values,
                     const std::vector<int>& rowPtr, const std::vector<int>& colIndices)
        : rows_(rows), columns_(columns), values_(values), rowPtr_(rowPtr), colIndices_(colIndices) {}

double& CSRMatrix::operator()(int row, int column) {
    int start = rowPtr_[row];
    int end = rowPtr_[row + 1];
    for (int i = start; i < end; ++i) {
        if (colIndices_[i] == column) {
            return values_[i];
        }
    }
    throw std::out_of_range("Column index out of range.");
}

double CSRMatrix::operator()(int row, int column) const {
    int start = rowPtr_[row];
    int end = rowPtr_[row + 1];
    for (int i = start; i < end; ++i) {
        if (colIndices_[i] == column) {
            return values_[i];
        }
    }
    return 0.0; // Default value for non-existing entries
}

int CSRMatrix::getRows() const {
    return rows_;
}

int CSRMatrix::getColumns() const {
    return columns_;
}
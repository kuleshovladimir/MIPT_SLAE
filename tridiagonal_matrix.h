#ifndef TRIDIAGONAL_MATRIX_H
#define TRIDIAGONAL_MATRIX_H

#include <vector>

class TridiagonalMatrix {
public:
    TridiagonalMatrix(int size);
    double& operator()(int row, int column);
    double operator()(int row, int column) const;
    int getSize() const;

private:
    int size_;
    std::vector<double> diagonals_;  // Store the main diagonal, upper diagonal, and lower diagonal

    // Helper function to get the index in the diagonals_ vector for a given row and column
    int getIndex(int row, int column) const;
};

#endif
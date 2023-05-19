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
    std::vector<double> mainDiagonal_;
    std::vector<double> upperDiagonal_;
    std::vector<double> lowerDiagonal_;
};

#endif
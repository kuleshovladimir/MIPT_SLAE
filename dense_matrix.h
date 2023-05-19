#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <vector>

class DenseMatrix {
public:
    DenseMatrix(int rows, int columns);
    double& operator()(int row, int column);
    double operator()(int row, int column) const;
    int getRows() const;
    int getColumns() const;

private:
    int rows_;
    int columns_;
    std::vector<double> data_;
};

#endif

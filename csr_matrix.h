#ifndef CSR_MATRIX_H
#define CSR_MATRIX_H

#include <vector>

class CSRMatrix {
public:
    CSRMatrix(int rows, int columns, const std::vector<double>& values,
              const std::vector<int>& rowPtr, const std::vector<int>& colIndices);
    double& operator()(int row, int column);
    double operator()(int row, int column) const;
    int getRows() const;
    int getColumns() const;

private:
    int rows_;
    int columns_;
    std::vector<double> values_;
    std::vector<int> rowPtr_;
    std::vector<int> colIndices_;
};

#endif
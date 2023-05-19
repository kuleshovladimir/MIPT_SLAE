#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <vector>

class DenseMatrix {
public:
    DenseMatrix(int size);
    int getSize() const;
    double getMaxEigenvalue() const;
    double getMinEigenvalue() const;
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;
    std::vector<double>& getRow(int row);
    const std::vector<double>& getRow(int row) const;
    std::vector<double> operator*(const std::vector<double>& vec) const;

private:
    std::vector<std::vector<double>> matrix_;
};

#endif
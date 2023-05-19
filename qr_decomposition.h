#ifndef QR_DECOMPOSITION_H
#define QR_DECOMPOSITION_H

#include "dense_matrix.h"

class QRDecomposition {
public:
    QRDecomposition(const DenseMatrix& matrix);
    const DenseMatrix& getQ() const;
    const DenseMatrix& getR() const;

private:
    DenseMatrix Q_;
    DenseMatrix R_;
};

#endif
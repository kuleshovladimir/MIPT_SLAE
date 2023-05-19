#ifndef QR_DECOMPOSITION_H
#define QR_DECOMPOSITION_H

#include "tridiagonal_matrix.h"

class QRDecomposition {
public:
    QRDecomposition(const TridiagonalMatrix& matrix);
    const TridiagonalMatrix& getQ() const;
    const TridiagonalMatrix& getR() const;

private:
    TridiagonalMatrix Q_;
    TridiagonalMatrix R_;
};

#endif
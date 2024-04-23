#include "matrix.h"

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m3.nRows; i++)
        for (int j = 0; j < m3.nCols; j++) {
            m3.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m))
        *m = mulMatrices(*m, *m);
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);
    
    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);
    
    getSquareOfMatrixIfSymmetric(&m);
    
    outputMatrix(m);
    
    return 0;
}
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

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    return isEMatrix(&m3) ? 1 : 0;
}

int main() {
    int nRows1, nCols1;
    scanf("%d %d", &nRows1, &nCols1);

    matrix m1 = getMemMatrix(nRows1, nCols1);
    inputMatrix(&m1);

    int nRows2, nCols2;
    scanf("%d %d", &nRows2, &nCols2);

    matrix m2 = getMemMatrix(nRows2, nCols2);
    inputMatrix(&m2);

    printf("%d", isMutuallyInverseMatrices(m1, m2));

    return 0;
}
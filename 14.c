#include "matrix.h"
#include <math.h>

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count += 1;
    return count;
}

int countZeroRows(matrix m) {
    int countZeroRows = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroRows += 1;
    return countZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zeroRowsOfMatrix[nMatrix];
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        int zeroRows = countZeroRows(ms[i]);
        zeroRowsOfMatrix[i] = zeroRows;
        if (zeroRows > maxZeroRows)
            maxZeroRows = zeroRows;
    }
    for (int i = 0; i < nMatrix; i++) {
        if (zeroRowsOfMatrix[i] == maxZeroRows) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    int nMatrices;
    scanf("%d", &nMatrices);

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    inputMatrices(ms, nMatrices);

    printMatrixWithMaxZeroRows(ms, nMatrices);

    return 0;
}

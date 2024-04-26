#include "matrix.h"
#include <math.h>

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countMatrix = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            countMatrix += 1;
    return countMatrix;
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    int nMatrices;
    scanf("%d", &nMatrices);

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    inputMatrices(ms, nMatrices);

    printf("%d", countNonDescendingRowsMatrices(ms, nMatrices));

    return 0;
}
#include "matrix.h"

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    sortRowsByMinElement(m);

    outputMatrix(m);
    
    return 0;
}
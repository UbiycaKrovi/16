#include "matrix.h"

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortRowsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
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
#include "matrix.h"
#include <math.h>

float getDistance(int *a, int n) {
    float distance = 0;

    for (int i = 0; i < n; i++)
        distance += a[i] * a[i];
    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *,
                                                                       int)) {
    float criteriaArray[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        float t = criteriaArray[i];
        int j = i;
        while (j > 0 && criteriaArray[j - 1] > t) {
            criteriaArray[j] = criteriaArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        criteriaArray[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    sortByDistances(m);

    outputMatrix(m);

    return 0;
}
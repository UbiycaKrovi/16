#include "matrix.h"
#include <math.h>
#include <float.h>

double maxAbsoluteValueOfMatrix(matrix m) {
    double absoluteValue = fabs(m.values[0][0]);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (fabs(m.values[i][j]) > absoluteValue)
                absoluteValue = fabs(m.values[i][j]);
    return absoluteValue;
}

void printMatrixWithMinAbsoluteValue(matrix *ms, int nMatrix) {
    double absoluteValuesOfMatrix[nMatrix];
    double minAbsoluteValue = maxAbsoluteValueOfMatrix(ms[0]);
    absoluteValuesOfMatrix[0] = minAbsoluteValue;
    for (int i = 1; i < nMatrix; i++) {
        double absoluteValue = maxAbsoluteValueOfMatrix(ms[i]);
        absoluteValuesOfMatrix[i] = absoluteValue;
        if (absoluteValue < minAbsoluteValue)
            minAbsoluteValue = absoluteValue;
    }
    for (int i = 0; i < nMatrix; i++) {
        if (absoluteValuesOfMatrix[i] - minAbsoluteValue < DBL_EPSILON) {
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

    printMatrixWithMinAbsoluteValue(ms, nMatrices);

    return 0;
}
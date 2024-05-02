#include "matrix.h"
#include <limits.h>

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long scalarProduct = 0;
    int maxElementRow = INT_MIN;
    int minElementCol = INT_MAX;

    for (int col = 0; col < m.cols; col++) {
        if (m.data[i][col] > maxElementRow) {
            maxElementRow = m.data[i][col];
        }
    }

    for (int row = 0; row < m.rows; row++) {
        if (m.data[row][j] < minElementCol) {
            minElementCol = m.data[row][j];
        }
    }

    scalarProduct = (long long)maxElementRow * minElementCol;

    return scalarProduct;
}

long long getSpecialScalarProduct(Matrix m, int n) {
    long long specialScalarProduct = 0;

    int maxElementRow = INT_MIN;
    int minElementCol = INT_MAX;
    int rowWithMaxElement = -1;
    int colWithMinElement = -1;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (m.data[row][col] > maxElementRow) {
                maxElementRow = m.data[row][col];
                rowWithMaxElement = row;
            }
        }
    }

    for (int col = 0; col < n; col++) {
        if (m.data[rowWithMaxElement][col] < minElementCol) {
            minElementCol = m.data[rowWithMaxElement][col];
            colWithMinElement = col;
        }
    }

    specialScalarProduct = getScalarProductRowAndCol(m, rowWithMaxElement, colWithMinElement);

    return specialScalarProduct;
}

int main() {
    matrix squareMatrix;
    int n = squareMatrix.rows;

    long long result = getSpecialScalarProduct(squareMatrix, n);

    printf("%lld\n", result);

    return 0;
}
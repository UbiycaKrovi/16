#include "matrix.h"

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxOfPsuedoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 2;
    int maxOfPsuedoDiagonal[n];

    for (size_t i = 0; i < n; i++)
        maxOfPsuedoDiagonal[i] = 0;
    
    int indexPsuedoDiagonalElement;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i != j) {
                if (i > j)
                    indexPsuedoDiagonalElement = j - i + m.nRows - 1;
                else    
                    indexPsuedoDiagonalElement = j - i + m.nRows - 2;
                maxOfPsuedoDiagonal[indexPsuedoDiagonalElement] = max(maxOfPsuedoDiagonal[indexPsuedoDiagonalElement], m.values[i][j]);
            }
    return getSum(maxOfPsuedoDiagonal, n);
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    printf("%lld", findSumOfMaxOfPsuedoDiagonal(m));

    return 0;
}
#include "matrix.h"

int getMinInArea(matrix m) {
    int minInArea;
    position maxElement = getMaxValuePos(m);
    int left = maxElement.colIndex;
    int right = maxElement.colIndex;

    for (int i = maxElement.rowIndex; i >= 0; i--) {
        int minInRow = getMin(m.values[i], left, right);

        if (i == maxElement.rowIndex || minInRow < minInArea)
            minInArea = minInRow;

        if (right < m.nCols - 1)
            right++;
            
        if (left > 0)
            left--;
    }
    return minInArea;
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m1 = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    printf("%d", getMinInArea(m));

    return 0;
}

#include "matrix.h"
#include <math.h>

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    int minRow = 0;
    int minCol = 0;
    for (int i = 0; i < m.nCols; i++)
        for (int j = 0; j < m.nRows; j++)
            if (m.values[j][i] < min) {
                min = m.values[j][i];
                minRow = j;
                minCol = i;
            }
    return (position) {minRow, minCol};
}

void swapPenultimateRow(matrix m) {
    assert(m.nRows > 1);
    position posMin = getLeftMin(m);
    int minColEl[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        minColEl[i] = m.values[i][posMin.colIndex];
    for (size_t i = 0; i < m.nRows; i++)
        m.values[m.nRows - 2][i] = minColEl[i];
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    swapPenultimateRow(m);

    outputMatrix(m);

    return 0;
}
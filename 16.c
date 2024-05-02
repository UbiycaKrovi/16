#include "matrix.h"

int min2(int a, int b) {
    return a < b ? a : b;
}

int getNSpecialElement2(matrix m) {
    int k = 0;

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            int isSpecial = 1;

            for (int left = 0; left < j; left++) {
                if (m.data[i][left] >= m.data[i][j]) {
                    isSpecial = 0;
                    break;
                }
            }

            for (int right = j + 1; right < m.cols; right++) {
                if (m.data[i][right] <= m.data[i][j]) {
                    isSpecial = 0;
                    break;
                }
            }

            if (isSpecial) {
                k++;
            }
        }
    }

    return k;
}

int main() {
    Matrix exampleMatrix;

    int specialElementsCount = getNSpecialElement2(exampleMatrix);

    printf("%d\n", specialElementsCount);

    return 0;
}
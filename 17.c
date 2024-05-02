#include "matrix.h"
#include <math.h>

double getScalarProduct(int *a, int *b, int n) {
    double scalarProduct = 0;
    for (int i = 0; i < n; i++) {
        scalarProduct += a[i] * b[i];
    }
    return scalarProduct;
}

double getVectorLength(int *a, int n) {
    double length = 0;
    for (int i = 0; i < n; i++) {
        length += a[i] * a[i];
    }
    return sqrt(length);
}

double getCosine(int *a, int *b, int n) {
    double scalarProduct = getScalarProduct(a, b, n);
    double lengthA = getVectorLength(a, n);
    double lengthB = getVectorLength(b, n);
    return scalarProduct / (lengthA * lengthB);
}

int getVectorIndexWithMaxAngle(matrix m, int *v) {
    int maxIndex = -1;
    double maxCosine = -2;

    for (int i = 0; i < m.rows; i++) {
        double cosine = getCosine(m.data[i], v, m.cols);
        if (cosine > maxCosine) {
            maxCosine = cosine;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {
    matrix vectorsMatrix;

    int vectorV[] = {1, 2, 3};

    int maxAngleVectorIndex = getVectorIndexWithMaxAngle(vectorsMatrix, vectorV);

    printf("%d\n", maxAngleVectorIndex);

    return 0;
}
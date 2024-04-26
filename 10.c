#include "matrix.h"
#include <math.h>

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long a = *(const long long *) pa;
    long long b = *(const long long *) pb;
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count = 0;
    int resCount = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1])
            count++;
        if (count > 0) {
            resCount++;
            count = 0;
        }
    }
    return resCount;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumRows[m.nRows];
    for (int i = 0; i < m.nCols; i++)
        sumRows[i] = getSum(m.values[i], m.nCols);
    return countNUnique(sumRows, m.nRows);
}

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(&m);

    printf("%d", countEqClassesByRowsSum(m));

    return 0;
}
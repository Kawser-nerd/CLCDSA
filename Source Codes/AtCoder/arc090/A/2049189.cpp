#include <stdio.h>

#define TWO 2

int getMostCandies (int N, int **matrix) {
    int max = 0;
    for (int i=0; i < N; i++) {
        int sum = 0;
        for (int j=0; j <= i; j++) {
            sum += matrix[0][j];
        }
        for (int j=i; j < N; j++) {
            sum += matrix[1][j];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int main () {
    int N;
    int result;
    scanf("%d", &N);

    // Allocate Memory
    int **matrix = new int*[TWO];
    for (int i=0; i < TWO; i++) {
        matrix[i] = new int[N];
    }

    // Input Matrix
    for (int i=0; i < TWO; i++) {
        for (int j=0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    result = getMostCandies(N, matrix);
    printf("%d\n", result);

    // Delete Memory
    for (int i=0; i < TWO; i++) {
        delete[] matrix[i];
        matrix[i] = 0;
    }
    delete[] matrix;
    matrix = 0;

    return 0;
}
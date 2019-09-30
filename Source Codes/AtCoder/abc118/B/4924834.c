#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int  N, M;
    int* foods;
    int  K;
    int  n;
    char buffer[1000];
    if (fgets(buffer, 1000, stdin) != NULL) {
        N = atoi(strtok(buffer, " "));
        M = atoi(strtok(NULL, " "));
        foods = calloc(M, sizeof(int));
        for (int i = 0; i < N; i++) {
            if (fgets(buffer, 1000, stdin) != NULL) {
                K = atoi(strtok(buffer, " "));
                for (int j = 0; j < K; j++) {
                    n = atoi(strtok(NULL, " "));
                    foods[n-1] += 1;
                }
            } else {
                return 1;
            }
        }
    } else {
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
        if (N == foods[i]) {
            sum += 1;
        }
    }
    printf("%d", sum);
    return 0;
}
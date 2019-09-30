#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N;
    int* monsters;
    char* buffer;
    if (scanf("%d ", &N) != EOF) {
        buffer = malloc(sizeof(char)*N*11+1);
        monsters = malloc(sizeof(int)*N);
        if (fgets(buffer, N*11+1, stdin) != NULL) {
            monsters[0] = atoi(strtok(buffer, " "));
            for (int i = 1; i < N; i++) {
                monsters[i] = atoi(strtok(NULL, " "));
            }
        } else {
            free(buffer);
            free(monsters);
            fprintf(stderr, "[x] fgets() error.\n");
            return 1;
        }
    } else {
        fprintf(stderr, "[x] scanf() error.\n");
        return 1;
    }
    int end;
    int min_index;
    while (1) {
        end = 1;
        for (int i = 0; i < N; i++) {
            if (monsters[i] != 0) {
                min_index = i;
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            if (monsters[i] != 0 && monsters[i] < monsters[min_index]) {
                min_index = i;
            }
        }
        for (int i = 0; i < N; i++) {
            if (i != min_index && monsters[i] != 0) {
                monsters[i] = monsters[i] % monsters[min_index];
                end = 0;
            }
        }
        if (end) break;
    }
    printf("%d", monsters[min_index]);
    free(buffer);
    free(monsters);
    return 0;
}
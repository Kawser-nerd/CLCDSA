#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N;
    char* buffer;
    int side_value = 0, max_side = 0, side_sum = 0;;

    if (scanf("%d ", &N) != EOF) {
        buffer = malloc(sizeof(char)*N*4);
        if (fgets(buffer, N*4, stdin) != NULL) {
            side_value = atoi(strtok(buffer, " "));
            max_side  = side_value;
            side_sum += side_value;
            for (int i = 1; i < N; i++) {
                side_value = atoi(strtok(NULL, " "));
                side_sum += side_value;
                if (max_side < side_value) {
                    max_side = side_value;
                }
            }
        }
    }

    if (side_sum-max_side > max_side) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}
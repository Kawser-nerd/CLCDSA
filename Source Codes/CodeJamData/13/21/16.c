#include <stdio.h>
#include <stdlib.h>
#define MAX_MOTES 102
#define MIN(A, B) (A < B ? A : B)

int sizes[MAX_MOTES];

int comp(const void *a, const void *b) {
    int *c = (int *)a, *d = (int *)b;
    if (*c < *d) return -1;
    if (*c == *d) return 0;
    return 1;
}

int main() {
    FILE *input = fopen("mote.in", "r");
    FILE *output = fopen("mote.out", "w");

    int num_cases;
    int size, num_motes;
    int run_cost, best_cost;
    int i, j;

    fscanf(input, "%d ", &num_cases);
    for (i = 0; i < num_cases; i++) {
        fscanf(input, "%d %d ", &size, &num_motes);
        for (j = 0; j < num_motes; j++) {
            fscanf(input, "%d ", sizes+j);
        }
        run_cost = 0; best_cost = 1000;
        qsort(sizes, num_motes, sizeof(int), comp);

        for (j = 0; j < num_motes; j++) {
            best_cost = MIN(best_cost, run_cost + num_motes-j);
            if (size <= sizes[j] && size < 2) break;
            while (size <= sizes[j]) {
                size = 2*size - 1;
                run_cost++;
            }
            size += sizes[j];
        }
        if (j == num_motes) best_cost = MIN(best_cost, run_cost);

        fprintf(output, "Case #%d: %d \n", i+1, best_cost);
    }

    return 0;
}
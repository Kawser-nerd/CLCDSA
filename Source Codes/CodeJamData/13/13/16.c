#include <stdio.h>
#define MAX(A, B) ((A) > (B) ? (A) : (B))

int divisors[4];
int freq[4];

int main() {
    FILE *input = fopen("luck.in", "r");
    FILE *output = fopen("luck.out", "w");

    int i, j, k, l, divisor;
    int num_divs;
    int max_freq, max_div;
    int num_tests, num_selects, select_size, range, num_prods;
    int prod, count;
    fscanf(input, "%d %d %d %d %d ", &num_tests, &num_selects, &select_size, &range, &num_prods);
    fprintf(output, "Case #1:\n");
    for (i = 0; i < num_selects; i++) {
        for (j = 0; j < 4; j++) {
            divisors[j] = 0;
            freq[j] = 0;
        }
        num_divs = 0; max_freq = 0; max_div = 2;
        for (j = 0; j < num_prods; j++) {
            fscanf(input, "%d ", &prod);
            for (k = 2; k <= 5; k++) {
                for (divisor = k, l = 0; prod % divisor == 0; divisor *= k) {
                    l++;
                    freq[k-2]++;
                }
                if (divisors[k-2] < l) {
                    num_divs += l - divisors[k-2];
                    divisors[k-2] = l;
                }
            }
        }
        if (divisors[0] >= 2 && num_divs > 3) {
            num_divs -= 2;
            divisors[0] -= 2;
            divisors[2] = 1;
        }
        if (num_divs == 2 && divisors[2]) {
            num_divs++;
            divisors[2] == 0; divisors[0] = 2;
        } 
        for (j = 2; j <= 5; j++) {
            if (freq[j-2] > max_freq) {
                max_freq = freq[j-2]; max_div = j;
            }
        }
        while (num_divs < 3) {
            num_divs++; divisors[max_div-2]++;
        }
        count = 0;
        for (j = 2; j <= 5; j++) {
            for (k = 0; k < divisors[j-2]; k++) {
                if (count == 3) break;
                fprintf(output, "%d", j);
                count++;
            }
        }
        fprintf(output, "\n");
    }

    fclose(input); fclose(output);
    return 0;
}
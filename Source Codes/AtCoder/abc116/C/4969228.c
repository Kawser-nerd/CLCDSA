#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int  N, h[100], zero_num, not_zero, cnt = 0;
    char b[400];
    if (scanf("%3d ", &N) != EOF) {
        if (fgets(b, 400, stdin) != NULL) {
            h[0] = atoi(strtok(b, " "));
            for (int i = 1; i < N; i++) {
                h[i] = atoi(strtok(NULL, " "));
            }
            while (1) {
                not_zero = 0;
                zero_num = 0;
                for (int i = 0; i < N; i++) {
                    if (h[i] != 0) {
                        if (h[i] >= 1) {
                            h[i] -= 1;
                            not_zero = 1;
                        } else {
                            break;
                        }
                    } else {
                        zero_num += 1;
                        if (not_zero) {
                            break;
                        }
                    }
                }
                if (zero_num == N) break;
                cnt++;
            }
            printf("%d", cnt);
        }
    }
    return 0;
}
#include <stdio.h>

int main() {
    int n, s;

    scanf("%d", &n);

    s = 2025 - n;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (s == i * j) {
                printf("%d x %d\n", i, j);
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
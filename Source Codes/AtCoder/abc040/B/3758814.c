#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int h, w;
    int min;

    scanf("%d", &n);
    min = n;

    for (int h = 1; h <= n / 2 + 1; h++) {
        w = n / h;
        if (min > abs(h - w) + n - (w * h)) {
            min = abs(h - w) + n - (w * h);
        }
    }
    printf("%d\n", min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
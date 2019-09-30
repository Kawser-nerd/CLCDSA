#include <stdio.h>

#define N 20

int main(void) {
    int a, n, x, sum = 0;

    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);

        if (x % 2 == 1) {
            sum += a;
        }

        x /= 2;
    }

    printf("%d\n", sum);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &x);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^
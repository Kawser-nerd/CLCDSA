#include <stdio.h>

int main() {
    int a, b, n;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);

    for (int i = n; i <= n + (a * b); i++) {
        if (i % a == 0 && i % b == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
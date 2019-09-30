#include <stdio.h>

int main() {
    int l, h, n, a;
    int tmp[51] = { 0 };

    scanf("%d %d", &l, &h);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        tmp[i] = a;
    }

    for (int i = 0; i < n; i++) {
        a = tmp[i];
        if (a < l) {
            printf("%d\n", l - a);
        } else if (a > h) {
            printf("-1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &l, &h);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^
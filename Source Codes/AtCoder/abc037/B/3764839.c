#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q, l, r, t;
    int *a;

    scanf("%d %d", &n, &q);

    a = (int *)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &l, &r, &t);
        for (int j = l; j <= r; j++) {
            a[j] = t;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }

    if (a != NULL) {
        free(a);
        a = NULL;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &q);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &l, &r, &t);
         ^
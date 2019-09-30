#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, a, w = -1, cnt = 0;
    int *t;

    scanf("%d", &n);
    t = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        t[i] = a;
        while (t[i] % 2 == 0) {
            t[i] /= 2;
        }
    }

    qsort(t, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        if (w < t[i]) {
            cnt++;
            w = t[i];
        }
    }
    printf("%d\n", cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^
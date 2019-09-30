#include <stdio.h>
#include <stdlib.h>
static int n, a[100000];
static int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main(void) {
    int i, j, ans = 1;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &j);
        while (1)
            if (j & 1)
                break;
            else
                j >>= 1;
        a[i] = j;
    }
    qsort(a, n, sizeof(int), cmp);
    for (i = 0; i < n - 1; ++i)
        if (a[i] != a[i + 1])
            ++ans;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &j);
         ^
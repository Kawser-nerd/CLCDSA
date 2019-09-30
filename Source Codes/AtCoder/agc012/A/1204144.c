#include <stdio.h>
#include <stdlib.h>
int a[1<<19];
int cmp(const int* a, const int* b) {
    return *b - *a;
}
int main(void) {
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &a[3 * i], &a[3 * i + 1], &a[3 * i + 2]);
    qsort(a, 3 * n, sizeof(int), cmp);
    for(int i = 1; i < 2 * n; i += 2)
        sum += a[i];
    printf("%lld", sum);
} ./Main.c: In function ‘main’:
./Main.c:13:34: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
     qsort(a, 3 * n, sizeof(int), cmp);
                                  ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &a[3 * i], &a[3 * i + 1], &a[3 * i + 2]);
         ^
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int index;
    int length;
} A;
int f_cmp(const void *a, const void *b) {
    return ((A *)b)->length - ((A *)a)->length;
}
static int n;
static A as[100000];
int main(void) {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        as[i].index = i + 1;
        scanf("%d", &as[i].length);
    }
    qsort(as, n, sizeof(A), f_cmp);
    for (i = 0; i < n; ++i)
        printf("%d\n", as[i].index);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &as[i].length);
         ^
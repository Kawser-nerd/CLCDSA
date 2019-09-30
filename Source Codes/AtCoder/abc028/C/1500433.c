#include <stdio.h>
static int a[5], max1, max2, max3;
int main(void) {
    int i, j, k;
    scanf("%d%d%d%d%d", a, a + 1, a + 2, a + 3, a + 4);
    for (i = 0; i <= 2; ++i)
        for (j = i + 1; j <= 3; ++j)
            for (k = j + 1; k <= 4; ++k)
                if (a[i] + a[j] + a[k] >= max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = a[i] + a[j] + a[k];
                }
    printf("%d\n", max3);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d", a, a + 1, a + 2, a + 3, a + 4);
     ^
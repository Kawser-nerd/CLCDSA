#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int h = n / (60 * 60);
    n %= (60 * 60);
    int m = n / 60;
    n %= 60;
    printf("%02d:%02d:%02d\n", h, m, n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
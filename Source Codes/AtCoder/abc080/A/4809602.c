#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a * n > b)
    {
        printf("%d\n", b);
    }
    else
    {
        printf("%d\n", a * n);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &n, &a, &b);
     ^
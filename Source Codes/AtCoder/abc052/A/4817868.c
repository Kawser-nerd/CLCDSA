#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a * b == c * d)
    {
        printf("%d\n", a * b);
    }
    else
    {
        printf("%d\n", a * b > c * d ? a * b : c * d);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &a, &b, &c, &d);
     ^
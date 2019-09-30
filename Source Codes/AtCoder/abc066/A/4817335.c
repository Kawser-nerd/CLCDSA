#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a <= b && c <= b)
    {
        printf("%d\n", a + c);
    }
    else if (b <= a && c <= a)
    {
        printf("%d\n", b + c);
    }
    else
    {
        printf("%d\n", a + b);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &a, &b, &c);
     ^
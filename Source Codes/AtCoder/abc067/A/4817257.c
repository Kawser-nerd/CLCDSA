#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)
    {
        printf("Possible\n");
    }
    else
    {
        printf("Impossible\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^
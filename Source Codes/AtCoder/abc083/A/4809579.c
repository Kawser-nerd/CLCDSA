#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int right, left;
    left = a + b;
    right = c + d;
    if (right > left)
    {
        printf("Right\n");
    }
    else if (right < left)
    {
        printf("Left\n");
    }
    else
    {
        printf("Balanced\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &a, &b, &c, &d);
     ^
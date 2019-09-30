#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 1)
    {
        a = 14;
    }
    if (b == 1)
    {
        b = 14;
    }
    if (a == b)
    {
        printf("Draw\n");
    }
    else if (a > b)
    {
        printf("Alice\n");
    }
    else
    {
        printf("Bob\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^
#include<stdio.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    while (n > 0)
    {
        n -= a;
        if (n <= 0)
        {
            printf("Ant\n");
            return 0;
        }
        n -= b;
        if (n <= 0)
        {
            printf("Bug\n");
            return 0;
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("Not Prime\n");
        return 0;
    }
    if (n < 4)
    {
        printf("Prime\n");
        return 0;
    }
    if (n == 5)
    {
        printf("Prime\n");
        return 0;
    }
    if (n % 2 == 0 || n % 5 == 0 || n % 3 == 0)
    {
        printf("Not Prime\n");
        return 0;
    }
    printf("Prime\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
#include <stdio.h>
int main()
{
    int N, A, B, a;
    scanf("%d%d%d", &N, &A, &B);
    if (1 <= N <= 20 && 1 <= A <= 100 && 1 <= B <= 2000)
    {
        a = N * A;
        if (a > B)
        {
            printf("%d", B);
        }
        else
        {
            printf("%d", a);
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &N, &A, &B);
     ^
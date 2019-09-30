#include<stdio.h>
int main()
{
    int  N, A, B, X;
    scanf("%d %d %d", &N, &A, &B);
     X = N * A;
    if(X<B)
     printf("%d\n", X);
    else
     printf("%d\n", B);
     return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &N, &A, &B);
     ^
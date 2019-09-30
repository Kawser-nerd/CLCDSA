#include "stdio.h"
int main()
{
    int A, N;

    scanf("%d %d", &N, &A);

    if(N % 500 <= A)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &A);
     ^
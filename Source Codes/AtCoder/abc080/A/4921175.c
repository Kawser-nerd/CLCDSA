#include<stdio.h>
int main()
{
    int N, A, B, x;
    scanf("%d %d %d",&N, &A, &B);
    x=N*A;
    if(x>B)
    {
        printf("%d",B);
    }
    else if(x==B)
    {
        printf("%d\n",x);
    }
    else
    {
        printf("%d",x);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N, &A, &B);
     ^
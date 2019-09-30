#include <stdio.h>

int main(void)
{
    int a,b;
    int n,x;
    scanf("%d %d",&a,&b);
    n=b-a-1;
    x=(n*(n+1))/2-a;
    printf("%d\n",x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^
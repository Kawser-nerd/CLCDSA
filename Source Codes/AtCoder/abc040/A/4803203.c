#include <stdio.h>
int main()
{
    int x,n;
    scanf("%d %d",&n,&x);
    if(n-x<x-1) printf("%d\n",n-x);
        else printf("%d\n",x-1);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&x);
     ^
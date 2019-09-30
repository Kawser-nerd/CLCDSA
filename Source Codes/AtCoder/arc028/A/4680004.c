#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    n%=(a+b);
    if(n>0&&n<=a)puts("Ant");
    else puts("Bug");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^
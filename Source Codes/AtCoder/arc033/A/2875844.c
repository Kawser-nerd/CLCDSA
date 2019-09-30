#include<stdio.h>
int main()
{
    int sum=0,i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    sum+=i;
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
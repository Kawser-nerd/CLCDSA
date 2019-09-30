#include<stdio.h>
int srx[100001],i,sry,n;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {scanf("%d",&sry);  
    srx[sry]=1;}
    sry=0;
    for(i=1;i<=100001;++i)
    if(srx[i])
    sry++;
    printf("%d\n",n-sry);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     {scanf("%d",&sry);  
      ^
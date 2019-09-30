#include<stdio.h>
int n,srx,sry,t;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {scanf("%d",&t);
    if(t>srx)
    {sry=srx;
    srx=t;}
    else if(t<srx&&t>sry)
    sry=t;}
    printf("%d\n",sry);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     {scanf("%d",&t);
      ^
#include<stdio.h>
int main()
{
    int n,s,a,i,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("%d%d",&a,&b);
    s+=a*b;}
    s*=1.05;
    printf("%d\n",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     {scanf("%d%d",&a,&b);
      ^
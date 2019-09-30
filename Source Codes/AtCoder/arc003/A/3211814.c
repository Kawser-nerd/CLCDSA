#include<stdio.h>
int srx,i,n;
char sry;
double lhy;
void mzy()
{
    scanf("%d",&n);
    for(i=0;i<=n+1;i++)
    {scanf("%c",&sry);
    if(sry=='A')
    srx+=4;
    if(sry=='B')
    srx+=3;
    if(sry=='C')
    srx+=2;
    if(sry=='D')
    srx+=1;
    else
    srx+=0;}
}
void zjq()
{
    lhy=srx;
    lhy/=n;
    if(srx==0)
    {printf("0\n");
    return ;}
    printf("%.14f\n",lhy);
}
int main()
{
    mzy();
    zjq();
    return 0;
} ./Main.c: In function ‘mzy’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     {scanf("%c",&sry);
      ^
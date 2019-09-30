#include<stdio.h>
#include<math.h>
int n,a,b,t,i;
int lgx(int x,int y)
{
    int i;
    while(y)
    {i=x%y;
    x=y;
    y=i;}
    return x;
}
int main()
{
    scanf("%d%d%d",&a,&b,&n);
    t=a*b/lgx(a,b);
    if(n%t)
    printf("%d\n",(n/t+1)*t);
    else
    printf("%d\n",n/t*t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&n);
     ^
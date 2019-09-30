#include<stdio.h>
#include<math.h>
int lgx(double x)
{
    for(int i=1;i<=100;++i)
    if(i>=x)
    return i;
}
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    printf("%d\n",lgx((double)a/b)*b-a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
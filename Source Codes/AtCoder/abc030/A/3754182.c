#include<stdio.h>
double mzy,zjq,lhy,lgx,srx,sry;
int main()
{
    scanf("%lf%lf%lf%lf",&mzy,&zjq,&lhy,&lgx);
    srx=zjq/mzy;
    sry=lgx/lhy;
    if(srx<sry)
    printf("AOKI\n");
    if(srx==sry)
    printf("DRAW\n");
    if(srx>sry)
    printf("TAKAHASHI\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf%lf%lf",&mzy,&zjq,&lhy,&lgx);
     ^
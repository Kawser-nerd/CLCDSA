#include<stdio.h>

int main(void)
{
    int a,b,h,w,s;

    scanf("%d%d",&h,&w);
    scanf("%d%d",&a,&b);
    s=(h-a)*(w-b);
    printf("%d\n",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
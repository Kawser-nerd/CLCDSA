#include<stdio.h>
int main(void)
{
    int H,W,h,w,c=0;
    scanf("%d%d%d%d",&H,&W,&h,&w);
    c=(H-h)*(W-w);
    printf("%d",c);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&H,&W,&h,&w);
     ^
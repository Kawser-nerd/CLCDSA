#include <stdio.h>
int main()
{   float h,w;
    scanf("%f%f",&w,&h);
    if(h/w==0.75)printf("4:3\n");
    else printf("16:9\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f%f",&w,&h);
     ^
#include <stdio.h>
int main(void){
    int h,w;
    scanf("%d%d",&h,&w);
    printf("%d\n",(w-1)*h+(h-1)*w);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
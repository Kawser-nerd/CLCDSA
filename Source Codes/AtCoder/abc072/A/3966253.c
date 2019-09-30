#include <stdio.h>
int main(void){
    int x,t;
    scanf("%d%d",&x,&t);
    if(x-t<=0) printf("0");
    else printf("%d",x-t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&t);
     ^
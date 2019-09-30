#include <stdio.h>
int main(void){
    int x;
    scanf("%d",&x);
    printf("%s\n",x<1200?"ABC":"ARC");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^
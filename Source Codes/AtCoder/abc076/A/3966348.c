#include <stdio.h>
int main(void){
    int r,g;
    scanf("%d%d",&r,&g);
    printf("%d",2*g-r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&r,&g);
     ^
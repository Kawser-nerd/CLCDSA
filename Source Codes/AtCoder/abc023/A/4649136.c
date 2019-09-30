#include <stdio.h>
int main(void){
    int x;
    scanf("%d",&x);
    printf("%d\n",x/10+x%10);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^
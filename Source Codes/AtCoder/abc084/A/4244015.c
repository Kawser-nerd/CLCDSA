#include<stdio.h>
int main(void){
    int M;
    scanf("%d",&M);
    printf("%d\n",48-M);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&M);
     ^
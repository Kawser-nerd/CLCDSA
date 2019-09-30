#include <stdio.h>
int main(void){
    int l1,l2,l3;
    scanf("%d%d%d",&l1,&l2,&l3);
    printf("%d\n",l1==l2?l3:(l2==l3?l1:l2));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l1,&l2,&l3);
     ^
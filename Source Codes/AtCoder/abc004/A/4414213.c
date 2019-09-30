#include <stdio.h>
int main(void){
    int ans;
    scanf("%d",&ans);
    printf("%d",2*ans);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&ans);
     ^
#include <stdio.h>

int main(void){
    char X;
    scanf("%c",&X);
    printf("%d\n",X-'A'+1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&X);
     ^
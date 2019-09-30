#include <stdio.h>
#include <math.h>
int main(void){
    int n,pow;
    scanf("%d", &n);
    pow=sqrt(n);
    printf("%d\n",pow*pow);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
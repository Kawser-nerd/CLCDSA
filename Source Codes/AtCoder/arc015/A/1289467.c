#include <stdio.h>
int main(void){
    double n,m;
    scanf("%lf",&n);
    m=32+n*9/5;
    printf("%lf\n",m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf",&n);
     ^
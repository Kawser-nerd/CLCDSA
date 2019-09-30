#include <stdio.h>
int main(void){
    double t,x;
    scanf("%lf%lf",&t,&x);
    printf("%lf\n",t/x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf",&t,&x);
     ^
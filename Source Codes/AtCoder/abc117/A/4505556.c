#include <stdio.h>

int main(){
    int t,x;
    scanf("%d %d",&t,&x);
    printf("%lf",(double)t/(double)x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&t,&x);
     ^
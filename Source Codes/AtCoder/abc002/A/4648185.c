#include <stdio.h>
int main(void){
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",x>y?x:y);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&x,&y);
     ^
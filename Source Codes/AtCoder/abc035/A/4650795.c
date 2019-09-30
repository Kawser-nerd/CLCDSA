#include <stdio.h>
int main(void){
    long long int w,h;
    scanf("%lld%lld",&w,&h);
    printf("%s\n",w*3==h*4?"4:3":"16:9");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&w,&h);
     ^
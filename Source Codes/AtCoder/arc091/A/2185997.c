#include <stdio.h>
int main(void){
    long long int N,M;
    scanf("%lld %lld",&N,&M);
    if(N>=2&&M>=2)printf("%lld",(N-2)*(M-2));
    else{
        if(!(N==1&&M==1))printf("%lld",N*M-2);
        else printf("1");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&N,&M);
     ^
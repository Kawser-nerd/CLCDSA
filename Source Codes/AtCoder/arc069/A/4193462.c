#include <stdio.h>
int main()
{   long long n,m;
    scanf("%lld%lld",&n,&m);
    if(n>=m/2){
        printf("%lld",m/2);
    }else{
        printf("%lld",n+(m-n*2)/4);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
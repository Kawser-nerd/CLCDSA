#include <stdio.h>

int main()
{   long long n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    if(b<a||(a!=b&&n==1)){
        printf("0");
    }else if(a==b){
        printf("1");
    }else
    printf("%lld",(n-2)*(b-a)+1);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&n,&a,&b);
     ^
#include <stdio.h>
long long Min(long long a,long long b){
    return a<=b?a:b;
}
int main()
{   long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a%2==1&&b%2==1&&c%2==1){
        printf("%lld",Min(a*b,Min(b*c,c*a)));
    }else{
        printf("0");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&a,&b,&c);
     ^
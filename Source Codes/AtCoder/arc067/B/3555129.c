#include <stdio.h>
int main(void){
    long long n,a,b,ans=0;
    scanf("%lld%lld%lld",&n,&a,&b);
    long long x[n];
    for (int i=0; i<n; i++){
        scanf("%lld",&x[i]);
    }
    for (int i=0; i<n-1; i++){
        if ((x[i+1]-x[i])*a<b){
            ans+=(x[i+1]-x[i])*a;
        } else {
            ans+=b;
        }
    }
    printf("%lld\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&n,&a,&b);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&x[i]);
         ^
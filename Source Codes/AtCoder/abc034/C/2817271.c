#include <stdio.h>
#include <stdlib.h>
 
long long mod=1000000007;
long long modp(long long d,long long p){
    if (p==0){
        return (1) ;
    } else if (p%2==0){
        long long d2=modp(d,p/2);
        return ((d2*d2)%mod);
    } else {
        return ((d*modp(d,p-1))%mod);
    }
}
 
int main(void){
    long long w,h;
    scanf("%lld%lld",&w,&h);
    long long n=(w-1)+(h-1),ans=1;
    for (long long i=0; i<w-1; i++){
        ans=(ans*(n-i))%mod;
    }
    long long tmp=1;
    for (long long i=0; i<w-1; i++){
        tmp=(tmp*(i+1))%mod;
    }
    ans=(ans*modp(tmp,mod-2))%mod;
    printf("%lld",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&w,&h);
     ^
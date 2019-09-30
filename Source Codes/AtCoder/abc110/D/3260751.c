#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

long long mod=1000000007;

long long modp(long long d,long long p){
    if (p==0){
        return 1 ;
    } else if (p==1){
        return d%mod ;
    } else if (p%2==0){
        return ((modp(d,p/2)%mod)*(modp(d,p/2))%mod)%mod;
    } else {
        return ((modp(d,p/2)%mod)*(modp(d,p/2))%mod)*d%mod;
    }
}

long long ncr(long long a,long long b){
    long long combinationans=1;
    long long combinationanss=1;
    long long combinationansm=1;
    for (long long i=0; i<b; i++){
        combinationanss=(combinationanss*(a-i))%mod;
        combinationansm=(combinationansm*modp(i+1,mod-2))%mod;
    }
    combinationans=(combinationanss*combinationansm)%mod;
    return (combinationans);
}

int main(void){
    long long n,m,p,ans=1;
    scanf("%lld%lld",&n,&m);
    p=m;
    for (long long i=2; i<=p; i++){
        long long count=0;
        while(p%i==0){
            p/=i;
            count++;
        }
        if (count!=0){
            ans=(ans*ncr(count+n-1,count))%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
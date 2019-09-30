#include <stdio.h>
#define MOD 1000000007
#define ll long long
ll a[100000];
ll b[100000];
int main(void){
    ll n,m;
    ll p=0,q=0;
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<n;i++){
        p += i*(n-i)*(a[i]-a[i-1]);
        p %= MOD;
    }
    for(int i=1;i<m;i++){
        q += i*(m-i)*(b[i]-b[i-1]);
        q %= MOD;
    }
    printf("%lld\n",p*q%MOD);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&m);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&b[i]);
         ^
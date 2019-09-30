#include <stdio.h>
#define MOD 1000000007
#define swap(a,b) do{int tmp; tmp = a; a = b; b = tmp;}while(0)

long long int modinv(long long int a, long long int m) {
    long long int b = m, u = 1, v = 0;
    while (b) {
        long long int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(void){
    long long int n,k,a=1,b=1;
    int i;
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(i=2;i<=n+k-1;i++){
        a *= i;
        a %= MOD;
        if(i==k||i==n-1){
            b *= a;
            b %= MOD;
        }
    }
    a %= MOD;
    printf("%lld\n",a*modinv(b,MOD)%MOD);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&k);
     ^
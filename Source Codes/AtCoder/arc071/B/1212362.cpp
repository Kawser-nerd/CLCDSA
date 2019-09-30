#include<cstdio>

#define MOD 1000000007

long long int x[1000000];
long long int y[1000000];

int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%lld",&x[i]);
    for(int i=0; i<m; i++)
        scanf("%lld",&y[i]);

    long long int lx=0, ly=0;
    for(int i=0; i<n-1; i++)
        lx += (x[i+1] - x[i])*(i+1) * (n-i-1), lx %= MOD;
    for(int i=0; i<m-1; i++)
        ly += (y[i+1] - y[i])*(i+1) * (m-i-1), ly %= MOD;

    printf("%lld\n", lx*ly % MOD);
    return 0;
}
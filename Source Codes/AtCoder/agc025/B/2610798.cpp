#include <stdio.h>
#define N_MAX 300010
#define ll long long
#define CONST 998244353

ll C[N_MAX];

ll ext_gcd(ll a, ll b, ll&x, ll&y){
    if(b == 0){
        x = 1; y = 0; return a;
    }
    ll q = a / b;
    ll g = ext_gcd(b, a-q*b, x, y);
    ll z = x - q * y;
    x = y; y = z;
    return g;
}

ll invmod(ll a, ll m){
    ll x, y;
    ext_gcd(a, m, x, y);
    x %= m;
    if(x < 0) x += m;
    return x % CONST;
}


int main(void){
    ll N, A, B, K;
    scanf("%lld", &N);
    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &K);

    C[0] = 1;
    for(ll i = 1; i <= N; i++){
        C[i] = ((C[i - 1] * (N - i + 1)) % CONST * invmod(i, CONST)) % CONST;
        //printf("%lld %lld\n", i, C[i]);
    }

    ll sum = 0;
    for(ll n1 = 0; n1 <= N; n1++){
        if((K - A * n1) < 0){
            break;
        }
        if((K - A * n1) % B != 0){
            continue;
        }
        ll n2 = (K - A * n1) / B;
        if(n2 > N){
            continue;
        }
        sum += C[n1] * C[n2];
        sum = sum % CONST;
    }

    printf("%lld\n", sum);
}
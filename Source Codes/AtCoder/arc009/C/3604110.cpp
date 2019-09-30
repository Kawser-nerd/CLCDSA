#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1777777777;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

long long power(long long x, long long c) {
    if(c==0) return 1;
    if(c==1) return x;
    if (c%2==1) return (power( (x*x)%MOD, c/2)*x)%MOD;
    else return power( (x*x)%MOD, c/2)%MOD;
}

ll comb(ll n, ll m){
    n%=MOD;
    m = min(m,n-m);
    ll a=1, b=1;
    for(ll i=0;i<m;i++){
        a=(a*(n-i))%MOD;
        b=(b*(m-i))%MOD;
    }
    b=power(b,MOD-2);
    return a*b%MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;
    cin>>N>>K;
    ll x = comb(N,K);
    ll f[K+1];
    f[1] = 0;
    f[2] = 1;
    FOR(i,3,K+1) f[i] = (ll)(i-1) * (f[i-1]+f[i-2]) % MOD;
    cout1(x*f[K]%MOD);
}
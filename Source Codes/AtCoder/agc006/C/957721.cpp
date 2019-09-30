#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

int N;
vector<ll> X;
int M;
ll K;
vector<int> A;

vector<int> add(const vector<int> &a, const vector<int> &b) {
    vector<int> X(N-1);
    for (int i = 0; i < N-1; i++) {
        X[i] = a[b[i]];
    }
    return X;
}

int main(int,char**) {
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    X.resize(N); rv(X); 
    cin >> M >> K;
    A.resize(M); rv(A);
    for(int&a:A) --a;

    vector<int> P(N-1), R;
    for (int i = 0; i < N-1; i++) {
        P[i] = i;
    }
    R = P;

    for(int a:A) {
        swap(P[a-1],P[a]);
    }

    while (K) {
        if (K&1) {
            R = add(R, P);
        }
        P = add(P, P);
        K /= 2;
    }

    ll c = X[0];
    printf("%d\n", X[0]);
    for (int i = 0; i < N-1; i++) {
        c += X[R[i]+1] - X[R[i]];
        printf("%lld\n", c);
    }

} ./Main.cpp:78:20: warning: format specifies type 'int' but the argument has type 'value_type' (aka 'long long') [-Wformat]
    printf("%d\n", X[0]);
            ~~     ^~~~
            %lld
1 warning generated.
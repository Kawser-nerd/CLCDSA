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
using namespace std;

#ifndef MDEBUG
#define NDEBUG
#endif

#define x first
#define y second
#define ll long long
#define d double
#define ld long double
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define psi pair<string,int>
#define pis pair<int,string>
#define psl pair<string,ll>
#define pls pair<ll,string>
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
// auto fraclt = [](auto&a,auto&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
template<typename T> void fracn(pair<T,T>&a) {auto g=gcd(a.x,a.y);a.x/=g;a.y/=g;}
template<typename T> struct Index { int operator[](const T&t){auto i=m.find(t);return i!=m.end()?i->y:m[t]=m.size();}int s(){return m.size();} unordered_map<T,int> m; };

#define M 400
#define MOD 1000000007

ll PREF[M+1][M+1];
ll DP[M+1][M+1];

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    for (int i = 0; i <= M; i++) {
        PREF[i][0] = 0;
        DP[0][i] = 0;
    }
    DP[0][0] = 1;

    for (int i = 1; i <= M; i++) {
        ll c = 1;
        for (int j = 0; j <= M; j++) {
            PREF[j][i] = (PREF[j][i-1] + c) % MOD;
            c = c*i % MOD;
   //         if (j < 5 && i < 5) cout << j << ' ' << i << '=' << PREF[j][i] << endl;
        }
    }

    ri(N); ri(C);
    vector<int> A(N); rv(A);
    vector<int> B(N); rv(B);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            DP[i][j] = 0;
            for (int k = 0; k <= j; k++) {
                DP[i][j] = (DP[i][j] + DP[i-1][k] * (MOD + PREF[j-k][B[i-1]] - PREF[j-k][A[i-1]-1])) % MOD;
            }
 //           cout << i << ' ' << j << ' '<< DP[i][j] << endl;
        }
    }

    cout << DP[N][C] << endl;



}
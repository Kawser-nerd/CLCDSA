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

#define TOOMUCH 10000000000

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    vector<bool> E(100000,true); E[0]=E[1]=false;
    vector<ll> PC;
    vector<int> P;
    for (int i = 2; i < 100000; i++) {
        if (E[i]) {
            for (ll j = (ll)i*i; j < 100000; j+=i) {
                E[j] = false;
            }
            if (i < 2500)
                PC.push_back((ll)i*i*i);
            P.push_back(i);
        }
    }

    int N;
    scanf("%d", &N);
    vector<ll> S(N);
    for(auto&s:S) scanf("%lld", &s);
    for(auto&s:S) for (auto&p:PC) while (s%p==0) s/=p;
    
    map<ll,int> C;
    for(auto&s:S) C[s]++;

    int ans = 0;
    for(auto iter = C.begin(); iter != C.end(); ++iter) {
        ll a = iter->x;
        if (a==1) { ans += 1; continue; }
        ll b = 1;
        for (auto &p: P) {
            if (a == 1) break;
            if (a % p==0) {
                if (b * p > TOOMUCH) { b = -1; break; }
                b *= p;
                a /= p;
                if (a % p == 0) {
                    a /= p;
                } else {
                    if (b * p > TOOMUCH) { b = -1; break; }
                    b *= p;
                }
            }
            if ((ll)p*p>a) break;
        }
        if (a != 1 && b != -1) {
            if (b * a < b) { b = -1; }
            else {
                b *= a;
                if (b * a < b) { b=-1; }
                else b *= a;
            }
        }

        auto bi = C.find(b);
        if (bi == C.end()) {
            ans += iter->y;
        } else if (bi->y < iter->y) {
            ans += iter->y;
        } else if (bi->y == iter->y && iter->x < b) {
            ans += iter->y;
        }
    }
    cout << ans << endl;
}
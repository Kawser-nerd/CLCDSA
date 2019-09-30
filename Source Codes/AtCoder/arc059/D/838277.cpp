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


template <int N> class Field {
    inline int mod(int i) {int tmp=i%N; return tmp ? i>=0?tmp:tmp+N : 0;}
    inline int mod(ll i) {int tmp=i%N; return tmp ? i>=0?tmp:tmp+N : 0;}
    inline int inv(int a) {
        int t=0,nt=1,r=N,nr=a;
        while(nr) { int q=r/nr; t-=q*nt; swap(t,nt); r-=q*nr; swap(r,nr); }
        assert(r<=1); return (t<0) ? t+N : t;
    }
public:
    inline Field(int x = 0) : v(mod(x)) {}
    inline Field<N>&operator+=(const Field<N>&o) {v=mod(v+o.v); return *this; } 
    inline Field<N>&operator-=(const Field<N>&o) {v=mod(v-o.v); return *this; } 
    inline Field<N>&operator*=(const Field<N>&o) {v=mod((ll)v*o.v); return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) {Field<N>r(*this);return r+=o;}
    inline Field<N> operator-(const Field<N>&o) {Field<N>r(*this);return r-=o;}
    inline Field<N> operator*(const Field<N>&o) {Field<N>r(*this);return r*=o;}
    inline Field<N> operator/(const Field<N>&o) {Field<N>r(*this);return r/=o;}
    inline Field<N> operator-() {return {-v};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r(*this); ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r(*this); --*this; return r; }
    inline bool operator==(const Field<N>&o) { return o.v==v; }
    inline explicit operator int() const { return v; }
private: int v;
};
template<int N>istream &operator>>(istream&is,Field<N>&f){int v;is>>v;f=v;return is;}
template<int N>ostream &operator<<(ostream&os,const Field<N>&f){return os<<(int)f;}

#define MN 5000
#define FF Field<MOD>

FF F[MN+1];
FF I[MN+1];
FF P[MN+1];
//FF DP[MN+1][MN+1];

FF Q[MN+1][MN+1];

#define MOD 1000000007

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    string S; cin >> S;
    int L = S.size();

    F[0] = 1; I[0] = 1; P[0] = 1;
    for (int i = 1; i <= MN; i++) {
        F[i] = F[i-1] * i;
        I[i] = I[i-1] / i;
        P[i] = P[i-1] * 2;
    }

    for (int i = 1; i <= L; i++) {
        Q[0][i] = 0;
    }
    Q[0][0] = 1;

    for (int k = 1; k <= N; k++) {
        Q[k][0] = Q[k-1][1] + Q[k-1][0];
        for (int l = 1; l < N; l++) {
            Q[k][l] = Q[k-1][l-1]*2 + Q[k-1][l+1]; 
        }
        Q[k][N] = Q[k-1][N-1]*2;
    }

    cout << Q[N][L] / P[L] << endl;

/*
    DP[0][0] = 1;
    for (int u = 1; u <= N; u++) {
        for (int c = 1; c <= L; c++) {
            DP[u][c] = DP[u-1][c-1];
            for (int k = 2; u - 1 - k >= 0; k += 2) {
                DP[u][c] += DP[u-1-k][c-1]*P[k/2]*(F[k-2]*I[k/2-1]*I[k/2-1]-F[k-2]*I[k/2]*I[k/2-2]);
            }
            cout << u << ' ' << c << '=' << DP[u][c] << endl;
        }
    }

    FF ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += DP[i][L];
    }
    cout << ans << endl;
*/

}
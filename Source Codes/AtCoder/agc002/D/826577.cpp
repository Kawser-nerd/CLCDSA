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

#define MAX 100000

int S[MAX];
int B[MAX];

map<int, int> HS[MAX];
map<int, int> HB[MAX];

int find(int a, int t) {
    auto iter = HB[a].upper_bound(t);
    --iter;
    if (iter->y == a) return a;
    else return find(iter->y,t);
}

bool united(int a,int b, int t) {
    int fa = find(a,t);
    int fb = find(b,t);
    return fa==fb;
}

int getSize(int a,int t) {
    a = find(a,t);
    auto iter = HS[a].upper_bound(t);
    --iter;
    return iter->y;
}

bool isdone(int a, int b, int size, int t) {
    int sizeA = getSize(a, t);
    if (sizeA >= size) return true;
    if (united(a,b,t)) return false;
    return getSize(b,t) + sizeA >= size;
}


int find(int i) {
    while(B[i] != i) i = B[i];
    return i;
}

bool unite(int a,int b, int t) {
    a = B[a] = find(a);
    b = B[b] = find(b);
    if (a==b) return false;
    if (S[a] <= S[b]) {
        HS[b][t] = S[b] += S[a];
        HB[a][t] = B[a] = b;
    } else {
        HB[b][t] = B[b] = a;
        HS[a][t] = S[a] += S[b];
    }
    return true;
}

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N,M,Q;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        B[i] = i; HB[i][0] = i;
        S[i] = 1; HS[i][0] = 1;
    }
    for (int i = 0; i < M; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        unite(a-1,b-1,i+1);
    }
    for (int i = 0; i < N; i++) {
        HB[i][M] = B[i];
        HS[i][M] = S[i];
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        int lo = 1, hi = M, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isdone(x-1, y-1, z, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("%d\n", res);
    }
}
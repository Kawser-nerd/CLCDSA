#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
const int INF = 1001001001;
const ll LINF = 1e18;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    T r;
    while((r=a%b)) {
        a = b; b = r;
    }
    return b;
}
bool p_comp_fs(const P p1, const P p2){ return p1.first < p2.first;};
bool p_comp_fg(const P p1, const P p2){ return p1.first > p2.first;};
bool p_comp_ss(const P p1, const P p2){ return p1.second < p2.second;};
bool p_comp_sg(const P p1, const P p2){ return p1.second > p2.second;};

struct UnionFind{
    vl par;
    vl rank;
    UnionFind(ll N) : par(N, 0), rank(N, 0){
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    ll root(ll x){
        if(par[x] == x) return x;
        else{
            par[x] = root(par[x]); // compression
            return par[x];
        }
    }
    
    void unite(ll x, ll y){
        ll rx = root(x); ll ry = root(y);
        if(rx == ry) return;
        if(rank[rx] < rank[ry]) swap(rx, ry);
        if(rank[rx] == rank[ry]) ++rank[rx];
        par[ry] = rx;
    }
    
    bool same(ll x, ll y){
        return root(x) == root(y);
    }
};
    
int main(){
    ll N, M; cin >> N >> M;
    vl as(M, 0), bs(M, 0);
    REP(i, M){
        ll a, b; cin >> a >> b;
        as[i] = a - 1;
        bs[i] = b - 1;
    }
    
    ll ret = 0;
    REP(i, M){
        auto uf = UnionFind(N);
        REP(j, M){
            if(j != i){
                uf.unite(as[j], bs[j]);
            }
        }
        bool ok = true;
        REP(j, N){
            if (!uf.same(0, j)) {
                ok = false; break;
            }
        }
        if(!ok) ret++;
    }
    cout << ret << endstr;
    return 0;
}
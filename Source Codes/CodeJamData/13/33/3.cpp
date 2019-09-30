
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

const int M = 5*1e8;
struct T {
    struct node{
        node (int l, int r, int _mn, int _me): left(l), right(r), mn(_mn), me(_me) {}
        int left, right;
        int mn, me;
    };

    vector<node> V;
    int N; 
    T() {
        N = 1;
        while(N < 2*M) N*=2;
        V.PB(node(-1,-1,0,0));
    }

    bool _attack(int i, int l, int r, int L, int R, int s) {
        if (R <= l || r <= L) return false;
        if (i == -1) return (s > 0);
        if (V[i].me >= s) return false;
        if (l <= L && R <= r) return (s > V[i].mn);
        return _attack(V[i].left, l, r, L, (L+R)/2, s) || _attack(V[i].right, l, r, (L+R)/2, R, s);
    }
    bool attack(int l, int r, int s) {
        l += M; r += M;
        return _attack(0, l, r, 0, N, s);
    }

    void _build(int i, int l, int r, int L, int R, int s) {
        if (R <= l || r <= L) return;
        if (V[i].me >= s) return;
        if (l <= L && R <= r) {
            V[i].me = s;
            if (V[i].left != -1) V[i].mn = max(V[i].me, min(V[V[i].left].mn, V[V[i].right].mn));
            else V[i].mn = V[i].me;
            return;
        }
        if (V[i].left == -1) {
            V.PB(node(-1, -1, 0,0));
            V.PB(node(-1, -1, 0,0));
            V[i].left = SZ(V)-1;
            V[i].right = SZ(V)-2;
        }
        _build(V[i].left, l, r, L, (L+R)/2, s);
        _build(V[i].right, l, r, (L+R)/2, R, s);
        V[i].mn = max(V[i].me, min(V[V[i].left].mn, V[V[i].right].mn));
    }


    void build (int l, int r, int s) {
        l += M; r += M;
        _build(0, l, r, 0, N, s);
    }


};
struct attack{
    attack(int _w, int _e, int _s): w(_w), e(_e), s(_s) {}
    int w, e, s;
};
int solve() {
    int N;
    cin >> N;
    T t;
    vector<vector<attack> > D(676061, vector<attack>());
    REP(i, N) {
        int d,n,w,e,s,dd,dp,ds;
        cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
        REP(j, n) {
            D[d+j*dd].PB(attack(w+j*dp, e+j*dp, s+j*ds));
        }
    }
    int res = 0;
    REP(i, 676061) {
        vector<attack> &v = D[i];
        FORE(it, v) {
     //       cout << i << ": " << it-> w << " " << it->e << " " << it->s << endl;
            if (t.attack(it->w, it->e, it->s)) {
                ++res;
            }
        }
        FORE(it, v) {
            t.build(it->w, it->e, it->s);
        }
    }
    cout << res << endl;
    return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
	return 0;
}


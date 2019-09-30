
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

// TEAM library code starts here
const int MX = 50000;
struct Match { 
    int n;// n is the TOTAL number of vertices (0..n_-1)
    int up[MX]; // matching 
    bool vis[MX];    
    VI G[MX];     // edges, directed left to right

    void init(int _n) {
        n = _n;
        REP(i,n) {
            G[i].clear();
            up[i] = -1;
        }
    }
    void add(int a, int b){ G[a].PB(b); } // edge from a to b (directed left to right)

    bool aug(int x) {
        vis[x] = true;
        FORE(i,G[x]) if(up[*i] != x) if(up[*i] < 0 || (!vis[up[*i]] && aug(up[*i]))) {
            up[*i] = x;
            up[x] = *i;
            return true;
        }
        return false;
    }
    int match() {
        int cnt = 0;
        bool ok = true;
        while(ok) {
            ok = false;
            memset(vis, 0, n*sizeof(bool));
            REP(i,n) if(up[i] < 0 && aug(i)) {ok=true; cnt++; }
        };
        return cnt;
    }
};
// TEAM library code ends here

Match M;
void solve(int tc) {
    cout << "Case #" << tc << ": ";
    map<string,int> A, B;
    int n;
    cin >> n;
    M.init(2*n);
    REP(i,n) {
        string a, b;
        cin >> a >> b;
        if (A.find(a) == A.end()) A.insert({a,SZ(A)});
        if (B.find(b) == B.end()) B.insert({b,SZ(B)});
        M.add(A[a], n + B[b]);
    }
    int m = M.match();
    int res = n -  SZ(A) - SZ(B) + m;
    assert(res >= 0 && res <= n);
    cout << n -  SZ(A) - SZ(B) + m << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}


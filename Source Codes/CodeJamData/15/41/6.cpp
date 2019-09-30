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


const int INF=1e9;

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,m;
    cin >> n >> m;
    vector<string> A(n);
    VI mxR(n, -1), mnR(n, INF), mxC(m, -1), mnC(m, INF);
    REP(i,n) cin >> A[i];
    REP(i,n) REP(j,m) {
        if (A[i][j] != '.') {
            maxi(mxR[i], j);
            mini(mnR[i], j);
            maxi(mxC[j], i);
            mini(mnC[j], i);
        }
    }
    bool ok = true;
    int cnt = 0;
    REP(i,n) REP(j,m) {
        if (A[i][j] == '.') continue;
        if (mxR[i] == j && mnR[i] == j && mxC[j] == i && mnC[j] == i) ok = false;
        if (A[i][j] == '<' && mnR[i] == j) ++cnt;
        if (A[i][j] == '>' && mxR[i] == j) ++cnt;
        if (A[i][j] == '^' && mnC[j] == i) ++cnt;
        if (A[i][j] == 'v' && mxC[j] == i) ++cnt;
    }
    if (!ok) cout << "IMPOSSIBLE" << endl;
    else cout << cnt << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}


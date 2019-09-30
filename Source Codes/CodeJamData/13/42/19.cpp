

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

LL ans(LL N, LL cnt) {
    if (cnt >= N/2) return 0;
    else return 2*ans(N/2, cnt)+2;
}

LL solveA(int n, LL p) {
    LL N = ((LL)1ll<<n);
    if (p == N) return N-1;
    if (p == 0) return -1;
    return ans(N, N-p);
}

int solve() {
    int n; LL p;
    cin >> n >> p;
    cout << solveA(n, p) << " ";
    LL N = (LL) 1ll<<n;
    cout << N-2-solveA(n,N-p) << endl;

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


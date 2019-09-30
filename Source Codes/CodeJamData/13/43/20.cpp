

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

const int MN = 2010;
VI G[MN];
int d[MN];

int a[MN];
int b[MN];
int res[MN];
int solve() {
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) {
        G[i].clear();
        d[i] = 0;
    }

    REP(i, n) {
        bool ok = false;
        FORD(j, i-1, 0) {
            if (a[j] == a[i]-1 && !ok) {
               // cerr << j << "->" << i << endl;
                G[j].PB(i);
                ok = true;
            }
            if (a[j] >= a[i]) {
             //   cerr << i << "->" << j << endl;
                G[i].PB(j);
            }
        }

    }
   // cerr << "-" << endl;
    REP(i, n) {
        bool ok = false;
        FOR(j, i+1, n-1) {
            if (b[j] == b[i]-1 && !ok) {
                G[j].PB(i);
      //          cerr << j << "->" << i << endl;
                ok = true;
            }
            if (b[j] >= b[i]) {
      //          cerr << i << "->" << j << endl;
                G[i].PB(j);
            }
        }
    }
    REP(i, n) FORE(it, G[i]) d[*it]++;
    priority_queue<int, vector<int>, greater<int> > Q;
    REP(i, n) if (d[i] == 0) Q.push(i);
    int cnt = 0;
    assert(Q.size()==1);
    while(!Q.empty()) {
        int f = Q.top();
        res[f] = cnt;
        ++cnt;
        Q.pop();
        FORE(it, G[f]) {
            d[*it]--;
            if (d[*it]==0) Q.push(*it);
        }
    }
    assert(cnt == n);
    REP(i, n) cout << " " << res[i]+1;
    cout << endl;
    REP(i, n) {
        int m = 0;
        REP(j, i) {
            if (res[j] < res[i]) maxi(m, a[j]);
        }
        if (a[i] != m+1) cerr <<i << endl;
        assert(a[i] == m+1);
    }
    REP(i, n) {
        int m = 0;
        FOR(j, i+1, n-1) {
            if (res[j] < res[i]) maxi(m, b[j]);
        }
        if (b[i] != m+1) cerr <<i << endl;
        assert(b[i] == m+1);
    }


    return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ":";
        solve();
    }
	return 0;
}


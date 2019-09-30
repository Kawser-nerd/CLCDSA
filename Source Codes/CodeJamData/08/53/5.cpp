#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair <int, VI> PIVI;
typedef long long ll;

string s[100];

struct pm {
    int n, m;
    VVI adj;
    VI rev;

    void add_pair(int q, int w) {
        adj[q].pb(w+n);
    }    
    
    int solve() {
        int res = 0;
        while (true) {
            VI st;
            VI p(n + m, -1);
            vector<bool> b(n + m);
            int cr = 0;
            int f = -1;
            REP(i, n) if (rev[i] == -1 && !b[i]) {
                st.pb(i);
                b[i] = true;
                for(; cr < SZ(st); ++cr) {
                    int j = st[cr];
                    if (j >= n) {
                        if (rev[j] == -1) { f = j; goto augment; }
                        if (!b[rev[j]]) {b[rev[j]] = true; p[rev[j]] = j; st.pb(rev[j]); }
                    } else {
                        REP(k, SZ(adj[j])) {                            
                            int t = adj[j][k];
                            if (!b[t] && rev[t] != j) { b[t] = true; p[t] = j; st.pb(t); }
                        }
                    }
                }                             
            }               
augment:    
            if (f == -1) break;
            ++res;
            while (f != -1) {
                rev[p[f]] = f;
                rev[f] = p[f];
                f = p[p[f]];
            }
        }
        return res;
    }
    
    pm(int n, int m) : n(n), m(m) {
        adj.resize(n);
        rev.resize(n+m, -1);            
    }       
};

VPII a, b;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
	cin >> test;	
	int n, m;
	FOR (ntest, 1, test + 1) {
		cout << "Case #" << ntest << ": ";
		cin >> n >> m;
		REP (i, n)
			cin >> s[i];
		a.clear();
		b.clear();
		REP (i, n)
			REP (j, m) if (s[i][j] == '.') {
				if (j & 1)
					a.pb (PII (i, j));
				else
					b.pb (PII (i, j));
			}
		pm pair_match (SZ (a), SZ (b));
		REP (i, SZ (a))
			REP (j, SZ (b))
				if (abs (a[i].X - b[j].X) <= 1 && abs (a[i].Y - b[j].Y) <= 1) 
					pair_match.add_pair (i, j);
		cout << (SZ (a) + SZ (b) - pair_match.solve());
		cout << endl;		
	}	
	return 0;
}

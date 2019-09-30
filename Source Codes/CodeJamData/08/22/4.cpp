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

bool p[2000002];
int primes[2000002];
int cp;

template <int N>
struct Disjoint {
    int rank[N];
    int p[N];    
    int n;
   
    int findset(int q) {
        int r = q, t;
        while (p[r] != r) r = p[r];
        while (p[q] != q) {
            t = p[q];
            p[q] = r;
            q = t;
        }
        return r;
    }

    void join(int q, int w) {
        q = findset(q);
        w = findset(w);
        if (rank[q] < rank[w]) p[q] = w; else {
            p[w] = q;
            if (rank[q] == rank[w]) rank[w]++;
        }
    }
    
    void init(int _n) {
        n = _n;
        memset (rank, 0, sizeof (rank));        
        REP(i, n)
            p[i] = i;
    }
};

Disjoint <2000001> ds;
bool hh[2000001];

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    FOR (i, 2, 1000002) if (!p[i]) {
		primes[cp] = i;
		cp++;	
		for (int j = 2; i * j < 1000002; ++j)
			p[i * j] = true;
	}    
    int test;
    cin >> test;
    FOR (ntest, 1, test+1) {
		cout << "Case #" << ntest << ": ";

		ll a, b, u;
		
		cin >> a >> b >> u;		
		
		ds.init (b - a + 1);
		REP (i, cp) if (primes[i] >= u && primes[i] <= b - a) {
			
			ll p1 = a / primes[i] * primes[i];
			if (p1 < a)
				p1 += primes[i];
			p1 -= a;
			for (int t1 = p1; t1  + primes[i] <= b - a; t1 += primes[i])
				ds.join (t1, t1 + primes[i]);			
		}
		
		int res = 0;
		memset (hh, 0, sizeof (hh));
		REP (i, b - a + 1) {
			int q = ds.findset (i);
			if (!hh[q])
				++res;
			hh[q] = true;
		}
		cout << res;
		cout << endl;
	}    
	return 0;
}

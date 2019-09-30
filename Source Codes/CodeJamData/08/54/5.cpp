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

const int mod = 10007;

int inv[mod];
int all_fact;

int mpower(int a, int b, int n) {
    ll cur = a;
    ll res = 1;
    while (b) {
        if (b&1)
             res = (res * cur) % n;
        cur = (cur * cur) % n;    
        b >>= 1;
    }
    return res;
}

int nums (int x) {
	return x / mod + x / (mod * mod);
}

int fact (int x) {
	int r = 1;
	for (int i = 1; i <= x; ++i) {
		if (i % mod == 0) {
			int next = x / mod * mod;
			r = (r * mpower (all_fact, (next - i) / mod, mod)) % mod;
			i = next;
		} else
			r = (r * i) % mod;
	}
	return r;
}

int ways (int x, int y) {
	if (x < 0 || y < 0)
		return 0;
		 
	if (2 * x - y < 0) 
		return 0;
	
	if ((2 * x - y) % 3 != 0)
		return 0;
	
	int l = (2 * x - y) / 3;
	int k = x - 2 * l;
	
	if (k < 0)
		return 0;	
		
	int n = k + l;
	
	if (nums (n) != nums (k) + nums (n - k))
		return 0;
	
	int res = fact (n);
	res *= inv[fact (k)];
	res %= mod;
	res *= inv[fact (n-k)];
	res %= mod;
	return res;
}

int main() {
	FOR (i, 1, mod)
		inv[i] = mpower (i, mod - 2, mod);
	all_fact = 1;
	FOR (i, 1, mod) {
		all_fact *= i;
		all_fact %= mod;
	}
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
	cin >> test;	
	FOR (ntest, 1, test + 1) {
		cout << "Case #" << ntest << ": ";
		int h, w, r;
		cin >> h >> w >> r;
		VPII b (r);
		REP (i, r) 
			cin >> b[i].X >> b[i].Y;
			
		int res = 0;
		REP (j, 1<<r) {
			int bits = 0;
			VPII a;
			a.pb (PII (1, 1));
			a.pb (PII (h, w));
			REP (k, r)
				if (j & (1<<k)) {
					a.pb (b[k]);
					++bits;
				}
			SORT (a);
			int ans = 1;
			REP (i, SZ (a)-1) {
				ans = ans * ways (a[i+1].X - a[i].X, a[i+1].Y - a[i].Y);
				ans %= mod;
			}
			if (bits % 2 == 0) {
				res += ans;
			} else
				res -= ans;			
			res %= mod;
			res += mod;
			res %= mod;
		}
		cout << res;
		cout << endl;		
	}	
	return 0;
}

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

template<int N>
struct Summator {
    int a[N + 1];
    int n;
    #define PREV(x) (x & (x - 1))
    #define NEXT(x) ((x << 1) - PREV(x))
    int sum(int q,int w) {
        q++;    w++;        
        static int r, x;
        r = 0;
        for(x = w; x; x = PREV(x)) r += a[x];
        for(x = q - 1;x;x = PREV(x)) r -= a[x];
        return r;
    }
    void modify(int x, int value) {
        x++;
        for(;x <= n; x = NEXT(x)) a[x] += value;
    }    
    void init(int _n) { 
        n = _n;
        memset(a, 0, sizeof(a));
    }
};

int res[1000001];
Summator<1000001> d;

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    FOR (ntest, 1, test+1) {
		cout << "Case #" << ntest << ":";
		int n, k;
		cin >> k;
		cin >> n;
		VI a (n);
		REP (i, n)
			cin >> a[i];
		d.init (k);		
			
		int pos = 0;
		REP (i, k) {
			pos += i;
			pos %= k - i;
			int b1 = 0;
			int b2 = k - 1;
			while (b1 < b2) {
				int mid = (b1 + b2) / 2;
				if (mid+1 - d.sum (0, mid) >= pos+1)
					b2 = mid;
				else
					b1 = mid + 1;
			}
			res[b1] = i+1;
			d.modify (b1, 1);
		}
		REP (i, n)
			cout << ' ' << res[a[i]-1];
		cout << endl;
	}    
	return 0;
}

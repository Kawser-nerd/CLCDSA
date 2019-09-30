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
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair <int, VI> PIVI;
typedef long long ll;

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    FOR (ntest, 1, test+1) {
		cout << "Case #" << ntest << ": ";
		
		ll n, A, B, C, D, x0, y0, m, X, Y;
		
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> m;
		X = x0, Y = y0;
		
		ll a[3][3];
		memset (a, 0, sizeof (a));
		a[X % 3][Y % 3]++;
		FOR (i, 1, n) {
		  X = (A * X + B) % m;
		  Y = (C * Y + D) % m;		  
  		 a[X % 3][Y % 3]++;		  
		}
	
		ll res = 0;
		REP (q1, 3)
			REP (q2, 3)
				REP (w1, 3)
					REP (w2, 3)
						REP (e1, 3)
							REP (e2, 3) if ((q1 + w1 + e1) % 3 == 0 && (q2 + w2 + e2) % 3 == 0) 
							if (PII (q1, q2) <= PII (w1, w2) && PII (w1, w2) <= PII (e1, e2))
							{
								ll p1 = a[q1][q2];
								ll p2 = a[w1][w2];
								ll p3 = a[e1][e2];
								
								if ((q1 == w1 && w1 == e1) && (q2 == w2 && w2 == e2)) 
									res += p1 * (p1 - 1) * (p1 - 2) / 6; else
								if (q1 == w1 && q2 == w2)
									res += p3 * (p1 * (p1 - 1) / 2); else
								if (w1 == e1 && w2 == e2)									
									res += p1 * (p2 * (p2 - 1) / 2); else
								res += p1 * p2 * p3;
							}
		cout << res;
		cout << endl;					
	}    
	return 0;
}

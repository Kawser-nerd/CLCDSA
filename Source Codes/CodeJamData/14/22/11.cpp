#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 31 + 3;

int n = 31;
int a[N], b[N], k[N];

inline void read (int a[N])
{
	int val;
	assert(scanf("%d", &val) == 1);
	forn(i, n) a[i] = bool(val & (1 << (n - 1 - i)));
}

inline bool read()
{
	read(a);
	read(b);
	read(k);
	return true;
}

li d[N][2][2][2];

inline void solve(int test)
{
	printf("Case #%d: ", test);
	
	memset(d, 0, sizeof(d));
	
	d[0][0][0][0] = 1;
	
	forn(i, n) forn(pa, 2) forn(pb, 2) forn(pk, 2)
	{
		const li& dv = d[i][pa][pb][pk];
		
		forn(da, 2) forn(db, 2)
		{
			int ni = i + 1, npa = pa, npb = pb, npk = pk;
			if (npa == 0 && da > a[i]) continue;
			if (npb == 0 && db > b[i]) continue;
			if (npk == 0 && (da & db) > k[i]) continue;
			
			if (da < a[i]) npa = true;
			if (db < b[i]) npb = true;
			if ((da & db) < k[i]) npk = true;
			
			d[ni][npa][npb][npk] += dv;
		}
	}
	
	cout << d[n][1][1][1] << endl;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int testCount;
	cin >> testCount;
	
	forl(test, testCount)
	{
		assert(read());
		solve(test);
#ifdef SU2_PROJ
		cerr << test << ' ' << clock() << endl;
#endif
	}
	
	return 0;
}

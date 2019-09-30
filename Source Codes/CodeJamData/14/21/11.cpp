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

const int N = 100 + 13;

int n;
char buf[N];
string s[N];

inline bool read()
{
	if (scanf("%d", &n) != 1) return false;
	
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		s[i] = string(buf);
	}
	
	return true;
}

inline bool check ()
{
	set <string> used;
	
	forn(i, n)
	{
		string cur = "";
		forn(j, sz(s[i])) if (cur.empty() || s[i][j] != cur[sz(cur) - 1]) cur.pb(s[i][j]);
		used.insert(cur);
		if (sz(used) > 1) return false;
	}
	
	return true;
}

vector <int> v[N];

inline void solve(int test)
{
	printf("Case #%d: ", test);
	
	if (!check())
	{
		puts("Fegla won");
		return;
	}
	
	forn(i, n)
	{
		v[i].clear();
		
		for (int j = 0; j < sz(s[i]); )
		{
			int st = j++;
			while (j < sz(s[i]) && s[i][j] == s[i][j - 1]) j++;
			v[i].pb(j - st);
		}
		
		assert(sz(v[i]) == sz(v[0]));
	}
	
	int ans = 0;
	
	forn(j, sz(v[0]))
	{
		int minv = INF;
		
		forl(k, 100)
		{
			int cur = 0;
			forn(i, n) cur += abs(v[i][j] - k);
			minv = min(minv, cur);
		}
		
		ans += minv;
	}
	
	printf("%d\n", ans);
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

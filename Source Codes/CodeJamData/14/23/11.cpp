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

const int N = 50 + 3;

int n, m;
char buf[N];
string s[N];
vector <int> g[N];

inline bool read()
{
	if (scanf("%d%d", &n, &m) != 2) return false;
	
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		s[i] = string(buf);
	}
	
	forn(i, n) g[i].clear();
	
	forn(i, m)
	{
		int a, b;
		assert(scanf("%d%d", &a, &b) == 2);
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	return true;
}

int was[N];
vector <int> perm;
vector <int> path;
int used[N];

void dfs (int v)
{
	used[v] = true;
	
	forn(i, sz(g[v]))
	{
		int to = g[v][i];
		if (!used[to]) dfs(to);
	}
}

inline bool cmp (int a, int b) { return s[a] < s[b]; }

inline void solve(int test)
{
	printf("Case #%d: ", test);
	
	perm.clear();
	path.clear();
	memset(was, 0, sizeof(was));
	
	int start = 0;
	
	forn(i, n) if (s[i] < s[start]) start = i;
	
	forn(i, n) sort(all(g[i]), cmp);
	
	int v = start;
	path.pb(v);
	perm.pb(v);
	was[v] = true;
	
	while (true)
	{
		forn(i, n) used[i] = was[i];
		int idx = 0;
		while (idx < sz(path))
		{
			dfs(path[idx]);
			int cnt = 0;
			forn(i, n) cnt += used[i];
			if (cnt == n) break;
			idx++;
		}
		
		string minv = string(5, '9');
		int id = -1, idto = -1;
		
		for (int i = sz(path) - 1; i >= idx; i--)
		{
			int vv = path[i];
			
			forn(j, sz(g[vv]))
			{
				int to = g[vv][j];
				if (was[to]) continue;
				if (s[to] < minv) minv = s[to], id = i, idto = to;
			}
		}
		
		if (id == -1) break;
		
		while (sz(path) > id + 1) path.pop_back();
		path.pb(idto);
		
		perm.pb(idto);
		was[idto] = true;
	}
	
	//forn(i, sz(perm)) cerr << perm[i] << ' '; cerr << endl;
	
	assert(sz(perm) == n);
	
	forn(i, n) printf("%s", s[perm[i]].c_str());
	puts("");
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

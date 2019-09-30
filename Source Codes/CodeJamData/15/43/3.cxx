#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct te{
	int v1, v2;
	int a, f;
};

int qq;
int n, m, k, ee;
char s[102400]; 
int b[222][2024];
bool g[4096][4096];
VI a[9192];
te e[1024000];
int q[9192];
int d[9192];
int pa[9192];

void adde(int v1, int v2, int aa)
{
	a[v1].pb(ee);
	e[ee].v1 = v1;
	e[ee].v2 = v2;
	e[ee].a = aa;
	e[ee].f = 0;
	ee++;
	a[v2].pb(ee);
	e[ee].v1 = v2;
	e[ee].v2 = v1;
	e[ee].a = 0;
	e[ee].f = 0;
	ee++;
}

int find(int st, int en)
{
	memset(d, 0x3f, sizeof(d));
	d[st] = 0;
	int qb = 0, qe = 0;
	q[qe++] = st;
	while (qb != qe)
	{
		int p = q[qb++];
		forn(i1, a[p].sz)
		{
			int i = a[p][i1];
			int vn = e[i].v2;
			if (e[i].f < e[i].a && d[vn] > d[p] + 1)
			{
				d[vn] = d[p] + 1;
				pa[vn] = i;
				q[qe++] = vn;
			}
		}
	}
	return d[en] < 0x3f3f3f3f;
}

int flow(int st, int en)
{
	int ans = 0;
	for(;;)
	{
		int j = find(st, en);
		if (j <= 0) break;
		ans++;
		int v = en;
		while (v != st)
		{
			int ee = pa[v];
			e[ee].f++;
			e[ee ^ 1].f--;
			v = e[ee].v1;
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d\n", &n);
		MSI w;
		clr(b);
		m = 0;
		ee = 0;
		clr(g);
		forn(i, n)
		{
			gets(s);
			istringstream is(s);
			string str;
			while (is >> str)
			{
				if (!w.count(str)) w[str] = m++;
				b[i][++b[i][0]] = w[str];
			}
		}
		int st = m * 2 + n;
		int en = st + 1;
		k = en + 1;
		cerr << "k = " << k << endl;
		forn(i, m)
		{
			adde(i, m + i, 1);
/*			forn(j, m)
			{
				if (g[i][j])
				{
					adde(m + i, j);
				}
			}*/
		}
		forn(i, n)
		{
			For(j, 1, b[i][0])
			{
				int x = b[i][j];
				adde(m + x, m * 2 + i, 10000);
				adde(m * 2 + i, x, 10000);
			}
		}
		For(j, 1, b[0][0])
		{
			adde(st, b[0][j], 10000);
		}
		For(j, 1, b[1][0])
		{
			adde(m + b[1][j], en, 10000);
		}

		int ans = flow(st, en);
		printf("%d\n", ans);

		forn(i, k)
		{
			a[i].clear();
		}
		
		fflush(stdout);
	}

	return 0;
}

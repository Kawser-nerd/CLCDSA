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

int qq;
int n;
VI a[4024];
int e[82][2];
int c[4024];
int dist[2][82];
int d[82][82][2][4];
bool u[82][82][2][4];
int pa[2][82];

inline int get_node(int v, int i)
{
	if (e[i][e[i][0] != v] != v) for(;;);
	return e[i][e[i][0] == v];
}

void bfs(int t, int k)
{
	int q[102];
	bool u[102] = {0};
	int qb = 0, qe = 0;
	dist[t][k] = 0;
	q[qe++] = k;
	u[k] = true;
	while (qb != qe)
	{
		int v = q[qb++];
		forn(i1, a[v].sz)
		{
			int i = get_node(v, a[v][i1]);
			if (u[i]) continue;
			u[i] = true;
			q[qe++] = i;
			dist[t][i] = dist[t][v] + 1;
			pa[t][i] = a[v][i1];
		}
	}
}

int solve(int st0, int st1, int x, int y, int t, int mask)
{
	if (mask == 3) return 0;
//	cerr << st0 << " " << st1 << " " << x << " " << y << " " << t << " " << mask << endl << flush;
	int &ans = d[x][y][t][mask];
	if (u[x][y][t][mask]) return ans;
	u[x][y][t][mask] = true;
	ans = -1e9;
	int aa = -1000000000;

	bool w[82] = {0};
	bool w2[82] = {0};

	{
		int st = !t ? st0 : st1;
		int z = !t ? x : y;
		if (mask & (1 << t)) w2[z] = true;
		while (z != st)
		{
//			cerr << st << " " << z << " " << t << endl;
			w[pa[t][z]] = true;
			z = get_node(z, pa[t][z]);
			w2[z] = true;
		}
	}

	int st = t ? st0 : st1;
	int z = t ? x : y;
	if (mask & (1 << !t)) w2[z] = true;
	while (z != st)
	{
		w[pa[!t][z]] = true;
		z = get_node(z, pa[!t][z]);
		w2[z] = true;
	}

	z = !t ? x : y;
	int add = !w2[z] * c[z];

	if (!(mask & (1 << t)))
	{
		forn(i1, a[z].sz)
		{
			int i = a[z][i1];
			if (w[i]) continue;
			int vn = get_node(z, i);
	    
//			cerr << "move: " << st0 << " " << st1 << " " << x << " " << y << " " << t << " " << mask << endl;
//			if (dist[t][vn] <= dist[t][z]) continue;
//			cerr << "!1" << endl;
			int xn = x;
			int yn = y;
			if (t) yn = vn;
			else xn = vn;
			int tmp = -solve(st0, st1, xn, yn, !t, mask);
			aa = max(aa, tmp + add);
		}
		if (aa <= -1000000000)
		{
			aa = -solve(st0, st1, x, y, !t, mask | (1 << t)) + add;
		}
	}
	else
	{
		aa = -solve(st0, st1, x, y, !t, mask | (1 << t));
	}
	ans = aa;

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
		
		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%d", &c[i]);
		}
		forn(i, n - 1)
		{
			int x = i, y;
			scanf("%d", &y);
			y--;
			e[i][0] = x;
			e[i][1] = y;
			a[x].pb(i);
			a[y].pb(i);
		}
/*		forn(i, n)
		{
			forn(j, a[i].sz)
			{
				cerr << i << " " << get_node(i, a[i][j]) << endl;
			}
		}*/

		int ans = -1e9;

		forn(i, n)
		{
			int t = 1e9;
			forn(j, n)
			{
				bfs(0, i);
				bfs(1, j);
/*				cerr << i << ":";
				forn(k, n)
				{
					cerr << get_node(k, pa[0][k]) << " ";
				}
				cerr << endl;
				cerr << j << ":";
				forn(k, n)
				{
					cerr << get_node(k, pa[1][k]) << " ";
				}
				cerr << endl;*/
				memset(d, 0, sizeof(d));
				clr(u);
				int z = solve(i, j, i, j, 0, 0);
				if (rand() % 100 < 1) cerr << i << " " << j << " " << z << endl;
				if (z < t) t = z;
			}
			if (t > ans) ans = t;
		}

		printf("%d\n", ans);

		forn(i, n)
		{
			a[i].clear();
		}
		
		fflush(stdout);
	}

	return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, k;
int a[100][25];
bool g[100][100], u[100];
int ma[100];

bool go (int v)
{
	if (u[v])
		return 0;
	u[v] = 1;
	forn (i, n)
		if (g[v][i])
			if (ma[i] == -1 || go (ma[i]))
			{
				ma[i] = v;
				return 1;
			}
	return 0;
}

int main ()
{
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		scanf ("%d%d", &n, &k);
		forn (i, n)
			forn (j, k)
				scanf ("%d", &a[i][j]);
		seta (g, 0);
		forn (i, n)
			forn (j, n)
			{
				bool ok = 1;
				forn (l, k)
					if (a[i][l] <= a[j][l])
						ok = 0;
				g[i][j] = ok;
			}
		int res = n;
		seta (ma, 255);
		forn (i, n)
		{
			seta (u, 0);
			if (go (i))
				res --;
		}
		printf ("%d\n", res);
	}
	return 0;
}
